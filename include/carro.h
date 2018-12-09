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

public:
	Carro();
	Carro(std::string cor, std::string modelo, int rodas, int ano, int maxPassageiros);

	~Carro();
	/*
		Como o atributo é pouco comum, para ganho de eficiência no cadastro ele não estará presente.
		para adicionar deve usar o método 'set';
	*/
	double getConsumoPorKM();
	double getCombustivel();

	void print(std::ostream& cout);
	void put(std::istream& cin);
	void setCombustivel(double quantidade);

};

#endif