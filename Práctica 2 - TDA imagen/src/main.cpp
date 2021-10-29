// Realizado por: Arturo Alonso Carbonero y José Luis Molina Aguilar
// Grupo: 2ºC - C1
// Práctica 2. Abstracción - TDA imagen

/**
  *@file Función principal para la ejecución del programa
  */

#include <iostream>
#include <cstring>
#include <cstdlib>

#include "imagen.h"
#include "imagenES.h" // Material proporcionado

using namespace std;

// Función principal derivada de la proporcionada (negativo)
int main (int argc, char *argv[]){

  char *origen, *destino; // nombres de los ficheros que contienen las imágenes

  unsigned char *image;
  int nf, nc; // Número de filas y columnas de las imágenes

  int operacion;    // Variable para que el usuario selccione la operación a realizar sobre la imagen origen
  int min, max;     // Variables para el contraste
  int xIcon, yIcon; // Variables para la creación de un icono
  bool operacionValida=false; // Variable de control para el menú de selección de operaciones

  // Comprobar validez de la llamada
  if (argc != 3){
    cerr << "Error: Numero incorrecto de parametros.\n";
    cerr << "Uso: Imagen <FichImagenOriginal> <FichImagenDestino>\n";
    exit (1);
  }

  origen  = argv[1];
  destino = argv[2];

  cout << endl;
  cout << "Fichero origen: " << origen << endl;
  cout << "Fichero resultado: " << destino << endl;

  // Leer la imagen del fichero de entrada
  image = LeerImagenPGM (origen, nf, nc);
  if (!image){
    cerr << "Error: No pudo leerse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    exit (1);
  }

  // Mostrar los parametros calculados por la lectura de la imagen
  cout << endl;
  cout << "Dimensiones de " << origen << ":" << endl;

  cout << "   Imagen   = " << nf  << " filas x " << nc << " columnas " << endl;

  Imagen im(nf, nc); // Objeto de la clase Imagen de tamaño nf*nc

  // Ejecución del programa con un menú básico para seleccionar el tipo de operación
  while(!operacionValida){
    cout << "\nElija qué operación desea realizar sobre la imagen seleccionada: " << endl;
    cout << endl << "\t-OPERACIONES-" << endl;
    cout << " 1. Creación de icono" << endl;
    cout << " 2. Umbralización" << endl;
    cout << " 3. Contraste" <<  endl;
    cin >> operacion;

    if(operacion==1){
      cout << "Ha seleccionado la operación 'Creación de icono'" << endl;
      cout << "\nIntroduzca las dimensiones del icono a crear: " << endl;
      cout << "Filas: ";
      cin >> xIcon;
      cout << "Columnas: ";
      cin >> yIcon;
      cout << "Creando icono..." << endl;
      im.icono(image, destino, xIcon, yIcon);
      operacionValida=true;
    }else if(operacion==2){
      cout << "Ha seleccionado la operación 'Umbralización'" << endl;
      cout << "\nCreando imagen umbralizada..." << endl;
      im.Umbralizar(image, destino);
      operacionValida=true;
    }else if(operacion==3){
      cout << "Ha seleccionado la operación 'Contraste'" << endl;
      cout << "\nIntroduzca el min y el max del contraste (<min y >max de la imagen original): " << endl;
      cout << "min: ";
      cin >> min;
      cout << "max: ";
      cin >> max;
      cout << "Creando imagen con contraste..." << endl;
      im.contraste(image, destino, min, max);
      operacionValida=true;
    }else{
      cout << "\nOperacion no válida, mostrando menú..." << endl;
    }
  }

  // Liberar la imagen
  delete [] image;

  return (0);
}
