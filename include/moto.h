#ifndef MOTO_H
#define MOTO_H

#include "veiculo.h"
#include <string>

using namespace std;

class Moto : public Veiculo{
    private:
        int m_cilindradas;

    public:
    /* Construtores */
      Moto();
      Moto(string cor_, string modelo_, string placa_, string tipo_, int rodas_, int ano_, int maxPassageiros_, int cilindradas_);
      
    /* Destrutor */  
      ~Moto();

    /* Getters */
      string getTipo();
      double getConsumoPorKM() override;
      int getCilindradas();

    /* Setters */  
      void setCilindradas(int cilindradas_);
    
    /* Inserção e extração dos fluxos */
      void print(ostream &cout);
      void put(istream &cin);

    /* Sobrecarga de operadores */
      friend ostream &operator<<(ostream &os, Moto &m);
      friend istream &operator>>(istream &is, Moto &m);
};

#endif