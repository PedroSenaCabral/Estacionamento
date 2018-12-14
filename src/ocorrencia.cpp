/**
 * @file    ocorrencia.cpp
 * @author  Grupo LP 1
 * @brief   Implementação da classe 'ocorrencia' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include <iostream>
#include <cmath>
#include "ocorrencia.h"

/** Construtor parametrizado */
Ocorrencia::Ocorrencia(Veiculo* veiculo_, string tipo_){
	DiaHora* agora = new DiaHora();
	this->m_tempo = *agora;
	this->m_veiculo = veiculo_;
	this->m_tipo = tipo_;
	this->m_totalPago = 0;
}

/**
 * @brief      			Reconstroi a ocorrencia através da linha do arquivo .CSV
 *
 * @param  linhaCsv   	Linha do .CSV
 * @param  veiculos_  	Estrutura Map com os veículos
 */
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

/** Destrutor */
Ocorrencia::~Ocorrencia(){

}

/**
 * @brief	Método auxiliar privado para quebra da string em um vetor de string de acordo com um delimitador
 *
 * @param	linha        string a ser quebrada
 * @param	delimitador  caractere que determina a quebra
 *
 * @return 	String formatada
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

/**
 * @brief      Retorna o tempo que o veículo passou no estacionamento.
 *
 * @return     Variável do tipo DiaHora.
 */
DiaHora& Ocorrencia::getTempo()		{ return this->m_tempo; }

/**
 * @brief      Retorna o total pago pelo cliente
 *
 * @return     Variável double com o total.
 */
double Ocorrencia::getTotalPago()	{ return this->m_totalPago; }

/**
 * @brief      Retorna o tipo da saida no estacionamento
 *
 * @return     String com os valores "Entrada" ou "Saída".
 */
string Ocorrencia::getTipo()		{ return this->m_tipo; }

/**
 * @brief      Retorna um Veiculo.
 *
 * @return     Variavel do tipo Veiculo.
 */
Veiculo* Ocorrencia::getVeiculo()	{ return this->m_veiculo; }

/**
 * @brief      Retorna uma linha do arquivo .CSV.
 *
 * @return     Retorna a linha já separada por ponto e virgula.
 */
string Ocorrencia::getLinhaCsv()	{ return this->m_tipo + ";" + this->m_veiculo->getPlaca() + ";" + to_string(this->m_totalPago) + ";" + this->m_tempo.toString() ; }

/**
 * @brief      		Salva o veículo.
 *
 * @param   veic  	Variável do tipo Veículo.
 */	
void Ocorrencia::setVeiculo(Veiculo* veic){ this->m_veiculo = veic; }

/**
 *@brief Função de calcular o custo.
 *
 * @param      entrada  Variável do tipo DiaHora com as informações da entrada do carro
 * @param      tab      Tabela de prelços
 *
 * @return     Retorna o total pago no estacionamento
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

/**
 * @brief      Sobrecarga do operador de inserção
 *
 * @param      os    Stream de saida
 * @param      oc    Variavel do tipo Ocorrencia
 *
 * @return     Retorna o objeto formatado
 */
ostream &operator<<(ostream &os, Ocorrencia &oc){
    os << oc.getTipo() << " de veículo de placa [" << oc.getVeiculo()->getPlaca() << "] às " << oc.getTempo();
	os << (oc.getTipo() == "Saida" ? " | Valor pago: R$ " + to_string(oc.getTotalPago()) : "");
    return os;
}