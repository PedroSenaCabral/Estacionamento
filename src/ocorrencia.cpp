#include <string>
#include <iostream>

#include "ocorrencia.h"

/*construtor parametrizado, recebe uma referencia para veiculo e pega seu tipo*/
Ocorrencia::Ocorrencia (int Hentrada, int Mentrada, int Hsaida, int Msaida, int dias_, Veiculo &automovel){
	 if(horaEntrada < 0||horaEntrada >24){
        std::cerr<<" ERRO, hora de entrada invalida. "<<std::endl;
        }

    if(horaSaida < 0|| horaSaida > 24){
        std::cerr<<" ERRO, hora de saida invalida. "<<std::endl;
        }

    if(minEntrada < 0 || minEntrada > 60){
        std::cerr<<" ERRO, minuto de entrada invalido. "<<std::endl; 
        }

    if(minSaida < 0 || minSaida > 60){
        std::cerr<< "ERRO, minuto de saida invalido. "<<std::endl;
        }

    if(dias < 0){
        std::cerr<< "ERRO, valor de dia invalido. "<<std::endl;
        }

	else{
		horaEntrada = Hentrada;
    	minEntrada = Mentrada;
    	horaSaida = Hsaida;
    	minSaida = Msaida;
    	dias = dias_;
		tipoVeiculo = automovel.getTipo();

		calcularCusto();  //ja chama a função que calcula o custo para evitar 
						  //que o usuario tente printar a ocorrencia sem ter o valor de custo
	}
}



std::string Ocorrencia::getTipoVeiculo()
{
	return tipoVeiculo;
}

int Ocorrencia::getHoraEntrada ()
{
	return horaEntrada;
}

int Ocorrencia::getHoraSaida ()
{
	return horaSaida;
}

int Ocorrencia::getMinEntrada ()
{
	return minEntrada;
}

int Ocorrencia::getMinSaida ()
{
	return minSaida;
}

int Ocorrencia::getDias ()
{
	return dias;
}

int Ocorrencia::getCusto ()
{
	return custo;
}


void Ocorrencia::printOcorrencia ()
{
	std::cout<<"Veiculo : " <<tipoVeiculo <<std::endl;
	std::cout<<"Entrada : " <<horaEntrada <<"h " <<minEntrada<<"min "<<std::endl;
	std::cout<<"Saida : " <<horaSaida <<"h " <<minSaida<<"min "<<std::endl;
	std::cout<<"Custo : " <<custo<< " R$ "<<std::endl;
}


/*Função de calcular o custo, Funcionamento:
   
A função assume que cada tipo de veiculo tem um valor fixo para entrar no estacionamento, 
   a partir dai, é cobrado o valor de 1 real por hora no estacionamento.  
     		
Exemplo
   entrada -> 16:30, saida -> 15:00, e dias = 1, isso quer dizer que:
     -entrou as 16:30 do primeiro dia,
     -passou o segundo dia inteiro,	
     -saiu as 15:00 do terceiro dia.
*/

void Ocorrencia::calcularCusto ()
{
	if(horaEntrada==horaSaida){
		custo = Tabela.getValor(tipoVeiculo) + 24*dias;
		//ex: ficou 16:10 ate 16:40, não passou uma hora, so paga o valor fixo.
		}

	if(horaEntrada<horaSaida && minEntrada<=minSaida){
		custo = Tabela.getValor(tipoVeiculo) + (horaSaida-horaEntrada) + 24*dias;
		//ex: ficou 16:10 ate 17:30, paga o acréssimo pela hora passada.
		}

	if(horaEntrada<horaSaida && minEntrada>minSaida){
		custo = Tabela.getValor(tipoVeiculo) + (horaSaida-horaEntrada -1) +24*dias;
		//ex: 16:30 ate 18:10, não chegou a passar 2h, por isso, subtraimos 1. 
		}

	if(horaEntrada>horaSaida && minSaida>=minEntrada){
		custo = Tabela.getValor(tipoVeiculo) + 24-(horaEntrada-horaSaida) +24*dias;
		//ex: ficou 16:00 ate 15:10, 24-(16-15) = 23h 
		//ex2:ficou 23:00 ate 00:00, 24-(23-00) = 01h
		}
	
	if(horaEntrada>horaSaida && minSaida<minEntrada){
		custo = Tabela.getValor(tipoVeiculo) + 24-(horaEntrada-horaSaida+1) +24*dias; 
		//ex: ficou 23:10 ate 00:00, 24- (23-0+1) = 0h
		}
}



