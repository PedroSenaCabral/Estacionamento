/**
 * @file    veiculo.cpp
 * @brief   Implementação da classe abstrata Veículo em C++
 * @author  Dennis Ferreira, Mateus Brito e Lucas Lucena
 * @since   06/12/2018
 * @date    07/12/2018
 * @sa      SIGAA
 */

#include "veiculo.h"
using namespace std;

/* Construtores */
Veiculo::Veiculo(){}

Veiculo::Veiculo(std::string cor, std::string modelo, std::string placa, std::string tipo, int rodas, int ano, int maxPassageiros) : cor(cor),
            modelo(modelo), placa(placa), tipo(tipo), rodas(rodas), ano(ano), maxPassageiros(maxPassageiros) {}

/* Destrutor */
Veiculo::~Veiculo(){}

/* Getters */ 
string Veiculo::getCor()            { return this->cor; }
string Veiculo::getModelo()         { return this->modelo; }
string Veiculo::getPlaca()          { return this->placa; } 
string Veiculo::getTipo()           { return this->tipo; }
int    Veiculo::getRodas()          { return this->rodas; }
int    Veiculo::getAno()            { return this->ano; }
int    Veiculo::getMaxPassageiros() { return this->maxPassageiros; }

/* Setters */
void Veiculo::setCor(std::string cor)               { this->cor = cor; }
void Veiculo::setModelo(std::string modelo)         { this->modelo = modelo; }
void Veiculo::setPlaca(std::string placa)           { this->placa = placa; }
void Veiculo::setTipo(std::string tipo)             { this->tipo = tipo; }
void Veiculo::setAno(int ano)                       { this->ano = ano; }
void Veiculo::setRodas(int quantidade)              { this->rodas = quantidade; }
void Veiculo::setMaxPassageiros(int maxPassageiros) { this->maxPassageiros = maxPassageiros; }

/* Método Print */
ostream& operator<< (ostream& ostr, Veiculo* v)
{
    v->print(ostr);
    return ostr;
}
