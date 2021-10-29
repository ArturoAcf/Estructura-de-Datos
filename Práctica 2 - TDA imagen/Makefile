SRC = src
INC = inc
OBJ = obj
BIN = bin
LIB = lib

CXX = g++ -fpermissive
CPPFLAGS = -Wall -g -c -I$(INC)

all: $(BIN)/main

$(BIN)/main: $(OBJ)/main.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/main.o -l imagen -o $(BIN)/main -Llib

$(BIN)/imagen: $(OBJ)/imagen.o $(LIB)/libimagen.a
	$(CXX) $(OBJ)/imagen.o -l imagen -o $(BIN)/imagen -Llib

# *************************  CREACIÓN DE OBJETOS  **************************

$(OBJ)/imagen.o: $(SRC)/imagen.cpp $(INC)/imagen.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagen.cpp -o $(OBJ)/imagen.o

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/imagen.h $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/main.cpp -o $(OBJ)/main.o

$(OBJ)/imagenES.o: $(INC)/imagenES.h
	$(CXX) $(CPPFLAGS) $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o


# ************************  CREACION DE BIBLIOTECAS  ************************

$(LIB)/libimagen.a: $(OBJ)/imagen.o $(OBJ)/imagenES.o
	ar rvs $(LIB)/libimagen.a $(OBJ)/imagen.o $(OBJ)/imagenES.o

# *******************************  LIMPIEZA  ********************************

clean:
	-rm $(OBJ)/* $(LIB)/*
