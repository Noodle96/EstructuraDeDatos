template <typename T>
void LinkedList<T>::load( T d, bool &here){
    ifstream salidaPrin;
    string name = functionSupport::nameAgenda();

    salidaPrin.open(name+dat, ios::in);
    Persona p;
    int cont = 0;
    while(  salidaPrin.read((char*)&p, sizeof(p)) ){
        // p.showData();
        cont++;
        // p.reset();
        if(d==p) here=true;
        AddR(p);
    }
    // std::cout << "cont: "<< cont << '\n';
    salidaPrin.close();
}
