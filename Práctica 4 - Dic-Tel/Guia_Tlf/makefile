SRC = src
INC = include
OBJ = obj
BIN = bin

CXX = g++ -fpermissive
CPPFLAGS = -Wall -g -c -I$(INC)

all: $(BIN)/usoguia

$(BIN)/usoguia: $(OBJ)/usoguia.o $(OBJ)/Guia_Tlf.o
	$(CXX) $(OBJ)/usoguia.o -o $(BIN)/usoguia

# *************************  CREACIÓN DE OBJETOS  **************************

$(OBJ)/Guia_Tlf.o: $(SRC)/Guia_Tlf.cpp $(INC)/Guia_Tlf.h
	$(CXX) $(CPPFLAGS) $(SRC)/Guia_Tlf.cpp -o $(OBJ)/Guia_Tlf.o

$(OBJ)/usoguia.o: $(SRC)/usoguia.cpp $(INC)/Guia_Tlf.h
	$(CXX) $(CPPFLAGS) $(SRC)/usoguia.cpp -o $(OBJ)/usoguia.o

# *******************************  LIMPIEZA  ********************************

clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
