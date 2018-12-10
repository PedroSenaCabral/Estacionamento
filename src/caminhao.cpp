#include "caminhao.h"

Caminhao::Caminhao(string cor, string modelo, string placa, int rodas, int ano, int maxPassageiros,int eixos, float peso):
  Veiculo(cor, modelo, placa, rodas, ano, maxPassageiros),
  m_quant_eixos(eixos),m_peso_carga(peso){}


Caminhao::Caminhao():Veiculo("Nao definido", "Nao definido", "OOO-0000", -1, -1, -1) { 
  this->m_peso_carga = -1;
  this->m_quant_eixos = -1;
}

Caminhao::~Caminhao(){}

int Caminhao::getEixo()
{
  return this->m_quant_eixos;
}

float Caminhao::getPeso()
{
  return this->m_peso_carga;
}

double Caminhao::getConsumoPorKM()
{
  return 8.5;
}

string Caminhao::getTipo()
{
  return "Caminhao";
}

void Caminhao::setPeso(float peso_)
{
  this->m_peso_carga = peso_;
}
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

void Caminhao::put(istream& cin)
{
  std::cout<< "Entrada de Veículo - Caminhao" << std::endl 
    << "Por favor, inserir as informções na seguinte ordem:" << std::endl 
    << "Cor, Modelo, Placa, Num Rodas, Ano, Máx Passageiros, Quantidade de Eixo, Peso da carga." << std::endl;
  cin >> this->m_cor >> this->m_modelo >> this->m_placa >> this->m_rodas >> this->m_ano >> this->m_maxPassageiros >> this->m_quant_eixos >> this->m_peso_carga;
}

string Caminhao::toLinhaCsv(){
  return this->m_placa + ";" + this->getTipo() + ";" + this->m_cor + ";" + this->m_modelo + ";" + to_string(this->m_rodas)  + ";" + to_string(this->m_ano) + ";" + to_string(this->m_maxPassageiros) + ";" + to_string(this->m_quant_eixos)  + ";" + to_string(this->m_peso_carga);
}

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
