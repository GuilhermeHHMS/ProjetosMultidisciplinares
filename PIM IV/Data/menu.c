#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "register.h"
#include "login.h"
#include "menu.h"


int menu()
{

    int chave = 0;
    do
{
    int acaoLogin;



        printf("Escolha sua ação:\n [1] - Registrar novo colaborador\n [2] - Login de colaborador\n  ");
        scanf("%d", &acaoLogin);
        setbuf(stdin, NULL);


        switch(acaoLogin)
        {

        case 1:

            registrarUsuario();
            chave = 1;
            break;

        case 2:
            loginUsuario();
            chave = 1;
            break;

        default:
            printf("\nComando inválido...\n");
            system("PAUSE");
            break;
        }
    }
    while(chave == 0);
    return 0;




}


