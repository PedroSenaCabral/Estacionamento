/**
 * @file    caminhao.h
 * @brief   Definição da classe Caminhao em C++
 * @author  Victor Bittencourt
 * @since   06/12/2018
 * @date    07/12/2018
 * @sa      veiculo.h
 */
#ifndef _CAMINHAO_H
#define _CAMINHAO_H

#include <iostream>
#include "veiculo.h"

class Caminhao: public Veiculo{
private:
  int quant_eixos;
  float peso_carga;
  double consumo;

public:
  Caminhao (std::string cor, std::string modelo, std::string placa, std::string tipo, int rodas, int ano, int maxPassageiros,int eixos, float peso, double consumo_);
  ~Caminhao ();
  int getEixo();
  float getPeso();
  double getConsumoPorKM();

  void print(ostream& cout);
  void put(istream& cin);

  friend std::istream& operator<<(std::istream & os, Caminhao *v);
  friend istream& operator>>(std::istream& istr, Caminhao *v);

};




#endif
