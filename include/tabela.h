#ifndef TABELA_H
#define TABELA_H

#include <iostream>
#include <string>

class Tabela
{
private:
	double m_pCarro;
	double m_pMoto;
	double m_pCaminhao;

public:
	Tabela();
	Tabela(double, double, double);
	~Tabela();

	/** Getters */
	double getPcarro();
	double getPmoto();
	double getPcaminhao();

	/** Setters */
	void setPcarro(double);
	void setPmoto(double);
	void setPcaminhao(double);

	double getValor(std::string);

	
};


#endif