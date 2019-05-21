#include "hardDisk.h"


/*
    Esta funcion genera aproximadamente a lo maximo cantidad numeros aleatorios
*/
void HardDisk::generarAleatorios(int cantidad){
    srand(time(NULL));
    unsigned short int alea;
    std::vector<unsigned short int> Vbits(LIMITEPISTAS + 1,0);
    for(auto e = 0 ; e < cantidad; e++){
        alea = 0 + rand() % (LIMITEPISTAS + 1 - 0);
        //std::cout << alea << std::endl;
        if( !Vbits[alea] ){
            this->pistas.push_back(alea);
            Vbits[alea]=1;
        }
    }
    //this->first = (*this->pistas.begin()) ;
}

void HardDisk::test(){
    std::cout << "hardDisk Simulation" << LIMITEPISTAS << std::endl;
}

void HardDisk::printPistas(){
    //pistas.sort();
    for(auto it = this->pistas.begin() ;it != this->pistas.end() ; it++){
        std::cout << (*it) << std::endl;
    }
    //std::cout << "Numero de Pistas: " << this->pistas.size() << std::endl;
}




//planification algorithm HardDisk
float HardDisk::FIFO(){
    float TiempoBusquedaPromedio = 0.0;
    int sumatoriaTotal = 0;
    //first step:  vaciamos la this->lista de pistas en la queue
    std::queue< unsigned short int > Queuee;
    for(auto it = pistas.begin() ; it != pistas.end(); it++){
        Queuee.push((*it));
    }
    //std::cout << Queuee.front() << std::endl;

    //second Step :  calcular distancias entre cada pista sacada de la cola
    auto current = Queuee.front(); Queuee.pop();
    while(!Queuee.empty()){
        sumatoriaTotal += labs( current-Queuee.front() );
        current = Queuee.front(); Queuee.pop();
    }
    TiempoBusquedaPromedio = sumatoriaTotal / (this->pistas.size() -1);
    //std::cout <<"SumatoriaTotal" << sumatoriaTotal << "pistas - 1  " << (this->pistas.size() -1) << std::endl;
    return TiempoBusquedaPromedio;
}

float HardDisk::SSTF(){
    float TiempoBusquedaPromedio = 0.0;
    int sumatoriaTotal = 0;
    //first step ordenar la lista  en otra
    std::list<unsigned short int> copy;
    copy = this->pistas;
    copy.sort();
    //std::cout << "Printed the copy list ordenada" << '\n';
    // for(auto it = copy.begin() ;it != copy.end() ; it++){
    //     std::cout << (*it) << std::endl;
    // }
    //std::cout << "original" << '\n';
    //printPistas();


    //step 2: determinar cual es la posicion en copy  de el primer elemento de this->Pistas
    // int position=-1,e=0;
    // for(auto it = copy.begin() ; it != copy.end(); it++){
    //     if( (*it) == (*this->pistas.begin()) ){
    //         position = e;break;
    //     }
    //     e++;
    // }


    //find the first element in la list copy
    auto pos_current_in_copy = find(copy.begin(), copy.end(), (*this->pistas.begin()) );
    auto tempPost = pos_current_in_copy;
    //step2: verificanco si se va para abajo o hacia arriba
    auto next = ++tempPost; tempPost = pos_current_in_copy;
    auto prev = --tempPost; tempPost = pos_current_in_copy;

    //std::cout << "current: "<<(*pos_current_in_copy) << '\n';
    //std::cout << "next "<<(*next) << '\n';
    //std::cout <<"prev: "<< (*prev) << '\n';


    //para analizar cada caso
    int sumatoriaTotalPistas = 0;

    if(*pos_current_in_copy == *copy.begin()){
        //ir de abajo hacia arriba
        //std::cout << "ir de abajo hacia arriba" << std::endl;

        for(auto et = copy.begin() ;et != (--copy.end()) ; et++){
            //...
            auto temp_et = et; ++temp_et;
            sumatoriaTotalPistas += labs((*et) - (*temp_et));
            //std::cout <<"test:  de "  << (*et) << "hacia " << (*temp_et)  <<" es "<<  labs((*et) - (*temp_et)) << std::endl;
        }
        std::cout <<  "SUMATORIA TOTAL 1 "<< sumatoriaTotalPistas << std::endl;
        return sumatoriaTotalPistas / (copy.size() -1);
    }
    // else if(*pos_current_in_copy == --(*copy.end()) ){
    //     // ir de arriba hacia abajo
    //     std::cout << "ir de arriba hacia abajo" << std::endl;
    //     for(auto et = copy.cbegin() ;et != (--copy.cend()) ; et++){
    //         auto temp_et = et; ++temp_et;
    //         sumatoriaTotalPistas += labs( (*et)-(*temp_et) );
    //         std::cout <<"test:  de "  << (*et) << "hacia " << (*temp_et)  <<" es "<<  labs((*et) - (*temp_et)) << std::endl;
    //     }
    //     std::cout << "SUMATORIA TOTAL 2" << sumatoriaTotal << std::endl;
    //     return sumatoriaTotalPistas / (copy.size() -1);
    //}
    else if(      labs(*pos_current_in_copy-(*prev))  < labs(*pos_current_in_copy-(*next))   ){
        //ir hacia abajo hast 0
        std::queue<unsigned short int> qtest;

        //std::cout << "hacia abajo y luego de arriba hacia abajo" << std::endl;
        auto et = pos_current_in_copy;
        for( ; et != copy.end() ; et--){
            //std::cout <<"test_ "<<  (*et) << std::endl;
            qtest.push((*et));

        }
        // std::cout << "imprimiendo las pistas en absoluto" << std::endl;
        // for(auto ot = copy.begin() ; ot !=copy.end() ; ot++){
        //     std::cout << "copy_test: " << (*ot) << std::endl;
        // }
        //ir del tope hasta pos_current_in_copy
        for(auto it = --copy.end() ; it != pos_current_in_copy; it--){
            //std::cout <<"test "<<  (*it) << std::endl;
            qtest.push(*it);
        }
        ////////////////////////////////////////////////////////////////////////////////////////
        // desarrollando la cola
        auto current = qtest.front(); qtest.pop();
        //std::cout << "Imprimiendo la cola caso 2" << std::endl;
        while(!qtest.empty()){
            //std::cout << qtest.front() << std::endl; qtest.pop();
            sumatoriaTotalPistas += labs(current-qtest.front());
            current = qtest.front(); qtest.pop();
        }
        return sumatoriaTotalPistas / (copy.size() - 1);
        ////////////////////////////////////////////////////////////////////////////////////////

    }
    else{
        //std::cout << "hacia arriba y luego de abajo hacia arriba" << std::endl;
        std::queue<unsigned short int> qtest2;
        auto et = pos_current_in_copy;
        for( ; et != copy.end() ; et++){
            //std::cout <<"test_ "<<  (*et) << std::endl;
            qtest2.push((*et));
        }
        //std::cout << "--------" << std::endl;
        for(auto it = copy.begin() ; it != pos_current_in_copy ;  it++ ){
            //std::cout <<"test "<<  (*it) << std::endl;
            qtest2.push((*it));
        }
        ////////////////////////////////////////////////////////////////////////////////////////
        // desarrollando la cola
        auto current = qtest2.front(); qtest2.pop();
        //std::cout << "Imprimiendo la cola caso 3" << std::endl;
        while(!qtest2.empty()){
            //std::cout << qtest2.front() << std::endl; qtest2.pop();
            sumatoriaTotalPistas += labs( current - qtest2.front() );
            current = qtest2.front() ; qtest2.pop();
        }
        return sumatoriaTotalPistas / (copy.size() - 1) ;
        ////////////////////////////////////////////////////////////////////////////////////////


    }



    // std::cout << "Printed apartir del primer elemento en pistas" << '\n';
    // for( ;pos_current_in_copy != copy.end(); pos_current_in_copy--){
    //     std::cout << (*pos_current_in_copy) << std::endl;
    // }

}
float HardDisk::SCAN(){
    int sumatoriaTotalSCAN;
    auto currentElement = (*this->pistas.begin());
    std::queue<unsigned short int> myqueue; myqueue.push(currentElement);
    std::stack<unsigned short int> mystack;
    auto et = this->pistas.begin();++et;
    for( ; et != this->pistas.end() ; et++){
        if( (*et) > currentElement  ){
            myqueue.push((*et));
            currentElement = (*et);
        }
        else{
            mystack.push((*et));
            //currentElement = (*et);
        }
    }
     // analizando primero la cola
     auto currentE = myqueue.front(); myqueue.pop();
     while( !myqueue.empty() ){
         sumatoriaTotalSCAN += labs( currentE-myqueue.front() );
         currentE = myqueue.front(); myqueue.pop();
     }
     //para que llegue al extremo superior del disco
     sumatoriaTotalSCAN += labs( currentE - LIMITEPISTAS );

     //analizando luego  la pila
     auto currentEPila = mystack.top() ; mystack.pop();
     sumatoriaTotalSCAN  += labs(LIMITEPISTAS - currentEPila);
     while(!mystack.empty()){
         sumatoriaTotalSCAN += labs(currentEPila - mystack.top());
         currentEPila = mystack.top(); mystack.pop();
     }

     //para llegar al extremo inferior del disco
     sumatoriaTotalSCAN += labs(currentEPila - 0);
     return sumatoriaTotalSCAN / (pistas.size() - 1);
}
float HardDisk::CSCAN(){
    int sumatoriaTotalCSCAN = 0;
    auto currentElement = (*this->pistas.begin());
    std::queue<unsigned short int> myqueue1;
    std::queue<unsigned short int> myqueue2;
    auto et = this->pistas.begin();++et;
    for( ; et != this->pistas.end() ; et++){
        if( (*et) > currentElement  ){
            myqueue1.push((*et));
            currentElement = (*et);
        }
        else{
            myqueue2.push((*et));
            //currentElement = (*et);
        }
    }
    //analizando la primera cola
    auto current1 = myqueue1.front(); myqueue1.pop();
    while( !myqueue1.empty() ){
        sumatoriaTotalCSCAN += labs( current1-myqueue1.front() );
        current1 = myqueue1.front(); myqueue1.pop();
    }
    //para que llegue al extremo superior del disco
    sumatoriaTotalCSCAN += labs( current1 - LIMITEPISTAS );


    //analizando la segunda cola;
    //luego llega a CERO el cabezal
    sumatoriaTotalCSCAN += labs(LIMITEPISTAS - 0);
    auto current2 = myqueue2.front() ; myqueue2.pop();
    sumatoriaTotalCSCAN += labs(0 - current2);
    while(!myqueue2.empty()){
        sumatoriaTotalCSCAN += labs(current2 - myqueue2.front());
        current2 = myqueue2.front(); myqueue2.pop();
    }
    return sumatoriaTotalCSCAN / (pistas.size() - 1);
}



//
