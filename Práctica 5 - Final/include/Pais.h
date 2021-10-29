#ifndef __PAIS__
#define __PAIS__
#include "Punto.h"
class Pais{
  private:
    Punto p;
    string pais;
    string bandera;

  public:
    Pais(){}
    Punto GetPunto()const { return p;}
    string GetPais()const{ return pais;}
    string GetBandera()const{ return bandera;}

    bool operator<(const Pais &P)const{
	return pais<P.pais;
    }
    bool operator==(const Pais &otro)const{
        return this->p == otro.p;
    }


    friend istream & operator>>(istream & is, Pais & P){
        double lat,lng;

	is>>lat>>lng>>P.pais>>P.bandera;

	P.p=Punto(lat,lng,"");
	return is;
    }
    friend ostream & operator<<(ostream & os, const Pais &P){
	os<<P.p<<" "<<P.pais<<" "<<P.bandera<<endl;
	return os;
    }
};
#endif
