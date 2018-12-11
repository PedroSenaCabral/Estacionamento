/**
 *
 * @mainpage Estacionamento
 * @file    main.cpp
 * @author  Grupo LP 1
 * @brief   Implementação da 'MAIN' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 *
 * @copyright Copyright (c) 2018
 * 
 */

#include "estacionamento.h"

using namespace std;


int main(int argc, char const *argv[])
{

	Estacionamento parking(50, "files/logVeiculos.csv", "files/logOcorrencias.csv");

	parking.iniciarOperacao();

	return 0;

}