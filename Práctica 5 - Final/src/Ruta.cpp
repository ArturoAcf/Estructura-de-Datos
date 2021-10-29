/**
  *@file Fichero con la implementación del TDA Ruta
  */

#include "../include/Ruta.h"

using namespace std;

Ruta::Ruta(const Ruta& orig){
    this->puntos = orig.puntos;
    this->code = orig.code;
}

Ruta Ruta::operator=(const Ruta& otro){
    this->puntos = otro.puntos;
    this->code = otro.code;

    return *this;
}

string Ruta::getCode(){
    return code;
}

void Ruta::setCode(string ncod){
    this->code = ncod;
}

list<Punto> Ruta::getPuntos(){
    list<Punto> ans;
    for(list<Punto>::iterator i = puntos.begin(); i != puntos.end(); ++i)
        ans.push_back(*i);
    return ans;
}

void Ruta::setPuntos(const Punto &p){
    puntos.push_back(p);
}
