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

public:
    Veiculo();
    Veiculo(std::string cor, std::string modelo, int rodas, int ano, int maxPassageiros);
    
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

};

#endif
