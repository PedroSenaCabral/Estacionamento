/**
 * @file    diahora.cpp
 * @author  Grupo LP 1
 * @brief   Implementação da classe 'diahora' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "diahora.h"

/**
 * @brief           Verifica a duração de dias do mês
 *
 * @param  mes      Mês a ser verificado
 *
 * @return          Retorna a quantidade de dias dependendo do mês passado.
 */
int DiaHora::m_duracaoMes(int mes){
    mes = (mes == 0) ? this->m_mes : mes;
    if(mes == 2){
        return this->isBissexto() ? 29 : 28;
    }else if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        return 31;
    }else{
        return 30;
    };
}

/**
 * @brief      Construtor padrão
 */
DiaHora::DiaHora(){
    chrono::system_clock::time_point now = std::chrono::system_clock::now();
    time_t tt = chrono::system_clock::to_time_t(now);
    tm local_tm = *localtime(&tt);
    this->m_ano = local_tm.tm_year + 1900;
    this->m_mes = local_tm.tm_mon + 1;
    this->m_dia = local_tm.tm_mday;
    this->m_hora = local_tm.tm_hour;
    this->m_minuto = local_tm.tm_min;
    this->m_segundo = local_tm.tm_sec;
}

/** Construtor parametrizado */
DiaHora::DiaHora(int segundo, int minuto, int hora, int dia, int mes, int ano){
    this->m_ano = ano;
    this->m_mes = (mes > 12) ? 12 : (mes < 1) ? 1 : mes;
    int diamax = this->m_duracaoMes();
    this->m_dia = (dia > diamax) ? diamax : (dia < 1) ? 1 : dia;
    this->m_hora = hora;
    this->m_minuto = minuto;
    this->m_segundo = segundo;
}

/** Destrutor */
DiaHora::~DiaHora(){}

/** Getters */

/**
 * @brief      Retorna os segundos
 *
 * @return     Int com os segundos do dia
 */
int DiaHora::getSegundo()   { return this->m_segundo; }

/**
 * @brief      Retorna os minutos
 *
 * @return     Int com os minutos do dia
 */
int DiaHora::getMinuto()    { return this->m_minuto; }

/**
 * @brief      Retorna a hora.
 *
 * @return     Int com as horas do dia.
 */
int DiaHora::getHora()      { return this->m_hora; }

/**
 * @brief      Retorna o dia do mes.
 *
 * @return     Int com o dia do mes.
 */
int DiaHora::getDia()       { return this->m_dia; }

/**
 * @brief      Retorna o mês do ano.
 *
 * @return     Int com o mês.
 */
int DiaHora::getMes()       { return this->m_mes; }

/**
 * @brief      Retorna o ano
 *
 * @return     Int com o ano
 */
int DiaHora::getAno()       { return this->m_ano; }

/** Verifica se é bissexto. */
bool DiaHora::isBissexto(){
    return (( this->m_ano % 4 == 0 && this->m_ano % 100 != 0 ) || this->m_ano % 400 == 0 );
}

/** Métodos para calcular a data. */

void DiaHora::somarSegundos(int segundos){
    if(segundos < 0){
        return;
    }
    this->m_segundo += segundos;
    while(this->m_segundo >= 60){
        this->m_segundo -= 60;
        this->somarMinutos(1);
    }
}

void DiaHora::somarMinutos(int minutos){
    if(minutos < 0){
        return;
    }
    this->m_minuto += minutos;
    while(this->m_minuto >= 60){
        this->m_minuto -= 60;
        this->somarHoras(1);
    }
}

void DiaHora::somarHoras(int horas){
    if(horas < 0){
        return;
    }
    this->m_hora += horas;
    while(this->m_hora >= 24){
        this->m_hora -= 24;
        this->somarDias(1);
    }
}

void DiaHora::somarDias(int dias){
    if(dias < 0){
        return;
    }
    this->m_dia += dias;
    while(this->m_dia > this->m_duracaoMes()){
        this->m_dia -= this->m_duracaoMes();
        this->somarMeses(1);
    }
}

void DiaHora::somarMeses(int meses){
    this->m_mes += meses;
    while(this->m_mes > 12){
        this->m_mes -= 12;
        this->somarAnos(1);
    }
    // organizar os dias (evitar datas como 31/02)
    this->somarDias(0);
}

void DiaHora::somarAnos(int anos){
    this->m_ano += anos;
}

void DiaHora::proximoDia(){
    this->somarDias(1);
}

double DiaHora::diaDecimal(){
    double dia = this->m_segundo / 86400.0;
    dia += this->m_minuto / 1440.0;
    dia += this->m_hora / 24.0;
    dia += this->m_dia;
    return dia;
}

double DiaHora::horaDecimal(){
    double hora = this->m_segundo / 3600.0;
    hora += this->m_minuto / 60.0;
    hora += this->m_hora;
    return hora;
}

double DiaHora::horasDecorridas(DiaHora &antes){
    double horas = this->horaDecimal() - antes.horaDecimal();
    if(this->m_ano == antes.getAno() && this->m_mes == antes.getMes() && this->m_dia == antes.getDia()){
        return horas;
    }
    else if(this->m_ano == antes.getAno() && this->m_mes == antes.getMes() && this->m_dia > antes.getDia()){
        int diaAntes = antes.getDia();
        while(diaAntes < this->m_dia){
            diaAntes++;
            horas += 24.0;
        }
    }
    else if(this->m_ano == antes.getAno() && this->m_mes > antes.getMes()){
        DiaHora aux(antes.getSegundo(), antes.getMinuto(), antes.getHora(), antes.getDia(), antes.getMes(), antes.getAno());
        while(aux.getMes() < this->m_mes && aux.getDia() < this->m_dia){
            aux.somarDias(1);
            horas += 24.0;
        }
    }
    else if(this->m_ano > antes.getAno()){
        DiaHora aux(antes.getSegundo(), antes.getMinuto(), antes.getHora(), antes.getDia(), antes.getMes(), antes.getAno());
        while(aux.getMes() < this->m_mes && aux.getDia() < this->m_dia){
            aux.somarDias(1);
            horas += 24.0;
        }
    }
    return horas;
}

/** Método que converte a data de int para string. */

string DiaHora::toString(){
    string dia = to_string(this->m_dia);
    dia = (this->m_dia < 10) ? "0" + dia : dia;
    string mes = to_string(this->m_mes);
    mes = (this->m_mes < 10) ? "0" + mes : mes;
    string ano = to_string(this->m_ano);
    string seg = to_string(this->m_segundo);
    seg = (this->m_segundo < 10) ? "0" + seg : seg;
    string min = to_string(this->m_minuto);
    min = (this->m_minuto < 10) ? "0" + min : min;
    string hora = to_string(this->m_hora);
    hora = (this->m_hora < 10) ? "0" + hora : hora;
    return hora + ":" + min + ":" + seg + " " + dia + "/" + mes + "/" + ano;
}

/** Sobrecarga do operador de inserção. */
ostream &operator<<(ostream &os, DiaHora &dt){
    os << dt.toString();
    return os;
}