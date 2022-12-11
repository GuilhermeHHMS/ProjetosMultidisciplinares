#ifdef _WIN32
#include <windows.h>
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif // _WIN32

#include "misctools.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void salvarMedico(char nome[100], int senha)
{

    FILE *file;

    char arq[100];

    char dir[] = "Colaboradores\\";
    criarDiretorio(dir);
    strcpy(arq, nome);
    strcat(arq, ".txt");
    strcat(dir, arq);

    file = fopen(dir, "w");

    if(file == NULL)
    {
        printf(dir);
        printf("\nnão foi possivel abrir o arquivo...");
        fclose(file);
    }
    else
    {
        fprintf(file, "%s\n%d\n---------", nome, senha);

        printf("Registro finalizado com sucesso\n");

        fclose(file);
    }
}

void salvarDadosPac(char nome[100], int idade, int cep, char comorbidade)
{

    FILE *file;


    char arq[100];
    char dir[] = "Pacientes\\";
    criarDiretorio(dir);
    strcpy(arq, nome);
    strcat(arq, ".txt");
    strcat(dir, arq);

    file = fopen(dir, "w");

    if(file == NULL)
    {
        printf(dir);
        printf("não foi possível abrir o arquivo...");
        fclose(file);
        exit(0);
    }
    else
    {
        fprintf(file, "Nome: %s\nIdade: %d\nCEP: %d\nComorbidade: %c\n---------", nome, idade, cep, comorbidade);

        printf("Registro finalizado com sucesso\n");

        fclose(file);
    }
}

void messageError(void)
{
    printf("Você excedeu a quantidade de tentativas permitidas. Para tentar denovo, reinicie a aplicação.\nCaso não esteja registrado; contatar a equipe de suporte.\n");

    system("PAUSE");

}

int criarDiretorio(char *dir)
{

#ifdef _WIN32
    return CreateDirectory(dir, NULL);
#else
    return mkdir(dir, 755);
#endif // _WIN32
}

