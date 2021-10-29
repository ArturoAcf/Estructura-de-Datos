// Realizado por: Arturo Alonso Carbonero
// DNI: 75936665-A
// Grupo: 2ºC - C1
//
// NOTA -> He mantenido el material proporcionado casi intacto

/**
  *@file Diccionario.h
  *@brief Ficehro cabecera del TDA  dicionario proporcionado por el profesor
  */

#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>
#include <stdlib.h>
#include <iterator>

using namespace std;

/*Tipo elemento que define el diccionario. T es el tipo de dato asociado a una clave que
no se repite (DNI p.ej.) y list<U> es una lista de datos (string p.ej) asociados a la clave
de tipo T. El diccionario está ordenado de menor a mayor clave.
*/
template <class T,class U>
struct data{
    T clave;
    list<U> info_asoci;
 };


 /*Comparador de datos. Ordena 2 registros de acuerdo a la clave de tipo T. Puede usarse como
 un funtor.
 */
template <class T, class U>
bool operator< (const data<T,U> &d1,const data <T,U>&d2){
	   if (d1.clave<d2.clave)
		     return true;
	   return false;
}

/*Un diccionario es una lista de datos de los definidos anteriormente. Cuidado porque se
manejan listas de listas. Se añaden 2 funciones privadas que hacen más facil la implementación
de algunos operadores o funciones de la parte pública. Copiar copia un diccioario en
otro y borrar elimina todos los elementos de un diccionario. La implementación de copiar
puede hacerse usando iteradores o directamente usando la función assign.
*/
template <class T,class U>
class Diccionario{
	  private:


 		    list<data<T,U> > datos;

		    void Copiar(const Diccionario<T,U>& D){
			   /*typename list<data<T,U> >::const_iterator it_d;
			   typename list<data<T,U> >::iterator it=this->datos.begin();*/

			   datos.assign(D.datos.begin(),D.datos.end());
			   /*for (it_d=D.datos.begin(); it_d!=D.datos.end();++it_d,++it){
				     this->datos.insert(it,*it_d);

			   }*/
		    }

		    void Borrar(){

			      this->datos.erase(datos.begin(),datos.end());
		    }


	  public:
	         /* Constructor por defecto*/
		 Diccionario():datos(list<data<T,U> >()){}

		 /* Constructor de copias*/
		 Diccionario(const Diccionario &D){
			   Copiar(D);
		 }

		 /* Desstructor*/
		 ~Diccionario(){}

		 /* Operador de asignación*/
		 Diccionario<T,U> & operator=(const Diccionario<T,U> &D){
			   if (this!=&D){
				     Borrar();
				     Copiar(D);
			   }
			   return *this;
		 }

		/* Busca la clave p en el diccionario. Si está devuelve un iterador a
		dónde está clave. Si no está, devuelve end() y deja el iterador de salida
		apuntando al sitio dónde debería estar la clave
		*/
		bool Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out){

			  if (datos.size()>0){

			      typename list<data<T,U> >::iterator it;

			      for (it=datos.begin(); it!=datos.end() ;++it){
					if ((*it).clave==p) {
						  it_out=it;
						  return true;
					}
					else if ((*it).clave>p){
						  it_out=it;
						  return false;
					}

			      }

			      it_out=it;
			      return false;
			  }
			  else {
				    it_out=datos.end();
				    return false;
			  }
		 }

		 /* Inserta un nuevo registro en el diccionario. Lo hace a través de la clave
		 e inserta la lista con toda la información asociada a esa clave. Si el
		 diccionario no estuviera ordenado habría que usar la función sort()
		 */
		 void Insertar(const T& clave,const list<U> &info){

		     typename list<data<T,U> >::iterator it;

		     if (!Esta_Clave(clave,it)){
			       data<T,U> p;
			       p.clave = clave;
			       p.info_asoci=info;

			       datos.insert(it,p);

		     }

		 }

		 /*Añade una nueva informacion asocida a una clave que está en el diccionario.
		 la nueva información se inserta al final de la lista de información.
                  Si no esta la clave la inserta y añade la informacion asociada.
		 */
		 void AddSignificado_Palabra(const U & s ,const T &p){
			   typename list<data<T,U> >::iterator it;

			   if (!Esta_Clave(p,it)){
				    datos.insert(it,p);
			   }

			    //Insertamos el siginificado al final
		           (*it).info_asoci.insert((*it).info_asoci.end(),s);
		 }

		 /* Devuelve la información (una lista) asociada a una clave p. Podrían
		 haberse definido operator[] como
		 data<T,U> & operator[](int pos){ return datos.at(pos);}
		 const data<T,U> & operator[](int pos)const { return datos.at(pos);}
		  */
		  list<U>  getInfo_Asoc(const T & p) {
			   typename list<data<T,U> >::iterator it;

			   if (!Esta_Clave(p,it)){
				return list<U>();
			   }
			   else{
				return (*it).info_asoci;
			   }
		 }



		/*Devuelve el tamaño del diccionario*/
		 int size()const{
			   return datos.size();
		 }


		 /*Funciones begin y end asociadas al diccionario*/
		 typename list<data<T,U> >::iterator & begin(){
			   datos.begin();
		 }
		 typename list<data<T,U> >::iterator &end(){
			   datos.end();
		 }

		 typename list<data<T,U> >::const_iterator & begin()const{
			   datos.begin();
		 }
		 typename list<data<T,U> >::const_iterator &end()const {
			   datos.end();
		 }

//________________________________________________________________

// ---MÉTODOS AÑADIDOS---

// ---ITERADORES---

/**
  *@brief Clase para iterar sobre el diccionario
  */
class iterator{
private:
  typename list<data<T,U> >::iterator it;

public:
  iterator(){}

  bool operator==(const iterator &i){
    return i.it == it;
  }

  bool operator!=(const iterator &i){
    return i.it != it;
  }

  data<T,U> & operator*(){
    return *it;
  }

  iterator & operator++(){
    ++it;
    return *this;
  }

  iterator & operator=(const iterator &i){
    it = i;
    return *this;
  }

  friend class Diccionario;
};

/**
  *@brief Clase para iterar sobre el diccionario
  */
class const_iterator{
private:
  typename list<data<T,U> >::const_iterator it;

public:
  const_iterator(){}

  bool operator==(const const_iterator &i){
    return i.it == it;
  }

  bool operator!=(const const_iterator &i){
    return i.it != it;
  }

  const data<T,U> & operator*() const{
    return *it;
  }

  const_iterator & operator++(){
    ++it;
    return *this;
  }

  const_iterator & operator=(const iterator &i){
    it = i.it;
    return *this;
  }

  friend class Diccionario;
};

// ---MÉTODOS PARA EL DICCIONARIO---

/**
  *@brief Crear un lista de las palabras que empiezan por una letra dada
  *@param letra representa la letra por la que deben empezar las palabras
  *
  *@return Devuelve una lista con las palabras del diccionario que comiencen por letra
  */
list<string> palabrasPorInicial(char letra);

/**
  *@brief Elimina una palabra del diccionario
  *@param p representa una clave introducida, es decir, una palabra
  *
  *@return Devuelve void
  */
void eliminarPalabra(const T &p);

/**
  *@brief Sustituye una clave existente por otra
  *@brief p representa una clave introducida, es decir, una palabra
  *
  *@return Devuelve void
  */
void actualizarClave(const T &p);

/**
  *@brief Crea un diccionario con las palabras que comienzan por una letra dada
  *@param letra representa la letra por la que deben empezar las palabras
  *
  *@return Devuelve un diccionario con dichas palabras
  */
Diccionario<T,U> diccionarioLetra(char letra);

//________________________________________________________________

};

#endif
