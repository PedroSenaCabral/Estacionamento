/**
 * @file    veiculo.h
 * @author  Grupo LP 1
 * @brief   Definição da classe abstrata 'veiculo' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
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
    bool m_valido;

public:
    /** Construtor padrão */
    Veiculo();
    
    /**
     * @brief      Construtor parametrizado
     *
     * @param  cor_             Cor do veículo
     * @param  modelo_          Modelo do veiculo
     * @param  placa_           Placa do veículo
     * @param  rodas_           Quantidade de Rodas
     * @param  ano_             Ano de fabricação
     * @param  maxPassageiros_  Quantidade máxima de passageiros
     */
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
    bool        getValido();

    /* Metódo Virtual Puro */
    virtual double getConsumoPorKM() = 0;
    virtual void print(std::ostream& cout) = 0;
    virtual void put(std::istream& cin) = 0;
    virtual std::string toLinhaCsv() = 0;
    virtual std::string getTipo() = 0;

    /* Setters */
    void setCor(std::string cor_);
    void setModelo(std::string modelo_);
    void setAno(int ano_);
    void setPlaca(std::string placa_);
    void setRodas(int quantidade_);
    void setMaxPassageiros(int maxPassageiros_);
    
    /** Operadores de inserção e de extração */
    friend std::ostream& operator<<(std::ostream& os, Veiculo& v);
    friend std::istream& operator>>(std::istream& istr, Veiculo& v);

};

#endif