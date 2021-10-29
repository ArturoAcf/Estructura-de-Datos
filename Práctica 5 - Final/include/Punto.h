/**
  *@file Fichero cabecera del TDA Punto
  */

#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>
#include <string>

using namespace std;

/**
  *@brief Método para eliminar caractere no deseados en la lectura
  */
void QuitaSeparadores(istream &is){
    while(is && (is.peek() == '\t' || is.peek() == ' ' || is.peek() == '\n' || is.peek() == '(' || is.peek() == ',' || is.peek() == ')'))
        is.get();
}

class Punto {
private:
    double longitud, latitud;
    string descripcion;

public:
    /**
      *@brief Constructor por defecto
      */
    Punto();

    /**
      *@brief Constructor con parámetros
      *
      *@param latitud representa la latitud del punto
      *@param longitud representa la longitud del punto
      *@param Descr representa la descripción del punto
      */
    Punto(double latitud, double longitud, string Descr);

    /**
      *@brief Constructor de copia
      *
      *@param orig representa el objeto a copiar
      */
    Punto(const Punto& orig);

    /**
      *@brief Sobrecarga del operador '==' para el tipo Punto
      */
    bool operator==(const Punto& right) const;

    /**
      *@brief Sobrecarga del operador de asignación para el tipo Punto
      */
    Punto operator=(const Punto& otro);

    /**
      *@brief Consultor de la longitud del punto
      *
      *@return Devuelve un objeto de tipo double con el valor de la longitud
      */
    double GetLongitud();

    /**
      *@brief Consultor de la latitud del punto
      *
      *@return Devuelve un objeto de tipo double con el valor de la latitud
      */
    double GetLatitud();

    /**
      *@brief Consultor de la descripción del punto
      *
      *@return Devuelve un objeto de tipo string con el valor de la descripción
      */
    string getDescripcion();

    /**
      *@brief Modificador de la descripción del punto
      *
      *@param descr representa la nueva descripción
      */
    void setDescipcion(string descr);

    /**
      *@brief Modificador de la longitud del punto
      *
      *@param L0ng representa la nueva longitud
      */
    void setLongitud(double LOng);

    /**
      *@brief Modificador de la latitud del punto
      *
      *@param lat representa la nueva latitud
      */
    void setLatitud(double lat);

    /**
      *@brief Sobrecarga del operador de entrada para el tipo Punto
      */
    friend istream & operator>>(istream & is, Punto & P){
        double lat,lng;
        QuitaSeparadores(is);
        is>>lat;
        QuitaSeparadores(is);
        is>>lng;
        QuitaSeparadores(is);
        Punto aux(lat,lng,"");

        P=aux;

	      return is;
    }

    /**
      *@brief Sobrecarga del operador de salida para el tipo Punto
      */
    friend ostream & operator<<(ostream & os, const Punto &P){
	     os<<"(" << P.latitud << "," << P.longitud << ")" << endl;
	     return os;
    }
};

#endif /* PUNTO_H */
