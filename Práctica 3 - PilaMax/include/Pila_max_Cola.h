// Realizado por: Arturo Alonso Carbonero y José Luis Molina Aguilar
// Grupo: 2ºC - C1
// Práctica 2. TDA lineales - TDA Pila_max_Cola

  /**
    *@file Pila_max_Cola.h
    *@brief Fichero cabecera del TDA Pila con máximo basado en una Cola con templates
    *
    *Gestiona una secuencia de elementos con facilidades para la inserción y
    *borrado de elementos en un extremo
    */

  #ifndef _PILA_MAX_COLA_
  #define _PILA_MAX_COLA_

  #include <cassert>
  #include <iostream>
  #include "../src/cola.cpp" // Material proporcionado
  #include "elemento.h"

  using namespace std;

  /**
    *@brief TDA Pila_max_Cola
    *
    *Una pila con máximo basada en un cola es un conjunto de elementos del mismo
    *tipo con operaciones que permiten consultar, modificar, borrar, insertar, ect;
    *dichos elementos en uno de los extremos de la estructura, el tope.
    *Si n=0, diremos que la pila está vacía ya que no hay elementos.
    *
    *Cada elemento de la pila es un par de elementos que representan el elemento
    *insertado y el máximo. Dicho máximo se calcula comparandolo con el anterior
    *máximo y, si es mayor o el anterior es cero, este pasa a ser el máximo.
    *En caso de que el anterior máximo sea mayor, éste se mantiene como actual máximo.
    */

    class Pila_max_Cola{
    private:
      /**
        *@brief Cola que contiene los datos de Pila_max_Cola
        */
      Cola<elemento> pilaMax;
    public:
      /**
        *@brief Constructor por defecto
        */
      Pila_max_Cola();

      /**
        *@brief Constructor de copia
        *@param pm pila con máximo que queremos copiar
        */
      Pila_max_Cola(const Pila_max_Cola &pm);

      /**
        *@brief Destructor
        */
      ~Pila_max_Cola();

      /**
        *@brief sobrecarga del operador de asignación.
        *@param pm pila con máximo que queremos asignar.
        */
      Pila_max_Cola & operator=(const Pila_max_Cola &pm);

      /**
        *@brief Comprueba si la pila está vacía
        */
      bool vacia();

      /**
        *@brief Añade un elemento en el tope de la pila
        *@param elemento es el elemento insertado
        */
      void poner(const int elemento);

      /**
        *@brief Elimina el elemento del tope de la pila
        *@pre La pila debe contener al menos un elemento
        */
      void quitar();

      /**
        *@brief Devuelve el elemento del tope
        */
      elemento tope() const;

      /**
        *@brief Número de elementos de la pila
        */
      int num_elementos() const;
    };

  #endif
