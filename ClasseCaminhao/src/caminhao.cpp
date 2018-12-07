#include "veiculo.h"

Caminhao::Caminhao(std::string cor, std::string modelo, std::string placa, std::string tipo, int rodas, int ano, int maxPassageiros,int eixos, float peso):
Veiculo(std::string cor, std::string modelo, int rodas,
  int ano, int maxPassageiros),
  quant_eixos(eixos),peso_carga(peso),consumo(consumo_){};

Caminhao::~Caminhao();

int Caminhao::getEixo()
{
  return this->quant_eixos;
}

float Caminhao::getPeso()
{
  return this->peso_carga;
}

double Caminhao::getConsumoPorKM()
{
  return this->consumo;
}

void Caminhao::print(ostream& cout)
{

}

void Caminhao::put(istream& cin)
{

}

ostream& operator<< (ostream& ostr, Caminhao* v)
{
    v->print(ostr);
    return ostr;
}

istream& operator>> (istream& istr, Caminhao* v)
{
	v->put(istr);
	return istr;
}
