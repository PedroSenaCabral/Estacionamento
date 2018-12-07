#ifndef VEICULO_h
#define VEICULO_h

#include <iostream>

class Veiculo
{
private:
    std::string cor;
    std::string modelo;
    int rodas;
    int ano;
    int maxPassageiros;

    Veiculo();
    Veiculo(std::string cor, std::string modelo, int rodas, int ano, int maxPassageiros);
    ~Veiculo();
    
    std::string getCor();
    std::string getModelo();
            int getRodas();
            int getAno();
            int getMaxPassageiros();

 virtual double getConsumoPorKM() = 0;

           void setCor(std::string cor);
           void setModelo(std::string modelo);
           void setAno(int ano);
           void setRodas(int quantidade);
           void setMaxPassageiros(int maxPassageiros);

virtual void print(ostream& cout) = 0;

friend ostream& operator<<(ostream& o, Veiculo* v);

};

#endif
