#ifndef _DATA_H_
#define _DATA_H_

#include <chrono>
#include <iostream>

using namespace std;

class DiaHora
{
  public:
    DiaHora();
    DiaHora(int segundo, int minuto, int hora, int dia, int mes, int ano);
    ~DiaHora();
    int getSegundo();
    int getMinuto();
    int getHora();
    int getDia();
    int getMes();
    int getAno();
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
    friend ostream &operator<<(ostream &os, DiaHora &dt);

  private:
    int m_segundo;
    int m_minuto;
    int m_hora;
    int m_dia;
    int m_mes;
    int m_ano;

    // metodo privado para calcular quantos dias tem o mes atual: 28, 29, 30 ou 31
    int m_duracaoMes(int mes = 0);
};

#endif