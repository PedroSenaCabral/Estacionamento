/**
 * @file    caminhao.cpp
 * @author  Grupo LP 1
 * @brief   Implementação da classe 'caminhão' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "caminhao.h"


/** Construtor parametrizado */
Caminhao::Caminhao(string cor, string modelo, string placa, int rodas, int ano, int maxPassageiros,int eixos, double peso):
  Veiculo(cor, modelo, placa, rodas, ano, maxPassageiros),
  m_quant_eixos(eixos),m_peso_carga(peso){}


/**
 * @brief      Construtor padrão
 */
Caminhao::Caminhao():Veiculo("Nao definido", "Nao definido", "OOO-0000", -1, -1, -1) { 
  this->m_peso_carga = -1;
  this->m_quant_eixos = -1;
}

/** Destrutor */
Caminhao::~Caminhao(){}

/** Getters */ 

/**
 * @brief      Método get que retorna a quantidade de eixos.
 *
 * @return     Variavél do tipo int com a quantidade de eixos.
 */
int Caminhao::getEixo()           { return this->m_quant_eixos; }

/**
 * @brief      Método get que retorna o peso do caminhao.
 *
 * @return     Variavél do tipo double com o peso.
 */
double Caminhao::getPeso()        { return this->m_peso_carga; }

/**
 * @brief      Implementacao do metodo virtual da classe base 'getConsumoPorKM'.
 *
 * @return     Consumo de combustivel do caminhao.
 */
double Caminhao::getConsumoPorKM(){ return 8.5; }

/**
 * @brief      Método get que retorna o tipo do Veículo que será util na tabela de preços.
 *
 * @return     Variavél do tipo string com a tipo definido para "Caminhao".
 */
string Caminhao::getTipo()        { return "Caminhao"; }

/** Setters */


/**
 * @brief      Método que modifica o valor do peso do caminhão.
 *
 * @param  peso_  Variável do tipo double que terá o novo valor.
 */
void Caminhao::setPeso(double peso_){ this->m_peso_carga = peso_; }

/**
 * @brief      Implementação do metodo virtual da classe base 'print'.
 *
 * @param      ct   Stream de saída com os dados do Caminhão formatados.
 */
void Caminhao::print(ostream& ct)
{
    ct  << "Cor: " << this->m_cor << std::endl
        << "Modelo: " << this->m_modelo << std::endl
        << "Placa: " << this->m_placa << std::endl
        << "Número de rodas: " << this->m_rodas << std::endl
        << "Ano: " << this->m_ano << std::endl
        << "Máx Passageiros: " << this->m_maxPassageiros << std::endl
        << "Quantidade de Eixo: " << this->m_quant_eixos << std::endl
        << "Peso da carga : " << this->m_quant_eixos << std::endl
        << "Consumo Km/l : " << this->getConsumoPorKM()<< std::endl;
}

/**
 * @brief      Implementação do metodo virtual da classe base 'put'.
 *
 * @param      cin   Stream de entrada para guardar os dados do Caminhão.
 */
void Caminhao::put(istream& cin)
{
  std::cout<< "Entrada de Veículo - Caminhao" << std::endl 
    << "Por favor, inserir as informções na seguinte ordem:" << std::endl 
    << "Cor, Modelo, Placa, Num Rodas, Ano, Máx Passageiros, Quantidade de Eixo, Peso da carga." << std::endl;
  cin >> this->m_cor >> this->m_modelo >> this->m_placa >> this->m_rodas >> this->m_ano >> this->m_maxPassageiros >> this->m_quant_eixos >> this->m_peso_carga;
}

/**
 * @brief      Prepara a linha para o arquivo CSV
 *
 * @return     Os dados do Carro formatados e separados por ponto e virgula.
 */
string Caminhao::toLinhaCsv(){
  return this->m_placa + ";" + this->getTipo() + ";" + this->m_cor + ";" + this->m_modelo + ";" + to_string(this->m_rodas)  + ";" + to_string(this->m_ano) + ";" + to_string(this->m_maxPassageiros) + ";" + to_string(this->m_quant_eixos)  + ";" + to_string(this->m_peso_carga);
}

/** Sobrecarga de operadores */

ostream& operator<< (ostream& ostr, Caminhao& v)
{
    v.print(ostr);
    return ostr;
}

istream& operator>> (istream& istr, Caminhao& v)
{
	v.put(istr);
	return istr;
}
