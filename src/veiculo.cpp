#include "veiculo.h"
using namespace std;

Veiculo::Veiculo(){}

Veiculo::Veiculo(std::string cor, std::string modelo, int rodas, int ano, int maxPassageiros) : cor(cor),
            modelo(modelo), rodas(rodas), ano(ano), maxPassageiros(maxPassageiros) {}

Veiculo::~Veiculo(){}

string Veiculo::getCor() { return this->cor; };
string Veiculo::getModelo() { return this->modelo; };
int    Veiculo::getRodas() {return this->rodas; };
int    Veiculo::getAno() { return this->ano; };
int    Veiculo::getMaxPassageiros() { return this->maxPassageiros; };

void   Veiculo::setCor(std::string cor) { this->cor = cor;}
void   Veiculo::setModelo(std::string modelo) { this->modelo = modelo;}
void   Veiculo::setAno(int ano) { this->ano = ano;}
void   Veiculo::setRodas(int quantidade) { this->rodas = quantidade;}
void   Veiculo::setMaxPassageiros(int maxPassageiros) { this->maxPassageiros = maxPassageiros;}

ostream& operator<< (ostream& ostr, Veiculo* v)
{
	v->print(ostr);
	return ostr;
}
