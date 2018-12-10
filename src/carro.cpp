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
Carro::Carro(): Veiculo("Nao definido", "Nao definido", "OOO-0000", -1, -1, -1) { 
  this->m_combustivel = -1;
  this->m_volumePortaMalas = -1;
}

Carro::Carro(string cor, string modelo, string placa, int rodas, int ano, int maxPassageiros, double combustivel_, double volumePorlaMalas_):
	Veiculo(cor, modelo, placa, rodas, ano, maxPassageiros), m_combustivel(combustivel_), m_volumePortaMalas(volumePorlaMalas_){}

Carro::~Carro(){}

double Carro::getCombustivel()
{
	return this->m_combustivel;
}

double Carro::getVolumePortaMalas(){
	return this->m_volumePortaMalas;
}

double Carro::getConsumoPorKM()
{
	return 5.0;
}

string Carro::getTipo(){
    return "Carro";
}

void Carro::setCombustivel(double quantidade)
{
	this->m_combustivel = quantidade;
}

void Carro::setVolumePortaMalas(double volume){
	this->m_volumePortaMalas = volume;
}

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

void Carro::put(std::istream& cin){
	std::cout<< "Entrada de Veículo - Carro" << std::endl 
		<< "Por favor, inserir as informções na seguinte ordem:" << std::endl 
        << "Cor, Modelo, Placa, Num Rodas, Ano, Max Passageiros, Combustivel, Volume do Porta Malas." << std::endl;
    cin >> this->m_cor >> this->m_modelo >> this->m_placa >> this->m_rodas >> this->m_ano >> this->m_maxPassageiros >> this->m_combustivel >> this->m_volumePortaMalas;
}

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


