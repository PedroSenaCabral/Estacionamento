/**
 * @file    ocorrencia.h
 * @author  Grupo LP 1
 * @brief   Definição da classe 'ocorrencia' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef _OCORRENCIA_H_
#define _OCORRENCIA_H_

#include <string>
#include <vector>
#include <map>

#include "diahora.h"
#include "veiculo.h"
#include "tabela.h"

class Ocorrencia 
{
private:
	/** Variável do tipo DiaHora para salvar o tempo gasto no estacionamento. */
	DiaHora m_tempo;

	/** Total pago no estacionamento. */
	int m_totalPago;

	/** Tipo da ocorrencia: Entrada ou saida de Veiculo. */
	string m_tipo;

	/** Veiculo relacionado à Ocorrência. */
	Veiculo* m_veiculo;

	/** metodo privado auxiliar auxiliar para separar as informações da ocorrencia para o arquivo csv */
	vector<string> splitString(string& linha, char delimitador);

public:
	
	/**
	 * @brief      			Contrutor parametrizado.
	 *
	 * @param   veiculo_  	Veiculo relacionado à Ocorrência.
	 * @param  	tipo_     	Tipo da ocorrência que por padrão é "Entrada".
	 */
	Ocorrencia(Veiculo* veiculo_, string tipo_ = "Entrada");


	/**
	 * @brief      			Método para reconstruir a ocorrencia através do .CSV
	 *
	 * @param  linhaCsv   	A linha do arquivo .CSV
	 * @param  veiculos_  	Map para salvar os veiculos
	 */
	Ocorrencia(string linhaCsv, map<string, Veiculo*> veiculos_);
	
	/** Destrutor */
	~Ocorrencia();

	/** Getters */
	DiaHora& 	getTempo();
	double 		getTotalPago();
	string 		getTipo();
	Veiculo* 	getVeiculo();
	string 		getLinhaCsv();

	/** Setters */ 
	void setVeiculo(Veiculo* veic);


	double calcularCusto(DiaHora &entrada, Tabela &tab);
	
	/** Sobrecarga de operadores */
	friend ostream &operator<<(ostream &os, Ocorrencia &dt);
};

#endif
