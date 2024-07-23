#include <stdio.h>

typedef struct Aluno
{
    int matricula;
    char numero[20];

} Aluno;

void printmenu()
{
    printf("\nDigite 1 para armazenar um aluno\n");
    printf("Digite 2 para ler os alunos\n");
    printf("Digite 3 para sair\n\n");
    printf("Sua escolha: ");
}

int main(void)
{
    int menu = 0;
    Aluno alunos;
    while (menu != 3)
    {
        printmenu();
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
        {
            scanf("%d", &alunos.matricula);
            scanf("%s", alunos.numero);

            FILE *arquivo = fopen("arquivo.txt", "a+");

            fprintf(arquivo, "%d - %s\n", alunos.matricula, alunos.numero);
            fclose(arquivo);
        }
        case 2:
        {
            FILE *arquivo = fopen("arquivo.txt", "r");

            // while (fscanf(arquivo, "%d - %19s", &alunos.matricula, alunos.numero) != EOF)
            while (fscanf(arquivo, "%d - %[^\t\n]", &alunos.matricula, alunos.numero) != EOF)
            {
                printf("%d %s\n", alunos.matricula, alunos.numero);
            }

            /*
            char linha[100];
            while (fgets(linha, 100, arquivo) != NULL)
            {
            printf("%s", linha);
            }
            */
            fclose(arquivo);

            break;
        }
        case 3:
        {
            printf("Encerrando programa");
            break;
        }
        default:
        {
            printf("Tente novamente");
            break;
        }
        }
    }

    return 0;
}
/*
    do {
        printf("1. Opcao 1\n");
        printf("2. Opcao 2\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                int variavel1 = 10;
                printf("Executando a opcao 1 com variavel1 = %d\n", variavel1);
                break;
            }
            case 2: {
                int variavel2 = 20;
                printf("Executando a opcao 2 com variavel2 = %d\n", variavel2);
                break;
            }
            case 3:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 3);
*/