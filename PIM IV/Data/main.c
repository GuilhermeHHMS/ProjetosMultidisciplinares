#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include <locale.h>

void main()
{
    system("COLOR DF");
    setlocale(LC_ALL, "Portuguese");

    printf("\n################ Cadastro de pacientes ################\n\n");
    printf("||Programa para controle de diagnostico 2022 - Covid 19||\n\n");

    system("PAUSE");
    system("CLS");

    menu();

}
