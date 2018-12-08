#ifndef MOTO_H
#define MOTO_H

#include "veiculo.h"
#include <string>

using namespace std;

class Moto : public Veiculo{
    private:
        int m_cilindradas;

    public:
    //Moto();
      Moto(string cor_, string modelo_, string placa_, string tipo_, int rodas_, int ano_, int maxPassageiros_, int cilindradas_);
      ~Moto();

      string getTipo();
      double getConsumoPorKm();
      int getCilindradas();
      void setCilindradas(int cilindradas_);
      void print(ostream &cout);
      void put(std::istream &cin);

      friend ostream &operator<<(ostream &os, Moto &m);
};

#endif