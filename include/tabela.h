/**
 * @file tabela.h
 * @brief Definição da classe Tabela
 */

#ifndef TABELA_H
#define TABELA_H

#include <iostream>
#include <string>


class Tabela
{
private:
	double m_pCarro; /** Preço do Carro. */
	double m_pMoto; /** Preço da moto. */
	double m_pCaminhao; /** Preço do caminhão */
	double m_pHora; /** Preço por cada hora estacionada */
	double m_pDiaria; /** Preço da diária. */

public:
	Tabela(); /** Construtor padrão. */
	Tabela(double, double, double, double, double); /** Construtor parametrizado. */
	~Tabela(); /** Destrutor */

	/** Getters */
	double getPcarro();
	double getPmoto();
	double getPcaminhao();
	double getPhora();
	double getPdiaria();
	double getValor(std::string tipo_);

	/** Setters */
	void setPcarro(double);
	void setPmoto(double);
	void setPcaminhao(double);
	void setPhora(double);
	void setPdiaria(double);
	
};


#endif
