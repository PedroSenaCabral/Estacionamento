#ifndef _OCORRENCIA_H_
#define _OCORRENCIA_H_

#include <string>

#include "veiculo.h"
#include "tabela.h"

class Ocorrencia 
{
private:

	int horaEntrada;
	int minEntrada;
	int horaSaida;
	int minSaida;
	int dias;  //caso o veiculo tenha passado mais de um dia no estacionamento.

	int custo; 
	std::string tipoVeiculo; //se é carro, moto ou caminhão.

public:
	
	void printOcorrencia();
	
	void calcularCusto ();

	std::string getTipoVeiculo();
	int getHoraEntrada ();
	int getHoraSaida ();
	int getMinEntrada ();
	int getMinSaida ();
	int getDias ();
	int getCusto ();
	
	Ocorrencia (int, int, int, int, int, Veiculo &automovel); 

};

#endif
