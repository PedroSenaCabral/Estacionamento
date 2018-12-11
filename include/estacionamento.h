/**
 * @file    estacionamento.h
 * @author  Grupo LP 1
 * @brief   Definição da classe 'estacionamento' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
 */

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

    /** Estrutura do tipo Map para salvar os Veículos. */
    std::map<std::string, Veiculo*> m_veiculos;

    /** Estrutura do tipo Map para salvar as Ocorrencias. */
    std::map<std::string, Ocorrencia*> m_ocorrencias;

    /** Tabela de preço do estacionamento. */
    Tabela m_tabelaDePrecos;

    /** Quantidade de vagas no estacionamento. */
    int m_numeroDeVagas;

    /** Arquivo para salvar os Veículos que passam pelo estacionamento. */
    std::string m_arquivoVeiculos;

    /** Arquivo para salvar as movimentações no estacionamento. */
    std::string m_arquivoOcorrencias;
    
    /** metodo privado auxiliar auxiliar para separar as informações da ocorrencia para o arquivo csv */
	vector<string> splitString(string& linha, char delimitador);

  public:
    
    /**
     * @brief                       Construtor parametrizado
     *
     * @param  numeroDeVagas        Quantidade de vaga do estacionamento.
     * @param  arquivoVeiculos      Arquivo .CSV com os veiculos.
     * @param  arquivoOcorrencias   Arquivo .CSV com as ocorrencias.
     */
    Estacionamento(int numeroDeVagas, std::string arquivoVeiculos, std::string arquivoOcorrencias);
    
    /** Destrutor */
    ~Estacionamento();

    /** Getters */
    int getNumeroDeVagas();
    int getVagasLivres();
    int getVagasOcupadas();

    /** Verifica se o estacionamento está cheio. */
    bool isFull();

    /** Verifica se o estacionamento está vazio. */
    bool isEmpty();

    /** Métodos úteis para o estacionamento. */
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