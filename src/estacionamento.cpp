#include "estacionamento.h"
#include "buscarVeiculo.h"
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;
/**
 * @file    estacionamento.cpp
 * @author  Grupo LP 1
 * @brief   Implementação da classe 'estacionamento' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-10-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
 */

Estacionamento::Estacionamento(int numeroDeVagas, std::string arquivoVeiculos, std::string arquivoOcorrencias) : m_numeroDeVagas(numeroDeVagas), m_arquivoVeiculos(arquivoVeiculos), m_arquivoOcorrencias(arquivoOcorrencias)
{
    this->lerArquivoVeiculos();
	this->lerArquivoOcorencias();
}

Estacionamento::~Estacionamento()
{
    // deletar os ponteiros para as ocorrencias e veiculos?
}

/**
 * @brief	Método auxiliar privado para quebra da string em um vetor de string de acordo com um delimitador
 *
 * @param	linha        string a ser quebrada
 * @param	delimitador  caractere que determina a quebra
 *
 * @return 
 */
vector<string> Estacionamento::splitString(string& linha, char delimitador){
	vector<string> colunas;
	string buffer = "";
	for(unsigned i = 0; i < linha.size(); i++){
		char c = linha[i];
		if(c == delimitador){
			colunas.push_back(buffer);
			buffer = "";
		}else{
			string letra(1, c);
			buffer += letra;
		};
	};
	if(buffer != "") colunas.push_back(buffer);
	return colunas;
}

int Estacionamento::getNumeroDeVagas()
{
    return this->m_numeroDeVagas;
}

int Estacionamento::getVagasLivres()
{
    return this->getNumeroDeVagas() - this->getVagasOcupadas();
}

int Estacionamento::getVagasOcupadas()
{
    return this->m_ocorrencias.size();
}

bool Estacionamento::isFull()
{
    return this->getVagasOcupadas() == this->getNumeroDeVagas();
}

bool Estacionamento::isEmpty()
{
    return this->m_ocorrencias.size() == 0;
}

bool Estacionamento::entradaVeiculo(Veiculo &novoVeiculo, Ocorrencia &log)
{
	if(this->isFull()){
		cout << "O estacionamento esta lotado, aguarde um pouco" << endl;
		return false;
	}

	if(this->m_ocorrencias.count(novoVeiculo.getPlaca()) == 0)
	{
		if(this->m_veiculos.count(novoVeiculo.getPlaca()) == 0){
	        this->salvarVeiculoEmArquivo(novoVeiculo);
			this->m_veiculos.insert(pair<string, Veiculo*>(novoVeiculo.getPlaca(),&novoVeiculo));
		}else{
			// se já tivermos um veículo com esta placa, não adicionamos novamente ao map
			// pegamos o ponteiro da primeira entrada
			cout << "Seja bem vindo de volta!" << endl;
			log.setVeiculo(this->m_veiculos[novoVeiculo.getPlaca()]);
	    }

	    this->m_ocorrencias.insert(pair<string, Ocorrencia*>(novoVeiculo.getPlaca(), &log));
    	this->salvarOcorrenciaEmArquivo(log);

	}else{

    	cout<<"Ja existe um veiculo com essa placa no estacionamento"<<endl;
    	return false;
    }

    return true;
}

bool Estacionamento::saidaVeiculo(string placa)
{
	auto it = find_if(m_veiculos.begin(), m_veiculos.end(), BuscarVeiculo(placa));
	
	if(it != m_veiculos.end()) {

		Veiculo* veic = it->second;

		Ocorrencia saida(veic, "Saida");

		if(this->m_ocorrencias.count(placa) == 1){

			Ocorrencia* entrada = this->m_ocorrencias[placa];

			saida.calcularCusto(entrada->getTempo(), this->m_tabelaDePrecos);

			this->m_ocorrencias.erase(placa);

			this->salvarOcorrenciaEmArquivo(saida);

			cout << "Saida de veiculo: " << endl;
			cout << *veic << endl;
			cout << "O total pago foi de R$ " << saida.getTotalPago() << endl;
			return true;
		}else{
			cout << "veiculo ja deixou o estacionamento. " << endl;
		}
	} else {
		cout << "veículo não existe no estacionamento. " << endl;
	}
	return false;
}

void Estacionamento::listarVeiculos()
{
    for(auto it = this->m_veiculos.begin(); it != this->m_veiculos.end(); it++){
		Veiculo* veic = it->second;
        cout << (*veic) << endl;
    }
}

void Estacionamento::listarOcorrenciasAbertas()
{
    for(auto it = this->m_ocorrencias.begin(); it != this->m_ocorrencias.end(); it++){
		Ocorrencia* oc = it->second;
        cout << (*oc) << endl;
    }
}

void Estacionamento::listarOcorrenciasTotais()
{
	ifstream arq(this->m_arquivoOcorrencias);
    string linha;
    if(arq.is_open() == 0){
		cout << "Nao foi possivel acessar o arquivo de ocorrencias!" << endl;
		cout << "Verifique se ele existe e está acessível." << endl;
        return;
    };
	while(getline(arq, linha)){
        Ocorrencia* log = new Ocorrencia(linha, this->m_veiculos);
		if(log->getVeiculo() != nullptr){
			cout << (*log) << endl;
		};
    };
}

bool Estacionamento::salvarOcorrenciaEmArquivo(Ocorrencia &log)
{
    if(log.getVeiculo() != nullptr){
		ofstream arq(this->m_arquivoOcorrencias,ios_base::app);
		if(arq.is_open() == 0){
			cerr << "Nao foi possivel exportar para o arquivo de ocorrencias!" << endl;
        	return false;
		};
		arq << log.getLinhaCsv() << endl;
		return true;
	}else{
		cout << "A orcorrencia passa é invalida!" << endl;
	};
    return false;
}

bool Estacionamento::salvarVeiculoEmArquivo(Veiculo &veic)
{
        if(veic.getAno() != -1){
		ofstream arq(this->m_arquivoVeiculos,ios_base::app);
		if(arq.is_open() == 0){
			cerr << "Nao foi possivel exportar para o arquivo de veiculos!" << endl;
        	return false;
		};
		arq << veic.toLinhaCsv() << endl;
		return true;
	}else{
		cout << "A orcorrencia passa é invalida!" << endl;
	};
    return false;
}
bool Estacionamento::lerArquivoVeiculos()
{
	ifstream arq(this->m_arquivoVeiculos);
    string linha;
    if(arq.is_open() == 0){
		cout << "Nao foi possivel importar o arquivo de veiculos!" << endl;
		cout << "Verifique se ele existe e está acessível." << endl;
        return false;
    };
	while(getline(arq, linha)){
        vector<string> colunas = this->splitString(linha, ';');
		if(colunas.size() < 8){
			continue;
		}else{
			Veiculo* veic = nullptr;
			string tipo = colunas[1];
			if(tipo == "Moto"){
				veic = new Moto(colunas[2], colunas[3], colunas[0], stoi(colunas[4]), stoi(colunas[5]), stoi(colunas[6]), stoi(colunas[7]));
			}else if(tipo == "Carro"){
				veic = new Carro(colunas[2], colunas[3], colunas[0], stoi(colunas[4]), stoi(colunas[5]), stoi(colunas[6]), stod(colunas[7]), stod(colunas[8]));
			}else if(tipo == "Caminhao"){
				veic = new Caminhao(colunas[2], colunas[3], colunas[0], stoi(colunas[4]), stoi(colunas[5]), stoi(colunas[6]), stoi(colunas[7]), stod(colunas[8]));
			};
			if(veic != nullptr){
				this->m_veiculos.insert(pair<string, Veiculo*>(veic->getPlaca(), veic));
			}
		};
    };
	return true;
}
bool Estacionamento::lerArquivoOcorencias()
{
	ifstream arq(this->m_arquivoOcorrencias);
    string linha;
    if(arq.is_open() == 0){
		cout << "Nao foi possivel importar o arquivo de ocorrencias!" << endl;
		cout << "Verifique se ele existe e está acessível." << endl;
        return false;
    };
	while(getline(arq, linha)){
        Ocorrencia* log = new Ocorrencia(linha, this->m_veiculos);
		if(log->getVeiculo() != nullptr){
			if(this->m_ocorrencias.count(log->getVeiculo()->getPlaca()) == 1){
				// se já tem uma ocorrencia igual, está ocorrencia é de saída, então removemos a ocorrencia de entrada
				this->m_ocorrencias.erase(log->getVeiculo()->getPlaca());
			}else{
				// se não, é uma ocorrencia de entrada, então inseriomos
				this->m_ocorrencias.insert(pair<string, Ocorrencia*>(log->getVeiculo()->getPlaca(), log));
			};
		};
    };
	return true;
}

void Estacionamento::iniciarOperacao()
{
    bool sair = false;
	char opt;

	system("clear");

	while(!sair) {

		cout << "Opções: " << endl << 
			"(1) Entrada de Veiculo" << endl <<
			"(2) Saida de Veiculo" << endl <<
			"(3) Exibir Ocorrências Abertas" << endl <<
			"(4) Listar Veiculos Cadastros" << endl <<
			"(5) Historico de Ocorrências" << endl <<
			"(6) Sair" << endl;

		cin >>  opt;

		system("clear");
		switch(opt) {

			case '1':
				this->selecionarTipoVeiculo();
				break;

			case '2':
				{

					string placa;
					cout << "Digite a placa do veiculo: ";
					cin >> placa;
					this->saidaVeiculo(placa);
					break;
				}

			case '3':
				{
					this->listarOcorrenciasAbertas();
					break;
				}

			case '4':
				{
					this->listarVeiculos();
					break;
				}

			case '5':
				{
					this->listarOcorrenciasTotais();
					break;
				}
				
			case '6':
				sair = true;
				break;


			default:
				cout<< "Opção invalida.\n\n";
		}
	}

}


void Estacionamento::selecionarTipoVeiculo () {

	 bool sair = false;
	char opt;

	system("clear");

	while(!sair) {

		cout << "Qual o tipo de veículo? " << endl << 
			"(1) Moto" << endl <<
			"(2) Carro" << endl <<
			"(3) Caminhão" << endl <<
			"(4) Voltar" << endl;

		cin >>  opt;

		system("clear");
		switch(opt) {

			case '1':
			{
				Veiculo * moto = new Moto();
				cin >> *moto;

				Ocorrencia * ocorrencia = new Ocorrencia(moto);
		
				system("clear");

				if(entradaVeiculo((*moto), (*ocorrencia)))
				{	
					cout << "Entrada liberada." << endl;
				}else{
					cout << "Verifique se os dados estao corretos" << endl;
				}

				break;
			}
				
			case '2':
			{
				Veiculo * carro = new Carro();
				cin >> *carro;
				
				Ocorrencia * ocorrencia = new Ocorrencia(carro);

				system("clear");
				
				if(entradaVeiculo((*carro), (*ocorrencia)))
				{	
					cout << "Entrada liberada." << endl;
				}else{
					cout << "Verifique se os dados estao corretos" << endl;
				}

				break;
			}

			case '3':
			{
				Veiculo * caminhao = new Caminhao();
				cin >> *caminhao;
				
				Ocorrencia * ocorrencia = new Ocorrencia(caminhao);

				system("clear");

				if(entradaVeiculo((*caminhao), (*ocorrencia)))
				{	
					cout << "Entrada liberada." << endl;
				}else{
					cout << "Verifique se os dados estao corretos" << endl;
				}


				break;
			}

			case '4':
				sair = true;
				break;

			default:
				cout<< "Opção invalida.\n\n";
		}
	}


}