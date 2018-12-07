#include <string>
#include <iostream>

#include "ocorrencia.h"

/*construtor parametrizado, recebe uma referencia para veiculo e pega seu tipo*/
Ocorrencia::Ocorrencia (int Hentrada_, int Mentrada_, int Hsaida_, int Msaida_, int dias_, Veiculo &automovel_){
	 if(Hentrada_ < 0||Hentrada_ >24){
        std::cerr<<" ERRO, hora de entrada invalida. "<<std::endl;
        }

    if(Hsaida_ < 0|| Hsaida_ > 24){
        std::cerr<<" ERRO, hora de saida invalida. "<<std::endl;
        }

    if(Mentrada_ < 0 || Mentrada_ > 60){
        std::cerr<<" ERRO, minuto de entrada invalido. "<<std::endl; 
        }

    if(Msaida_ < 0 || Msaida_ > 60){
        std::cerr<< "ERRO, minuto de saida invalido. "<<std::endl;
        }

    if(dias_ < 0){
        std::cerr<< "ERRO, valor de dia invalido. "<<std::endl;
        }

	else{
		m_horaEntrada = Hentrada_;
    	m_minEntrada = Mentrada_;
    	m_horaSaida = Hsaida_;
    	m_minSaida = Msaida_;
    	m_dias = dias_;
		m_tipoVeiculo = automovel.getTipo();

		calcularCusto();  //ja chama a função que calcula o custo para evitar 
						  //que o usuario tente printar a ocorrencia sem ter o valor de custo
	}
}



std::string Ocorrencia::getTipoVeiculo()
{
	return m_tipoVeiculo;
}

int Ocorrencia::getHoraEntrada ()
{
	return m_horaEntrada;
}

int Ocorrencia::getHoraSaida ()
{
	return m_horaSaida;
}

int Ocorrencia::getMinEntrada ()
{
	return m_minEntrada;
}

int Ocorrencia::getMinSaida ()
{
	return m_minSaida;
}

int Ocorrencia::getDias ()
{
	return m_dias;
}

int Ocorrencia::getCusto ()
{
	return m_custo;
}


void Ocorrencia::printOcorrencia ()
{
	std::cout<<"Veiculo : " <<m_tipoVeiculo <<std::endl;
	std::cout<<"Entrada : " <<m_horaEntrada <<"h " <<m_minEntrada<<"min "<<std::endl;
	std::cout<<"Saida : " <<m_horaSaida <<"h " <<m_minSaida<<"min "<<std::endl;
	std::cout<<"Custo : " <<m_custo<< " R$ "<<std::endl;
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
	if(m_horaEntrada==m_horaSaida){
		m_custo = Tabela.getValor(m_tipoVeiculo) + 24*m_dias;
		//ex: ficou 16:10 ate 16:40, não passou uma hora, so paga o valor fixo.
		}

	if(m_horaEntrada<m_horaSaida && m_minEntrada<=m_minSaida){
		m_custo = Tabela.getValor(m_tipoVeiculo) + (m_horaSaida-m_horaEntrada) + 24*m_dias;
		//ex: ficou 16:10 ate 17:30, paga o acréssimo pela hora passada.
		}

	if(m_horaEntrada<m_horaSaida && m_minEntrada>m_minSaida){
		m_custo = Tabela.getValor(m_tipoVeiculo) + (m_horaSaida-m_horaEntrada -1) +24*m_dias;
		//ex: 16:30 ate 18:10, não chegou a passar 2h, por isso, subtraimos 1. 
		}

	if(m_horaEntrada>m_horaSaida && m_minSaida>=m_minEntrada){
		m_custo = Tabela.getValor(m_tipoVeiculo) + 24-(m_horaEntrada-m_horaSaida) +24*m_dias;
		//ex: ficou 16:00 ate 15:10, 24-(16-15) = 23h 
		//ex2:ficou 23:00 ate 00:00, 24-(23-00) = 01h
		}
	
	if(m_horaEntrada>m_horaSaida && m_minSaida<m_minEntrada){
		m_custo = Tabela.getValor(m_tipoVeiculo) + 24-(m_horaEntrada-m_horaSaida+1) +24*m_dias; 
		//ex: ficou 23:10 ate 00:00, 24- (23-0+1) = 0h
		}
}



