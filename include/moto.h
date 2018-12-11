/**
 * @file    moto.h
 * @author  Grupo LP 1
 * @brief   Definição da classe 'moto' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef MOTO_H
#define MOTO_H

#include "veiculo.h"
#include <string>

class Moto : public Veiculo{
    private:
        int m_cilindradas;

    public:
    /** Construtores */
      Moto();
      
      /**
       * @brief      Construtor parametrizado
       *
       * @param  cor_             Cor da moto
       * @param  modelo_          Modelo da moto
       * @param  placa_           Identificador da moto
       * @param  rodas_           Quantidade de rodas
       * @param  ano_             Ano de fabricação
       * @param  maxPassageiros_  Quantidade máxima de passageiros
       * @param  cilindradas_     Número de cilindradas
       */
      Moto(string cor_, string modelo_, string placa_, int rodas_, int ano_, int maxPassageiros_, int cilindradas_);
      
    /** Destrutor */  
      ~Moto();

    /** Getters */
      string getTipo();
      double getConsumoPorKM() override;
      int getCilindradas();

    /** Setters */  
      void setCilindradas(int cilindradas_);
    
    /** Inserção e extração dos fluxos */
      void print(ostream &cout);
      void put(istream &cin);
      string toLinhaCsv();

    /** Sobrecarga de operadores */
      friend ostream &operator<<(ostream &os, Moto &m);
      friend istream &operator>>(istream &is, Moto &m);
};

#endif