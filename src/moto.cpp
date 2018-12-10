/**
 * @file moto.cpp
 * @author Igor Bruno Damasceno (igoor.bruuno@gmail.com)
 * @brief Implementação da classe Moto para o Projeto de LP I
 * @version 0.1
 * @date 12-07-2018
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "moto.h"

/**
 * @brief Construtor sem parâmetros da classe Moto. Inicia os atributos como Padrão, "Nao definido" e -1.
 * 
 */
Moto::Moto():
    Veiculo("Nao definido", "Nao definido", "OOO-0000", -1, -1, -1), 
    m_cilindradas(-1){}

/**
 * @brief Construtor parametrizado da classe Moto.
 * 
 * @param cor_ Cor do veículo;
 * @param modelo_ Modelo do veículo;
 * @param placa_ Placa do veículo;
 * @param tipo_ Tipo do veículo (Carro, Moto, Caminhão);
 * @param rodas_ Quantidade de rodas do veículo;
 * @param ano_ Ano do veículo;
 * @param maxPassageiros_ Quantidade máxima de passageiros suportada pelo veículo;
 * @param cilindradas_ Cilindradas da Moto.
 */
Moto::Moto(string cor_, string modelo_, string placa_, int rodas_, int ano_, int maxPassageiros_, int cilindradas_):
    Veiculo(cor_, modelo_, placa_, rodas_, ano_, maxPassageiros_), 
    m_cilindradas(cilindradas_){}

/**
 * @brief Destrutor da Classe Moto. Imprime uma zoeria.
 * 
 */
Moto::~Moto(){
    cout << "O grau acabou." << endl;
}

/**
 * @brief Sobrecarga do método getTipo da classe Veiculo. Retorna o tipo do veículo (Moto).
 * 
 * @return string
 */
string Moto::getTipo(){
    return "Moto";
}

/**
 * @brief Sobrecarga do método getConsumoPorKm da classe Veiculo. Retorna o consumo de combustível por Km.
 * 
 * @return double 
 */

double Moto::getConsumoPorKM(){
    return 2.0;
}

/**
 * @brief Retorna as cilindradas.
 * 
 * @return int 
 */
int Moto::getCilindradas(){
    return m_cilindradas;
}

/**
 * @brief Método de ajuste para as cilindradas da Moto.
 * 
 * @param cilindradas_ Novo valor para cilindrada da Moto.
 */
void Moto::setCilindradas(int cilindradas_){
    this->m_cilindradas = cilindradas_;
}

/**
 * @brief Sobrecarga do método print da classe Veiculo.
 * 
 * @param os Fluxo de saída.
 */
void Moto::print(ostream &cout){
    cout<< "Cor: " << this->m_cor << std::endl
        << "Modelo: " << this->m_modelo << std::endl
        << "Placa: " << this->m_placa << std::endl
        << "Número de rodas: " << this->m_rodas << std::endl
        << "Ano: " << this->m_ano << std::endl
        << "Máx Passageiros: " << this->m_maxPassageiros << std::endl
        << "Cilindradas: " << this->m_cilindradas << endl;
}

/**
 * @brief Sobrecarta do método put da classe Veiculo.
 * 
 * @param cin Fluxo de entrada.
 */
void Moto::put(istream &cin){

    cout<< "Entrada de Veículo - Moto" << std::endl 
        << "Por favor, inserir as informções na seguinte ordem:" << std::endl 
        << "Cor, Modelo, Placa, Num Rodas, Ano, Máx Passageiros, Cilindradas." << std::endl;

    cin >> this->m_cor
        >> this->m_modelo
        >> this->m_placa 
        >> this->m_rodas 
        >> this->m_ano 
        >> this->m_maxPassageiros
        >> this->m_cilindradas;
}

string Moto::toLinhaCsv(){
    return this->m_placa + ";" + this->m_cor + ";" + this->m_modelo + ";" + to_string(this->m_rodas)  + ";" + to_string(this->m_ano) + ";" + to_string(this->m_maxPassageiros) + ";" + to_string(this->m_cilindradas);
}

/**
 * @brief Sobrecarga do operador de inserção (<<) da classe Moto.
 * 
 * @param os Fluxo de saída;
 * @param m Objeto Moto que será inserido no fluxo.
 * @return ostream& 
 */
ostream &operator<<(ostream &os, Moto &m){
    m.print(os);
    return os;
}

/**
 * @brief Sobrecarga do operador de extração (>>) da classe Moto.
 * 
 * @param is Fluxo de entrada;
 * @param m Objeto Moto do qual será extraído do fluxo.
 * @return istream& 
 */
istream &operator>>(istream &is, Moto &m){
    m.put(is);
    return is;
}