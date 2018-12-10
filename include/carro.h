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
	Carro();
	Carro(string cor, string modelo, string placa, int rodas, int ano, int maxPassageiros, double combustivel_, double volumePorlaMalas_);

	~Carro();
	/*
		Como o atributo é pouco comum, para ganho de eficiência no cadastro ele não estará presente.
		para adicionar deve usar o método 'set';
	*/
	double getConsumoPorKM();
	double getCombustivel();
	double getVolumePortaMalas();

	void setCombustivel(double quantidade);
	void setVolumePortaMalas(double volume);

	void print(std::ostream& cout);
	void put(std::istream& cin);
	std::string toLinhaCsv();

	friend std::istream& operator<<(std::istream & os, Carro &c);
  	/**
	* Sobrecarga do operador de inserção <<.
	* @return istream Retorna uma referência para um objeto ostream
	*/
  	friend istream& operator>>(std::istream& istr, Carro &c);

};

#endif