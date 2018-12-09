#include "carro.h"
#include <string>
#include <iostream>

/*
Se inicializa um Carro sem passar as informações, supomos que seja apenas uma carcaça de um carro
e inicializamos os valores padrões. :)

-1 significa NÃO DEFINIDO
*/

/**
 * @file carro.cpp
 * @author Mateus e Franklin
 * @brief Implementação da classe Carro para o Projeto de LP I
 * @version 0.1
 * @date 12-07-2018
 * 
 * @copyright Copyright (c) 2018
 * 
 */
Carro::Carro() {
	this->m_cor = "preto";
    this->m_modelo = "Não definido";
    this->m_rodas = 0;
    this->m_ano = -1;
    this->m_maxPassageiros = 0;
    this->m_combustivel = -1;
}

Carro::Carro(std::string cor, std::string modelo, int rodas, int ano, int maxPassageiros) 
{
	this->m_combustivel = -1; 
	this->m_cor = cor;
	this->m_modelo = modelo;
	this->m_rodas = rodas;
	this->m_ano = ano;
	this->m_maxPassageiros = maxPassageiros;
}

Carro::~Carro(){}

double Carro::getCombustivel()
{
	return this->m_combustivel;
}

double Carro::getConsumoPorKM()
{
	return 5.0;
}

void Carro::setCombustivel(double quantidade)
{
	this->m_combustivel = quantidade;
}

void Carro::print(std::ostream& ostr)
{
	ostr << "Cor: " << this->m_cor << std::endl
			<< "Modelo: " << this->m_modelo << std::endl
			<< "Número de rodas: " << this->m_rodas << std::endl
			<< "Ano: " << this->m_ano << std::endl
			<< "Máx Passageiros: " << this->m_maxPassageiros << std::endl
			<< "Combustivel: " << this->m_combustivel<<"L";
}



void Carro::put(std::istream& cin){
	std::cout<< "Entrada de Veículo - Carro" << std::endl 
		<< "Por favor, inserir as informções na seguinte ordem:" << std::endl 
        << "Cor, Modelo, Placa, Num Rodas, Ano, Máx Passageiros, Combustivel." << std::endl;
    cin >> this->m_cor >> this->m_modelo >> this->m_placa >> this->m_rodas >> this->m_ano >> this->m_maxPassageiros >> this->m_combustivel;
}


