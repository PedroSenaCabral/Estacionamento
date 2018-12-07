#include "moto.h"

using namespace std;

Moto::Moto(){
    this->m_cor = "Nao definido";
    this->m_modelo = "Nao definido";
    this->m_placa = "OOOO-0000";
    this->m_tipo = "Nao definido";
    this->m_rodas = -1;
    this->m_ano = -1;
    this->m_maxPassageiros = -1;
    this->m_cilindradas = -1;
}

Moto::Moto(string cor_, string modelo_, string placa_, string tipo_, int rodas_, int ano_, int maxPassageiros_, int cilindradas_):
    m_cor(cor_),
    m_modelo(modelo_),
    m_placa(placa_),
    m_tipo(tipo_),
    m_rodas(rodas_), 
    m_ano(ano_), 
    m_maxPassageiros(maxPassageiros_), 
    m_cilindradas(cilindradas_){}

Moto::~Moto(){
    cout << "O grau acabou." << endl;
}

string Moto::getTipo() override{
    return "Moto";
}

double Moto::getConsumoPorKm() override{
    return 2.0;
}

int Moto::getCilindradas(){
    return m_cilindradas;
}

void Moto::setCilindradas(int cilindradas_){
    this->m_cilindradas = cilindradas_;
}

void Moto::print(ostream &os) override{
    os  << "Cor: " << this->m_cor << std::endl
        << "Modelo: " << this->m_modelo << std::endl
        << "Placa: " << this->m_placa << std::endl
        << "Número de rodas: " << this->m_rodas << std::endl
        << "Ano: " << this->m_ano << std::endl
        << "Máx Passageiros: " << this->m_maxPassageiros << std::endl
        << "Cilindradas: " << this->m_cilindradas;
}

ostream& operator<<(ostream& os, Moto& m){
    os << "Cor: " << this->m_cor << std::endl
       << "Modelo: " << this->m_modelo << std::endl
       << "Placa: " << this->m_placa << std::endl
       << "Número de rodas: " << this->m_rodas << std::endl
       << "Ano: " << this->m_ano << std::endl
       << "Máx Passageiros: " << this->m_maxPassageiros << std::endl
       << "Cilindradas: " << this->m_cilindradas;
    return os;
}