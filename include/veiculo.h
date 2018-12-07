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
#include <string>

class Veiculo
{
protected:
    std::string cor;                  /* Cor do veículo */
    std::string modelo;              /* Modelo do veículo */
    std::string placa               /* Identificador único do veículo */
    std::string tipo               /* Idenficador do tipo de veículo */
    int         rodas;            /* Quantidade de rodas do veículo */
    int         ano;             /* Ano do modelo do veículo */
    int         maxPassageiros; /* Capacidade máxima de passageiros no veículo */

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
    virtual void print(ostream& cout) = 0;
    virtual void put(istream& cin) = 0;

    friend std::istream& operator<<(std::istream & os, Veiculo *v);
    friend istream& operator>>(std::istream& istr, Veiculo* v);

};

#endif
