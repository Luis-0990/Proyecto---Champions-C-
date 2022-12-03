using namespace std;
struct equipo{
   int num_Nodo;
   int goles;
   string nombre;
   string jugadores;
   string en_juego;
   equipo *enlace;
   equipo *izq;
   equipo *der;
};
struct mejor{
   int goles;
   string nombre;
   mejor *link;
   mejor *link2;
};
equipo *crear_Nodo2(int n);
equipo *crear_Nodo(int n);//Crea Nodo
bool prof3(equipo *arbol);
void Mostrar_Arbol(equipo *arbol,int cont);
equipo *BusquedaBinaria(equipo *arbol,int num);
//Lectura de archivo
void escribir(int G,string N,char letra,int x,int y);
void archivo_a_Lista(equipo *nuevo_nodo);
//Doblemente enlazado
void Doblemente_Enlazada(mejor *crea2);
mejor *Hacer_Caja(string N,int G);
mejor *Pop();
/////////////////
equipo *crea=NULL;
equipo *aux=NULL;
mejor *crea2=NULL;
mejor *aux2=NULL;
//Funciones
equipo *BusquedaBinaria(equipo *arbol,int num){
    equipo *qp;
     if(arbol==NULL){
        return NULL;
    }
    else if(num==arbol->num_Nodo){
        qp=arbol;
        return qp;
    }
    if(num < arbol->num_Nodo){
        return BusquedaBinaria(arbol->izq,num);
    }
    if(num > arbol->num_Nodo){
        return BusquedaBinaria(arbol->der,num);
    }
}
void ganador_Final(equipo *arbol,int Profundida1[],int cont){
            int conta=0;
            string N;
            int G;
            equipo *r=NULL,*A=NULL,*B=NULL;
                r=BusquedaBinaria(arbol,16);//Busca los nodos que seran reinscritos donde se pondra al ganador
                A=BusquedaBinaria(arbol,Profundida1[conta]);//Busca el nodo(equipo A) que jugara
                B=BusquedaBinaria(arbol,Profundida1[conta+1]);//Busca el nodo(equipo B) con el que jugara
               cout<<"      .FINAL. "<<endl;
                cout<<"      ="<<A->nombre<<"="<<endl;//Insertamos datos
                cout<<"  Goles metidos:"<<endl;
                cout<<"       ";
                cin>>A->goles;
                N=A->nombre;
                G=A->goles;
                escribir(G,N,0,0,4);
                cout<<" ......................"<<endl;
                cout<<"      ="<<B->nombre<<"="<<endl;
                cout<<"  Goles metidos:"<<endl;
                cout<<"      ";
                cin>>B->goles;
                N=B->nombre;
                G=B->goles;
                escribir(G,N,0,0,0);
                cout<<" ------------------------------------"<<endl;
                if(A->goles > B->goles){//Compara los goles para saber al ganador
                    r->nombre=A->nombre;
                    r->goles=A->goles;
                    escribir(G,r->nombre,0,2,0);
                }else{
                    r->nombre=B->nombre;
                    r->goles=B->goles;
                    escribir(G,r->nombre,0,2,0);
                }
                cout<<"\n\t\t-Champions League-\n\n";
                cout<<"     \t\t=Torneo terminado=\n"<<endl;
                Mostrar_Arbol(arbol,cont);
                cout<<endl;
}
void ganadores_2Categoria(equipo *arbol,int Profundida1[],int Profundida2[],int cont){
            int conta=0,y=3;
            string N;
            int G;
            equipo *r=NULL,*A=NULL,*B=NULL;
            char arreglo2[2]={'A','B'};
            for(int j=0;j<2;j++){
                r=BusquedaBinaria(arbol,Profundida1[j]);//Busca los nodos que seran reinscritos donde se pondra al ganador
                A=BusquedaBinaria(arbol,Profundida2[conta]);//Busca el nodo(equipo ALFA) que jugara
                B=BusquedaBinaria(arbol,Profundida2[conta+1]);//Busca el nodo(equipo BETA) con el que jugara
                cout<<"     Grupo "<<arreglo2[j]<<endl;
                cout<<"      ="<<A->nombre<<"="<<endl;//Insertamos datos
                cout<<"  Goles metidos:"<<endl;
                cout<<"       ";
                cin>>A->goles;
                N=A->nombre;
                G=A->goles;
                escribir(G,N,arreglo2[j],1,y);
                 y=0;
                cout<<" ......................"<<endl;
                cout<<"      ="<<B->nombre<<"="<<endl;
                cout<<"  Goles metidos:"<<endl;
                cout<<"      ";
                cin>>B->goles;
                N=B->nombre;
                G=B->goles;
                escribir(G,N,arreglo2[j],0,y);
                cout<<" ------------------------------------"<<endl;
                conta+=2;//Contador para ir al otro grupo
                if(A->goles > B->goles){//Compara los goles para saber al ganador
                    r->nombre=A->nombre;
                    r->goles=A->goles;
                }else{
                    r->nombre=B->nombre;
                    r->goles=B->goles;
                }
               }
                cout<<"\n\t\t-Champions League-\n\n";
                 cout<<"    \t\t\t=FINAL=\n"<<endl;
                Mostrar_Arbol(arbol,cont);
                cout<<"\n/////////////////////////////////////////////// "<<endl;
}
void ganadores_3Categoria(equipo *arbol,int Profundida2[],int Profundida3[],int cont){
            int conta=0,y=2;
            string N;
            int G;
            char arreglo2[4]={'A','B','C','D'};
            equipo *r=NULL,*A=NULL,*B=NULL;
            for(int j=0;j<4;j++){
                r=BusquedaBinaria(arbol,Profundida2[j]);//Busca los nodos que seran reinscritos donde se pondra al ganador
                A=BusquedaBinaria(arbol,Profundida3[conta]);//Busca el nodo(equipo ALFA) que jugara
                B=BusquedaBinaria(arbol,Profundida3[conta+1]);//Busca el nodo(equipo BETA) con el que jugara
                cout<<"     Grupo "<<arreglo2[j]<<endl;
                cout<<"      ="<<A->nombre<<"="<<endl;//Insertamos datos
                cout<<"  Goles metidos:"<<endl;
                cout<<"       ";
                cin>>A->goles;
                N=A->nombre;
                G=A->goles;
                escribir(G,N,arreglo2[j],1,y);
                y=0;
                cout<<" ......................"<<endl;
                cout<<"      ="<<B->nombre<<"="<<endl;
                cout<<"  Goles metidos:"<<endl;
                cout<<"      ";
                cin>>B->goles;
                N=B->nombre;
                G=B->goles;
                escribir(G,N,arreglo2[j],0,y);
                y=0;
                cout<<" ------------------------------------"<<endl;
                conta+=2;//Contador para ir al otro grupo
                if(A->goles > B->goles){//Compara los goles para saber al ganador
                    r->nombre=A->nombre;
                    r->goles=A->goles;
                }else{
                    r->nombre=B->nombre;
                    r->goles=B->goles;
                }
               }
                cout<<"\n\t\t-Champions League-\n\n";
                cout<<" \t\t-SEMIFINALES-\n"<<endl;
                Mostrar_Arbol(arbol,cont);
                cout<<"\n/////////////////////////////////////////////// "<<endl;
}
void ganadores_4Categoria(equipo *arbol,int Profundida3[],int Profundida4[],int cont){
            int conta=0,y=1;
            string N;//Nombre del equipo
            int G; //Cantidad de goles
            char arreglo2[8]={'A','B','C','D','E','F','G','H'};
            equipo *r=NULL,*A=NULL,*B=NULL;
            for(int j=0;j<8;j++){
                r=BusquedaBinaria(arbol,Profundida3[j]);//Busca los nodos que seran reinscritos donde se pondra al ganador
                A=BusquedaBinaria(arbol,Profundida4[conta]);//Busca el nodo(equipo ALFA) que jugara
                B=BusquedaBinaria(arbol,Profundida4[conta+1]);//Busca el nodo(equipo BETA) con el que jugara
                cout<<"     Grupo "<<arreglo2[j]<<endl;
                cout<<"      ="<<A->nombre<<"="<<endl;//Insertamos datos
                cout<<"  Goles metidos:"<<endl;
                cout<<"       ";
                cin>>A->goles;
                N=A->nombre;//Se guarda nombre y numero en variables para mandarlos a la funcion
                G=A->goles;
                escribir(G,N,arreglo2[j],1,y);
                y=0;
                cout<<" ......................"<<endl;
                cout<<"      ="<<B->nombre<<"="<<endl;
                cout<<"  Goles metidos:"<<endl;
                cout<<"      ";
                cin>>B->goles;
                N=B->nombre;
                G=B->goles;
                escribir(G,N,arreglo2[j],0,y);
                cout<<" ------------------------------------"<<endl;
                conta+=2;//Contador para ir al otro grupo
                if(A->goles > B->goles){//Compara los goles para saber al ganador
                    r->nombre=A->nombre;
                    r->goles=A->goles;
                }else{
                    r->nombre=B->nombre;
                    r->goles=B->goles;
                }
               }
                cout<<"\n\t\t-Champions League-\n\n";
                cout<<" \t\t2dos Partidos\n"<<endl;
                Mostrar_Arbol(arbol,cont);
                cout<<"\n/////////////////////////////////////////////// "<<endl;
}
void Mostrar_Arbol(equipo *arbol,int cont){
      char arreglo2[8]={'A','B','C','D','E','F','G','H'};
      if(arbol==NULL){
        return;
      }else{
           Mostrar_Arbol(arbol->der,cont+1);//Imprime primero todo el lado derecho
      for(int i=0;i<cont;i++){
         cout<<"          ";
      }
        if(prof3(arbol)){
        cout<<"|"<<arbol->goles<<":"<<arbol->nombre<<"| \t\t"<<arreglo2[0]<<endl;
        Mostrar_Arbol(arbol->izq,cont+1);
       }else{
           cout<<"|"<<arbol->goles<<":"<<arbol->nombre<<"|"<<endl;
           Mostrar_Arbol(arbol->izq,cont+1);
       }
      }
}
//Creacion de arbol
void insertarNodo(equipo *&arbol,int n){
    if(arbol==NULL){//Si el arbol esta vacio
          equipo *nuevo_nodo=crear_Nodo(n);
            arbol=nuevo_nodo;
    }else{//Si el arbolo tiene un nodo o mas
        int valorRaiz=arbol->num_Nodo;//obtener valor de la raiz
        if(n<valorRaiz){//si el elemento es menor a la raiz, insertamos izq
            insertarNodo(arbol->izq,n);
        }else{//si el elemento es mayor a la raiz, insertamos der
            insertarNodo(arbol->der,n);
        }
    }
};
equipo *crear_Nodo(int n){
    equipo *nuevo_nodo=new equipo();//Crea nuevo Nodo
    if(n==1||n==3||n==5||n==7||n==9||n==11||n==13||n==15||n==17||n==19||n==21||n==23||n==25||n==27||n==29||n==31){//Guardar el los ultimos nodos de
    nuevo_nodo->num_Nodo=n;                                                                                        //la ultima profundida del arbol
    nuevo_nodo->nombre=crea->nombre;//Lista simple a arbol
    crea=crea->enlace;
    }else{//No guarda nombre en los demas nodos
    nuevo_nodo->num_Nodo=n;
    nuevo_nodo->nombre="xxxxx";
    }
    nuevo_nodo->goles=0;//Con o sin nombre se llenara informacion
    nuevo_nodo->izq=NULL;
    nuevo_nodo->der=NULL;
    return nuevo_nodo;
};
void Imprime_lista(){
    int i=1;
    while(crea!=NULL){
        cout<<" "<<i++<<"."<<crea->nombre<<endl;;
        cout<<"\tJugadores: "<< crea->jugadores<<endl;
        cout<<"\tEn juego: "<< crea->en_juego<<endl;
        crea=crea->enlace;
    }
        crea=aux;
}
void liberaMemoria(){
    while(crea!=NULL){
        crea=crea->enlace;
        delete crea;
        aux=crea;
        }
    cout<<"Liberando memoria..."<<endl;
}
bool prof3(equipo *arbol){
    return (arbol->num_Nodo==2||arbol->num_Nodo==6||arbol->num_Nodo==10||arbol->num_Nodo==14||arbol->num_Nodo==18||arbol->num_Nodo==22||arbol->num_Nodo==26||arbol->num_Nodo==30);
}
void sustitucion(){
    int id;
        cout<<" Numero de equipo que quieres sustituir: ";
        cin>>id;
        if(id<=16){//total de nodos en la lista simple
        while(crea!=NULL){
        if(crea->num_Nodo==id){//Busca
        cout<<" Equipo actual: "<<crea->nombre<<endl;//Sustituye
        cout<<" Nombre del nuevo equipo(sin espacios): ";
        cin>>crea->nombre;
        cout<<" Numero de jugadores: ";
        cin>>crea->jugadores;
        cout<<" En juego 11\n"<<endl;
        system("pause");
        }
        crea=crea->enlace;
        }
        }else{
        cout<<" Equipo no encontrado "<<endl;
        }
        crea=aux;//Recoremos
        Imprime_lista();//Salida
}
void texto1(){
     cout<<endl;
     cout<<"  |-----------------------------------|"<<endl;
     cout<<"  |        ° Champions League °       |"<<endl;
     cout<<"  |-----------------------------------|"<<endl;
     cout<<"  | 1.Ver lista de participantes      |"<<endl;
     cout<<"  | 2.Iniciar Torneo                  |"<<endl;
     cout<<"  | 3.Ver Registros                   |"<<endl;
     cout<<"  | 4.Esqueleto del \240rbol             |"<<endl;
     cout<<"  | 5.El equipo que meti\242 m\240s         |"<<endl;
     cout<<"  |   goles de latemporada            |"<<endl;
     cout<<"  | 6.SALIR                           |"<<endl;
     cout<<"  |-----------------------------------|"<<endl;
     cout<<"  Opci\242n a elegir: ";
}
void texto2(){
     cout<<"  |-----------------------------------|"<<endl;
     cout<<"  |        ° Champions League °       |"<<endl;
     cout<<"  |-----------------------------------|"<<endl;
     cout<<"  | 1.Ver lista de participantes      |"<<endl;
     cout<<"  | 2.Sustituir un equipo             |"<<endl;
     cout<<"  | 3.SALIR                           |"<<endl;
     cout<<"  |-----------------------------------|"<<endl;
     cout<<"  Opci\242n a elegir: ";
}
/////////////Segundo Árbol//////////
void InsertarA(equipo *&arbol2,int n){
    if(arbol2==NULL){//Si el arbol esta vacio
          equipo *nuevo_nodo=crear_Nodo2(n);
            arbol2=nuevo_nodo;
    }else{//Si el arbolo tiene un nodo o mas
        int valorRaiz=arbol2->num_Nodo;//obtener valor de la raiz
        if(n<valorRaiz){//si el elemento es menor a la raiz, insertamos izq
            InsertarA(arbol2->izq,n);
        }else{//si el elemento es mayor a la raiz, insertamos der
            InsertarA(arbol2->der,n);
        }
    }
};
equipo *crear_Nodo2(int n){
    equipo *nuevo_nodo=new equipo();
    nuevo_nodo->num_Nodo=n;
    nuevo_nodo->izq=NULL;
    nuevo_nodo->der=NULL;
    return nuevo_nodo;
};
void Mostrar_Arbol2(equipo *arbol2,int cont){
      if(arbol2==NULL){
        return;
      }else{
      Mostrar_Arbol2(arbol2->der,cont+1);
      for(int i=0;i<cont;i++){
         cout<<"     ";
      }
     // cout<<"..."<<endl;
      cout<<"|"<<arbol2->num_Nodo<<"|"<<endl;
      delete arbol2;
      //cout<<"..."<<endl;
       Mostrar_Arbol2(arbol2->izq,cont+1);
      }
}
void Liberar_EntreOrden(equipo *arbol){
    if(arbol==NULL){
        return;
    }
      Liberar_EntreOrden(arbol->izq);
        delete arbol;
      Liberar_EntreOrden(arbol->der);
}
void Imprime_EntreOrden(equipo *arbol){
    if(arbol==NULL){
        return;
    }
      Imprime_EntreOrden(arbol->izq);
      cout<<"-"<<arbol->num_Nodo;
      Imprime_EntreOrden(arbol->der);
}
//////////Liata Doblemente enlazado//////////
void mejores_equipos(equipo *arbol,int N_nodos[]){
    string N;
    int mayor=0,G;
    equipo *A=NULL;
     //Entrada
          for(int i=0;i<31;i++){
            A=BusquedaBinaria(arbol,N_nodos[i]);
            N=A->nombre;
            G=A->goles;
            Doblemente_Enlazada(Hacer_Caja(N,G));
         }
         cout<<endl;
         //Buscando al numero más grande
         while(NULL!=(crea2=Pop())){
            if(crea2->goles>mayor){
                mayor=crea2->goles;
                N=crea2->nombre;
            }
            delete crea2;
         }
           //Salida
         cout<<"---------------------------------------------------"<<endl;
         cout<<" El equipo que meti\242  m\240s goles fue: "<<N<<endl;
         cout<<" Con un total de "<<mayor<<" goles"<<endl;
         cout<<"---------------------------------------------------"<<endl;
          cout<<" Eliminado memoria..."<<endl;
}
mejor *Hacer_Caja(string N,int G){
    crea2=new mejor;
    crea2->nombre=N;
    crea2->goles=G;
    return crea2;
}
void Doblemente_Enlazada(mejor *crea2){
    //Lista doblemente enlazada
    crea2->link=aux2;
    crea2->link2=NULL;
    if(aux2!=NULL){
        aux2->link2=crea2;
    }
    aux2=crea2;
}
mejor *Pop(){
    mejor *qp;
    qp=aux2;
    //Validacion
    if(aux2!=NULL){
        aux2=aux2->link;
    }
    return qp;
}
//////////////Archivos//////////////
void archivo_a_Lista(){
    int ID=16;
    equipo nuevo_nodo;
    ifstream archivo;
    archivo.open("Champions.txt");
    if(!archivo)
     cout << "Error abriendo el fichero" << endl;
     else  {
     while (!(archivo.eof() )){
              crea=new equipo;
              getline(archivo,crea->nombre);
              getline(archivo,crea->jugadores);
              getline(archivo,crea->en_juego);
              crea->num_Nodo=ID--;
             //Lista Simple
              crea->enlace=aux;
              aux=crea;
     }
     archivo.close();
     }
}
void escaneoArchivo(){ //Lee archivos  ya sea por renglon o por letra
     ifstream archivo;
     string texto;
     archivo.open("Champions League.txt",ios::in);//Abrimos archivo modo lectura
     if(archivo.fail()){
        cout<<"No se pudo abrir archivo";
        exit(1);
    }
    while(!archivo.eof()){//mientras no sea el final del archivo
        if(texto != "'\n'"){
            cout<<"\n ";
        }
        getline(archivo,texto);
        cout<<texto;
    }
    archivo.close();
}
void escribir(int G,string N,char letra,int x,int y){ //Crea archivo y escribir
    ofstream archivo;
    string  frase,frase2;
    //ruta relativa
    archivo.open("Champions League.txt",ios::app);
    //ruta absoluta
    //f.open("C:\\Users\\Dian\\Desktop\\Prueba1.txt",ios::app);
    if(!archivo){
      cout<<" Error abriendo el fichero"<<endl;
    }
    //En pantalla
    if(x!=2){
      cout<<" Cambios de jugadores: ";
      cin.ignore();//guardar
      getline(cin,frase);
      cout<<" Expulsados: ";
      getline(cin,frase2);
     }
     //Como lo va guardar en el archivo
      if(y==4||y==3||y==2){
          archivo<<"\n\t\t------------------------------------\n";
     }
      if(y==1){
         archivo<<"    1eros Partidos "<<endl;
     }else if(y==2){
         archivo<<"    2dos Partidos "<<endl;
     }else if(y==3){
         archivo<<"    -SEMIFINALES- "<<endl;
     }else if(y==4){
         archivo<<"    \t=FINAL="<<endl;
     }
     if(x==1){
      archivo<<"   \tGrupo "<<letra;
     }else if(x==2){
      archivo<<"\n\t\t.GANADOR."<<endl;
      archivo<<"   \t\t="<<N<<"="<<endl;
      return;
     }
      archivo<<"\n\t\tNombre: "<<N;
      archivo<<"\n\t\tGoles: "<<G;
      archivo<<"\n\t\tCambios de jugadores: ";
      archivo<<frase;
      archivo<<"\n\t\tExpulsados: ";
      archivo<<frase2;
      archivo<<"\n\t\t......................\n";
      archivo.close();
}

