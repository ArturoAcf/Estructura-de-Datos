/**
  *@file Fichero con la implementación del TDA Almacen_Rutas
  */

#include "../include/Almacen_Rutas.h"

using namespace std;

Almacen_Rutas::Almacen_Rutas(map<string,Ruta> Rutas, multimap<Pais,Ruta> puntosenruta){
    this->rutas = Rutas;
    this->puntos_enruta = puntosenruta;
}

map<string,Ruta> Almacen_Rutas::GetRutas() const{
    return rutas;
}

Almacen_Rutas& Almacen_Rutas::operator=(const Almacen_Rutas& right){
    if (this == &right)
        return *this;
    this->rutas = right.rutas;
    this->puntos_enruta = right.puntos_enruta;

    return *this;
}

void Almacen_Rutas::insertar( Ruta &R){
    rutas.insert(pair<string,Ruta> (R.getCode(),R));
}

Ruta Almacen_Rutas::GetRuta(string code){
    return rutas[code];
}

void Almacen_Rutas::borrar(Ruta &R){
    string codigo = R.getCode();
    rutas.erase(codigo);
}
