/**
 * @file    veiculo.cpp
 * @brief   Implementação da classe abstrata Veículo em C++
 * @author  Dennis Ferreira, Mateus Brito e Lucas Lucena
 * @since   06/12/2018
 * @date    07/12/2018
 * @sa      SIGAA
 */

#include "veiculo.h"

/* Construtores */
Veiculo::Veiculo(){}

Veiculo::Veiculo(std::string cor, std::string modelo, std::string placa, int rodas, int ano, int maxPassageiros) : m_cor(cor),
            m_modelo(modelo), m_placa(placa),m_rodas(rodas), m_ano(ano), m_maxPassageiros(maxPassageiros) {}

/* Destrutor */
Veiculo::~Veiculo(){}

/* Getters */ 

string Veiculo::getCor()            { return this->m_cor; }
string Veiculo::getModelo()         { return this->m_modelo; }
string Veiculo::getPlaca()          { return this->m_placa; }
string Veiculo::getTipo()           { return "Veiculo"; }
int    Veiculo::getRodas()          { return this->m_rodas; }
int    Veiculo::getAno()            { return this->m_ano; }
int    Veiculo::getMaxPassageiros() { return this->m_maxPassageiros; }


/* Setters */
void Veiculo::setCor(std::string cor)               { this->m_cor = cor; }
void Veiculo::setModelo(std::string modelo)         { this->m_modelo = modelo; }
void Veiculo::setPlaca(std::string placa)           { this->m_placa = placa; }
void Veiculo::setAno(int ano)                       { this->m_ano = ano; }
void Veiculo::setRodas(int quantidade)              { this->m_rodas = quantidade; }
void Veiculo::setMaxPassageiros(int maxPassageiros) { this->m_maxPassageiros = maxPassageiros; }

/* Método Print */
ostream& operator<< (ostream& ostr, Veiculo* v)
{
    v->print(ostr);
    return ostr;
}

istream& operator>> (istream& istr, Veiculo& v)
{
	v.put(istr);
	return istr;
}