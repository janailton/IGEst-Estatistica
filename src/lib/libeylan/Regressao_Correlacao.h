//    Copyright (C) 2010, 2009  José Janaílton da Silva 
//					<josejanailton@gmail.com>
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


#ifndef __REGRESSAO_CORRELACAO_H__
#define __REGRESSAO_CORRELACAO_H__

#include <vector>

class Regressao_Correlacao
{
public:
	Regressao_Correlacao(void);
	virtual ~Regressao_Correlacao(void);
	///! Armazena valores dos pares ordenados XY para posterior cálculo.
	///!	Utilize este método para adicionar valores do par XY.
	void Add( double x, double y);

	///! Limpa as variáveis e remove os pares armazenados
	void remover_pares();

	///! Calcular os coeficientes da função de regressão.
	///!	F(x) = b0 + b1*x
	double b0();
	double b1();

	double coeficiente_correlacao();
	///! Retorna o resultado do cálculo do coeficente de determinação
	double coeficiente_determinacao();

protected:

	struct Pares
	{
		double X;
		double Y;
		Pares() {	};
		Pares( double x, double y)
		{
			X = x;
			Y = y;
		}
	};

	std::vector<Pares> pares;
};


#endif