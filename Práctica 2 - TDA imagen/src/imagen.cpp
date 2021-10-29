// Realizado por: Arturo Alonso Carbonero y José Luis Molina Aguilar
// Grupo: 2ºC - C1
// Práctica 2. Abstracción - TDA imagen

/**
  *@file Implementación de la clase Imagen
  *@brief permite utilizar las funciones de la clase Imagen
  */

#include <fstream>
#include <iostream>

#include "imagen.h"
#include "imagenES.h"   // Material proporcionado

using namespace std;

Imagen::Imagen(){
    filas = 0;
    cols = 0;
    img = 0;
}

Imagen::Imagen(const Imagen& otro){
    for(int i = 0;i < otro.filas;i++)
        for(int j = 0;j < otro.cols;j++)
            img[i][j] = otro.img[i][j];
}

void Imagen::liberarMemoria(){
    if(img){
        delete[] img[0];
        delete[] img;
    }
}
Imagen::~Imagen() {
    liberarMemoria();
}

Imagen::Imagen(int nfilas, int ncols){
  this->reservarMemoria(nfilas, ncols);
}

void Imagen::reservarMemoria(int nfilas, int ncols){
    if(nfilas > 0)
        filas = nfilas;
    else
        filas = 0;
    if(ncols > 0)
        cols = ncols;
    else
        cols = 0;

    if(filas > 0){
        img = new byte*[nfilas];
        if(cols > 0){
            for(int f = 0; f < nfilas;f++)
                img[f] = new byte[ncols];
        }else
            for(int i = 0; i < filas;i++)
                img[i] = 0;

    }else
        img = 0;
}

// _____________________________________________________________________________

void Imagen::vectorAMatriz(const unsigned char *im){
  for(int i=0; i<filas; i++){
    for(int j=0; j<cols; j++){
      img[i][j]=im[i*cols+j];
    }
  }
}

void Imagen::matrizAVector(unsigned char *im){
  for(int i=0; i<filas; i++){
    for(int j=0; j<cols; j++){
      im[i*cols+j]=img[i][j];
    }
  }
}

// _____________________________________________________________________________

void Imagen::asigna_pixel(int fila, int col, byte valor){
    img[fila][col] = valor;
}

byte Imagen::valor_pixel(int fila, int col){
    byte pixel;
    pixel = img[fila][col];
    return pixel;
}

// _____________________________________________________________________________

Imagen& Imagen::operator =(const Imagen& orig){
    if(this != &orig){
        liberarMemoria();
        Imagen(orig.filas, orig.cols);
    }
    return *this;
}

// _____________________________________________________________________________

// Icono
void Imagen::icono(unsigned char *fichE, const char *fichS, const int &nf, const int &nc){
  // Paso de unsigned char * a unsigned char **
  unsigned char *imagenOriginal=fichE;
  this->vectorAMatriz(imagenOriginal);

  int coeficienteF=filas/nf, coeficienteC=cols/nc, restoCols=cols%nc, restofils=filas%nf;
  int suma=0, contRes, desplazamiento, inicio;

  Imagen imagenAux(filas, nc),
         icono(nf, nc);

  // Cálculo por columnas
  for(int i=0; i<filas; i++){
      contRes=0;
    for(int j=0; j<nc; j++){
        desplazamiento=coeficienteC;
      if(j<restoCols){
        desplazamiento+=1;
      }
      inicio=j*coeficienteC+contRes;

      for(int k=inicio; k<inicio+desplazamiento; k++){
        suma+=this->valor_pixel(i, k);
      }

      if(j<restoCols){
        contRes+=1;
      }

      imagenAux.asigna_pixel(i, j, suma/desplazamiento + 0.5);
      suma=0;
    }
  }

  // Cálculo por filas
  for(int i=0; i<nc; i++){
      contRes=0;
    for(int j=0; j<nf; j++){
        desplazamiento=coeficienteF;
      if(j<restofils){
        desplazamiento+=1;
      }

      inicio=j*coeficienteF+contRes;

      for(int k=inicio; k<inicio+desplazamiento; k++){
        suma+=imagenAux.valor_pixel(k, i);
      }

      if(j<restofils){
        contRes++;
      }

      icono.asigna_pixel(j, i, suma/desplazamiento + 0.5);
      suma=0;
    }
  }

  // Paso de unsigned char ** a unsigned char *
  unsigned char *salidaAux=new unsigned char[nf*nc];
  icono.matrizAVector(salidaAux);

  // Guardar la imagen resultado en el fichero
  if (EscribirImagenPGM (fichS, salidaAux, nf, nc))
    cout  << "El icono se guardó en " << fichS << endl;
  else{
    cerr << "Error: No pudo guardarse la imagen." << endl;
    cerr << "Terminando la ejecucion del programa." << endl;
    exit (2);
  }
}

// _____________________________________________________________________________

// Contraste
void Imagen::contraste(unsigned char *fichE, const char* fichS, int min, int max){
    // Paso de unsigned char * a unsigned char **
    unsigned char *imagenOriginal=fichE;
    this->vectorAMatriz(imagenOriginal);

    //Max > mayor valor de luminosidad
    //Min < menor valor de luminosidad
    int a, b;
    a = 255;
    b = 0;

    // Cálculo de min y max de la imagen
    for ( int i = 0; i<filas; i++ ){
        for(int j=0; j<cols; j++){
            if(img[i][j]< a)
                a = img[i][j];

            if(img[i][j] > b)
                b = img[i][j];
        }
    }

    int coeficiente = (max-min)/(b-a);
    int z;

    // Nuevo valor para el contraste
    for (int i=0; i<filas; i++){
        for(int j=0; j<cols; j++){
            z = min + coeficiente * (img[i][j] - a) + 0.5;
            img[i][j] = z;
        }
    }

    // Paso de unsigned char ** a unsigned char *
    unsigned char *salidaAux=new unsigned char[filas*cols];
    this->matrizAVector(salidaAux);

    if (EscribirImagenPGM (fichS, salidaAux, filas, cols))
      cout  << "La imagen con contraste se guardó en " << fichS << endl;
    else{
      cerr << "Error: No pudo guardarse la imagen." << endl;
      cerr << "Terminando la ejecucion del programa." << endl;
      exit (2);
    }
}

// _____________________________________________________________________________

// Umbralización

// Media
double Imagen::media(){
    double sum = 0;
    int ncasos = filas*cols;
    for(int i = 0; i < filas;i++)
        for(int j = 0; j < cols;j++)
            sum+=img[i][j];
    return (sum/ncasos);
}

// Cálculo del umbral
byte Imagen::calculaUmbral(){
const double conver = 0.1;
    double T = 0,
           T_old = 0;
    double media1 = 0,
           media2 = 0;
    int nelem1 = 0,
        nelem2 = 0;

    T = this->media();

    while(abs(T-T_old) >= conver){
        nelem1 = nelem2 = media1 = media2 = 0;

        for(int i = 0; i < filas;i++)
            for(int j = 0; j < cols;j++)
                if(img[i][j] >= T){
                    nelem1++;            // Contador de elementos mayores T
                    media1 += img[i][j]; // Media(por ahora sumatoria) de la parte mayor que T
                }else{
                    nelem2++;
                    media2 += img[i][j];
                }

        media1 =media1 / nelem1; // Calcula la media de los píxeles de la zona mas alta
        media2 =media2 / nelem2; // Calcula la media de los píxeles de la zona mas baja

        T_old = T;               // Actualizamos los valores
        T = (media1 + media2)/2;
    }
    return ((byte) T);
}

// Función de la Umbralización
void Imagen::Umbralizar(unsigned char *fichE, const char* fichS){
  // Paso de unsigned char * a unsigned char **
  unsigned char *imagenOriginal=fichE;
  this->vectorAMatriz(imagenOriginal);

    byte T = this->calculaUmbral();
    for(int i = 0; i < filas;i++){
        for(int j = 0; j < cols;j++){
            if(img[i][j] <= T)
                img[i][j] = 0;
            else
                img[i][j] = 255;
        }
    }

    // Paso de unsigned char ** a unsigned char *
    unsigned char *salidaAux=new unsigned char[filas*cols];
    this->matrizAVector(salidaAux);

    if (EscribirImagenPGM (fichS, salidaAux, filas, cols))
      cout  << "La imagen umbralizada se guardó en " << fichS << endl;
    else{
      cerr << "Error: No pudo guardarse la imagen." << endl;
      cerr << "Terminando la ejecucion del programa." << endl;
      exit (2);
    }
}
