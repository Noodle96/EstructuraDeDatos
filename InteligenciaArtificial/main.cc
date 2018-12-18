#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    fstream sw;
    std::vector<std::string> v;
    sw.open("stopWords.txt", ios::in);
    string w;
    int cont =0;
    sw >> w;
    while(!sw.eof()){
        cout << w << endl;
        v.push_back(w);
        sw >> w;
        cont++;
    }

    cout << endl;
    std::cout << "cantidad de palabras:  " << cont <<  '\n';

    sw.close();
    for(auto it = v.begin(); it != v.end() ; it++){
        //cout  << (*it) << " ";
    }
    cout << endl;
    auto it = find(v.begin(), v.end(),"twenty");
    cout << (*it) << endl;


    return 0;
}
