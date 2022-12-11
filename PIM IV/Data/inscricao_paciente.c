#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "misctools.h"
#include "inscricao_paciente.h"

void cadastrarPaciente()
{
    bool chave = 0;

    int dataNasc, dataDiag, idade, cepPac;
    idade=0;
    int ent = 0;

    char comorbidade, cadastroPac;

    char nomePac [100];
    char cpfPac [20];
    char telPac [20];
    char emailPac [100];
    char confCad;


    do
    {
        bool repetir = true;
        ent = 0;
        do
        {

            setbuf(stdin,NULL);
            system("CLS");


            printf("Registrando novo paciente:\n\n");
            printf("Por favor, preencha os dados a seguir com as informações do paciente.\n");

            printf("Nome completo: \n");
            gets(nomePac);
            system("CLS");

            printf("CPF: \n");
            gets(cpfPac);
            system("CLS");

            printf("Telefone: \n");
            gets(telPac);
            system("CLS");

            printf("CEP: [somente números]\n");
            scanf("%d", &cepPac);
            setbuf(stdin, NULL);
            system("CLS");

            printf("E-mail: \n");
            gets(emailPac);
            system("CLS");

            printf("Ano de nascimento: \n");
            scanf("%d", &dataNasc);
            setbuf(stdin, NULL);
            system("CLS");

            printf("Data do diagnóstico: [inserir apenas ano]\n");
            scanf("%d", &dataDiag);
            setbuf(stdin,NULL);
            system("CLS");

            printf("Possui comorbidades? [S/N]\n");
            scanf("%c", &comorbidade);
            setbuf(stdin,NULL);
            system("CLS");

            printf("\nPor favor, verifique se digitou corretamente os dados do paciente. \n");
            printf("Nome: %s\n", nomePac);
            printf("CPF: %s\n", cpfPac);
            printf("Telefone: %s\n", telPac);
            printf("CEP: %d\n", cepPac);
            printf("Ano de Nascimento: %d\n", dataNasc);
            printf("Data do Diagnóstico: %d\n", dataDiag);
            printf("E-mail: %s\n", emailPac);
            printf("Comorbidades: %c\n", comorbidade);
            setbuf(stdin,NULL);

            int ent = 0;

            //INICIO DO LOOP DE VERIFICACAO DE VARIAVEL CHAR
            do
            {
                printf("\nOs dados estão corretos? [S/N]");
                scanf("%c", &confCad);
                setbuf(stdin,NULL);


                if (confCad == 'S' || confCad == 's')
                {
                    repetir = false;
                    ent = 1;
                }
                else if (confCad == 'N' || confCad == 'n')
                {
                    ent = 1;
                }

                if(confCad != 'S' && confCad != 's')
                {
                    if(confCad != 'n' && confCad != 'n')
                    {

                        puts("Caractere inválido.");
                        system("PAUSE");

                    }
                }
            }
            while(ent == 0);
            //FIM DO LOOP DE VERIFICACAO DE VARIAVEL CHAR
        }
        while (repetir == true);

        idade = dataDiag-dataNasc;

        if (idade >= 65 || comorbidade == 'S' || comorbidade == 's')
        {
            printf("\nPaciente em grupo de risco\n");
            system("PAUSE");
            system("CLS");

            puts("Dados enviados para a central.\n");
            system("PAUSE");
            system("CLS");

            salvarDadosPac(nomePac, idade, cepPac, comorbidade);

        }

        else
        {
            printf ("\nPaciente fora do grupo de risco.\n");
        }

        do
        {
            //INICIO DO LOOP DE VERIFICACAO DE VARIAVEL CHAR
            printf("\nDeseja cadastrar novo paciente? [S/N] ");
            scanf("%c", &cadastroPac);
            setbuf(stdin, NULL);


            if (cadastroPac == 'S' || cadastroPac == 's')
            {
                chave = 1;
                ent = 1;
            }

            else if (cadastroPac == 'N' || cadastroPac == 'n')
            {
                chave = 0;
            }

            if(cadastroPac != 'S' && cadastroPac != 's')
            {

                if (cadastroPac != 'N' && cadastroPac != 'n')
                {

                    puts("\nCaractere inválido.\n\n");
                    system("PAUSE");

                }

                else
                {

                    ent = 1;

                }

            }

        }
        while(ent == 0);
        //FIM DO LOOP DE VERIFICACAO DE VARIAVEL CHAR

    }
    while (chave != 0);

    system("PAUSE");
    exit(0);
}


