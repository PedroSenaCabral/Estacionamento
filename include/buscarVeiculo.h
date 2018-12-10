#ifndef BUSCAR_VEICULO
#define BUSCAR_VEICULO

#include <string>
#include "veiculo.h"

class BuscarVeiculo {

private:

	string placa;

public:
	BuscarVeiculo(string buscarPlaca) : placa (buscarPlaca) {}
	
	bool operator()(pair<string, Veiculo*> aux) const {
		
		return (placa.compare(aux.second->getPlaca()) == 0); 
	}

};

#endif