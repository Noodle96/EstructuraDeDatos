template <typename T>
// l1 [label="{<data> cat |<ref>}"];
void LinkedList<T>::printGraphviz(int cant){
    ofstream fileDot;
    string name ;
    name = "dot" + to_string(cant);
    std::cout << name << '\n';
    fileDot.open("dots/"+name+".dot");
        fileDot << "digraph ll {" << std::endl;
            fileDot << "\tnode [shape=Mrecord, fontsize=16];" << std::endl;
            fileDot << "\trankdir=LR;" << std::endl;
            fileDot << "\tedge [tailclip=false];" << std::endl;
//            fileDot << "\tsize=\"20,20\";" << std::endl;
	    fileDot << "ranksep=.75;" << std::endl;

            // l1 [label="{ { <data>1 }|  <ref> OBx001201201 \n\n\n} | <actual> OA"];

            Nodo<T> *temp = m_pHead;
            int e = 1;
            for( ; temp; temp = temp->m_pSig, e++){
                fileDot << "\tnodo" << e << " [height = 0.015, width = 0.03,label=\"{ {<data> " << temp->m_Dato <<" } | <ref> " << temp->m_pSig << "\\n\\n\\n"  << "} | <actual> " << temp << " \"];" << std::endl;
            }
            // null[shape=box];
            fileDot << "\tnull[shape=box];" << std::endl << std::endl;
            e -=1; // e se adelantp uno mas
            std::string areglo_flecha = "[arrowtail=dot, arrowhead=vee, dir=both];";
            for(int j = 1 ;j <= e ; j++){
                if(j == e){
                    // l4:ref:c -> null [arrowtail=dot, arrowhead=vee, dir=both];
                    fileDot << "\tnodo" << j << ":ref:c -> null " << areglo_flecha << std::endl;
                }
                else{
                    // l1:ref:c -> l2 [ arrowtail=dot, arrowhead=vee, dir=both ];
                    // fileDot << "\tnodo" << j << ":ref:c -> " << "nodo" << j+1 << areglo_flecha << std::endl;
                    fileDot << "\tnodo" << j << ":ref:c -> " << "nodo" << j+1 << areglo_flecha << std::endl;

                }
            } //end_for

        fileDot << "}" << std::endl;
        fileDot.close();
    // std::cout << "entro a printGraphviz" << '\n';
    // dot -Tpng name.dot -o example.png
    string llamado =  "dot -Tpng dots/" + name + ".dot -o figures/" + name + ".png";
    cout   << llamado << endl;
    system(llamado.c_str());

}
