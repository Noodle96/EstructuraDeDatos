#ifndef Sequential_hpp
#define Sequential_hpp

#include <algorithm>
#include <climits>
#include <iostream>
#include <cstdio>
#include <vector>
#include <stdio.h>
#include <fstream>

using namespace std;

void begin(){
    ofstream file("Bplus.dot");
    file<<"digraph Q{"<<endl;
    file<<" node [shape=record,height=.1];"<<endl;
}

void end(){
    ofstream file;
    file.open("Bplus.dot",ios::app);
    file<<"}";
    file.close();
}

void graph(){
    system("dot -Tpdf Bplus.dot -o Bplus.pdf");
}

const int ORDER = 4;

enum NodeType {
    INTERNAL = 0,
    LEAF
};

struct Node {
    NodeType type;
    int size;
    Node* parent;
    Node* left_sibling;
    Node* right_sibling;
    int id;

    bool isRoot() {
        return parent == NULL;
    }

    bool isFull() {
        return size >= ORDER - 1;
    }
    virtual void print() = 0; // for debug
};

struct KeyValuePair {
    int key;
    int value;
};

int k = 0;

struct Leaf : Node {
    KeyValuePair key_value[ORDER];

    Leaf() {
        type = LEAF;
        size = 0;
        parent = left_sibling = right_sibling = NULL;
    }

    void print() {
        ofstream file;
        file.open("Bplus.dot",ios::app);

        if (parent) {
            std::cout<<"ID: "<<id<<" size: "<<size<<" parent: "<< parent->id;
        } else {
            std::cout<<"ID: "<<id<<" size: "<<size<<" parent: NULL";
        }
        if (left_sibling) {
            std::cout<<" Left sibling: "<<left_sibling->id;
        } else {
            std::cout<<" Left sibling: NULL";
        }
        if (right_sibling) {
            std::cout<<" Right sibling: "<<right_sibling->id<<'\n';
        } else {
            std::cout<<" Left sibling: NULL"<<'\n';
        }

        file<<" node"<<id<<"[label = \"<f0> ";
        int j = 1;

        std::cout<<"values: ";
        for (int i = 0; i < size; ++i) {
            std::cout<< key_value[i].key<<' ';
            file<<"|"<<key_value[i].key<<"|<f"<<j<<"> ";
            j++;
        }

        file<<"\"];"<<endl;
        file<<" \"node"<<parent->id<<"\":f"<<k<<" -> \"node"<<id<<"\""<<endl;
        k++;

        std::cout<<'\n';
    }
};

struct KeyReferencePair {
    int key;
    Node* reference;
};

struct InternalNode : Node {
    KeyReferencePair key_ref[ORDER+1];

    InternalNode() {
        type = INTERNAL;
        size = 0;
        parent = left_sibling = right_sibling = NULL;
        key_ref[0].key = INT_MAX;
    }

    void print() {
        ofstream file;
        file.open("Bplus.dot",ios::app);

        if (parent) {
            std::cout<<"ID: "<<id<<" size: "<<size<<" parent: "<< parent->id;
        } else {
            std::cout<<"ID: "<<id<<" size: "<<size<<" parent: NULL";
        }
        if (left_sibling) {
            std::cout<<" Left sibling: "<<left_sibling->id;
        } else {
            std::cout<<" Left sibling: NULL";
        }
        if (right_sibling) {
            std::cout<<" Right sibling: "<<right_sibling->id<<'\n';
        } else {
            std::cout<<" Left sibling: NULL"<<'\n';
        }

        file<<" node"<<id<<"[label = \"<f0> ";
        int j = 1;

        std::cout<<"keys: ";
        for (int i = 0; i < size; ++i) {
            std::cout<< key_ref[i].key<<' ';
            file<<"|"<<key_ref[i].key<<"|<f"<<j<<"> ";
            j++;
        }

        file<<"\"];"<<endl;

        cout<<'\n';
        std::cout<<"childs ID: ";
        for (int i = 0; i <= size; ++i) {
            std::cout<< key_ref[i].reference->id<<' ';
        }
        std::cout<<'\n';
    }
};


class SeqBPlusTree {
private:
    Node* root;
    int depth;
    int node_count; // # of nodes
    // a monotonicly increasing accumulator for node id assignment
    // may overflow if the numebr nodes ever created by the tree is more than INT_MAX
    // But this is hardly happending because we don't expect the tree size to be
    // that huge (unfortunately the memory will overflow first) or the tree structures
    // to exists for that long time.
    // Possible improvement: maintain a set of ids of deleted nodes in addition
    // to id_accumulator. Only increase id_accumulator and use it to assign a new
    // node id when the set is empty. Otherwise, extract an id from the set for
    // a newly created node.
    int id_accumulator;

public:
    SeqBPlusTree();
    void print();
    int search(int key);
    bool insert(int key, int value);
    bool remove(int key);
private:
    Leaf* leaf_search(int key, Node* curr_node);
    void sort_entry_by_key(Node* curr_node);
    void split_leaf(Leaf* curr_leaf);
    void leaf_remove(int key);
    void parent_insert(Node* curr_node, int key, Node* right_half);
    void split_internal(InternalNode* curr_node);
    void print_recusive(vector<Node*> nodeVec);
};


// at the beginning the root should be only a leaf
SeqBPlusTree::SeqBPlusTree() {
    root = new Leaf();
    depth = 0;
    node_count = 1;
    id_accumulator = 1;
    root->id = 1;
}

int SeqBPlusTree::search(int key) {
    Leaf* leaf = leaf_search(key, root);
    for (int i = 0; i < leaf->size; ++i) {
        if (key == leaf->key_value[i].key) {
            return leaf->key_value[i].value;
        }
    }
    return -1;
}


bool SeqBPlusTree::insert(int key, int value) {
    Leaf* leaf = leaf_search(key, root);
    for (int i = 0; i < leaf->size; ++i) {
        if (key == leaf->key_value[i].key) {
            leaf->key_value[i].value = value;
            return false;
        }
    }
    // if the node is full, need to split after insertion
    bool needSplit = leaf->isFull();
    leaf->key_value[leaf->size].key = key;
    leaf->key_value[leaf->size++].value = value;
    sort_entry_by_key(leaf);

    if (needSplit) {
        split_leaf(leaf);
    }

    return true;
}

bool SeqBPlusTree::remove(int key){
    int rev = -1;
    Leaf* leaf = leaf_search(key, root);
    InternalNode* parent = (InternalNode*) leaf->parent;
    for (int i = 0; i < leaf->size; ++i) {
        if (key == leaf->key_value[i].key) {
            rev = i;
            if(rev < 0){return false;}
            else{
                for (int i = rev+1; i < leaf->size; ++i){
                    leaf->key_value[i-1] = leaf->key_value[i];
                }
                leaf->size--;
            }
            rev = -1;
            for (int i = 0; i <= parent->size; ++i) {
                if (key == parent->key_ref[i].key) {
                    rev = i;
                    if(rev < 0){return true;}
                    else{
                        for (int i = rev+1; i < parent->size; ++i){
                            parent->key_ref[i-1] = parent->key_ref[i];
                        }
                        parent->key_ref[i].key = leaf->key_value[0].key;
                    }
                    bool needSplit = leaf->isFull();
                    sort_entry_by_key(leaf);
                    if (needSplit) {
                        split_leaf(leaf);
                    }
                    cout<<"key has been removed"<<endl;
                    return true;
                }
            }
            cout<<"key has been removed"<<endl;
            return true;
        }
    }
    return false;
}

void SeqBPlusTree::print() {
    vector<Node*> rootVec;
    rootVec.push_back(root);
    print_recusive(rootVec);
}

Leaf* SeqBPlusTree::leaf_search(int key, Node* curr_node) {
    if (LEAF == curr_node->type) {
        return (Leaf*) curr_node;
    }
    InternalNode* curr_internal = (InternalNode*) curr_node;
    for (int i = 0; i < curr_internal->size; ++i) {
        if (key < curr_internal->key_ref[i].key) {
            return leaf_search(key, curr_internal->key_ref[i].reference);
        }
    }
    // if the key is lager than every seperator, the only possible location
    // is in the dummy reference
    return leaf_search(key, curr_internal->key_ref[curr_internal->size].reference);
}

void SeqBPlusTree::sort_entry_by_key(Node* curr_node) {
    if (LEAF == curr_node->type) {
        Leaf* curr_leaf = (Leaf*)curr_node;
        sort(curr_leaf->key_value, curr_leaf->key_value + curr_leaf->size,
            [](KeyValuePair a, KeyValuePair b) {
                return a.key < b.key;
            });
    } else {
        InternalNode* curr_internal = (InternalNode*)curr_node;
        // need to +1 because there is a dummy key INT_MAX at key_ref[size]
        sort(curr_internal->key_ref, curr_internal->key_ref + curr_internal->size+1,
            [](KeyReferencePair a, KeyReferencePair b) {
                return a.key < b.key;
            });
    }
    return;
}

void SeqBPlusTree::split_leaf(Leaf* curr_node) {
    if (curr_node == NULL || LEAF != curr_node->type || !curr_node->isFull()) {
        cerr << "Not a valid leaf or the leaf is not full." << endl;
        return;
    }

    Leaf* right_half = new Leaf();
    for (int i = curr_node->size/2, j = 0; i < curr_node->size; ++i, ++j) {
        right_half->key_value[j] = curr_node->key_value[i];
        right_half->size++;
    }
    right_half->id = ++id_accumulator;
    ++node_count;

    int medianKey = curr_node->key_value[curr_node->size/2].key;
    curr_node->size = curr_node->size/2;

    // update siblings, from right to left
    if (NULL != curr_node->right_sibling) {
        curr_node->right_sibling->left_sibling = right_half;
    }
    right_half->right_sibling = curr_node->right_sibling;
    right_half->left_sibling  = curr_node;
    curr_node->right_sibling  = right_half;

    parent_insert(curr_node, medianKey, right_half);

    return;
}

void SeqBPlusTree::parent_insert(Node* curr_node, int key, Node* right_half) {
    InternalNode* parent = (InternalNode*) curr_node->parent;
    // if the split node is root, we need to add a new root
    if (parent == NULL) {
        parent = new InternalNode();
        depth++;
        parent->id = ++id_accumulator;
        node_count++;
        root = parent;
    }
    // if parent is full, we need to split the parent afterwards
    bool parent_split = parent->isFull();

    // ++ first because there is a dummy key INT_MAX at key_ref[size]
    parent->key_ref[++(parent->size)].key   = key;
    parent->key_ref[parent->size].reference = curr_node;
    sort_entry_by_key(parent);
    // Search for the first key-reference pair whose key is greater than the
    // inserted key, this pair is also pointed to the current node
    // Now redirect it to the right.
    // Need to use <= because also need to check the dummy key INT_MAX at key_ref[size]
    for (int i = 0; i <= parent->size; ++i) {
        if (key < parent->key_ref[i].key) {
            parent->key_ref[i].reference = right_half;
            break;
        }
    }
    curr_node->parent  = parent;
    right_half->parent = parent;

    // if parent is full, we need to split the parent
    if (parent_split) {
        split_internal(parent);
    }

    return;
}

void SeqBPlusTree::split_internal(InternalNode* curr_node) {
    if (curr_node == NULL || !curr_node->isFull()) {
        cerr << "Not a valid node or the node is not full." << endl;
        return;
    }

    InternalNode* right_half = new InternalNode();
    // Need to use <= because we also want to copy the dummy key INT_MAX at key_ref[size]
    for (int i = curr_node->size/2 + 1, j = 0; i <= curr_node->size; ++i, ++j) {
        right_half->key_ref[j] = curr_node->key_ref[i];
        right_half->size++;
        Node* child = curr_node->key_ref[i].reference;
        child->parent = right_half;
    }
    right_half->size--; // -1 because there is a dummy key INT_MAX at key_ref[size]
    right_half->id = ++id_accumulator;
    ++node_count;

    int medianKey = curr_node->key_ref[curr_node->size/2].key;
    curr_node->size = curr_node->size / 2;
    curr_node->key_ref[curr_node->size].key = INT_MAX;

    // update siblings, from right to left
    if (NULL != curr_node->right_sibling) {
        curr_node->right_sibling->left_sibling = right_half;
    }
    right_half->right_sibling = curr_node->right_sibling;
    right_half->left_sibling  = curr_node;
    curr_node->right_sibling  = right_half;

    parent_insert(curr_node, medianKey, right_half);

    return;
}
void SeqBPlusTree::print_recusive(vector<Node*> nodeVec) {
    vector<Node*> nextLevel;
    bool hit_leaves = LEAF == nodeVec.front()->type;
    for (int i = 0; i < nodeVec.size(); ++i) {
        nodeVec.at(i)->print();
        // cout << " ";
        cout << endl;
        if (hit_leaves) continue;
        for(int j = 0; j <= nodeVec.at(i)->size; ++j) {
            nextLevel.push_back( ((InternalNode*)nodeVec.at(i))->key_ref[j].reference);
        }
    }
    cout << endl;
    if (hit_leaves) return;
    print_recusive(nextLevel);
}

#endif
