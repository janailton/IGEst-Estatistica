//    Copyright (C) 2009 José Janaílton da Silva <josejanailton@gmail.com>
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



#ifndef _ESTATISTICA_DESCRITIVA_H_
#define _ESTATISTICA_DESCRITIVA_H_


#include "Slot.h"
#include <string>
#include <cmath>
#include <sstream>
#include <exception>
#include <algorithm>
using namespace std;


	
	struct DistribFrequencia{

		double LimInferior;
		double LimSuperior;
		double PontoMedio;
		double Fi;
		double Fac;
		double fi;
		double fac;
		double FiXm;
		double FiXm2;

	};

	struct regDistribFrequencia{

		DistribFrequencia *Distrib;
		int tamanho;
		string texto;
		
	};
	

	class EstatisticaDescritiva : public Slot{
		public:
			EstatisticaDescritiva() {   };
			~EstatisticaDescritiva() {   };
			EstatisticaDescritiva(int elements);
			virtual void Add(double _data);
			void Ordenar_Dados();
			bool Dados_Ordenados();
			
			// Estatística descritiva
			double Amplitude_total();
            int NumerodeClasses();
			int Amplitude_de_Classe();

			double Media();
			double Mediana();
			double Mediana( double LimMediana, double tamClasse, double freqAntMediana, double freqMediana);

			double Moda();
			double Variancia();
			double DesvioPadrao();
			double Coeficiente_de_Variacao();

			//string Criar_Distrib_Frequencia();
			regDistribFrequencia Distrib_de_Frequencia();

		private:
			bool DadosOrdenados;
			bool Calculado;
			int numClasses;
			int Arredondar(double numero);
			void CalculaFI( DistribFrequencia& f);
			void CalculaFac(DistribFrequencia& f, double Fant);
			int Numero_de_Classes();
      
};









#endif 
