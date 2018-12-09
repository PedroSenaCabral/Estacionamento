# Linguagem de Programação 1


CC = g++
PROG = $(BIN)/estacionamento

OBJ = ./build
SRC = ./src
BIN = ./bin
INC = ./include

CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)

OBJS = $(OBJ)/veiculo.o $(OBJ)/carro.o $(OBJ)/caminhao.o $(OBJ)/moto.o $(OBJ)/tabela.o $(OBJ)/ocorrencia.o $(OBJ)/main.o

all: $(PROG)
	$(PROG)

$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

$(OBJ)/veiculo.o: $(INC)/veiculo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/veiculo.cpp -o $(OBJ)/veiculo.o

$(OBJ)/carro.o: $(INC)/carro.h
	$(CC) $(CPPFLAGS) -c $(SRC)/carro.cpp -o $(OBJ)/carro.o

$(OBJ)/caminhao.o: $(INC)/caminhao.h
	$(CC) $(CPPFLAGS) -c $(SRC)/caminhao.cpp -o $(OBJ)/caminhao.o

$(OBJ)/moto.o: $(INC)/moto.h
	$(CC) $(CPPFLAGS) -c $(SRC)/moto.cpp -o $(OBJ)/moto.o

$(OBJ)/tabela.o: $(INC)/tabela.h
	$(CC) $(CPPFLAGS) -c $(SRC)/tabela.cpp -o $(OBJ)/tabela.o

$(OBJ)/ocorrencia.o: $(INC)/ocorrencia.h
	$(CC) $(CPPFLAGS) -c $(SRC)/ocorrencia.cpp -o $(OBJ)/ocorrencia.o

$(OBJ)/main.o: $(SRC)/main.cpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o

clean: 
	rm -f $(BIN)/*
	rm -f $(OBJ)/*