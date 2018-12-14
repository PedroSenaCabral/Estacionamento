/**
 * @file    moto.cpp
 * @author  Grupo LP 1
 * @brief   Implementação da classe 'moto' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "moto.h"

/**
 * @brief Construtor sem parâmetros da classe Moto. Inicia os atributos como Padrão, "Nao definido" e -1.
 * 
 */
Moto::Moto():
    Veiculo("Nao definido", "Nao definido", "OOO-0000", -1, -1, -1), 
    m_cilindradas(-1){}

/**
 * @brief Construtor parametrizado da classe Moto.
 * 
 * @param cor_ Cor do veículo;
 * @param modelo_ Modelo do veículo;
 * @param placa_ Placa do veículo;
 * @param tipo_ Tipo do veículo (Carro, Moto, Caminhão);
 * @param rodas_ Quantidade de rodas do veículo;
 * @param ano_ Ano do veículo;
 * @param maxPassageiros_ Quantidade máxima de passageiros suportada pelo veículo;
 * @param cilindradas_ Cilindradas da Moto.
 */
Moto::Moto(string cor_, string modelo_, string placa_, int rodas_, int ano_, int maxPassageiros_, int cilindradas_):
    Veiculo(cor_, modelo_, placa_, rodas_, ano_, maxPassageiros_), 
    m_cilindradas(cilindradas_){}

/**
 * @brief Destrutor da Classe Moto. Imprime uma zoeria.
 * 
 */
Moto::~Moto(){
    cout << "O grau acabou." << endl;
}

/**
 * @brief Sobrecarga do método getTipo da classe Veiculo. Retorna o tipo do veículo (Moto).
 * 
 * @return string
 */
string Moto::getTipo(){
    return "Moto";
}

/**
 * @brief Sobrecarga do método getConsumoPorKm da classe Veiculo. Retorna o consumo de combustível por Km.
 * 
 * @return double 
 */

double Moto::getConsumoPorKM(){
    return 2.0;
}

/**
 * @brief Retorna as cilindradas.
 * 
 * @return int 
 */
int Moto::getCilindradas(){
    return m_cilindradas;
}


/**
 * @brief Método de ajuste para as cilindradas da Moto.
 * 
 * @param cilindradas_ Novo valor para cilindrada da Moto.
 */
void Moto::setCilindradas(int cilindradas_){
    this->m_cilindradas = cilindradas_;
}

/**
 * @brief Sobrecarga do método print da classe Veiculo.
 * 
 * @param os Fluxo de saída.
 */
void Moto::print(ostream &cout){
    cout<< "Cor: " << this->m_cor << std::endl
        << "Modelo: " << this->m_modelo << std::endl
        << "Placa: " << this->m_placa << std::endl
        << "Número de rodas: " << this->m_rodas << std::endl
        << "Ano: " << this->m_ano << std::endl
        << "Máx Passageiros: " << this->m_maxPassageiros << std::endl
        << "Cilindradas: " << this->m_cilindradas << endl;
}

/**
 * @brief Sobrecarta do método put da classe Veiculo.
 * 
 * @param is Fluxo de entrada.
 */
void Moto::put(istream &is){
    
       string cor_,modelo_,placa_,rodas_,ano_,maxPassageiros_,cilindradas_;
        
       std::cout<< "<<INSIRA OS DADOS DA MOTO>>" << std::endl;
                 
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
        cout<<"Cilindradas: ";
        is >> cilindradas_;

        if(formatoCorreto(cor_,modelo_,placa_,rodas_,ano_,maxPassageiros_,cilindradas_)){
            this->m_cor = cor_;
            this->m_modelo  = modelo_;
            this->m_placa = placa_;
            this->m_rodas = stoi(rodas_);
            this->m_ano = stoi(ano_);
            this->m_maxPassageiros  = stoi(maxPassageiros_);
            this->m_cilindradas = stoi(cilindradas_);                
        }else{
            m_valido = false;
        }
}

string Moto::toLinhaCsv(){
    return this->m_placa + ";" + this->getTipo() + ";" + this->m_cor + ";" + this->m_modelo + ";" + to_string(this->m_rodas)  + ";" + to_string(this->m_ano) + ";" + to_string(this->m_maxPassageiros) + ";" + to_string(this->m_cilindradas);
}

/**
 * @brief Sobrecarga do operador de inserção (<<) da classe Moto.
 * 
 * @param os Fluxo de saída;
 * @param m Objeto Moto que será inserido no fluxo.
 * @return ostream& 
 */
ostream &operator<<(ostream &os, Moto &m){
    m.print(os);
    return os;
}

/**
 * @brief Sobrecarga do operador de extração (>>) da classe Moto.
 * 
 * @param is Fluxo de entrada;
 * @param m Objeto Moto do qual será extraído do fluxo.
 * @return istream& 
 */
istream &operator>>(istream &is, Moto &m){
    m.put(is);
    return is;
}

bool Moto::formatoCorreto(string cor_, string modelo_, string placa_, string rodas_, string ano_, string passageiros_, string cilindradas_){
    string vetor[7];
    vetor[0]=cor_;
    vetor[1]=modelo_;
    vetor[2]=placa_;
    vetor[3]=rodas_;
    vetor[4]=ano_;
    vetor[5]=passageiros_;
    vetor[6]=cilindradas_;
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
    string passageiros = vetor[5];
    int tamanho_passageiros = vetor[5].length();
    string cilindradas = vetor[6];
    int tamanho_cilindradas = vetor[6].length();

    if(ehNumero(rodas,tamanho_rodas)==false){
        cout<<"Rodas tem que ser do tipo inteiro!"<<endl;
        erro=true;
    }
    if(ehNumero(ano,tamanho_ano)==false){
        cout<<"Ano tem que ser do tipo inteiro!"<<endl;
        erro=true;
    }
    if(ehNumero(passageiros,tamanho_passageiros)==false){
        cout<<"Max Passageiros tem que ser do tipo inteiro!"<<endl;
        erro=true;
    }
    if(ehNumero(cilindradas,tamanho_cilindradas)==false){
        cout<<"Cilindradas tem que ser do tipo inteiro!"<<endl;
        erro=true;
    }
    if(erro==true){
        return false;
    }
    return true;

}

bool Moto::ehNumero(string palavra, int tamanhoPalavra){ 
    string numeros = "0123456789";
    int cont_validos=0;

    for (int i = 0; i < tamanhoPalavra; i++){
        for (int j = 0; j < 10; j++){
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