/**
 * @file    carro.cpp
 * @author  Grupo LP 1
 * @brief   Implementação da classe 'carro' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "carro.h"
#include <string>
#include <iostream>

/*
Se inicializa um Carro sem passar as informações, supomos que seja apenas uma carcaça de um carro
e inicializamos os valores padrões. :)

-1 significa NÃO DEFINIDO
*/


/** Consturtor padrão */
Carro::Carro(): Veiculo("Nao definido", "Nao definido", "OOO-0000", -1, -1, -1) { 
  this->m_combustivel = -1;
  this->m_volumePortaMalas = -1;
}

/** Construtor parametrizado. */
Carro::Carro(string cor, string modelo, string placa, int rodas, int ano, int maxPassageiros, double combustivel_, double volumePortaMalas_):
	Veiculo(cor, modelo, placa, rodas, ano, maxPassageiros), m_combustivel(combustivel_), m_volumePortaMalas(volumePortaMalas_){}

/** Destrutor */ 
Carro::~Carro(){}

/** Getters */

/**
 * @brief      Método get que retorna a capacidade do tanque de combustivel.
 *
 * @return     Variavél do tipo double com a capacidade do tanque.
 */
double Carro::getCombustivel(){ return this->m_combustivel; }

/**
 * @brief      Método get que retorna o volume do porta malas.
 *
 * @return     Variavél do tipo double com o volume do porta malas.
 */
double Carro::getVolumePortaMalas(){ return this->m_volumePortaMalas; }

/**
 * @brief      Implementacao do metodo virtual da classe base 'getConsumoPorKM'.
 *
 * @return     Consumo de combustivel do carro.
 */
double Carro::getConsumoPorKM(){ return 5.0; }

/**
 * @brief      Método get que retorna o tipo do Veículo que será util na tabela de preços.
 *
 * @return     Variavél do tipo string com a tipo definido para "Carro".
 */
string Carro::getTipo(){ return "Carro"; }

/** Setters */


/**
 * @brief      Método que modifica a capacidade do tanque de combustivel.
 *
 * @param  quantidade  Variável do tipo double que terá o novo valor do tanque.
 */
void Carro::setCombustivel(double quantidade){ this->m_combustivel = quantidade; }

/**
 * @brief      Método que modifica a capacidade do porta malas.
 *
 * @param  volume  Variável do tipo double que terá o novo volume do porta malas.
 */
void Carro::setVolumePortaMalas(double volume){ this->m_volumePortaMalas = volume; }

/**
 * @brief      Implementação do metodo virtual da classe base 'print'.
 *
 * @param      ct    Stream de saída com os dados do Carro formatados.
 */
void Carro::print(ostream& ct)
{
    ct  << "Cor: " << this->m_cor << std::endl
        << "Modelo: " << this->m_modelo << std::endl
        << "Placa: " << this->m_placa << std::endl
        << "Numero de rodas: " << this->m_rodas << std::endl
        << "Ano: " << this->m_ano << std::endl
        << "Max Passageiros: " << this->m_maxPassageiros << std::endl
        << "Combustivel: " << this->m_combustivel << std::endl
        << "Volume do porta malas: " << this->m_volumePortaMalas << std::endl
        << "Consumo Km/l : " << this->getConsumoPorKM()<< std::endl;
}

/**
 * @brief      Método para ler os dados do Carro.
 *
 * @param      is   Stream de entrada para guardar os dados do Carro.
 */
void Carro::put(std::istream& is){
	

    string cor_,modelo_,placa_,rodas_,ano_,maxPassageiros_,combustivel_,volumePortaMalas_;
        
    std::cout<< "<<INSIRA OS DADOS DO CARRO>>" << std::endl;
                 
        cout<<"Cor: ";
        is >> cor_;
        cout<<"Modelo: ";
        is >> modelo_;
        cout<<"Placa (XXX-0000): ";
        is >> placa_;
        cout<<"Qtde de Rodas: ";
        is >> rodas_ ;
        cout<<"Ano: ";
        is >> ano_;
        cout<<"Qntde de Passageiros: ";
        is >>maxPassageiros_;
        cout<<"Volume de combustivel: ";
        is >> combustivel_;
        cout<<"Volume do porta-malas: ";
        is >> volumePortaMalas_;   

        
        if(formatoCorreto(cor_,modelo_,placa_,rodas_,ano_,maxPassageiros_,combustivel_,volumePortaMalas_)){
            this->m_cor = cor_;
            this->m_modelo  = modelo_;
            this->m_placa = placa_;
            this->m_rodas = stoi(rodas_);
            this->m_ano = stoi(ano_);
            this->m_maxPassageiros = stoi(maxPassageiros_);
            this->m_combustivel  = stod(combustivel_);
            this->m_volumePortaMalas = stod(volumePortaMalas_);                
        }else{
            m_valido = false;
        }

}

/**
 * @brief      Prepara a linha para o arquivo CSV
 *
 * @return     Os dados do Carro formatados e separados por ponto e virgula.
 */
string Carro::toLinhaCsv(){
  return this->m_placa + ";" + this->getTipo() + ";" + this->m_cor + ";" + this->m_modelo + ";" + to_string(this->m_rodas)  + ";" + to_string(this->m_ano) + ";" + to_string(this->m_maxPassageiros) + ";" + to_string(this->m_combustivel)  + ";" + to_string(this->m_volumePortaMalas);
}

ostream& operator<< (ostream& ostr, Carro& c)
{
    c.print(ostr);
    return ostr;
}

istream& operator>> (istream& istr, Carro& c)
{
	c.put(istr);
	return istr;
}



bool Carro::formatoCorreto(string cor_, string modelo_, string placa_, string rodas_, string ano_,string maxPassageiros_, string combustivel_, string volumePortaMalas_){
    string vetor[8];
    vetor[0]=cor_;
    vetor[1]=modelo_;
    vetor[2]=placa_;
    vetor[3]=rodas_;
    vetor[4]=ano_;
    vetor[5]=maxPassageiros_;
    vetor[6]=combustivel_;
    vetor[7]=volumePortaMalas_;
    /**Testando o formato da placa*/    
    bool erro = false;
    string maiusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numeros = "0123456789";
    int tamanho_placa = vetor[2].length();
    string placa = vetor[2];

    
    if(tamanho_placa!=8){
        cout<<"Tamanho da placa inválido"<<endl;
        erro =true;
    }

    int ehmaiuscula =0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 26; j++){
            if(placa[i]==maiusculas[j]){
                ehmaiuscula++;
            }            
        }        
    }

    int ehnumero = 0;
    for (int i = 4; i < 8; i++){
        for (int j = 0; j < 26; j++){
            if(placa[i]==numeros[j]){
                ehnumero++;
            }            
        }        
    }
    if(ehnumero!=4||placa[3]!='-' || ehmaiuscula!=3){
        cout<<"Formato da placa errado"<<endl;
        erro=true;
    }

    /**testando entradas que deveriam ser do tipo int*/
    string rodas = vetor[3];
    int tamanho_rodas = vetor[3].length();
    string ano = vetor[4];
    int tamanho_ano = vetor[4].length();
    string maxPassageiros = vetor[5];
    int tamanho_maxPassageiros = vetor[5].length();
    string combustivel = vetor[6];
    int tamanho_combustivel = vetor[6].length();
    string volumePortaMalas= vetor[7];
    int tamanho_volumePortaMalas = vetor[7].length();

    if(ehNumero(rodas,tamanho_rodas)==false){
        cout<<"Rodas tem que ser do tipo inteiro!"<<endl;
        erro=true;
    }
    if(ehNumero(ano,tamanho_ano)==false){
        cout<<"Ano tem que ser do tipo inteiro!"<<endl;
        erro=true;
    }
    if(ehNumero(maxPassageiros,tamanho_maxPassageiros)==false){
        cout<<"Max Passageiros tem que ser do tipo inteiro!"<<endl;
        erro=true;
    }
    if(ehNumero(combustivel,tamanho_combustivel)==false){
        cout<<"Combustivel tem que ser do tipo double!"<<endl;
        erro=true;
    }
    if(ehNumero(volumePortaMalas,tamanho_volumePortaMalas)==false){
        cout<<"Volume do portamalas tem que ser do tipo double!"<<endl;
        erro=true;
    }
    if(erro==true){
        return false;
    }
    return true;

}

bool Carro::ehNumero(string palavra, int tamanhoPalavra){ 
    string numeros = "0123456789.";
    int cont_validos=0;

    for (int i = 0; i < tamanhoPalavra; i++){
        for (int j = 0; j < 11; j++){
            if(palavra[i]==numeros[j]){
                cont_validos++;

            }
        }
    }
   
    if(tamanhoPalavra!=cont_validos){
        return false;
    }  

    return true;  
}