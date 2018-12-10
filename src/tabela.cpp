#include "tabela.h"

Tabela::Tabela():
	m_pCarro(6.0), m_pMoto(4.0), m_pCaminhao(10.0), m_pHora(1.0), m_pDiaria(20.0)
{}

Tabela::Tabela(double _pCarro, double _pMoto, double _pCaminhao, double _pHora, double _pDiaria):
	m_pCarro(_pCarro), m_pMoto(_pMoto), m_pCaminhao(_pCaminhao), m_pHora(_pHora), m_pDiaria(_pDiaria){}

Tabela::~Tabela(){}


double Tabela::getPcarro(){ return m_pCarro; }

double Tabela::getPmoto(){ return m_pMoto; }

double Tabela::getPcaminhao(){ return m_pCaminhao; }

double Tabela::getValor(std::string tipo_) {
	if (tipo_.compare("carro") == 0) {
		return m_pCarro;
	} else if (tipo_.compare("caminhao") == 0) {
		return m_pCaminhao;
	} else 	if (tipo_.compare("moto") == 0) {
		return m_pMoto;
	} else {
		return -1;
	}
}

double Tabela::getPhora(){
	return this->m_pHora;
}

double Tabela::getPdiaria(){
	return this->m_pDiaria;
}

void Tabela::setPcarro(double _pCarro){ m_pCarro = _pCarro; }

void Tabela::setPmoto(double _pMoto){ m_pMoto = _pMoto; }

void Tabela::setPcaminhao(double _pCaminhao){ m_pCaminhao = _pCaminhao; }

void Tabela::setPhora(double _pHora){ this->m_pHora = _pHora; }

void Tabela::setPdiaria(double _pDiaria){ this->m_pDiaria = _pDiaria; }
