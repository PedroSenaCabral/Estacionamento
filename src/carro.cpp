/**
 * @file    carro.cpp
 * @author  Grupo LP 1
 * @brief   Implementação da classe 'carro' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "carro.h"
#include <string>
#include <iostream>

<<<<<<< HEAD
=======

>>>>>>> ebb3c75df813a328a449d740b71c06cbaf7e470d
/*
Se inicializa um Carro sem passar as informações, supomos que seja apenas uma carcaça de um carro
e inicializamos os valores padrões. :)

-1 significa NÃO DEFINIDO
*/


/** Consturtor padrão */
Carro::Carro(): Veiculo("Nao definido", "Nao definido", "OOO-0000", -1, -1, -1) { 
  this->m_combustivel = -1;
  this->m_volumePortaMalas = -1;
}

/** Construtor parametrizado. */
Carro::Carro(string cor, string modelo, string placa, int rodas, int ano, int maxPassageiros, double combustivel_, double volumePortaMalas_):
	Veiculo(cor, modelo, placa, rodas, ano, maxPassageiros), m_combustivel(combustivel_), m_volumePortaMalas(volumePortaMalas_){}

/** Destrutor */ 
Carro::~Carro(){}

/** Getters */

/**
 * @brief      Método get que retorna a capacidade do tanque de combustivel.
 *
 * @return     Variavél do tipo double com a capacidade do tanque.
 */
double Carro::getCombustivel(){ return this->m_combustivel; }

/**
 * @brief      Método get que retorna o volume do porta malas.
 *
 * @return     Variavél do tipo double com o volume do porta malas.
 */
double Carro::getVolumePortaMalas(){ return this->m_volumePortaMalas; }

/**
 * @brief      Implementacao do metodo virtual da classe base 'getConsumoPorKM'.
 *
 * @return     Consumo de combustivel do carro.
 */
double Carro::getConsumoPorKM(){ return 5.0; }

/**
 * @brief      Método get que retorna o tipo do Veículo que será util na tabela de preços.
 *
 * @return     Variavél do tipo string com a tipo definido para "Carro".
 */
string Carro::getTipo(){ return "Carro"; }

/** Setters */


/**
 * @brief      Método que modifica a capacidade do tanque de combustivel.
 *
 * @param  quantidade  Variável do tipo double que terá o novo valor do tanque.
 */
void Carro::setCombustivel(double quantidade){ this->m_combustivel = quantidade; }

/**
 * @brief      Método que modifica a capacidade do porta malas.
 *
 * @param  volume  Variável do tipo double que terá o novo volume do porta malas.
 */
void Carro::setVolumePortaMalas(double volume){ this->m_volumePortaMalas = volume; }

/**
 * @brief      Implementação do metodo virtual da classe base 'print'.
 *
 * @param      ct    Stream de saída com os dados do Carro formatados.
 */
void Carro::print(ostream& ct)
{
    ct  << "Cor: " << this->m_cor << std::endl
        << "Modelo: " << this->m_modelo << std::endl
        << "Placa: " << this->m_placa << std::endl
        << "Numero de rodas: " << this->m_rodas << std::endl
        << "Ano: " << this->m_ano << std::endl
        << "Max Passageiros: " << this->m_maxPassageiros << std::endl
        << "Combustivel: " << this->m_combustivel << std::endl
        << "Volume do porta malas: " << this->m_volumePortaMalas << std::endl
        << "Consumo Km/l : " << this->getConsumoPorKM()<< std::endl;
}

/**
 * @brief      Método para ler os dados do Carro.
 *
 * @param      cin   Stream de entrada para guardar os dados do Carro.
 */
void Carro::put(std::istream& cin){
	std::cout<< "Entrada de Veículo - Carro" << std::endl 
		<< "Por favor, inserir as informções na seguinte ordem:" << std::endl 
        << "Cor, Modelo, Placa, Num Rodas, Ano, Max Passageiros, Combustivel, Volume do Porta Malas." << std::endl;
    cin >> this->m_cor >> this->m_modelo >> this->m_placa >> this->m_rodas >> this->m_ano >> this->m_maxPassageiros >> this->m_combustivel >> this->m_volumePortaMalas;
}

/**
 * @brief      Prepara a linha para o arquivo CSV
 *
 * @return     Os dados do Carro formatados e separados por ponto e virgula.
 */
string Carro::toLinhaCsv(){
  return this->m_placa + ";" + this->getTipo() + ";" + this->m_cor + ";" + this->m_modelo + ";" + to_string(this->m_rodas)  + ";" + to_string(this->m_ano) + ";" + to_string(this->m_maxPassageiros) + ";" + to_string(this->m_combustivel)  + ";" + to_string(this->m_volumePortaMalas);
}

ostream& operator<< (ostream& ostr, Carro& c)
{
    c.print(ostr);
    return ostr;
}

istream& operator>> (istream& istr, Carro& c)
{
	c.put(istr);
	return istr;
}


