#include <iostream>
#include<fstream>
#include "Funciones_Champion.h"
using namespace std;
//Funciones
void Mostrar_Arbol(equipo *arbol,int cont);
void insertarNodo(equipo *&arbol,int n);
void Liberar_EntreOrden(equipo *arbol);
void Imprime_EntreOrden(equipo *arbol);
equipo *BusquedaBinaria(equipo *arbol,int num);
void liberaMemoria();
void Imprime_lista();
void sustitucion();
//Case 2
void ganadores_4Categoria(equipo *arbol,int Profundida3[],int Profundida4[],int cont);
void ganadores_3Categoria(equipo *arbol,int Profundida2[],int Profundida3[],int cont);
void ganadores_2Categoria(equipo *arbol,int Profundida1[],int Profundida2[],int cont);
void ganador_Final(equipo *arbol,int Profundida1[],int cont);
//Case 4 - Segundo Árbol
void InsertarA(equipo *&arbol2,int n);
void Mostrar_Arbol2(equipo *arbol2,int cont);
//Case 5
void mejores_equipos(equipo *arbol,int N_nodos[]);
//Archivos
void escaneo_de_archivo();
void escaneoArchivo();
void archivo_a_Lista();
//Textos
void texto1();
void texto2();

int main(){
    int N_nodos[31]={16,8,4,2,1,3,6,5,7,12,10,9,11,14,13,15,24,20,18,17,19,22,21,23,28,26,25,27,30,29,31};//Todos los nodos=Linea recta
    int Profundida4[16]={1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31};//Profundida 4 del arbol donde se encuentran los equipos
    int Profundida3[8]={2,6,10,14,18,22,26,30};//Profundida 3 del arbol para los ganadores: 4ta categoria
    int Profundida2[4]={4,12,20,28};//Profundida 2 del arbol para los ganadores: 3ra categoria
    int Profundida1[2]={8,24};//Profundida 1 arbol para los ganadores: 2da categoria
    int op,cont=0,opc,x=0;
    equipo *arbol=NULL;
    equipo *arbol2=NULL;
    do{
     texto1();
     cin>>op;
     cout<<endl;
    switch(op){
        case 1:
            do{
             texto2();
             cin>>opc;
             switch(opc){
                case 1:
                    if(x!=0){
                      Imprime_lista();
                    }else{
                      archivo_a_Lista();
                      Imprime_lista();
                      x=1;
                    }
                break;
                case 2:
                   sustitucion();
                break;
                case 3:
                    opc=-2;
                break;
                default:
                   cout<<" Opci\242n no valida"<<endl;
                break;
             }
            }while(opc!=-2);
             cout<<" Regresando..."<<endl;
        break;
        case 2:
              for(int i=0;i<31;i++){
             insertarNodo(arbol,N_nodos[i]);
             }
             cout<<"\n\t\tChampions League:\n\n";
             cout<<" \t\t1eros Partidos\n"<<endl;
             Mostrar_Arbol(arbol,cont);
             cout<<endl;
             system("pause");
             cout<<"\nEn este torneo no puede ver empates "<<endl;
             cout<<"ingrese goles distintos\n"<<endl;
             ganadores_4Categoria(arbol,Profundida3,Profundida4,cont);
             ganadores_3Categoria(arbol,Profundida2,Profundida3,cont);
             ganadores_2Categoria(arbol,Profundida1,Profundida2,cont);
             ganador_Final(arbol,Profundida1,cont);
        break;
        case 3:
            escaneoArchivo();
        break;
        case 4:
             cont=0;
             cout<<"\n Esqueleto del \240rbol "<<endl;
            for(int z=0;z<31;z++){
            InsertarA(arbol2,N_nodos[z]);
            }
             Mostrar_Arbol2(arbol2,cont);
             cout<<endl;
             cout<<"\n Ordenamiento ENTRE ORDEN\n"<<endl;
              Imprime_EntreOrden(arbol2);
              Liberar_EntreOrden(arbol2);
             cout<<endl<<endl;
        break;
        case 5:
            //Lista Doblemente enlazado
             mejores_equipos(arbol,N_nodos);
            break;
        case 6:
            //Liberar Memoria
             Liberar_EntreOrden(arbol);
             liberaMemoria();
             op=-1;
        break;
        default:
            cout<<"Opci\242n no valida"<<endl;
            break;
     }
    }while(op!=-1);
    cout<<"SALIENDO..."<<endl;
    return 0;
}





