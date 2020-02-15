#include "ajuda.h"
#include <map>

const std::string ajuda_binomial 
=	"Distribuição Binomial\n\n"
	"Parâmetros:\n"
	"\tX : termo independente;\n"
	"\tn : número de tentativas/observações do evento;\n"
	"\tP : probabilidade de suceso em cada tentativa;\n\n"
	"Resultado: a probabilidade de serem observadas X ocorrências do evento.\n"
	"\tA probabilidade está no intervalo entre 0 e 1.\n"
	"\tCaso o resultado não esteja entre 0 e 1, os dados fornecidos estão\ninconsistentes.\n\n";

const std::string ajuda_hipergeometrica 
=	"Distribuição Hipergeométrica\n\n"
	"Parâmetros:\n"
	"\tX : termo independente;\n"
	"\tN : total de observações do evento;\n"
	"\tn : amostra de N;\n"
	"\tk : número de sucessos/ocorrências do evento;\n\n"
	"Resultado: a probabilidade de serem observadas X ocorrências do evento.\n"
	"\tA probabilidade está no intervalo entre 0 e 1.\n"
	"\tCaso o resultado não esteja entre 0 e 1, os dados fornecidos estão\ninconsistentes.\n\n";

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