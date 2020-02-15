#include "ajuda.h"
#include <map>

const std::string ajuda_binomial 
=	"Distribui��o Binomial\n\n"
	"Par�metros:\n"
	"\tX : termo independente;\n"
	"\tn : n�mero de tentativas/observa��es do evento;\n"
	"\tP : probabilidade de suceso em cada tentativa;\n\n"
	"Resultado: a probabilidade de serem observadas X ocorr�ncias do evento.\n"
	"\tA probabilidade est� no intervalo entre 0 e 1.\n"
	"\tCaso o resultado n�o esteja entre 0 e 1, os dados fornecidos est�o\ninconsistentes.\n\n";

const std::string ajuda_hipergeometrica 
=	"Distribui��o Hipergeom�trica\n\n"
	"Par�metros:\n"
	"\tX : termo independente;\n"
	"\tN : total de observa��es do evento;\n"
	"\tn : amostra de N;\n"
	"\tk : n�mero de sucessos/ocorr�ncias do evento;\n\n"
	"Resultado: a probabilidade de serem observadas X ocorr�ncias do evento.\n"
	"\tA probabilidade est� no intervalo entre 0 e 1.\n"
	"\tCaso o resultado n�o esteja entre 0 e 1, os dados fornecidos est�o\ninconsistentes.\n\n";

std::map< Estatistica , std::string > eylan_ajuda;
int cria_ajuda()
{
	eylan_ajuda[ BINOMIAL ] = ajuda_binomial;
	eylan_ajuda[ HIPERGEOMETRICA ] = ajuda_hipergeometrica;

	return 1;
}

int i = cria_ajuda();

const std::string ajuda( Estatistica tipo_funcao )
{
	return eylan_ajuda[ tipo_funcao ];
}