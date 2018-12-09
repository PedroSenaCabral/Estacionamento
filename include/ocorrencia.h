#ifndef _OCORRENCIA_H_
#define _OCORRENCIA_H_

#include <string>
#include <vector>
#include <map>

#include "diahora.h"
#include "veiculo.h"
#include "tabela.h"

class Ocorrencia 
{
private:

	DiaHora m_tempo;

	int m_totalPago;

	string m_tipo; // Entrada ou Saida
	Veiculo* m_veiculo;

	/** metodo privado auxiliar auxiliar para separar as informações da ocorrencia para o arquivo csv */
	vector<string> splitString(string& linha, char delimitador);

public:
	
	Ocorrencia(Veiculo* veiculo_, string tipo_ = "Entrada");
	Ocorrencia(string linhaCsv, map<string, Veiculo*> veiculos_);
	~Ocorrencia();

	DiaHora& getTempo();
	double getTotalPago();
	string getTipo();
	double calcularCusto(DiaHora &entrada, Tabela &tab);
	Veiculo* getVeiculo();
	
	friend ostream &operator<<(ostream &os, Ocorrencia &dt);
	string getLinhaCsv();
};

#endif
