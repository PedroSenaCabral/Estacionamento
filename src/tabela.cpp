#include "tabela.h"

Tabela::Tabela(){}

Tabela::Tabela(double _pCarro, double _pMoto, double _pCaminhao):m_pCarro(_pCarro), m_pMoto(_pMoto), m_pCaminhao(_pCaminhao){}

Tabela::~Tabela(){}


double Tabela::getPcarro(){ return m_pCarro; }

double Tabela::getPmoto(){ return m_pMoto; }

double Tabela::getPcaminhao(){ return m_pCaminhao; }

double Tabela::getValor(std::string tipo_){
	if (tipo_ = "carro"){
		return m_pCarro;
	}
	if (tipo_ = "caminhao"){
		return m_pCaminhao;
	}
	if (tipo_ = "moto"){
		return m_pMoto;
	}
}

void Tabela::setPcarro(double _pCarro){ m_pCarro = _pCarro; }

void Tabela::setPmoto(double _pMoto){ m_pMoto = _pMoto; }

<<<<<<< HEAD
void Tabela::setPcaminhao(double _pCaminhao){ pCaminhao = _pCaminhao; }
=======
void Tabela::setPcaminhao(double _pCaminhao){ m_pCaminhao = _pCaminhao; }

double Tabela::getValor(std::string tipoVeiculo) {
	return 0;
}
>>>>>>> 27ce42034cfaf111a25a790cc2105e271b98ab1d
