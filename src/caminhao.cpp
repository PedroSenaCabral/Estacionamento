/**
 * @file    caminhao.cpp
 * @author  Grupo LP 1
 * @brief   Implementação da classe 'caminhão' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "caminhao.h"


/** Construtor parametrizado */
Caminhao::Caminhao(string cor, string modelo, string placa, int rodas, int ano, int maxPassageiros,int eixos, double peso):
  Veiculo(cor, modelo, placa, rodas, ano, maxPassageiros),
  m_quant_eixos(eixos),m_peso_carga(peso){}


/**
 * @brief      Construtor padrão
 */
Caminhao::Caminhao():Veiculo("Nao definido", "Nao definido", "OOO-0000", -1, -1, -1) { 
  this->m_peso_carga = -1;
  this->m_quant_eixos = -1;
}

/** Destrutor */
Caminhao::~Caminhao(){}

/** Getters */ 

/**
 * @brief      Método get que retorna a quantidade de eixos.
 *
 * @return     Variavél do tipo int com a quantidade de eixos.
 */
int Caminhao::getEixo()           { return this->m_quant_eixos; }

/**
 * @brief      Método get que retorna o peso do caminhao.
 *
 * @return     Variavél do tipo double com o peso.
 */
double Caminhao::getPeso()        { return this->m_peso_carga; }

/**
 * @brief      Implementacao do metodo virtual da classe base 'getConsumoPorKM'.
 *
 * @return     Consumo de combustivel do caminhao.
 */
double Caminhao::getConsumoPorKM(){ return 8.5; }

/**
 * @brief      Método get que retorna o tipo do Veículo que será util na tabela de preços.
 *
 * @return     Variavél do tipo string com a tipo definido para "Caminhao".
 */
string Caminhao::getTipo()        { return "Caminhao"; }

/** Setters */


/**
 * @brief      Método que modifica o valor do peso do caminhão.
 *
 * @param  peso_  Variável do tipo double que terá o novo valor.
 */
void Caminhao::setPeso(double peso_){ this->m_peso_carga = peso_; }

/**
 * @brief      Implementação do metodo virtual da classe base 'print'.
 *
 * @param      ct   Stream de saída com os dados do Caminhão formatados.
 */
void Caminhao::print(ostream& ct)
{
    ct  << "Cor: " << this->m_cor << std::endl
        << "Modelo: " << this->m_modelo << std::endl
        << "Placa: " << this->m_placa << std::endl
        << "Número de rodas: " << this->m_rodas << std::endl
        << "Ano: " << this->m_ano << std::endl
        << "Máx Passageiros: " << this->m_maxPassageiros << std::endl
        << "Quantidade de Eixo: " << this->m_quant_eixos << std::endl
        << "Peso da carga : " << this->m_quant_eixos << std::endl
        << "Consumo Km/l : " << this->getConsumoPorKM()<< std::endl;
}

/**
 * @brief      Implementação do metodo virtual da classe base 'put'.
 *
 * @param      is  Stream de entrada para guardar os dados do Caminhão.
 */
void Caminhao::put(istream& is)
{
  std::cout<< "Entrada de Veículo - Caminhao" << std::endl 
    << "Por favor, inserir as informções na seguinte ordem:" << std::endl 
    << "Cor, Modelo, Placa, Num Rodas, Ano, Máx Passageiros, Quantidade de Eixo, Peso da carga." << std::endl;
  
     string cor_,modelo_,placa_,rodas_,ano_,maxPassageiros_,quant_eixos_,peso_carga_;
        
        is >> cor_
            >> modelo_
            >> placa_ 
            >> rodas_ 
            >> ano_ 
            >>maxPassageiros_
            >> quant_eixos_
            >> peso_carga_;  
        if(formatoCorreto(cor_,modelo_,placa_,rodas_,ano_,maxPassageiros_,quant_eixos_,peso_carga_)){
            this->m_cor = cor_;
            this->m_modelo  = modelo_;
            this->m_placa = placa_;
            this->m_rodas = stoi(rodas_);
            this->m_ano = stoi(ano_);
            this->m_maxPassageiros = stoi(maxPassageiros_);
            this->m_quant_eixos  = stoi(quant_eixos_);
            this->m_peso_carga = stod(peso_carga_);                
        }else{
            m_valido = false;
        }





}

/**
 * @brief      Prepara a linha para o arquivo CSV
 *
 * @return     Os dados do Carro formatados e separados por ponto e virgula.
 */
string Caminhao::toLinhaCsv(){
  return this->m_placa + ";" + this->getTipo() + ";" + this->m_cor + ";" + this->m_modelo + ";" + to_string(this->m_rodas)  + ";" + to_string(this->m_ano) + ";" + to_string(this->m_maxPassageiros) + ";" + to_string(this->m_quant_eixos)  + ";" + to_string(this->m_peso_carga);
}

/** Sobrecarga de operadores */

ostream& operator<< (ostream& ostr, Caminhao& v)
{
    v.print(ostr);
    return ostr;
}

istream& operator>> (istream& istr, Caminhao& v)
{
	v.put(istr);
	return istr;
}



bool Caminhao::formatoCorreto(string cor_, string modelo_, string placa_, string rodas_, string ano_, string maxPassageiros_, string eixos_, string peso_){
    string vetor[8];
    vetor[0]=cor_;
    vetor[1]=modelo_;
    vetor[2]=placa_;
    vetor[3]=rodas_;
    vetor[4]=ano_;
    vetor[5]=maxPassageiros_;
    vetor[6]=eixos_;
    vetor[7]=peso_;
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
    string eixos = vetor[6];
    int tamanho_eixos = vetor[6].length();
    string peso= vetor[7];
    int tamanho_peso = vetor[7].length();

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
    if(ehNumero(eixos,tamanho_eixos)==false){
        cout<<"Eixos tem que ser do tipo inteiro!"<<endl;
        erro=true;
    }
    if(ehNumero(peso,tamanho_peso)==false){
        cout<<"Peso do portamalas tem que ser do tipo double!"<<endl;
        erro=true;
    }
    if(erro==true){
        return false;
    }
    return true;

}

bool Caminhao::ehNumero(string palavra, int tamanhoPalavra){ 
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