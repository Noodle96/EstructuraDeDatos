
//begin matrizEsparsa.tpp

/*
    FUNCIONES DE LA MATRIS ESPARSA:
        bool find_fil(int f, int c, NodoEs<T> ** & p);
        bool find_col(int f, int c, NodoEs<T> ** & p);
        void Add(int f, int c, T D);
        void Print(ostream & os);

*/


//FIND FILA
template<typename T>
bool Matrix<T>::find_fil(int f, int c, NodoEs<T> ** & p){
   p = &m_columnas[c];
   while(*p){
       if((*p)->m_Fil == f) return true;
       if((*p)->m_Fil > f) return false;
       p = &((*p)->m_pSigFil);
   }
   return false;
}


//FIND COLUMNA
template<typename T>
bool Matrix<T>::find_col(int f, int c, NodoEs<T> ** & p){
   p = &m_filas[f];
   while(*p){
       if((*p)->m_Col == c) return true;
       if((*p)->m_Col > c) return false;
       p = &((*p)->m_pSigCol);
   }
   return false;
}


//ADD
template<typename T>
void Matrix<T>::Add(int f, int c, T D){
       NodoEs<T> ** p;
       NodoEs<T> ** q;
       bool ff = find_fil(f,c,q);
       bool cc = find_col(f,c,p);
       if(!cc && !ff){
           NodoEs<T> * pNuevo = new NodoEs<T>(f,c,D);
           pNuevo->m_pSigCol = *q;
           pNuevo->m_pSigFil = *p;
           *q = *p = pNuevo;
       }
}

//PRINT
template<typename T>
void Matrix<T>::Print(ostream & os){
      NodoEs<T> ** p;
      for(int i=0;i<fil;i++){
        //os<<endl;
        for(int j=0;j<col;j++)
           if (find_col(i,j,p))
               os<<(*p)->m_Dato<<" ";
           else
               os<<"0 ";
       }
       os << endl;
}







//end matrizEsparsa.tpp
