#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "misctools.h"
#include "inscricao_paciente.h"
#include "login.h"

void loginUsuario()
{

    system("CLS");

    FILE *file;
    char arq[100];
    char dados[100];
    char pegarDados[3][100];
    char nome[100];
    int senha;
    int convertDados;

    int i = 0;
    int tentativa = 0;

    do
    {
        char dir[] = "Colaboradores\\";

        printf("Digite o nome do colaborador: ");
        gets(nome);
        setbuf(stdin, NULL);


        strcpy(arq, nome);
        strcat(arq, ".txt");
        strcat(dir, arq);

        puts("");
        puts(dir);

        file = fopen(dir, "r");

        if(file == NULL)
        {
            printf("\nNão foi possível encontrar este usuário...\n");
            system("PAUSE");

            memset(&dir, 0, sizeof(dir));

            tentativa ++;
            fclose(file);
        }

        if(tentativa >= 3)
        {
            messageError();
            return 0;
        }
    }
    while(file == NULL );

    while(fgets(dados, 100, file) != NULL)
    {

        strcpy(pegarDados[i], dados);
        i++;
    }

    convertDados = atoi(pegarDados[1]);
    system("CLS");

    tentativa = 0;

    do
    {

        printf("\nDigite a senha: ");
        scanf("%d", &senha);
        setbuf(stdin, NULL);


        if(senha != convertDados)
        {
            printf("A senha está incorreta...\n");
            tentativa ++;
        }

    }
    while(tentativa < 3 && senha != convertDados );

    if(tentativa >= 3)
    {
        messageError();
        fclose(file);
        return;
    }
    printf("Direcionando para a página de registro de paciente...\n");
    fclose(file);
    system("PAUSE");

    cadastrarPaciente();
}
