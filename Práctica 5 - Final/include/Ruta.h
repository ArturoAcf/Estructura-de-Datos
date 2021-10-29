/**
  *@file Fichero cabecera del TDA Ruta
  */

#ifndef RUTA_H
#define RUTA_H

#include "../src/Punto.cpp"
#include <list>
#include <iostream>

using namespace std;

class Ruta {
private:
    list<Punto> puntos;
    string code;

public:
    /**
      *@brief Constructor por defecto
      */
    Ruta(){};

    /**
      *@brief Constructor de copia
      *
      *@param orig representa un objeto de tipo Ruta
      */
    Ruta(const Ruta& orig);

    /**
      *@brief Destructor
      */
    ~Ruta(){};

    /**
      *@brief Sobrecarga del operador de asignación
      *
      *@param otro representa el objeto de tipo Ruta a asignar
      *
      *@return Devuelve *this
      */
    Ruta operator=(const Ruta& otro);

    /**
      *@brief Consultor del código de una Ruta
      *
      *@return Devuelve el código de la Ruta
      */
    string getCode();

    /**
      *@brief Modificador del código de una Ruta
      *
      *@param ncod representa el nuevo código
      */
    void setCode(string ncod);

    /**
      *@brief Consultor de la lista de puntos de una Ruta
      *
      *@return Devuelve una lista de tipo Punto
      */
    list<Punto> getPuntos();

    /**
      *@brief Modificador de un punto de la lista de puntos
      *
      *@param p representa el punto a insertar
      */
    void setPuntos(const Punto &p);

  /**
    *@brief Clase para iterar sobre la Ruta
    */
  class iterator{
  private:
      list<Punto>::iterator it;
  public:
    friend class Ruta;

    iterator(){};

    iterator & operator++(){
		   ++it;
		   return *this;
	  }

		iterator & operator--(){
			--it;
			return *this;
		}

		Punto &operator*(){
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
      *@brief Inicializa un iterador al inicio de la Ruta
      */
    iterator begin(){
			iterator i;
			i.it = puntos.begin();
			return i;
		}

    /**
      *@brief Inicializa un iterador al final de la Ruta
      */
		iterator end(){
			iterator i;
			i.it = puntos.end();
			return i;
		}

  /**
    *@brief Clase para iterar sobre la Ruta
    */
  class const_iterator{
  private:
        list<Punto>::const_iterator it;
  public:
    friend class Ruta;

    const_iterator(){};

    const_iterator &operator=(const iterator & iter){
        it = iter.it;
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

		const Punto &operator*(){
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
      *@brief Inicializa un iterador al inicio de la Ruta
      */
    const_iterator begin()const{
			const_iterator i;
			i.it = puntos.begin();
			return i;
		}

    /**
      *@brief Inicializa un iterador al final de la Ruta
      */
		const_iterator end()const{
			const_iterator i;
			i.it = puntos.end();
			return i;
		}

    /**
      *@brief Sobrecarga del operador de salida para el tipo Ruta
      */
    friend ostream &operator<<(ostream &os,const Ruta &R){
      Ruta::const_iterator it;
      os<<R.code << "\t";

      for (it=R.begin(); it != R.end(); ++it){
        os<<*it<<"\t";
	    }

	    return os;
    }

    /**
      *@brief Sobrecarga del operador de entrada para el tipo Ruta
      */
    friend istream &operator >>(istream & is, Ruta &R){
      if (is.peek()=='#'){
		      string a;
		      getline(is,a);
      }

        int nruta;
        Punto P;
        Ruta aux;
        string codigo;
        is>>codigo;
        QuitaSeparadores(is);

        is>>nruta;
        QuitaSeparadores(is);

        aux.code = codigo;

        for(int i = 0; i <nruta;++i){
          is>>P;
          aux.setPuntos(P) ;
          QuitaSeparadores(is);
        }

        QuitaSeparadores(is);
        R=aux;

        return is;
    }
};

#endif /* RUTA_H */
