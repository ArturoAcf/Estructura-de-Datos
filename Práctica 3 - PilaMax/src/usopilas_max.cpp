// Realizado por: Arturo Alonso Carbonero y José Luis Molina Aguilar
// Grupo: 2ºC - C1
// Práctica 2. TDA lineales - TDA Pila_max_VD

/**
  *@file Prueba de los TDA creados Pila_max_VD y Pila_max_Cola
  */

// NOTA
// Tras ejecutar ./bin/usopila_max muestra las pilas de forma correcta, pero al final del todo
// aparece cierto error.
// Resultado de dicha ejecución:
    /*Pila max hecha con Colas:
    ( 10, 10 )
    ( 9, 9 )
    ( 8, 8 )
    ( 7, 7 )
    ( 6, 6 )
    ( 5, 5 )
    ( 4, 4 )
    ( 3, 3 )
    ( 2, 2 )
    ( 1, 1 )
    ( 0, 0 )

    Pila max hecha con Vector Dinamico:
    ( 20, 20 )
    ( 19, 19 )
    ( 18, 18 )
    ( 17, 17 )
    ( 16, 16 )
    ( 15, 15 )
    ( 14, 14 )
    ( 13, 13 )
    ( 12, 12 )
    ( 11, 11 )
    ( 10, 10 )
    free(): double free detected in tcache 2
    Abortado (`core' generado)*/
// Aparentemente no influye en la ejecución de los bucles, pero no hemos logrado una solución.
// Independientemente, las pilas funcionan correctamente.

#include <iostream>

#include "elemento.h"
#include "Pila_max_Cola.cpp"
#include "Pila_max_VD.cpp"

using namespace std;

int main() {
    cout << "Pila max hecha con Colas: " << endl;
    Pila_max_Cola pc;

    // Se introducen los valores al revés (con respecto al ejemplo del guión)
    // para mostrar que se actualiza el tope correctamente.
    // Si el bucle for va de 10 a 0, el tope siempre es 10.
    for (int i = 0; i <= 10; i++) {
        pc.poner(i);
    }
    while (!pc.vacia()) {
        elemento x = pc.tope();
        cout << x << endl;
        pc.quitar();
    }

    cout << "\nPila max hecha con Vector Dinamico: " << endl;
    Pila_max_VD<int> vd;

    // Ídem
    for (int i = 10; i <= 20; i++) {
        vd.poner(i);
    }
    while (!vd.Vacia()) {
        elemento x = vd.tope();
        cout << x <<endl;
        vd.quitar();
    }

    return 0;
}
