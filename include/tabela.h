#ifndef TABELA_H
#define TABELA_H

#include <iostream>
#include <string>
<<<<<<< HEAD

=======
>>>>>>> 27ce42034cfaf111a25a790cc2105e271b98ab1d

class Tabela
{
private:
	double m_pCarro;
	double m_pMoto;
	double m_pCaminhao;

public:
	Tabela();
	Tabela(double, double, double);
	~Tabela();

	/** Getters */
	double getPcarro();
	double getPmoto();
	double getPcaminhao();
	double getValor(std::string tipo_);

	/** Setters */
	void setPcarro(double);
	void setPmoto(double);
	void setPcaminhao(double);

	double getValor(std::string);

	
};


#endif
