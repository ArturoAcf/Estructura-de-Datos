/**
  *@file Objeto elemento que representa el contenido de cada una de las celdas de las pilas con máximo
  */

#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <iostream>

struct elemento {
    int ele;
    int maximo;

    friend std::ostream& operator<<(std::ostream &salida, const elemento &e){
        salida << "( "<< e.ele << ", " << e.maximo << " )";
        return salida;
    };
};

#endif
