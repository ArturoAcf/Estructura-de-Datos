SRC = src
INC = include
OBJ = obj
BIN = bin

CXX = g++ -fpermissive
CPPFLAGS = -Wall -g -c -I$(INC)

all: $(BIN)/usopilas_max

documentacion:
	doxygen doc/doxys/Doxyfile

$(BIN)/usopilas_max: $(OBJ)/usopilas_max.o $(OBJ)/Pila_max_VD.o $(OBJ)/Pila_max_Cola.o
	$(CXX) $(OBJ)/usopilas_max.o -o $(BIN)/usopilas_max

# *************************  CREACIÓN DE OBJETOS  **************************

$(OBJ)/Pila_max_Cola.o: $(SRC)/Pila_max_Cola.cpp $(INC)/cola.h $(INC)/Pila_max_Cola.h $(INC)/elemento.h
	$(CXX) $(CPPFLAGS) $(SRC)/Pila_max_Cola.cpp -o $(OBJ)/Pila_max_Cola.o

$(OBJ)/Pila_max_VD.o: $(SRC)/Pila_max_VD.cpp $(INC)/Pila_max_VD.h $(INC)/elemento.h
	$(CXX) $(CPPFLAGS) $(SRC)/Pila_max_VD.cpp -o $(OBJ)/Pila_max_VD.o

$(OBJ)/usopilas_max.o: $(SRC)/usopilas_max.cpp $(INC)/Pila_max_VD.h $(INC)/Pila_max_Cola.h $(INC)/cola.h $(INC)/elemento.h
	$(CXX) $(CPPFLAGS) $(SRC)/usopilas_max.cpp -o $(OBJ)/usopilas_max.o

# *******************************  LIMPIEZA  ********************************

clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
