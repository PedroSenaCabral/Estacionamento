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

#include <iostream>
#include <iostream>
#include <string>

class Veiculo
{   
protected:
    std::string m_cor;                  /* Cor do veículo */
    std::string m_modelo;              /* Modelo do veículo */
    std::string m_placa;               /* Identificador único do veículo */
    std::string m_tipo;               /* Idenficador do tipo de veículo */
    int         m_rodas;            /* Quantidade de rodas do veículo */
    int         m_ano;             /* Ano do modelo do veículo */
    int         m_maxPassageiros; /* Capacidade máxima de passageiros no veículo */

public:
/* Construtores */
    Veiculo();
    Veiculo(std::string cor, std::string modelo, std::string placa, std::string tipo, int rodas, int ano, int maxPassageiros);

/* Destrutor */
    ~Veiculo();

/* Getters */   
    std::string getCor();
    std::string getModelo();
    std::string getPlaca();
    std::string getTipo();
    int         getRodas();
    int         getAno();
    int         getMaxPassageiros();

/* Metódo Virtual Puro */
    virtual double getConsumoPorKM() = 0;

/* Setters */
    void setCor(std::string cor);
    void setModelo(std::string modelo);
    void setAno(int ano);
    void setPlaca(std::string placa);
    void setTipo(std::string tipo);
    void setRodas(int quantidade);
    void setMaxPassageiros(int maxPassageiros);

/* Operadores de inserção e de extração */
    virtual void print(std::ostream& cout) = 0;
    virtual void put(std::istream& cin) = 0;

    friend std::ostream& operator<<(std::ostream & os, Veiculo* v);
    friend std::istream& operator>>(std::istream& istr, Veiculo* v);

};

#endif