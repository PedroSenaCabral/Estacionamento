/**
 * @file    diahora.h
 * @author  Grupo LP 1
 * @brief   Definição da classe 'diahora' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
 */

#ifndef _DATA_H_
#define _DATA_H_

#include <chrono>
#include <iostream>

using namespace std;

class DiaHora
{
  public:
    /** Construtor padrão */
    DiaHora();

    /**
     * @brief      Construtor paramentrizado.
     *
     * @param  segundo  Segundos
     * @param  minuto   Minutos
     * @param  hora     Horas
     * @param  dia      Dia
     * @param  mes      Mês
     * @param  ano      Ano
     */
    DiaHora(int segundo, int minuto, int hora, int dia, int mes, int ano);

    /** Destrutor */
    ~DiaHora();

    /** Getters */
    int getSegundo();
    int getMinuto();
    int getHora();
    int getDia();
    int getMes();
    int getAno();

    /** Métodos úteis */

    bool isBissexto();
    void somarSegundos(int segundos);
    void somarMinutos(int minutos);
    void somarHoras(int horas);
    void somarDias(int dias);
    void somarMeses(int meses);
    void somarAnos(int anos);
    void proximoDia();
    double diaDecimal();
    double horaDecimal();
    double horasDecorridas(DiaHora &outroTempo);
    string toString();

    /** Sobrecarga dos operadores */ 
    friend ostream &operator<<(ostream &os, DiaHora &dt);

  private:
    int m_segundo;
    int m_minuto;
    int m_hora;
    int m_dia;
    int m_mes;
    int m_ano;

    /** metodo privado para calcular quantos dias tem o mes atual: 28, 29, 30 ou 31 */
    int m_duracaoMes(int mes = 0);
};

#endif