#include "estacionamento.h"

using namespace std;

/**
 * @file carro.cpp
 * @author Grupo LP 1
 * @brief Implementação da 'MAIN' para o Projeto Final de LP I
 * @version 0.1
 * @date 12-10-2018
 * 
 * @copyright Copyright (c) 2018
 * 
 */
int main(int argc, char const *argv[])
{

	Estacionamento parking(50, "files/logVeiculos.csv", "files/logOcorrencias.csv");

	parking.iniciarOperacao();

	return 0;

}