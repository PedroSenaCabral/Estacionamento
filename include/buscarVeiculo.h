/**
 * @file    buscarVeiculo.h
 * @author  Grupo LP 1
 * @brief   Definição da classe 'buscarVeiculo' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef BUSCAR_VEICULO
#define BUSCAR_VEICULO

#include <string>
#include "veiculo.h"

class BuscarVeiculo {

private:

	/** Variável 'placa' usada na busca por um Veículo. */
	string placa;

public:
	
	/**
	 * @brief      			Construtor parametrizado
	 *
	 * @param  buscarPlaca  Placa a ser buscada.
	 */
	BuscarVeiculo(string buscarPlaca) : placa (buscarPlaca) {}
	
	/** Sobrecarga do operador de comparação */
	bool operator()(pair<string, Veiculo*> aux) const {
		
		return (placa.compare(aux.second->getPlaca()) == 0); 
	}

};

#endif