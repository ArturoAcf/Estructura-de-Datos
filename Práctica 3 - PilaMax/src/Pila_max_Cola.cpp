// Realizado por: Arturo Alonso Carbonero y José Luis Molina Aguilar
// Grupo: 2ºC - C1
// Práctica 2. TDA lineales - TDA Pila_max_Cola

/**
  *@file Pila_max_Cola.cpp
  *@brief Fichero con las operaciones del TDA Pila con máximo basado en una Cola con templates
  *
  *Gestiona una secuencia de elementos con facilidades para la inserción y
  *borrado de elementos en un extremo
  */

  #include <cassert>
  #include <iostream>
  #include "../include/Pila_max_Cola.h"
  #include "../include/elemento.h"

  using namespace std;

  Pila_max_Cola::Pila_max_Cola(){
    Cola<elemento> pilaMax;
  }

  Pila_max_Cola::Pila_max_Cola(const Pila_max_Cola &pm){
    this->pilaMax=pm.pilaMax;
  }

  Pila_max_Cola::~Pila_max_Cola(){
    pilaMax.~Cola();
  }

  bool Pila_max_Cola::vacia(){
    return pilaMax.vacia();
  }

  Pila_max_Cola &Pila_max_Cola::operator=(const Pila_max_Cola &pm){
    pilaMax=pm.pilaMax;
    return *this;
  }

  void Pila_max_Cola::poner(const int ele){
    elemento nuevo;
    nuevo.ele=ele;

    if(vacia()){
      nuevo.maximo=ele;
    }else{
        elemento anterior=tope();
      if(ele>anterior.maximo){
        nuevo.maximo=ele;
      }else{
        nuevo.maximo=anterior.maximo;
      }
    }

    pilaMax.poner(nuevo);
  }

  void Pila_max_Cola::quitar(){
    Cola<elemento> aux;

    int tam=num_elementos()-1;

    for(int i=0; i<tam; i++){
      aux.poner(pilaMax.frente());
      pilaMax.quitar();
    }

    pilaMax=aux;
  }

  elemento Pila_max_Cola::tope() const{
    Cola<elemento> aux=pilaMax;
    elemento top=aux.frente();

    while(!aux.vacia()){
      top.ele=aux.frente().ele;
      top.maximo=aux.frente().maximo;
      aux.quitar();
    }

    return top;
  }

  int Pila_max_Cola::num_elementos() const{
    return pilaMax.num_elementos();
  }
