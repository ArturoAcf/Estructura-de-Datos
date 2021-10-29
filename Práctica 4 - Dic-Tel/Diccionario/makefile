SRC = src
INC = include
OBJ = obj
BIN = bin

CXX = g++ -fpermissive
CPPFLAGS = -Wall -g -c -I$(INC)

all: $(BIN)/usodiccionario

$(BIN)/usodiccionario: $(OBJ)/usodiccionario.o $(OBJ)/Diccionario.o
	$(CXX) $(OBJ)/usodiccionario.o -o $(BIN)/usodiccionario

# *************************  CREACIÓN DE OBJETOS  **************************

$(OBJ)/Diccionario.o: $(SRC)/Diccionario.cpp $(INC)/Diccionario.h
	$(CXX) $(CPPFLAGS) $(SRC)/Diccionario.cpp -o $(OBJ)/Diccionario.o

$(OBJ)/usodiccionario.o: $(SRC)/usodiccionario.cpp $(INC)/Diccionario.h
	$(CXX) $(CPPFLAGS) $(SRC)/usodiccionario.cpp -o $(OBJ)/usodiccionario.o

# *******************************  LIMPIEZA  ********************************

clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
