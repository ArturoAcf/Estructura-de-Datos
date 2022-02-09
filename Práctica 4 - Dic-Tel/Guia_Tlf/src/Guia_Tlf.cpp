// Realizado por Arturo Alonso Carbonero 
// Grupo -> 2ºC - C1

/**
  *@file Fichero con la implementación de los métodos del TDA Guia_Tlf
  */

#include "../include/Guia_Tlf.h"
#include <iostream>
#include <map>
#include <stdlib.h>
#include <cstring>

using namespace std;

// Guía con los nombres que empiecen por la inicial deseada
Guia_Tlf Guia_Tlf::buscarPorInicial(char inicial){
  Guia_Tlf p_amarillas; // Guía de teléfono auxiliar
  Guia_Tlf::iterator it;
  char l=toupper(inicial);

  for(it=begin(); it!=end(); ++it){
      char primeraL=obtenerInicial((*it).first);
    if(primeraL==l){
      p_amarillas.insert(*it);
    }
  }

  return p_amarillas;
}

// Buscar un nombre por su número
string Guia_Tlf::numeroDeNombre(string &numero){
  string resultado;
  bool r=false;
  Guia_Tlf::iterator it;

  for(it=begin(); it!=end() && !r; ++it){ // r corta el bucle cuando se encuentra el número
    if(numero==(*it).second){
      resultado=(*it).first;
      r=true;
    }else{
      resultado="-";
    }
  }

  return resultado;
}

// Guía con los móviles de España
Guia_Tlf Guia_Tlf::movilesEsp(){
  Guia_Tlf moviles_esp;
  Guia_Tlf::iterator it;

  for(it=begin(); it!=end(); ++it){
      int num=obtenerDigito((*it).second);
    if(num==54 || num==55){ // En código ASCII, 54=6 y 55=7.
      moviles_esp.insert(*it);
    }
  }

  return moviles_esp;
}

// Sustituir un número por otro
void Guia_Tlf::sustituirNumero(string &num1, string &num2){
  Guia_Tlf::iterator it;

  for(it=begin(); it!=end(); ++it){
    if((*it).second==num1){
      (*it).second=num2;
    }
  }
}
