/**
 * @file    tabela.h
 * @author  Grupo LP 1
 * @brief   Definição da classe 'tabela' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
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
<<<<<<< HEAD
	/** Construtor padrão. */
	Tabela(); 
	
=======
	Tabela(); /** Construtor padrão. */
>>>>>>> ebb3c75df813a328a449d740b71c06cbaf7e470d
	/**
 	* @brief Construtor parametrizado
 	*
 	* @param  _pCarro     Preço do Carro
 	* @param  _pMoto      Preço da Moto
 	* @param  _pCaminhao  Preço do Caminhão
 	* @param  _pHora      Preço por hora
 	* @param  _pDiaria    Preço por dia
<<<<<<< HEAD
	 */
	Tabela(double, double, double, double, double); 
=======
 	*/
	Tabela(double, double, double, double, double);
>>>>>>> ebb3c75df813a328a449d740b71c06cbaf7e470d
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
