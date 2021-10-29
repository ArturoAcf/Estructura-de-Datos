// Realizado por: Arturo Alonso Carbonero y José Luis Molina Aguilar
// Grupo: 2ºC - C1
// Práctica 2. Abstracción - TDA imagen

/**
  *@file Fichero cabecera de la clase Imagen
  *@brief Declaración de las propiedades de la clase Imagen
  */

#ifndef _IMAGEN_H_
#define _IMAGEN_H_

typedef unsigned char byte; // Tipo de los píxeles de una imagen

class Imagen{
private:
  /**
    *@page repMatriz2D Rep del TDA Imagen
    *
    *@section invMatriz2D Invariante de la representación
    *
    *El invariantes es filas!=0 y cols!=0
    *
    *@section faMatriz2D Función de abstracción
    *
    *Un objeto válido rep del TDA Imagen representa
    *
    *img[filas][cols]
    */
  int filas;  // Número de filas de la Imagen
  int cols;   // Número de columnas de la Imagen
  byte **img; // Mátriz de píxeles que representa una Imagen
public:
  /**
    *@brief Constructor por defecto de la clase Imagen
    *
    *@note Crea un objeto de la clase Imagen vacío
    */
  Imagen();

  /**
    *@brief Constructor de copia de la clase Imagen
    *
    *@param Recibe un objeto de la clase Imagen
    *@note Copia en un objeto de la clase Imgane, el objeto que recibe
    */
  Imagen(const Imagen& otro);

  /**
    *@brief Sobrecarga del operador de asignación de la clase imagen
    *
    *@param "orig" indica una referencia a un objeto de la clas Imagen
    *@note permite asignar un objeto de la clase Imagen a otro de forma directa
    */
  Imagen& operator =(const Imagen& orig);

  /**
    *@brief Constructor con parámetros de la clase Imagen que reserva memoria para filas x cols píxeles
    *
    *@param "filas" indica la cantidad de filas del objeto de la clase Imagen que se crea
    *@param "cols" indica la cantidad de columnas del objeto de la clase Imagen que se crea
    *@note El objeto no está inicializado
    */
  Imagen(int filas, int cols);

  /**
  *@brief Método que llamará el constructor con parámetros
  *
  *@param "filas" indica la cantidad de filas del objeto de la clase Imagen que se crea
  *@param "cols" indica la cantidad de columnas del objeto de la clase Imagen que se crea
  */
  void reservarMemoria(int filas, int cols);

  /**
  *@brief Método que llamará el destructor de la clase Imagen
  *
  *@note Libera la memoria que tenía reservada el objeto correspondiente
  */
  void liberarMemoria();

  /**
    *@brief Destructor de la clase Imagen
    *
    *@note Libera el espacio reservado por los objetos
    *@note El objeto eliminado deja de ser utilizable
    */
  ~Imagen();

  /**
    *@brief Calcula y devuelve el número de filas de una Imagen
    *
    *@return Entero que indica el número de filas de una Imagen
    *@note La Imagen no se modifica
    */
  int num_filas() const; // get de las filas

  /**
    *@brief Calcula y devuelve el número de columnas de una Imagen
    *
    *@return Entero que indica el número de columnas de una Imagen
    *@note La Imagen no se modifica
    */
  int num_columnas() const; // get de las columnas

  /**
    *@brief Asigna el valor "valor" al píxel situado en la posición "filas"x"cols"
    *
    *@param "filas" Indica la fila del píxel a modificar
    *@param "cols" Indica la columna del píxel a modificar
    *@param "valor" Indica el valor que tendrá el píxel
    *@return void
    *@pre 0 <= "filas" < i.num_filas()
    *@pre 0 <= "cols" < i.num_columnas()
    *@pre 0 <= valor <= 255
    *@post El píxel correspondiente a la posición "filas"x"cols" será modificado y el resto se mantienen
    */
  void asigna_pixel(int filas, int cols, byte valor);

  /**
  *@brief Calcula y devuelve el valor de el píxel deseado
  *
  *@param "fila" Indica el valor de la fila del píxel
  *@param "col" Indica el valor de la columna del píxel
  *@return Valor de tipo byte que contiene el valor del píxel situado en la posición fila x col
  */
  byte valor_pixel(int fila, int col);

  /**
    *@brief Consulta el valor del píxel en la posición "filas"x"cols"
    *
    *@param "filas" Indica la fila del píxel a consultar
    *@param "cols" Indica la columna del píxel a consultar
    *@pre 0 <= "filas" < i.num_filas ()
    *@pre 0 <= "cols" < i.num_columnas ()
    *@return Valor del píxel en la posición "filas"x"cols" de tipo byte
    *@note La imagen no se modifica
    */
  byte valor_pixel(int filas, int cols) const; // get del valor de un byte

  /**
    *@brief Método que cambia un objeto de tipo "unsigned char *" a "unsigned char **"
    *
    *@param "im" Array que contendrá los valores "unsigned char **"
    *@note Sirve para poder manejar un objeto de la clase Imagen tras leero y poder aplicar las funciones de "imagenES.h"
    *@return void
    */
  void vectorAMatriz(const unsigned char *im);

  /**
    *@brief Método que cambia un objeto de tipo "unsigned char **" a "unsigned char *"
    *
    *@param "im" Array que contendrá los valores "unsigned char *"
    *@note Sirve para poder manejar un objeto de la clase Imagen tras leero y poder aplicar las funciones de "imagenES.h"
    *@return void
    */
  void matrizAVector(unsigned char *im);

  /**
    *@brief Crea un icono de la imagen leida del tamaño indicado
    *
    *@param "fichE" Fichero de entrada que contiene la imagen a utilizar
    *@param "fichS" Fichero de salida que contendrá el resultado
    *@param "nf" Indica el número de filas que tendrá el icono
    *@param "nc" Indica el número de columnas que tendrá el icono
    *@return void
    *@pre nf < número de filas de la imagen contenida en fichE
    *@pre nc < número de columnas de la imagen contenida en fichE
    *@post Creación de un icono de la imagen contenida en fichE, de tamaño nf x nc, guardado en fichS
    */
  void icono(unsigned char *fichE, const char *fichS, const int &nf, const int &nc);

  /**
    *@brief Crea una copia de la imagen original con contraste
    *
    *@param "fichE" Fichero de entrada que contiene la imagen a utilizar
    *@param "fichS" Fichero de salida que contendrá el resultado
    *@param "min" Indica el mínimo de luminosidad
    *@param "max" Indica el máximo de luminosidad
    *@return void
    *@pre min < mínimo de la imagen original
    *@pre max > máximo de la imagen original
    *@post Copia de la imagen contenida en fichE, con el contraste indicado, guardada en fichS
    */
  void contraste(unsigned char *fichE, const char *fichS, int min, int max);

  /**
    *@brief Calcula el valor de nivel de gris medio
    *
    *@return Valor de tipo Double con el valor medio indicado
    */
  double media();

  /**
    *@brief Calcula el umbral para realizar la Umbralización
    *
    *@return Variable de tipo byte con el valor del umbral correspondiente
    */
  byte calculaUmbral();

  /**
    *@brief Realiza la umbralización final de la imagen
    *
    *@param "fichE" Fichero de entrada que contiene la imagen a utilizar
    *@param "fichS" Fichero de salida que contendrá el resultado
    *@return void
    *@post Copia de la imagen contenida en fichE, umbralizada, en fichS
    */
  void Umbralizar(unsigned char *fichE, const char* fichS);
};

#endif
