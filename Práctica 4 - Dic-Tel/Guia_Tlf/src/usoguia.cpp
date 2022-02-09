// Realizado por Arturo Alonso Carbonero 
// Grupo -> 2ºC - C1
//
// NOTA -> No he incluido nada del usoguia.cpp proporcionado salvo el principio, por lo que no añade ni elimina contactos.
//         Ya disponíamos de esa utilidad por lo que no sería un añadido propio.
// NOTA -> Los ficheros de entrada con las guías en formato txt están en la carpeta bin por agilizar.

/**
  *@file Fichero que contiene la función princiapl "main" del programa
  *
  *@note Ejecución -> ./usoguia nombrefich.txt, siendo usoguia el ejecutable en ../bin
  */

#include "Guia_Tlf.cpp"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc , char * argv[]){
  if (argc!=2){
      cout<<"Introduzca el nombre del fichero con la guia"<<endl;
      return 0;
  }
  ifstream f(argv[1]);
  if (!f){
      cout<<"Fichero no encontrado, tal vez no exista o se haya equivocado introduciendo "<<argv[1]<<endl;
      return 0;
  }

 // Variables para los métodos
 Guia_Tlf g;
 int i;
 char inicial;
 string numero, num1, num2;

 f>>g;
 cout<<"\nListado de la guía mediante el operador '<<': "<<endl<<g<<endl;
 cin.clear();

 cout<<"_______________________________________________"<<endl;
 cout<<"\nSeleccione la operación a realizar sobre la guia:"<<endl;
 cout<<"\t1. Crear una guía con nombres por inicial."<<endl;
 cout<<"\t2. Búsqueda de nombre por número de teléfono."<<endl;
 cout<<"\t3. Crear una guía con los móviles de España."<<endl;
 cout<<"\t4. Sustituir un número de teléfono por otro nuevo."<<endl;

 cin>>i;

 while(i!=-1){
   if(i==1){
     cout<<"Introduzca una inicial"<<endl;
     cin>>inicial;

     Guia_Tlf guia_inic=g.buscarPorInicial(inicial);

     cout<<"Lista de los nombres que empiezan por "<<inicial<<": "<<endl;
     cout<<guia_inic<<endl;

     cout<<"\nPulse 1 para continuar"<<endl<<"Pulse -1 para terminar "<<endl;
     cin>>i;
   }else if(i==2){
     cout<<"Introduzca un numero de teléfono"<<endl;
     cin>>numero;
     string resultado=g.numeroDeNombre(numero);
     bool existe_num=false;

     while(!existe_num){
       if(resultado!="-"){
         cout<<"Nombre asociado a ese número: "<<resultado<<endl;
         existe_num=true;
       }else{
         cout<<"El número buscado no existe, introduzca otro número"<<endl;
         cin>>numero;
         resultado=g.numeroDeNombre(numero);
       }
     };

     cout<<"\nPulse 2 para continuar"<<endl<<"Pulse -1 para terminar "<<endl;
     cin>>i;
   }else if(i==3){
     Guia_Tlf guia_esp=g.movilesEsp();

     if(guia_esp.begin()!=guia_esp.end()){
       cout<<"Guía con los números de los móviles de España contenidos en la guía original: "<<endl;
       cout<<guia_esp<<endl;
     }else{
       cout<<"No existen números de teléfono móvil de origen español en la guía original"<<endl;
     }

     cout<<"Pulse 3 para reintentar"<<endl<<"Pulse -1 para terminar "<<endl;
     cin>>i;
   }else if(i==4){
     bool existe=false;

     while(existe==false){
       cout<<"Introduzca el número a actualizar: ";
       cin>>num1;

       if(g.compruebaNum(num1)){
         existe=true;
       }else{
         cout<<"Número no encontrado"<<endl;
       }
     }

     cout<<"\nIntroduzca el nuevo número: ";
     cin>>num2;

     g.sustituirNumero(num1, num2);
     cout<<"\nLista actualizada: "<<endl<<g<<endl;

     cout<<"\nPulse 4 para continuar"<<endl<<"Pulse -1 para terminar "<<endl;
     cin>>i;
   }else{
     cout<<"ERROR -> Operación "<<i<<" no encontrada, por favor seleccione de nuevo la operación que desea realizar: ";
     cin>>i;
   }
 } // While

 cout<<"\n_______________________________________________"<<endl;
 cout<<"\nListado de la guia con iteradores:"<<endl;
 Guia_Tlf::iterator it;
 for(it=g.begin(); it!=g.end(); ++it){
     cout<<*it;
 }
} // Main
