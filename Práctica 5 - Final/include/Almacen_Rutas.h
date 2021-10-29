/**
  *@file Fichero cabecera del TDA Almacen_Rutas
  */

#ifndef ALMACEN_RUTAS_H
#define ALMACEN_RUTAS_H

#include "Ruta.h"
#include <map>
#include <string>
#include "Pais.h"
#include <utility>

using namespace std;

class Almacen_Rutas{
private:
    map<string,Ruta> rutas;
    multimap<Pais,Ruta> puntos_enruta;

public:
    /**
      *@brief Constructor por defecto
      */
    Almacen_Rutas() : rutas{} , puntos_enruta{}
    {};

    /**
      *@brief Constructor con parámetros
      *
      *@param Rutas representa un map que contiene un string y una lista de tipo Punto asociada
      *@param puntosenruta representa un multimap que contiene un Pais y una lista de tipo Punto asociada
      */
    Almacen_Rutas(map<string,Ruta> Rutas, multimap<Pais,Ruta> puntosenruta);

    /**
      *@brief Constructor de copia
      *
      *@param other representa un objeto de de tipo Almacen_Rutas
      */
    Almacen_Rutas(const Almacen_Rutas& other) :
        rutas(other.rutas), puntos_enruta(other.puntos_enruta) {
    }

    /**
      *@brief Consultor de las rutas de un almacén
      *
      *@return Devuelve un objeto de tipo map que contiene un string y una Ruta asociada
      */
    map<string,Ruta> GetRutas() const;

    /**
      *@brief Sobrecarga del operador de asignación
      *
      *@param right representa el objeto del tipo Almacen_Rutas a asignar
      *
      *@return Devuelve *this
      */
    Almacen_Rutas& operator=(const Almacen_Rutas& right);

    /**
      *@brief Insertar una nueva ruta en un almacén
      *
      *@param R representa un objeto de tipo Ruta
      */
    void insertar( Ruta &R);

    /**
      *@brief Consultor de una Ruta del almacén apartir de su código
      *
      *@param code representa el código de la Ruta a consultar
      *
      *@return Devuelve un objeto de tipo Ruta
      */
    Ruta GetRuta(string code);

    /**
      *@brief Eliminar una ruta del almacén
      *
      *@param R representa la ruta a eliminar
      */
    void borrar(Ruta &R);

    /**
      *@brief sobrecarga del operador de salida para el tipo Almacen_Rutas
      */
    friend ostream& operator<<(ostream& os, const Almacen_Rutas& obj) {
        Almacen_Rutas::const_iterator it;
        if(obj.rutas.empty())
            os<<"vacio"<<endl;

        for(it = obj.begin(); it != obj.end();++it){
           os << (*it).second<<endl;

        }
        return os;
    }

    /**
      *@brief Sobrecarga del operador de entrada para el tipo Almacen_Rutas
      */
    friend istream& operator>>(istream& is,Almacen_Rutas& obj) {
        if(is.peek() == '#'){ // Leemos el comentario
            string a;
            getline(is,a);
        }

        QuitaSeparadores(is);
        Ruta R;
        Almacen_Rutas aux;

        while(!is.eof()){
            is>>R;
            aux.insertar(R);
        }

        obj=aux;
        return is;
    }

    /**
      *@brief Clase para iterar sobre un almacén
      */
    class iterator{
    private:
          map<string,Ruta>::iterator it;

    public:
        friend class Almacen_Rutas;
        iterator(){};
        iterator & operator++(){
			++it;
			return *this;
		}
		iterator & operator--(){
			--it;
			return *this;
		}

		const pair<string,Ruta> operator*(){
                    return *it;
		}

		bool operator==(const iterator &iter){
			return iter.it == it;
		}

		bool operator!=(const iterator &iter){
			return iter.it != it;
		}
         };

    /**
      *@brief Inicializa un iterador al inicio del almacén
      */
    iterator begin(){
			iterator i;
			i.it = rutas.begin();
			return i;
		}

    /**
      *@brief Inicializa un iterador al final del almacén
      */
		iterator end(){
			iterator i;
			i.it = rutas.end();
			return i;
		}

    /**
      *@brief Clase para iterar sobre un almacén
      */
    class const_iterator{
    private:
       map<string,Ruta>::const_iterator it;
    public:
        friend class Almacen_Rutas;
        const_iterator(){};
        const_iterator(const iterator & iter){
            it = iter.it;
        }
        const_iterator & operator=(const iterator & iter){
		it=iter.it;
		return *this;
	}
        const_iterator & operator++(){
			++it;
			return *this;
		}
		const_iterator & operator--(){
			--it;
			return *this;
		}

		const pair<string,Ruta> operator*(){
			return *it;
		}

		bool operator==(const const_iterator &iter){
			return iter.it == it;
		}

		bool operator!=(const const_iterator &iter){
			return iter.it != it;
		}

    };

    /**
      *@brief Inicializa un iterador al inicio del almacén
      */
    const_iterator begin()const{
			const_iterator i;
			i.it = rutas.begin();
			return i;
		}

    /**
      *@brief Inicializa un iterador al final del almacén
      */
		const_iterator end()const{
			const_iterator i;
			i.it = rutas.end();
			return i;
		}
};


#endif /* ALMACEN_RUTAS_H */
