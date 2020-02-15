//    Copyright (C) 2009 Jos� Jana�lton da Silva <josejanailton@gmail.com>
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA





#include "EstatisticaDescritiva.h"



//Inicializa a classe primitiva
EstatisticaDescritiva::EstatisticaDescritiva(int elements): Slot( elements)
{
	Calculado = false;
	DadosOrdenados = false;
}

void EstatisticaDescritiva::Add(double _data)
{
	Slot::Add(_data); //Adiciona um dado � lista
	DadosOrdenados = false; //Avisa que a lista precisa ser (re)ordenada
	Calculado = false;
}

int EstatisticaDescritiva::Arredondar( double numero)
{
	int aux1 = (int) numero;
	double aux2 = (double) aux1;

	if (aux2 == numero)
		return aux1;
	else return ++aux1;
}

void EstatisticaDescritiva::Ordenar_Dados()
{

	sort(); // Ordena os dados armazenados
	DadosOrdenados = true; // Atesta que os dados j� est�o ordenados
}

bool EstatisticaDescritiva::Dados_Ordenados()
{
	// Esta fun��o retorna true se os dados est�o ordenados na lista
	// Caso contr�rio, retorna false
	return DadosOrdenados;
}


double EstatisticaDescritiva::Amplitude_total()
{
	if (!Dados_Ordenados()) // Checa se os dados est�o ordenados
		Ordenar_Dados(); // Caso negativo, ordena os dados.

	// A Amplitude total: Maior n�mero - menor valor da lista
	return data.back() - data.front(); // Retorna o valor da amplitude total
}

int EstatisticaDescritiva::NumerodeClasses()
{
	if (Calculado)
	{
     	return numClasses;
	}
	else return -1;

}

int EstatisticaDescritiva::Numero_de_Classes()
{
	double k;
	// O n�mero de classes � obtido pela raiz quadrada do n�mero de elementos
	// dos dados que foram armazenados
	k = sqrt( static_cast< double >( data.size()) );
 
  	return Arredondar(k); //Arredonda antes de sair da fun��o
}


void EstatisticaDescritiva::CalculaFI( DistribFrequencia& f)
{
	f.Fi = 0;
	
	for (int i = 0; i< data.size(); i++)
		if (data[i] >= f.LimInferior && data[i] < f.LimSuperior)
			f.Fi++;
}

void EstatisticaDescritiva::CalculaFac( DistribFrequencia& f, double Fant)
{
	f.Fac = f.Fi + Fant;
}


int EstatisticaDescritiva::Amplitude_de_Classe()
{
    float numClasses = Numero_de_Classes();
    if (numClasses == 0.0) return 0;
	// A Amplitude de classe � Amplitude total dividida pelo n�mero de classes
	double h = Amplitude_total() / numClasses;

    h += 0.09;

	return Arredondar(h); // Arredonda o valor antes de sair da fun��o
}

double EstatisticaDescritiva::Media()
{

    if(data.size() == 0) return 0;

	double soma = 0;
	for (int i=0; i< data.size(); i++)
		soma += data[i];

 	return (soma / data.size());

}

double EstatisticaDescritiva::Mediana( double LimMediana, double tamClasse, double freqAntMediana, double freqMediana)
{

	return LimMediana + (( (data.size()/2 - freqAntMediana)*tamClasse ) / freqMediana);

}

double EstatisticaDescritiva::Mediana()
{
	/*
	double n1, n2;
	n1 = (data.size()) / 2;
	n1 = Arredondar(n1);
	n2 = n1+1;

	return (data[(int)n1] + data[(int)n2])/2;
	*/

	if( (data.size() % 2) == 0 )
	{
		return ( data[  static_cast< int >(data.size()/2) -1 ] + data[ static_cast< int >(data.size()/2) ])/2 ;

	}
	else
		return data[( (int)(data.size()+1)/2 ) -1];

}

double EstatisticaDescritiva::Moda()
{

    double aux1 = 0.0, aux2 = 0.0;
	double moda = 0.0;
	for (int i=0; i<data.size(); i++)
	{
		double aux1 = count (data.begin(), data.end(), data[i]);
		if (aux1 == 1) continue; // O numero aparece apenas uma vez, n�o nos interessa.
		if ( aux2 < aux1)
		{
			moda = data[i];
			aux2 = aux1;
		}

		
	}

	return moda;
}

double EstatisticaDescritiva::Variancia()
{
    // Se o denomnador for zero, sai da fun��o
    // Isso evita divis�o de zero por zero;

    if( (getSize()-1 == 0) )
    {
        return 0;

    }

	double media = Media();
	double aux = 0.0, aux2 = 0.0;

	for (int i = 0; i< data.size(); i++)
	{
		aux = ( data[i] - media);
		aux2 += (aux * aux);
		
	}
	return aux2 / ( getSize()-1);

}

double EstatisticaDescritiva::DesvioPadrao()
{
    return sqrt( static_cast< double >( Variancia() ) );
}

double EstatisticaDescritiva::Coeficiente_de_Variacao()
{
    // Previne divis�o por zero
    if ( Media() == 0) return 0;
    else return ( DesvioPadrao() / Media() ) * 100;
}

/*
string EstatisticaDescritiva::Criar_Distrib_Frequencia()
{

	try{

	// Esta � a fun��o mais interessante da classe, por hora...
	// Ela retorna uma string com a distribui��o de frequ�ncia

    // Ponteido para uma estrutura que armazernar� dados da
	// tabela de distribui��o de frequ�ncia
	DistribFrequencia *distribf = NULL;

	// Aloca mem�ria para armazenar os dados distribui��o de frequ�ncia
    distribf = new DistribFrequencia[Numero_de_Classes()];

	// Esse objeto ficar� respons�vel pela convers�o de vari�veis para
	// o tipo string
	ostringstream os;

	
	double liminf = data[0]; // Limite inferior da primeira classe
	double limsup = liminf + Amplitude_de_Classe(); //limite superior da primeira classe

	// Calcula a distribui��o de frequ�ncia
	for (int classe = 0; classe <= Numero_de_Classes()-1; classe++)
	{
	

		distribf[classe].LimInferior = liminf; // calcula o limite inferior da classe
		distribf[classe].LimSuperior = limsup; // Calcula o limite superior da classe

		// Calcula o ponto m�dio das classes
		distribf[classe].PontoMedio = (distribf[classe].LimSuperior + distribf[classe].LimInferior)/2;

		
		CalculaFI( distribf[classe] );

		if (classe == 0)
		CalculaFac( distribf[classe], classe );
		else CalculaFac( distribf[classe], distribf[classe-1].Fac);


		distribf[classe].fi = (distribf[classe].Fi * 100) / data.size();

		distribf[classe].fac = (distribf[classe].Fac * 100) / data.size();

		distribf[classe].FiXm = distribf[classe].PontoMedio * distribf[classe].Fi;

		distribf[classe].FiXm2 = distribf[classe].PontoMedio * distribf[classe].PontoMedio * distribf[classe].Fi;
		
		
		
		// A tabela que ser� retornada por esta fun��o
		os << "\nClasse = " << classe+1 << endl;
		os << "limite inferior = " << distribf[classe].LimInferior << endl;
		os << "limite superior = " << distribf[classe].LimSuperior << endl;
		os << "Ponto Medio = " << distribf[classe].PontoMedio << endl;
		os << "Fi = " << distribf[classe].Fi << endl;
		os << "Fac = " << distribf[classe].Fac << endl;
		os << "fi(%) = " << distribf[classe].fi << endl;
		os << "fac(%) = " << distribf[classe].fac << endl;
		//os << "Ponto medio * Fi = " << distribf[classe].FiXm << endl;
		//os << "Ponto medio^2 * Fi = " << distribf[classe].FiXm2 << endl;

		// "Move-se" para o pr�ximo limite
		liminf = limsup;
		limsup = liminf + Amplitude_de_Classe();



	}
	

	
	//delete [] distribf;
	string str;
	str = os.str();

	Calculado = true;
	return str;

			}

		catch (exception e) 
			{
				cout << "Ocorreu um problema inesperado:" << endl;
				cout << e.what() << endl;
			}



}
*/

regDistribFrequencia EstatisticaDescritiva::Distrib_de_Frequencia()
{

	try{

	// Esta � a fun��o mais interessante da classe, por hora...
	// Ela retorna uma string com a distribui��o de frequ�ncia

    // Ponteido para uma estrutura que armazernar� dados da
	// tabela de distribui��o de frequ�ncia
	DistribFrequencia *distribf = NULL;

	numClasses = Numero_de_Classes();
	// Aloca mem�ria para armazenar os dados distribui��o de frequ�ncia
	distribf = new DistribFrequencia[ numClasses ];

	// Esse objeto ficar� respons�vel pela convers�o de vari�veis para
	// o tipo string
	ostringstream os;

	const int ampClasse = Amplitude_de_Classe();
	double liminf = data[0]; // Limite inferior da primeira classe
	double limsup = liminf + ampClasse ; //limite superior da primeira classe

	// Calcula a distribui��o de frequ�ncia
	for (int classe = 0; classe <= numClasses -1; classe++)
	{
	

		distribf[classe].LimInferior = liminf; // calcula o limite inferior da classe
		distribf[classe].LimSuperior = limsup; // Calcula o limite superior da classe

		// Calcula o ponto m�dio das classes
		distribf[classe].PontoMedio = (distribf[classe].LimSuperior + distribf[classe].LimInferior)/2;

		
		CalculaFI( distribf[classe] );

		if (classe == 0)
		CalculaFac( distribf[classe], classe );
		else CalculaFac( distribf[classe], distribf[classe-1].Fac);


		distribf[classe].fi = (distribf[classe].Fi * 100) / data.size();

		distribf[classe].fac = (distribf[classe].Fac * 100) / data.size();

		distribf[classe].FiXm = distribf[classe].PontoMedio * distribf[classe].Fi;

		distribf[classe].FiXm2 = distribf[classe].PontoMedio * distribf[classe].PontoMedio * distribf[classe].Fi;
		
		
		
		// A tabela que ser� retornada por esta fun��o
		os << "\nClasse = " << classe+1 << endl;
		os << "limite inferior = " << distribf[classe].LimInferior << endl;
		os << "limite superior = " << distribf[classe].LimSuperior << endl;
		os << "Ponto Medio = " << distribf[classe].PontoMedio << endl;
		os << "Fi = " << distribf[classe].Fi << endl;
		os << "Fac = " << distribf[classe].Fac << endl;
		os << "fi(%) = " << distribf[classe].fi << endl;
		os << "fac(%) = " << distribf[classe].fac << endl;
		//os << "Ponto medio * Fi = " << distribf[classe].FiXm << endl;
		//os << "Ponto medio^2 * Fi = " << distribf[classe].FiXm2 << endl;

		// "Move-se" para o pr�ximo limite
		liminf = limsup;
		limsup = liminf + ampClasse;



	}


	int corrigeNumClasses = numClasses;

	for (int i = numClasses-1 ; i >= 0 ; i--)
	{
		if (distribf[i].fi == 0.0 )
		{
			corrigeNumClasses--;
		}
		else break;

	}

	
	//delete [] distribf;
	regDistribFrequencia distr;
	distr.Distrib = distribf;
	distr.tamanho = corrigeNumClasses;
	distr.texto = os.str();

	numClasses = corrigeNumClasses;


	
	Calculado = true;
	return distr;

	}

	catch (...)
	{

	}



}




