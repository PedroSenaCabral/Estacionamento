#include "estacionamento.h"

using namespace std;

int main(int argc, char const *argv[])
{

	Estacionamento parking(50, "files/logVeiculos.csv", "files/logOcorrencias.csv");

	parking.iniciarOperacao();

	return 0;

}