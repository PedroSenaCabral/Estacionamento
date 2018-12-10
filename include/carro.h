/**
 * @file carro.h
 * @brief Definição da classe Carro
 */

#ifndef CARRO_h
#define CARRO_h

#include "veiculo.h"
#include <string>

class Carro : public Veiculo {

private:
	/*
	Parâmetro opcional, não é uma informação comum para um estacionamento guardar, porém, em casos especiais
	esta informação pode ser útil para análises.
	*/
	double m_combustivel;
	double m_volumePortaMalas;

public:
	/** Construtor padrão. */
	Carro();

	/** Construtor parametrizado. */
	Carro(string cor, string modelo, string placa, int rodas, int ano, int maxPassageiros, double combustivel_, double volumePorlaMalas_);

	/** Destrutor */
	~Carro();
	
	/** Getters */

	/*
		Como o atributo é pouco comum, para ganho de eficiência no cadastro ele não estará presente.
		para adicionar deve usar o método 'set';
	*/
	double getConsumoPorKM();
	double getCombustivel();
	double getVolumePortaMalas();
	string getTipo();

	/** Setters */

	void setCombustivel(double quantidade);
	void setVolumePortaMalas(double volume);

	/** Operadores de inserção e extração. */
	void print(std::ostream& cout);
	void put(std::istream& cin);
	friend std::istream& operator<<(std::istream & os, Carro &c);
  	friend istream& operator>>(std::istream& istr, Carro &c);


	/** Metódo para formatar a linha pro CSV. */
	std::string toLinhaCsv();

	
};

#endif