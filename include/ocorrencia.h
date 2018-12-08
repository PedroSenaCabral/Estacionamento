#ifndef _OCORRENCIA_H_
#define _OCORRENCIA_H_

#include <string>

#include "veiculo.h"
#include "tabela.h"

class Ocorrencia 
{
private:

	int m_horaEntrada;
	int m_minEntrada;
	int m_horaSaida;
	int m_minSaida;
	int m_dias;  //caso o veiculo tenha passado mais de um dia no estacionamento.

	int m_custo; 
	std::string m_tipoVeiculo; //se é carro, moto ou caminhão.

	Tabela tabela;

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
	
	Ocorrencia (int, int, int, int, int, Veiculo &automovel_); 

};

#endif
