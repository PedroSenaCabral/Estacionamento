#include <iostream>
#include <cmath>
#include "ocorrencia.h"

Ocorrencia::Ocorrencia(Veiculo* veiculo_, string tipo_){
	DiaHora* agora = new DiaHora();
	this->m_tempo = *agora;
	this->m_veiculo = veiculo_;
	this->m_tipo = tipo_;
	this->m_totalPago = 0;
}

Ocorrencia::Ocorrencia(string linhaCsv, map<string, Veiculo*> veiculos_){
	// recontriur a ocorrencia através da linha csv

	vector<string> colunas = this->splitString(linhaCsv, ';');
	if(colunas.size() != 4){
		this->m_veiculo = nullptr;
	}
	else{
		this->m_tipo = colunas[0];
		this->m_veiculo = veiculos_[colunas[1]];
		this->m_totalPago = stod(colunas[2]);
		string aux = colunas[3];
		vector<string> hora_dia = this->splitString(aux, ' ');
		vector<string> horas = this->splitString(hora_dia[0], ':');
		vector<string> dias = this->splitString(hora_dia[1], '/');
		int seg = stoi(horas[2]);
		int min = stoi(horas[1]);
		int hora_ = stoi(horas[0]);
		int dia_ = stoi(dias[0]);
		int mes = stoi(dias[1]);
		int ano = stoi(dias[2]);
		this->m_tempo =  *(new DiaHora(seg, min, hora_, dia_, mes, ano));
	}
}

Ocorrencia::~Ocorrencia(){

}

/**
 * @brief	Método auxiliar privado para quebra da string em um vetor de string de acordo com um delimitador
 *
 * @param	linha        string a ser quebrada
 * @param	delimitador  caractere que determina a quebra
 *
 * @return 
 */
vector<string> Ocorrencia::splitString(string& linha, char delimitador){
	vector<string> colunas;
	string buffer = "";
	for(unsigned i = 0; i < linha.size(); i++){
		char c = linha[i];
		if(c == delimitador){
			colunas.push_back(buffer);
			buffer = "";
		}else{
			string letra(1, c);
			buffer += letra;
		};
	};
	if(buffer != "") colunas.push_back(buffer);
	return colunas;
}

DiaHora& Ocorrencia::getTempo(){
	return this->m_tempo;
}

double Ocorrencia::getTotalPago(){
	return this->m_totalPago;
}

string Ocorrencia::getTipo(){
	return this->m_tipo;
}

void Ocorrencia::setVeiculo(Veiculo* veic){
	this->m_veiculo = veic;
}

/*Função de calcular o custo, Funcionamento:
 *
*/
double Ocorrencia::calcularCusto(DiaHora &entrada, Tabela &tab)
{
	double valorPorHora = tab.getPhora(); 
	double valorPorDia = tab.getPdiaria(); 
	this->m_totalPago = tab.getValor(this->m_veiculo->getTipo());
	
	double horasDecimal = this->getTempo().horasDecorridas(entrada);
	if(horasDecimal < 24.0){
		this->m_totalPago += valorPorHora*floor(horasDecimal);
	}
	else{
		this->m_totalPago += valorPorDia*floor(horasDecimal/24.0);
	}
	return this->getTotalPago();
}

Veiculo* Ocorrencia::getVeiculo(){
	return this->m_veiculo;
}

ostream &operator<<(ostream &os, Ocorrencia &oc){
    os << oc.getTipo() << " de [" << oc.getVeiculo()->getPlaca() << "] as " << oc.getTempo();
	os << (oc.getTipo() == "Saida" ? to_string(oc.getTotalPago()) : "");
    return os;
}

string Ocorrencia::getLinhaCsv(){
	return this->m_tipo + ";" + this->m_veiculo->getPlaca() + ";" + to_string(this->m_totalPago) + ";" + this->m_tempo.toString() ;
}



