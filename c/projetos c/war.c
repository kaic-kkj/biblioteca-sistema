/*
CLIENTE PEDE:
PROGRAMA QUE RODE NO TERMINAL E SIMULE UMA GUERRA ENTRE 5 PAISES:
DEVE SER FEITO EM STRUCT E SWITCH CASE, SERAO PEDIDOS PRO USUARIO COLOCAR:
NOME DE GUERRA, NUMERO DE TROPAS, COR DAS TROPAS.
*/

#include <stdio.h>
#include <string.h>

#define MAX_PAISES 5
#define MAX_NOME 50

struct war
{
    char nome[MAX_NOME];
    char cor[MAX_NOME];
    int tropas;
};

void limparbuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    struct war paises[MAX_PAISES];
    int totalPaises = 0;
    int opcao;

    do
    {
        printf("===================================================\n");
        printf("GUERRA ENTRE PAISES\n");
        printf("===================================================\n");
        printf("escolha uma das opcoes abaixo: \n");
        printf("====================================================\n");
        printf("1. Cadastrar pais\n");
        printf("2. Ver paises\n");
        printf("3. Sair da guerra\n");
        printf("====================================================\n");
        scanf("%d", &opcao);
        limparbuffer();

        switch (opcao)
        {
            case 1:
                if(totalPaises < MAX_PAISES)
                {
                    printf("digite o nome do pais: \n");
                    fgets(paises[totalPaises].nome, MAX_NOME, stdin);
                    printf("digite a cor da bandeira das tropas: \n");
                    fgets(paises[totalPaises].cor, MAX_NOME, stdin);
                    
                    paises[totalPaises].nome[strcspn(paises[totalPaises].nome, "\n")] = '\0';
                    paises[totalPaises].cor[strcspn(paises[totalPaises].cor, "\n")] = '\0';
                    
                    printf("digite o numero de tropas: \n");
                    scanf("%d", &paises[totalPaises].tropas);
                    limparbuffer();

                    totalPaises++;
                    printf("BANDO DE GUERRA CADASTRADO COM SUCESSO\n");
                }
                else
                    {
                        printf("erro inesperado!");
                    }
                printf("aperte enter para continuar...");
                getchar();
                break;
            
            case 2:
                    if (totalPaises == 0)
                    {
                        printf("nenhuma guerra acontecendo!\n");
                    }
                    
                    else
                    {
                        for (int i = 0; i < totalPaises; i++)
                        {
                            printf("===================================================\n");
                            printf("nome de guerra: %s\n", paises[i].nome);
                            printf("cor da bandeira das tropas: %s\n", paises[i].cor);
                            printf("numero de guerreiros: %d\n", paises[i].tropas);
                            printf("===================================================\n");
                        }
                        printf("pressione enter para continuar...");
                        getchar();
                    }
                    break;

            case 3:
                printf("saindo...");
                break;
            
        default:
            printf("algo deu errado >:(");
            break;
        }
    } 
    while (opcao != 3);
    



}