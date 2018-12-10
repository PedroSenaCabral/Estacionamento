/**
 * @file tabela.cpp
 * @brief Implementação da classe Tabela
 */
#include "tabela.h"


/** Construtor padrão */
Tabela::Tabela():
	m_pCarro(6.0), m_pMoto(4.0), m_pCaminhao(10.0), m_pHora(1.0), m_pDiaria(20.0)
{}

/**
 * @brief Construtor parametrizado
 *
 * @param  _pCarro     Preço do Carro
 * @param  _pMoto      Preço da Moto
 * @param  _pCaminhao  Preço do Caminhão
 * @param  _pHora      Preço por hora
 * @param  _pDiaria    Preço por dia
 */
Tabela::Tabela(double _pCarro, double _pMoto, double _pCaminhao, double _pHora, double _pDiaria):
	m_pCarro(_pCarro), m_pMoto(_pMoto), m_pCaminhao(_pCaminhao), m_pHora(_pHora), m_pDiaria(_pDiaria){}

/** Destrutor */
Tabela::~Tabela(){}

/** Getters */

/**
 * @brief      Método get que retorna o preço do carro.
 *
 * @return     Variavél do tipo double com o preço do carro
 */
double Tabela::getPcarro(){ return this->m_pCarro; }

/**
 * @brief      Método get que retorna o preço da moto.
 *
 * @return     Variavél do tipo double com o preço da moto
 */
double Tabela::getPmoto(){ return this->m_pMoto; }

/**
 * @brief      Método get que retorna o preço do caminhão.
 *
 * @return     Variavél do tipo double com o preço do caminhão
 */
double Tabela::getPcaminhao(){ return this->m_pCaminhao; }


/**
 * @brief      Método get que retorna o preço por hora.
 *
 * @return     Variavél do tipo double com o preço por hora.
 */
double Tabela::getPhora(){
	return this->m_pHora;
}

/**
 * @brief      Método get que retorna o preço por hora.
 *
 * @return     Variavél do tipo double com o preço por hora.
 */
double Tabela::getPdiaria(){
	return this->m_pDiaria;
}

/**
 * @brief      Método que retorna o preço do veiculo de acordo com seu tipo.
 *
 * @param  tipo_  Tipo do veiculo
 *
 * @return     Variavél do tipo double com o preço do veiculo
 */
double Tabela::getValor(std::string tipo_) {
	if (tipo_ == "Carro") {
		return m_pCarro;
	} else if (tipo_ == "Caminhao") {
		return m_pCaminhao;
	} else 	if (tipo_ == "Moto") {
		return m_pMoto;
	} else {
		return -100;
	}
}

/** Setters */



/**
 * @brief      Método que modifica o valor do preço do carro.
 *
 * @param  _pCarro  Variável do tipo double que terá o novo valor.
 */
void Tabela::setPcarro(double _pCarro)		{ this->m_pCarro = _pCarro; }

/**
 * @brief      Método que modifica o valor do preço da moto.
 *
 * @param  _pMoto  Variável do tipo double que terá o novo valor.
 */
void Tabela::setPmoto(double _pMoto)		{ this->m_pMoto = _pMoto; }

/**
 * @brief      Método que modifica o valor do preço do caminhão.
 *
 * @param  _pCaminhao  Variável do tipo double que terá o novo valor.
 */
void Tabela::setPcaminhao(double _pCaminhao){ m_pCaminhao = _pCaminhao; }

/**
 * @brief      Método que modifica o valor do preço por hora.
 *
 * @param  _pHora  Variável do tipo double que terá o novo valor.
 */
void Tabela::setPhora(double _pHora)		{ this->m_pHora = _pHora; }

/**
 * @brief      Método que modifica o valor do preço por dia.
 *
 * @param  _pDiaria  Variável do tipo double que terá o novo valor.
 */
void Tabela::setPdiaria(double _pDiaria)	{ this->m_pDiaria = _pDiaria; }
