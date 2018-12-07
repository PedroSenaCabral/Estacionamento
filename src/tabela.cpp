#include "tabela.h"

Tabela::Tabela(){}

Tabela::Tabela(double _pCarro, double _pMoto, double _pCaminhao):pCarro(_pCarro), pMoto(_pMoto), pCaminhao(_pCaminhao){}

Tabela::~Tabela(){}


double Tabela::getPcarro(){ return pCarro; }

double Tabela::getPmoto(){ return pMoto; }

double Tabela::getPcaminhao(){ return pCaminhao; }


void Tabela::setPcarro(double _pCarro){ pCarro = _pCarro; }

void Tabela::setPmoto(double _pMoto){ pMoto = _pMoto; }

void Tabela::setPcaminhao(double _pCaminhao){ pCaminhao = _pCaminhao; }