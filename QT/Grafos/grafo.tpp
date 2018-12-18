//BEGIN GRAFO.TPP

/*
    Insertar:
    Primero Crea un vertice y lo agrega a la lista de Vertices del grafo
*/
template<typename V, typename E>
bool Grafo<V,E>::addVertice(V v){
    m_ListaG.push_back(Vertice<V,E>(v));
}




//print normalizado; es decir el la lista de vertices con su respectiva lista de aristas
template<typename V, typename E>
void Grafo<V,E>::print(){
    auto it = m_ListaG.begin();
    for( ; it != m_ListaG.end() ; it++){
        std::cout << (*it).m_DatoV << " -> " ;
        for(auto et = (*it).m_listAristaV.begin() ;  et != (*it).m_listAristaV.end() ; et++){
            std::cout << (*et).m_DatoE << "|" << (*et).p_Destino->m_DatoV << "   ";
        }
        std::cout << "\n";
    }
}




/*
    AddArista:
        Primero verificamos si es que  existe el vertice con el valor v1 y v2=> en caso esto sea true
        se agrega nomas
        lo contratio No.
*/
template<typename V, typename E>
bool Grafo<V,E>::addArista(V v1,V v2,E e){
    auto itv1 = std::find( m_ListaG.begin(), m_ListaG.end(), Vertice<V,E>(v1));
    auto itv2 = std::find( m_ListaG.begin(), m_ListaG.end(), Vertice<V,E>(v2));
    if( itv1 != m_ListaG.end() && itv2 != m_ListaG.end()  ){ //found ambos

        (*itv1).m_listAristaV.push_back(Arista<V,E>(e,&(*itv2)));
        return true;
    }
    else{
        std::cout << "No encontrados" << std::endl;
        return false;
    }
}



//print in dot to show in main windows
//arequipa-> 8|puno -> 89|cusco
template<typename V, typename E>
void Grafo<V,E>::PrintInDot(){
    std::fstream file;
    file.open("/home/Nano/QT/Grafos/file.dot",std::ios::out);
        file << "digraph ll {\n";
        for(auto et =m_ListaG.begin() ; et != m_ListaG.end() ; et++ )file << (*et).m_DatoV  << " ";
    auto it = m_ListaG.begin();
    for( ; it != m_ListaG.end() ; it++){
        //std::cout << (*it).m_DatoV << " -> " ; // arequipa
        for(auto et = (*it).m_listAristaV.begin() ;  et != (*it).m_listAristaV.end() ; et++){
            //std::cout << (*et).m_DatoE << "|" << (*et).p_Destino->m_DatoV << "   "; // 8|puno -> 89|cusco
            file << "\t" << (*it).m_DatoV << "->" << (*et).p_Destino->m_DatoV << "[label=\"" << (*et).m_DatoE << "\"];\n";
        }
        //std::cout << "\n";
    }
    file << "\n}";
    file.close();
    system("dot -Tpng  /home/Nano/QT/Grafos/file.dot -o /home/Nano/QT/Grafos/file.png");
}


























//END GRAFO.TPP
