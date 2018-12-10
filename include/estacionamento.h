#ifndef _ESTACIONAMENTO_H_
#define _ESTACIONAMENTO_H_

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "veiculo.h"
#include "moto.h"
#include "carro.h"
#include "caminhao.h"
#include "ocorrencia.h"
#include "tabela.h"
#include "buscarVeiculo.h"
#include <algorithm>

class Estacionamento{
  private:

    std::map<std::string, Veiculo*> m_veiculos;
    std::map<std::string, Ocorrencia*> m_ocorrencias;
    Tabela m_tabelaDePrecos;

    int m_numeroDeVagas;

    std::string m_arquivoVeiculos;
    std::string m_arquivoOcorrencias;
    
  public:
    Estacionamento(int numeroDeVagas, std::string arquivoVeiculos, std::string arquivoOcorrencias);
    ~Estacionamento();

    int getNumeroDeVagas();
    int getVagasLivres();
    int getVagasOcupadas();
    bool isFull();
    bool isEmpty();

    bool entradaVeiculo(Veiculo &novoVeiculo, Ocorrencia &log);
    bool saidaVeiculo(string placa);
    void listarVeiculos();
    void listarOcorrenciasAbertas();
    void listarOcorrenciasTotais();
    bool salvarOcorrenciaEmArquivo(Ocorrencia &log);
    bool salvarVeiculoEmArquivo(Veiculo &veic);
    bool lerArquivoVeiculos();
    bool lerArquivoOcorencias();

    void iniciarOperacao();
    void selecionarTipoVeiculo();

};

#endif