#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 5
#define MAX_TITULO 100

struct Livro
{
    char titulo[MAX_TITULO];
    char autor[MAX_TITULO];
    char editora[MAX_TITULO];
    int edicao;

};

void limparbuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    struct Livro biblio[MAX_LIVROS];
    int totalLivros = 0;
    int opcao;


    do
    {
        printf("BIBLIOTECA VIRTUAL\n");
        printf("escolha uma das opcoes: \n");
        printf("==================================================\n");
        printf("1. Cadastrar livro\n");
        printf("2. ver livros\n");
        printf("3. sair\n");
        printf("==================================================\n");
        
        scanf("%d", &opcao);
        limparbuffer();

        switch (opcao)
        {
            case 1:
                if (totalLivros < MAX_LIVROS)
                {
                    printf("digite o titulo do livro: ");
                    fgets(biblio[totalLivros].titulo, MAX_TITULO, stdin);

                    printf("digite o autor do livro: ");
                    fgets(biblio[totalLivros].autor, MAX_TITULO, stdin);

                    printf("digite a editora do livro: ");
                    fgets(biblio[totalLivros].editora, MAX_TITULO, stdin);

                    biblio[totalLivros].titulo[strcspn(biblio[totalLivros].titulo, "\n")] = '\0';
                    biblio[totalLivros].autor[strcspn(biblio[totalLivros].autor, "\n")] = '\0';
                    biblio[totalLivros].editora[strcspn(biblio[totalLivros].editora, "\n")] = '\0';
                    
                    printf("digite a edicao do livro: ");
                    scanf("%d", &biblio[totalLivros].edicao);
                    limparbuffer();

                    totalLivros++;

                    printf("livro cadastrado com sucesso!\n");
                }
                else
                    {
                        printf("algo deu errado");
                    }
                printf("pressione enter para continuar...");
                getchar();
                break;
            
            case 2:
                    if (totalLivros == 0)
                    {
                        printf("nenhum livro cadastrado\n");
                    }
                    else
                    {
                        for (int i = 0; i < totalLivros; i++)
                        {
                            printf("==================================================\n");
                            printf("livro %d\n", i + 1);
                            printf("titulo: %s\n", biblio[i].titulo);
                            printf("autor: %s\n", biblio[i].autor);
                            printf("editora: %s\n", biblio[i].editora);
                            printf("edicao: %d\n", biblio[i].edicao);
                            
                        }
                        printf("==================================================\n");
                    }
                   printf("pressione enter para continuar...");
                    getchar();
                    break;

            case 3:
                printf("saindo...\n");
                break;
        }
    }


    while (opcao != 3);


}
