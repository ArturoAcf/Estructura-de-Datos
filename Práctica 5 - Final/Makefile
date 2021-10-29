SRC = src
INC = include
OBJ = obj
BIN = bin
LIB = lib

CXX = g++ -fpermissive
CPPFLAGS = -Wall -g -I$(INC) -c

all: $(BIN)/rutas_aereas

# ******************* GENERACIÓN DEL EJECUTABLE *******************

$(BIN)/rutas_aereas: $(SRC)/rutas_aereas.cpp
	$(CXX) $(SRC)/rutas_aereas.cpp $(SRC)/imagen.cpp $(SRC)/imagenES.cpp $(INC)/Pais.h $(INC)/Paises.h -o $(BIN)/rutas_aereas

# ******************* DOCUMENTACIÓN *******************

documentacion:
	doxygen -g doc/documento

doc : documentacion
	doxygen doc/documento

# ******************* LIMPIEZA *******************

clean :
	-rm $(BIN)/*
