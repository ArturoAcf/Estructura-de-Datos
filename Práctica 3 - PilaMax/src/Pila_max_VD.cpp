// Realizado por: Arturo Alonso Carbonero y José Luis Molina Aguilar
// Grupo: 2ºC - C1
// Práctica 2. TDA lineales - TDA Pila_max_VD

/**
  *@file Pila_max_VD.cpp
  *@brief Fichero con las operaciones del TDA Pila con máximo basado en la clase vector de la STL
  *
  *Gestiona una secuencia de elementos con facilidades para la inserción y
  *borrado de elementos en un extremo
  */

  #include <cassert>
  #include <iostream>
  #include "../include/Pila_max_VD.h"
  #include "../include/elemento.h"

  using namespace std;

  template<class T>
  Pila_max_VD<T>::Pila_max_VD(){
      vector<elemento> datos;
  }

  template<class T>
  Pila_max_VD<T>::Pila_max_VD(const Pila_max_VD& orig){
      this->datos = orig.datos;
  }

  template<class T>
  Pila_max_VD<T>::~Pila_max_VD(){
      datos.~vector();
  }

  template<class T>
  Pila_max_VD<T> &Pila_max_VD<T>::operator=(const Pila_max_VD& otra){
      this->datos = otra.datos;
      return *this;
  }

  template<class T>
  bool Pila_max_VD<T>::Vacia(){
      return (datos.size() == 0);
  }

  template<class T>
  elemento Pila_max_VD<T>::tope(){
      assert(datos.size() > 0);
      return datos.back();
  }

  template<class T>
  void Pila_max_VD<T>::poner(const int & element){
      if(datos.size() == 0 || datos.back().maximo < element){
      elemento aux = {element,element};
      datos.push_back(aux);

  }else{
      if(datos.back().maximo > element){
          elemento aux = {element,datos.back().maximo};
          datos.push_back(aux);
      }
  }
  }

  template<class T>
  void Pila_max_VD<T>::quitar(){
     assert(datos.size() > 0);
      datos.pop_back();
  }

  template<class T>
  int Pila_max_VD<T>::numElementos() const{
       return datos.size();
  }
