

template<typename V, typename E>
int Graph<V,E>::GetMin(vector<V> &D ,vector<bool> &S){
    int lend = D.size();
    int min = INT_MAX;
    int g;
    int e =  0;
    for(; e < lend  ; e++){
        if(S[e] == 0){
            if( D[e] < min ){
                min = D[e]; g = e;
            }
        }
    }
    return g;
}


template<typename V, typename E>
void Graph<V,E>::copy(Matriz &M ,V &v, vector<E>& d){

    // int idx = getIndexV(v);
    // cout << "dentro de dijstra" << "idx: " << idx << endl;

    for(int e = 0 ; e < M.size() ; e++){
        d[e] = M[v][e];
    }
}

template<typename V , typename E>
vector<E> Graph<V,E>::dijkstra(Matriz M, V Origen){
    auto lenFila(M.size());
    /*Se crea un vector para los vertices seleccionados*/
    vector<bool> S( lenFila,0 );

    /*y tambien un vector para las distancias que corresponde del vertice origen a los demas vertices*/
    vector<E> D( lenFila );


    S[0] = 1; //nuestro primer vertice inicial sera el origen y como ya lo tomamos , ya no se tocará adelante.
    int o = getIndexV(Origen);

    copy(M,o,D);
    // for(int e = 0 ; e < D.size(); e++){
    //     cout << D[e] << " ";
    // }
    cout << endl;
    int N = 1;
    int se;
    while( N <= lenFila ){
        se = GetMin(D,S);
        // cout << "pas copy y se: " << se << endl;;
        S[se] = 1; N++;

        for(int x = 0 ; x < lenFila; x++){
            if(S[x] == 0)
                D[x] = min(D[x],D[se] + M[se][x]);
        }

    }
    return D;
}
