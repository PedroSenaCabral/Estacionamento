/**
 * @file    veiculo.h
 * @brief   Definição da classe abstrata Veículo em C++
 * @author  Dennis Ferreira, Mateus Brito e Lucas Lucena
 * @since   06/12/2018
 * @date    07/12/2018
 * @sa      SIGAA
 */

#ifndef VEICULO_h
#define VEICULO_h

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Veiculo
{   
protected:

    std::string m_cor;                  /* Cor do veículo */
    std::string m_modelo;              /* Modelo do veículo */
    std::string m_placa;               /* Identificador único do veículo */
    int         m_rodas;            /* Quantidade de rodas do veículo */
    int         m_ano;             /* Ano do modelo do veículo */
    int         m_maxPassageiros; /* Capacidade máxima de passageiros no veículo */

    /** metodo privado auxiliar auxiliar para separar as informações da ocorrencia para o arquivo csv */
	vector<string> splitString(string& linha, char delimitador);

public:
/* Construtores */
    Veiculo();
    Veiculo(std::string cor_, std::string modelo_, std::string placa_, int rodas_, int ano_, int maxPassageiros_);

/* Destrutor */
    ~Veiculo();

/* Getters */   
    std::string getCor();
    std::string getModelo();
    std::string getPlaca();
    int         getRodas();
    int         getAno();
    int         getMaxPassageiros();

/* Metódo Virtual Puro */
    virtual double getConsumoPorKM() = 0;

/* Setters */
    void setCor(std::string cor_);
    void setModelo(std::string modelo_);
    void setAno(int ano_);
    void setPlaca(std::string placa_);
    void setRodas(int quantidade_);
    void setMaxPassageiros(int maxPassageiros_);

/* Operadores de inserção e de extração */
    virtual void print(std::ostream& cout) = 0;
    virtual void put(std::istream& cin) = 0;
    virtual std::string toLinhaCsv() = 0;
    virtual std::string getTipo() = 0;

    friend std::ostream& operator<<(std::ostream& os, Veiculo& v);
    friend std::istream& operator>>(std::istream& istr, Veiculo& v);

};

#endif