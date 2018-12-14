/**
 * @file    estacionamento.cpp
 * @author  Grupo LP 1
 * @brief   Implementação da classe 'estacionamento' para o Projeto Final de LP I
 * @since   12-06-2018
 * @date    12-12-2018
 * @version 1.0
 * 
 * @copyright Copyright (c) 2018
 * 
 */
#include "estacionamento.h"
#include "buscarVeiculo.h"
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;


Estacionamento::Estacionamento(int numeroDeVagas, std::string arquivoVeiculos, std::string arquivoOcorrencias) : m_numeroDeVagas(numeroDeVagas), m_arquivoVeiculos(arquivoVeiculos), m_arquivoOcorrencias(arquivoOcorrencias)
{
    this->lerArquivoVeiculos();
	this->lerArquivoOcorencias();
}

Estacionamento::~Estacionamento()
{

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


/** Getters */

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


/** Verifica se o estacionamento está cheio. */ 
bool Estacionamento::isFull()
{
    return this->getVagasOcupadas() == this->getNumeroDeVagas();
}

/** Verifica se o estacionamento está vazio. */ 
bool Estacionamento::isEmpty()
{
    return this->m_ocorrencias.size() == 0;
}

/** Métodos úteis. */

/**
 * @brief      Metódo para controlar a entrada de veiculos.
 *
 * @param      novoVeiculo  Veículo que irá entrar no estacionamento
 * @param      log          Arquivo para salvar as ocorrencias,
 *
 * @return     True, caso o veiculo não esteja no estacionamento. False caso contrario.
 */
bool Estacionamento::entradaVeiculo(Veiculo &novoVeiculo, Ocorrencia &log)
{
	if(this->isFull()){
		cout << "Não há vagas. Estacionamento LOTADO. " << endl;
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

    	cout<<"Já existe um veiculo com essa placa no estacionamento."<<endl;
    	return false;
    }

    return true;
}

/**
 * @brief      		Metódo para controlar a saida de veiculos.
 *
 * @param  placa  	Placa do carro que está saindo.
 *
 * @return     		True, caso a saida do veiculo tenha sido sucedida. False caso
 *             contrario.
 */
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

			cout << "Saída de veiculo:" << endl;
			cout << *veic << endl;
			cout << "Valor pago (R$): " << saida.getTotalPago() << endl;
			return true;
		}else{
			cout << "O veículo já deixou o estacionamento. " << endl;
		}
	} else {
		cout << "O veículo não existe no estacionamento. " << endl;
	}
	return false;
}

/** Lista os veículos no estaciomaneto. */
void Estacionamento::listarVeiculos()
{
	cout << "VEÍCULOS CADASTRADOS" << endl; 
	cout << "--------------------" << endl; 
    for(auto it = this->m_veiculos.begin(); it != this->m_veiculos.end(); it++){
		Veiculo* veic = it->second;
        cout << (*veic) << endl;
    }
}

/** Lista as ocorrencias em aberto. */
void Estacionamento::listarOcorrenciasAbertas()
{
	cout << "OCORRÊNCIAS ABERTAS" << endl; 
	cout << "-------------------" << endl; 

    for(auto it = this->m_ocorrencias.begin(); it != this->m_ocorrencias.end(); it++){
		Ocorrencia* oc = it->second;
        cout << (*oc) << endl;
    }
}

/** Lista todas as ocorrencias */
void Estacionamento::listarOcorrenciasTotais()
{
	
	ifstream arq(this->m_arquivoOcorrencias);
    string linha;
    if(arq.is_open() == 0){
		cout << "Nao foi possivel acessar o arquivo de ocorrencias!" << endl;
		cout << "Verifique se ele existe e está acessível." << endl;
        return;
    };

	cout << "OCORRÊNCIAS REGISTRADAS " << endl; 
	cout << "-----------------------" << endl; 

	while(getline(arq, linha)){
        Ocorrencia* log = new Ocorrencia(linha, this->m_veiculos);
		if(log->getVeiculo() != nullptr){
			cout << (*log) << endl << endl;
		};
    };
}

/**
 * @brief      Salva as ocorrencias no arquivo de log
 *
 * @param      log   Arquivo que receberá as ocorrencias
 *
 * @return     True, caso salve corretamente. False caso contrario.
 */
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

/**
 * @brief      Salva os veiculos no arquivo de log
 *
 * @param      veicu   Arquivo que receberá os veiculos
 *
 * @return     True, caso salve corretamente. False caso contrario.
 */
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


/**
 * @brief      Método para ler o arquivo de log dos Veiculos
 *
 * @return     True, caso leia corretamente. False caso contrario.
 */
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

/**
 * @brief      Método para ler o arquivo de log das Ocorrencias
 *
 * @return     True, caso leia corretamente. False caso contrario.
 */
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


/**
 * @brief      Método que inicia todo o sistema Estacionamento.
 */
void Estacionamento::iniciarOperacao()
{
    bool sair = false;
	char opt;

	system("clear");
	cout<<
	" SISTEMA DE GERENCIAMENTO DE ESTACIONAMENTO" << endl <<
	"---------------------------------------------" << endl;

	while(!sair) {

		cout << "MENU INICIAL:" << endl << 
			"(1) Entrada de Veiculo" << endl <<
			"(2) Saida de Veiculo" << endl <<
			"(3) Exibir Ocorrências Abertas" << endl <<
			"(4) Listar Veiculos Cadastros" << endl <<
			"(5) Historico de Ocorrências" << endl <<
			"(6) Sair" << endl;

		cout <<"Selecione uma opção: ";
		cin >>  opt;

		system("clear");
		switch(opt) {

			case '1':
				this->selecionarTipoVeiculo();
				continuarOperacao();
				break;

			case '2':
				{

					string placa;
					cout << "Digite a placa do veiculo: ";
					cin >> placa;
					this->saidaVeiculo(placa);
					continuarOperacao();
					break;
				}

			case '3':
				{
					this->listarOcorrenciasAbertas();
					continuarOperacao();
					break;
				}

			case '4':
				{
					this->listarVeiculos();
					continuarOperacao();
					break;
				}

			case '5':
				{
					this->listarOcorrenciasTotais();
					continuarOperacao();
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

void Estacionamento::continuarOperacao(){
	char opt2;

	cout << endl <<
	"(0)Menu inicial" <<endl<<
	"(6)Sair do programa " <<endl;
	
	cout <<"Selecione uma opção: ";
	cin >> opt2;
	
	switch(opt2) {
		case '0':
			system("clear");
			cout<<
			" SISTEMA DE GERENCIAMENTO DE ESTACIONAMENTO" << endl <<
			"---------------------------------------------" << endl;
			break;

		case '6':
			exit(0);
		default:
			cout<< "Opção invalida.Tente novamente." << endl;
			continuarOperacao();
	}
}

/**
 * @brief      Método para selecionar o tipo do veiculo no Menu.
 */
void Estacionamento::selecionarTipoVeiculo () {

	bool sair = false;
	char opt;

	system("clear");

	while(!sair) {

		cout << "Veículo a ser inserido? " << endl << 
			"(1) Moto" << endl <<
			"(2) Carro" << endl <<
			"(3) Caminhão" << endl <<
			"(4) Voltar" << endl;

		cout <<"Selecione uma opção: ";
		cin >>  opt;

		system("clear");
		switch(opt) {

			case '1':
			{
				Veiculo * moto = new Moto();
				cin >> *moto;

				if((moto->getValido())==false){
					break;
				}

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
				
				if((carro->getValido())==false){
					break;
				}

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
				
				if((caminhao->getValido())==false){
					break;
				}

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