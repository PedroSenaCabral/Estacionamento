#include "veiculo.h"

using namespace std;

int main(int argc, char const *argv[])
{

	bool sair = false;
	char opt;

	system("clear");

	while(!sair) {

		cout << "Opções: " << endl << 
			"(1) Entrada de Veiculo" << endl <<
			"(2) Saida de Veiculo" << endl <<
			"(3) - Sair" << endl;

		cin >>  opt;

		system("clear");
		switch(opt) {

			case '1':

				

				cout << "ADD Veiculo";
				break;

			case '2':

				cout << "Remover Veiculo";
				break;

			case '3':
				sair = true;
				break;

			default:
				cout<< "Opção invalida.\n\n";
		}
	}



	/* code */
	return 0;
}