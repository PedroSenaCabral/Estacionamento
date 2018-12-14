/**
 * @file    caminhao.h
 * @author  Grupo LP 1
 * @brief   Definição da classe 'caminhao' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#ifndef _CAMINHAO_H
#define _CAMINHAO_H

#include <iostream>
#include "veiculo.h"
#include <string>

using namespace std;
/**
* A classe Caminhao armazena um conjunto de valores, permitindo utilizá-los quando necessário.
*
*/
class Caminhao: public Veiculo{
private:
  int m_quant_eixos; /**< Define a quantidade de eixos do caminhao. */
  double m_peso_carga; /**< Define o peso da carga do caminhao. */

public:
  /**
  * Contrutor padrão. Constrói um objeto com valores default.
	*
  */
  Caminhao();

  /**
  * Contrutor parametrizado. Constrói um objeto apartir dos valores passados no construtor.
	* @param cor_ O atributo cor que será armazenado.
	* @param modelo_ O atributo modelo que será armazenado.
  * @param placa_ O atributo placa que será armazenado.
  * @param rodas_ O atributo rodas que será armazenado.
  * @param ano_ O atributo ano que erá armazenado.
  * @param maxPassageiros_ O atributo Max Passageiros que será armazenado.
  * @param eixos_ O atributo eixos que será armazenado.
  * @param peso_ O atributo peso que será armazenado.
  */
  Caminhao(std::string cor_, std::string modelo_, std::string placa_, int rodas_, int ano_, int maxPassageiros_, int eixos_, double peso_);
  
  /**
  * Destrutor.
  */
  ~Caminhao ();
 
  /**
  * Método que retorna o tipo do objeto.
  * @return string
  */
  string getTipo();

  /**
  * Método que retorna a quantidade de eixos.
  * @return int
  */
  int getEixo();

  /**
  * Método que retorna o peso do caminhao.
  * @return float
  */
  double getPeso();

  /**
  * Sobrecarga do método getConsumoPorKm da classe Veiculo. Retorna o consumo de combustível por Km.
  *
  * @return double
  */
  double getConsumoPorKM();

  /**
  * Método que atualiza o peso da carga do caminhao.
  *
  */
  void setPeso(double peso_);

  /**
  * Método que sobrecarrega o método print da classe Veiculo. Imprime os dados do caminhao.
  *
  */
  void print(ostream& cout);

  /**
  * Método que sobrecarrega o método put da classe Veiculo. Recebe os dados do caminhao.
  *
  */
  void put(istream& is);
  bool formatoCorreto(string cor_, string modelo_, string placa_, string rodas_, string ano_, string maxPassageiros_, string eixos_, string peso_);
  bool ehNumero(string palavra, int tamanhoPalavra);
  

  /**
  * @brief      Prepara a linha para o arquivo CSV
  *
  */
  string toLinhaCsv();

  /**
  * Sobrecarga do operador de extração <<.
  * @return ostream Retorna uma referência para um objeto ostream
  */
  friend std::ostream& operator<<(std::ostream& os, Caminhao& v);
  
  /**
  * Sobrecarga do operador de inserção <<.
  * @return istream Retorna uma referência para um objeto ostream
  */
  friend istream& operator>>(std::istream& istr, Caminhao& v);

};




#endif
