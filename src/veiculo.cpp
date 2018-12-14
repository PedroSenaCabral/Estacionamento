/**
 * @file    veiculo.cpp
 * @author  Grupo LP 1
 * @brief   Implementação da classe abstrata 'veiculo' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "veiculo.h"


/** Construtores */
Veiculo::Veiculo(){}

/** Construtor parametrizado */
Veiculo::Veiculo(std::string cor, std::string modelo, std::string placa, int rodas, int ano, int maxPassageiros) : m_cor(cor),
            m_modelo(modelo), m_placa(placa),m_rodas(rodas), m_ano(ano), m_maxPassageiros(maxPassageiros),m_valido(true) {}

/** Destrutor */
Veiculo::~Veiculo(){}

/** Getters */ 

/**
 * @brief      Método get que retorna a cor do veículo.
 *
 * @return     Variavél do tipo string com a cor do veículo.
 */
string Veiculo::getCor()            { return this->m_cor; }

/**
 * @brief      Método get que retorna o modelo do veículo.
 *
 * @return     Variavél do tipo string com o modelo do veículo.
 */
string Veiculo::getModelo()         { return this->m_modelo; }

/**
 * @brief      Método get que retorna a placa do veículo.
 *
 * @return     Variavél do tipo string com a placa do veículo.
 */
string Veiculo::getPlaca()          { return this->m_placa; }

/**
 * @brief      Método get que retorna a quantidade de rodas do veículo.
 *
 * @return     Variavél do tipo int com a quantidade de rodas do veículo.
 */
int    Veiculo::getRodas()          { return this->m_rodas; }

/**
 * @brief      Método get que retorna o ano de fabricação do veículo.
 *
 * @return     Variavél do tipo int com o ano de fabricação do veículo.
 */
int    Veiculo::getAno()            { return this->m_ano; }


/**
 * @brief      Método get que retorna a quantidade máxima de passageiros do veículo.
 *
 * @return     Variavél do tipo int com a quantidade máxima de passageiros do veículo.
 */
int    Veiculo::getMaxPassageiros() { return this->m_maxPassageiros; }


bool Veiculo::getValido(){ return this->m_valido;}
/* Setters */


/**
 * @brief      Método que modifica o valor da cor do veículo.
 *
 * @param  cor  Variável do tipo string que terá a nova cor.
 */
void Veiculo::setCor(std::string cor)               { this->m_cor = cor; }

/**
 * @brief      Método que modifica o valor do modelo do veículo.
 *
 * @param  modelo  Variável do tipo string que terá o novo modelo.
 */
void Veiculo::setModelo(std::string modelo)         { this->m_modelo = modelo; }

/**
 * @brief      		Método que modifica o valor placa do veículo.
 *
 * @param  placa  	Variável do tipo string que terá a nova placa.
 */
void Veiculo::setPlaca(std::string placa)           { this->m_placa = placa; }

/**
 * @brief      	Método que modifica o ano de fabricação do veículo.
 *
 * @param  ano  Variável do tipo int que terá o novo ano de fabricação.
 */
void Veiculo::setAno(int ano)                       { this->m_ano = ano; }

/**
 * @brief      			Método que modifica o valor da quantidade de rodas do veículo.
 *
 * @param  quantidade  	Variável do tipo int que terá a nova quantidade de rodas.
 */
void Veiculo::setRodas(int quantidade)              { this->m_rodas = quantidade; }

/**
 * @brief      				Método que modifica o valor quantidade maxima de passageiros do veículo.
 *
 * @param  maxPassageiros  	Variável do tipo int que terá a quantidade de passageiros.
 */
void Veiculo::setMaxPassageiros(int maxPassageiros) { this->m_maxPassageiros = maxPassageiros; }

/**
 * @brief 		Sobrecarga do operador de inserção
 *
 * @param      	ostr  Stream de saida
 * @param      	v     Objeto do tipo Veiculo
 *
 * @return     	Retorna o objeto formatado
 */
ostream& operator<< (ostream& ostr, Veiculo& v)
{
    v.print(ostr);
    return ostr;
}

/**
 * @brief      Sobrecarga do operador de extração
 *
 * @param      istr  Stream de entrada
 * @param      v     Objeto do tipo Veiculo
 *
 * @return     Salva o objeto
 */
istream& operator>> (istream& istr, Veiculo& v)
{
	v.put(istr);
	return istr;
}