#include "tabela.h"

Tabela::Tabela(){}

Tabela::Tabela(double _pCarro, double _pMoto, double _pCaminhao):m_pCarro(_pCarro), m_pMoto(_pMoto), m_pCaminhao(_pCaminhao){}

Tabela::~Tabela(){}


double Tabela::getPcarro(){ return m_pCarro; }

double Tabela::getPmoto(){ return m_pMoto; }

double Tabela::getPcaminhao(){ return m_pCaminhao; }


void Tabela::setPcarro(double _pCarro){ m_pCarro = _pCarro; }

void Tabela::setPmoto(double _pMoto){ m_pMoto = _pMoto; }

void Tabela::setPcaminhao(double _pCaminhao){ m_pCaminhao = _pCaminhao; }