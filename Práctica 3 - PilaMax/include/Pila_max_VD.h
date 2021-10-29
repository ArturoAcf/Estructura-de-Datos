// Realizado por: Arturo Alonso Carbonero y José Luis Molina Aguilar
// Grupo: 2ºC - C1
// Práctica 2. TDA lineales - TDA Pila_max_VD

  /**
    *@file Pila_max_VD.h
    *@brief Fichero cabecera del TDA Pila con máximo basado en la clase vector de la STL
    *
    *Gestiona una secuencia de elementos con facilidades para la inserción y
    *borrado de elementos en un extremo
    */

    #ifndef _PILA_MAX_VD_
    #define _PILA_MAX_VD_

    #include <cassert>
    #include <iostream>
    #include <vector>
    #include "elemento.h"

    using namespace std;

    /**
      *@brief TDA Pila_max_VD
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

      template <class T>
      class Pila_max_VD{
      private:
        vector<elemento> datos;

      public:
        /**
         * @brief Construcor por defector
         */
        Pila_max_VD();

        /**
         * @brief Constructor de copia
         * @param orig la pila de la que se realiza la copia
         */
        Pila_max_VD(const Pila_max_VD& orig);

        /**
         * @brief Destructor
         */
        ~Pila_max_VD();

        /**
          *@brief Sobrecarga del operador de asignación
          *@param otra es la pila a asignar
          */
        Pila_max_VD& operator=(const Pila_max_VD& otra);

        /**
          *@brief Comprueba si la pila está vacía
          */
        bool Vacia();

        /**
          *@brief Devuelve el elemento del tope
          */
        elemento tope();

        /**
          *@brief Añade un elemento en el tope de la pila
          *@param elemento es el elemento insertado
          */
        void poner(const int & element);

        /**
          *@brief Elimina el elemento del tope de la pila
          *@pre La pila debe contener al menos un elemento
          */
        void quitar();

        /**
          *@brief Número de elementos de la pila
          */
        int numElementos() const;
      };

    #endif
