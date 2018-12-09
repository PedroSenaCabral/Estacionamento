#include "estacionamento.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

Estacionamento::Estacionamento(int numeroDeVagas, std::string arquivoVeiculos, std::string arquivoOcorrencias) : m_numeroDeVagas(numeroDeVagas), m_arquivoVeiculos(arquivoVeiculos), m_arquivoOcorrencias(arquivoOcorrencias)
{
    // verificar se o arquivo existe e ler
}

Estacionamento::~Estacionamento()
{
    // deletar os ponteiros para as ocorrencias e veiculos?
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
    this->m_veiculos.insert(pair<string, Veiculo*>(novoVeiculo.getPlaca(),&novoVeiculo));
    this->salvarVeiculoEmArquivo(novoVeiculo);
    this->m_ocorrencias.insert(pair<string, Ocorrencia*>(novoVeiculo.getPlaca(), &log));
    this->salvarOcorrenciaEmArquivo(log);
    return true;
}

bool Estacionamento::saidaVeiculo(string placa)
{

    // o veiculo vai continuar no map para fins de histórico
    // a ocorrencia vai sair do map e ser salva como saída com a hora de saída
    return false;
}

void Estacionamento::listarVeiculos()
{
    // adicionar algum texto indicando que estamos imprimindo a lista de veículos
    for(auto it = this->m_veiculos.begin(); it != this->m_veiculos.end(); it++){
        cout << it->second << endl;
    }
}

void Estacionamento::listarOcorrenciasAbertas()
{
    // adicionar algum texto indicando que estamos imprimindo a lista de ocorrencias
    for(auto it = this->m_veiculos.begin(); it != this->m_veiculos.end(); it++){
        cout << it->second << endl;
    }
}

void Estacionamento::listarOcorrenciasTotais()
{
    // interar sobre o arquivo imprimindo todas as ocorrencias
}

bool Estacionamento::salvarOcorrenciaEmArquivo(Ocorrencia &log)
{
    if(log.getVeiculo() != nullptr){
		ofstream arq(this->m_arquivoOcorrencias,ios_base::app);
		if(arq.is_open() == 0){
			cerr << "Nao foi possivel exportar o arquivo de ocorrencias!" << endl;
        	return false;
		};
		arq << log.getLinhaCsv() << endl;
	}else{
		cout << "A orcorrencia passa é invalida!" << endl;
	};
    return false;
}

bool Estacionamento::salvarVeiculoEmArquivo(Veiculo &veic)
{
    // abrir arquivo, salvar veículo, fechar arquivo
    return false;
}
bool Estacionamento::lerArquivoVeiculos()
{
    // reconstruir o map usando o arquivo de veículos
    return false;
}
bool Estacionamento::lerArquivoOcorencias()
{
    // reconstruir o map usando o arquivo de ocorrencias
    return false;
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

}