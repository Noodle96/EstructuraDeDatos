namespace functionSupport{
    void clear(){
        system("clear");
    }
    std::string nameAgenda(){
        return "agenda";
    }
    void Menu(){
		cout << "\n\n\n" ;
		cout << "\t\t\tMENU PRINCIPAL - AGENDA DEL PERSONAL\n" << endl;;
        cout << "\t\t\t 1   Agregar Personal" << endl;          //echo
		cout << "\t\t\t 2   Eliminar Personal " << endl;        //echo
		cout << "\t\t\t 3   Buscar Personal " << endl;
		cout << "\t\t\t 4   Modificar Personal " << endl;
        cout << "\t\t\t 5   Mostrar Personal" << endl;          // echo
		cout << "\t\t\t 0   Salir" << endl;                     //echo
		cout << "\n\t\t\tElige una opcion -->  ";
    }
}
