# Linguagem de Programação 1


CC = g++
PROG = $(BIN)/estacionamento

OBJ = ./build
SRC = ./src
BIN = ./bin
INC = ./include

CPPFLAGS = -Wall -pedantic -std=c++11 -I$(INC)

OBJS = $(OBJ)/diahora.o $(OBJ)/veiculo.o $(OBJ)/carro.o $(OBJ)/caminhao.o $(OBJ)/moto.o $(OBJ)/tabela.o $(OBJ)/ocorrencia.o $(OBJ)/estacionamento.o $(OBJ)/main.o

all: $(PROG)
	$(PROG)

$(PROG): $(OBJS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJS)

$(OBJ)/veiculo.o: $(SRC)/veiculo.cpp $(INC)/veiculo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/veiculo.cpp -o $(OBJ)/veiculo.o

$(OBJ)/diahora.o: $(SRC)/diahora.cpp $(INC)/diahora.h
	$(CC) $(CPPFLAGS) -c $(SRC)/diahora.cpp -o $(OBJ)/diahora.o

$(OBJ)/carro.o: $(SRC)/carro.cpp $(INC)/carro.h $(INC)/veiculo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/carro.cpp -o $(OBJ)/carro.o

$(OBJ)/caminhao.o: $(SRC)/caminhao.cpp $(INC)/caminhao.h $(INC)/veiculo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/caminhao.cpp -o $(OBJ)/caminhao.o

$(OBJ)/moto.o: $(SRC)/moto.cpp $(INC)/moto.h $(INC)/veiculo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/moto.cpp -o $(OBJ)/moto.o

$(OBJ)/tabela.o: $(SRC)/tabela.cpp $(INC)/tabela.h
	$(CC) $(CPPFLAGS) -c $(SRC)/tabela.cpp -o $(OBJ)/tabela.o

$(OBJ)/ocorrencia.o: $(SRC)/ocorrencia.cpp $(INC)/ocorrencia.h $(INC)/diahora.h $(INC)/tabela.h $(INC)/veiculo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/ocorrencia.cpp -o $(OBJ)/ocorrencia.o

$(OBJ)/estacionamento.o: $(SRC)/estacionamento.cpp $(INC)/estacionamento.h $(INC)/veiculo.h $(INC)/moto.h $(INC)/carro.h $(INC)/caminhao.h $(INC)/ocorrencia.h $(INC)/tabela.h $(INC)/buscarVeiculo.h
	$(CC) $(CPPFLAGS) -c $(SRC)/estacionamento.cpp -o $(OBJ)/estacionamento.o

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/estacionamento.h
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o

clean: 
	rm -f $(BIN)/*
	rm -f $(OBJ)/*

# propriedades para serem usadas ao compilar no windows com o MinGW com gcc e gdb
# não usar o comando Make e sim o executável: mingw32-make.exe

mkdirswin:
	if not exist $(BIN) mkdir "$(BIN)
	if not exist $(OBJ) mkdir "$(OBJ)

runwin: mkdirswin $(PROG)
	chcp 65001
	$(PROG)

cleanwin: 
	del /q "$(BIN)\*
	del /q "$(OBJ)\*