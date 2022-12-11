#include <stdio.h>
#include <stdlib.h>
#include "login.h"
#include "misctools.h"
#include "register.h"

/*
*
*"setbuf(stdin, NULL)" - Fun��o para limpeza de buffer, modo sem bufferiza��o.
*
*/

void registrarUsuario()
{

    char nome[50];
    int senha, confSenha;
    int codGeral = 90870;

    char verifiConfSenha, verifiCodGeral;


    printf("Digite o nome do colaborador: ");
    gets(nome);

    do
    {

        printf("Digite a senha [somente n�meros]: ");
        scanf("%d", &senha);

        printf("Confirme a senha : ");
        scanf("%d", &confSenha);

        setbuf(stdin, NULL);


        if(senha == confSenha)
        {
            printf("Senha confirmada\n\n");

            verifiConfSenha = 's';


            do
            {
                printf("\nPara finalizar o registro digite o c�digo geral: ");
                scanf("%d", &codGeral);
                setbuf(stdin, NULL);


                if(codGeral == 90870 )
                {


                    salvarMedico(nome, senha);
                    system("PAUSE");
                    system("CLS");
                    printf("Direcionando para a p�gina de login...\n\n");
                    system("PAUSE");

                    loginUsuario();


                    verifiCodGeral = 's';

                }
                else
                {
                    printf("\n\nC�digo incorreto\nContate a central\n");
                    verifiCodGeral = 'n';

                }

            }
            while(verifiCodGeral == 'n');

        }

        else
        {
            printf("\n\nSenha n�o corresponde\nDigite novamente\n\n");
            verifiConfSenha = 'n';

        }

    }
    while(verifiConfSenha == 'n');

}
