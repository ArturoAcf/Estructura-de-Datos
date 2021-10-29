// Realizado por Arturo Alonso Carbonero - DNI -> 75936665-A
// Grupo -> 2ºC - C1

/**
  *@file Fichero con la implementación de los métodos del TDA Diccionario
  */

#include "../include/Diccionario.h"
#include <iostream>
#include <list>
#include <stdlib.h>
#include <cstring>

using namespace std;

// Creación de lista de palabras que empiezan por una letra
template <class T, class U>
list<string> Diccionario<T,U>::palabrasPorInicial(char letra){
  typename list<data<T,U>>::iterator it;
  list <string> palabras;
  string palabra;
  bool empiezaPor=false;

  for(it=this.begin(); it!=this.end() && !empiezaPor; ++it){
      palabra=(*it).clave;
    if(palabra.front()==letra){
      empiezaPor=true;
      palabras.push_back(palabra);
    }
  }

  return palabras;
}

// Eliminar toda la información de una palabra
template <class T, class U>
void Diccionario<T,U>::eliminarPalabra(const T &p){
  typename list<data<T,U> >::iterator it;

  if(!Esta_Clave(p,it)){
    cout<<"No existe la clave"<<p<<endl;
  }else{
    datos.erase(it);
  }
}

// Actualizar una clave por otra dada
template <class T, class U>
void Diccionario<T,U>::actualizarClave(const T &p){
  typename list<data<T,U>>::iterator it;

  if(!Esta_Clave(p,it)){
    cout<<"No existe la clave"<<p<<endl;
  }else{
    (*it).clave=p;
  }
}

// Diccionario con las palabras que empiezan por una letra dada
template <class T, class U>
Diccionario<T,U> Diccionario<T,U>::diccionarioLetra(char letra){
  Diccionario<T,U> nuevoDiccionario;
  string palabra;

  for(it=this.begin(); it!=this.end(); ++it){
      palabra=(*it).clave;
    if(palabra.front()==letra){
      nuevoDiccionario.insertar(palabra, (*it).info_asoci);
    }
  }

  return nuevoDiccionario;
}
