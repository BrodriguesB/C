#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "Funcoes.h"

/*  CADASTRO DE OFICINA
    AUTOR: BRUNO RODRIGUES
    DATA: 03/07/2017

    REFERÊNCIAS:
        http://www.cprogressivo.net/
        http://www.clubedohardware.com.br/
        https://stackoverflow.com/questions/18565663/while-c-getchar-eof-not-terminating
*/

int main()
{
    //Saida de texto com idioma em português
    setlocale(LC_ALL,"portuguese");
    menu();

    return 0;
}
