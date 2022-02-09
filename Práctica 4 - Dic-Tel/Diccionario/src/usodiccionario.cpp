// Realizado por Arturo Alonso Carbonero
// Grupo -> 2ºC - C1
// NOTA -> Con el material proporcionado ocurre una violación de segmento que
//         no he podido solucionar por lo que el main no es funcional.
//         En ocasiones muestra ese error y en ocasiones muestra espacios en blanco de forma infinita.
//         Desconozco si el error es del material o de mi ordenador, pero tras mostrar el diccionario, falla.
//         El caso es que no está relacionado con mis métodos, ya que sucedió antes de definirlos.
//         Todo ello antes de crear los iteradores.
//         Si no he averiguado mal, el fallo está en el operador <<.
// NOTA -> Por su parte, la guía funciona correctamente.
// NOTA -> Los ficheros de entrada con los diccioarios de tipo txt están en bin.

/**
  *@file Fichero que contiene la función princiapl "main" del programa
  *
  *@note Ejecución -> ./usodiccionario < nombrefich.txt, siendo usodiccionario el ejecutable en ../bin
  */

#include <iostream>
#include "../include/Diccionario.h"
#include <list>
#include <cstring>

/*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre
listas de listas y otro sobre listas
*/
ostream & operator<<(ostream & os, const Diccionario<string,string> & D){

	  list<data<string,string> >::const_iterator it;

	  for (it=D.begin(); it!=D.end(); ++it){

		    list<string>::const_iterator it_s;

		    os<<endl<<(*it).clave<<endl<<" informacion asociada:"<<endl;
		    for (it_s=(*it).info_asoci.begin();it_s!=(*it).info_asoci.end();++it_s){
			      os<<(*it_s)<<endl;
		    }
		    os<<"**************************************"<<endl;
	  }

	  return os;
}

/*Operator >>. El formato de la entrada es:
     numero de claves en la primera linea
     clave-iésima retorno de carro
     numero de informaciones asociadas en la siguiente linea
     y en cada linea obviamente la informacion asociada
*/

istream & operator >>(istream & is,Diccionario<string,string> &D){
	  int np;
	  is>>np;
	  is.ignore();//quitamos \n
	  Diccionario<string,string> Daux;
	  for (int i=0;i<np; i++){
		    string clave;

		    getline(is,clave);

		    int ns;
		    is>>ns;
		    is.ignore();//quitamos \n
		    list<string>laux;
		    for (int j=0;j<ns; j++){
			      string s;
			      getline(is,s);

			      // cout<<"Significado leido "<<s<<endl;
			      laux.insert(laux.end(),s);
		    }
		    Daux.Insertar(clave,laux);

	  }
	  D=Daux;
	  return is;
}

/*Recorre la lista de información asociada a una clave y la imprime*/
void EscribeSigni(const list<string>&l){
	  list<string>::const_iterator it_s;

	  for (it_s=l.begin();it_s!=l.end();++it_s){
		    cout<<*it_s<<endl;
	  }
}


/*Lee un diccioario e imprime datos asociados a una clave.
Hay un fichero ejemplo de prueba: data.txt.Para lanzar el programa con ese fichero se escribe:
                  ./usodiccionario < data.txt
*/
int main(){
 Diccionario<string,string> D;

cin>>D;
cout<<D;

// No he llamado a los métodos añadidos, ya que tras hacer cout<<D; nada sucede.
// Igualmente el main quedaría similar al de la guia, el cual funciona correctamente.

}
