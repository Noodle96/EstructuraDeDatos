template <typename T>
void LinkedList<T>::write(T d){
    ofstream entradaPrin;
    string name = functionSupport::nameAgenda();
    entradaPrin.open(name+dat, ios::out | ios::app);

    // Persona p;
    // p.setNumeroDocumento(34);
    // p.setNombre("Pablo");
    // p.setApellido("Movics");
    // p.setFechaNacimiento("1-12-12");
    // p.showData();

    // p.pedir();
    entradaPrin.write((char*)&d, sizeof(d));
    // entradaPrin.seekp(0, ios::end);
    // int l = entradaPrin.tellp() / sizeof(p);
    // std::cout << l << std::endl;
    entradaPrin.close();

}
