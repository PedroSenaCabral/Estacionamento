#ifndef VEICULO_h
#define VEICULO_h

#include <iostream>
#include <string>

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

    friend std::ostream& operator<<(std::ostream &os, const Veiculo* v);
    friend std::istream& operator>>(std::istream &is, Veiculo *v);

};

#endif
