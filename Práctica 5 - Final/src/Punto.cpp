/**
  *@file Fichero con la implementación del TDA Punto
  */

#include "../include/Punto.h"

using namespace std;

Punto::Punto(){
    longitud = 0.0;
    latitud = 0.0;
    descripcion = "";
}

Punto::Punto(double latitud, double longitud, string Descr){
    this->latitud = latitud;
    this->longitud = longitud;
    this->descripcion = Descr;
}

Punto::Punto(const Punto& orig){
    this->latitud = orig.latitud;
    this->longitud = orig.longitud;
    this->descripcion = orig.descripcion;
}

bool Punto::operator==(const Punto& right) const {
    return(this->latitud == right.latitud && this->longitud == right.longitud);
}

Punto Punto::operator=(const Punto& otro){
    this->latitud = otro.latitud;
    this->longitud = otro.longitud;
    this->descripcion = otro.descripcion;

    return *this;
}

double Punto::GetLongitud(){
    return longitud;
}

double Punto::GetLatitud(){
    return latitud;
}

string Punto::getDescripcion(){
    return descripcion;
}

void Punto::setDescipcion(string descr){
    descripcion += descr;
}

void Punto::setLongitud(double LOng){
    longitud = LOng;
}

void Punto::setLatitud(double lat){
    latitud = lat;
}
