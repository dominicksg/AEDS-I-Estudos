#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h> // Permitir caractere especial
#include <stdlib.h>

// Não é possivel definir structs após a main, e declarar elas antes (como as funções)
typedef struct Passagem
{
    int id;
    char cod_origem[4]; // Um número extra para todos, por causa do ";"
    char cod_destino[4];
    char cid_origem[59];
    char cid_destino[59];
    char data[11];
    char hora_partida[6];
    char hora_chegada[6];
    long valor;
} Passagem;

//------------------------- Funções Início -------------------------//

void menu_principal();

void checkfile(FILE *);

int ler_e_printar_ntotal_passagens(FILE *, int);

void pular_n_linhas(FILE *, char[], int);

void lista_as_passagens(FILE *, char[], int, struct Passagem *);

//------------------------- Funções Fim -------------------------//

int main(void)
{
    int menumain = 0, menusearch = 0;
    int npassagens;
    char linha[100];
    setlocale(LC_ALL, "Portuguese_Brazil"); // Permitir caractere especial

    //  FILE *arq = fopen(passagens.txt, r);    // Leitura
    //  FILE *arq = fopen(passagens.txt, r+);   // Leitura e escrita
    //  FILE *arq = fopen(passagens.txt, w);    // Escrita no começo, apaga tudo antes
    //  FILE *arq = fopen(passagens.txt, a);    // Escrita no final

    while (menumain != 6)
    {
        menu_principal();
        scanf("%d", &menumain);
        printf("/--------------------------------------------------------------------/\n");

        // Atenção: Para cada operação, abrir o arquivo, realizar o processamento (ler/gravar) e fechar o arquivo.
        switch (menumain)
        {
        case 1: // Listar todas as passagens
                // Apresentar o total de passagens e uma listagem das passagens com todas as suas informações de forma estruturada e organizada. Após a listagem, retornar ao menu principal.
            FILE *arquivo = fopen("D:/Douglas/Pessoal/Coding/University/AEDS 1/Trabalho Milhas/passagens.txt", "r");

            break;
            //------------------------------ Início Menu Pesquisa ------------------------------//
        case 2: // Pesquisar uma passagem
                // Após digitar a chave de pesquisa o programa deve exibir os dados das passagens ou informar que nenhuma passagem foi encontrada.
            while (menusearch < 1 || menusearch > 5)
            {
                printf("\nEscolha por qual opção de busca deseja pesquisar:\n\n");
                printf("1- ID da passagem\n");
                printf("2- Aeroporto de origem\n");
                printf("3- Aeroporto destino\n");
                printf("4- Cudade origem\n");
                printf("5- Cidade Destino\n");
                printf("\nEscolha a sua operação digitando um número correspondente: ");
                scanf("%d", &menusearch);
                printf("/--------------------------------------------------------------------/\n");

                switch (menusearch)
                {
                case 1: // ID da Passagem

                    break;
                case 2: // Aeroporto de origem
                    break;
                case 3: // Aeroporto destino
                    break;
                case 4: // Cudade origem
                    break;
                case 5: // Cidade Destino
                    break;
                default:
                    printf("\n**Opção inexistente, por favor escolha uma opção válida**\n\n");
                    printf("/--------------------------------------------------------------------/\n");
                    break;
                }
            }
            //------------------------------ Fim Menu Pesquisa ------------------------------//

        case 3: // Cadastrar uma passagem
                // O usuário deve informar todas as informações necessárias para cadastrar uma passagem. O sistema deve validar a entrada de dados, solicitando ao usuário digitar novamente, caso necessário. Após cadastrar a passagem, o sistema deve emitir uma mensagem de passagem cadastrada e gravar o arquivo com as passagens. Retornar ao menu principal.
            break;

        case 4: // Editar uma passagem
                // O programa deve solicitar que o usuário digite o ID da passagem a ser editada, apresentar as informações da passagem encontrada e solicitar ao usuário que digite as novas informações da passagem, exceto a chave. Após editar a passagem, o sistema deve emitir uma mensagem de passagem atualizada e gravar o arquivo com as passagens. Informar passagem não encontrada, caso a pesquisa não retorne nenhuma passagem. Retornar ao menu principal.
            break;

        case 5: // Excluir uma passagem
                // O programa deve solicitar que o usuário digite o ID da passagem a ser excluída, apresentar as informações da passagem encontrada e solicitar ao usuário que confirme a exclusão. Em caso afirmativo, excluir a passagem. Após excluir a passagem, o sistema deve emitir uma mensagem de passagem excluída e gravar o arquivo com as passagens. Informar passagem não encontrado, caso a pesquisa não retorne nenhuma passagem. Retornar ao menu principal.
            break;

        case 6: // Sair do Programa
                // O programa deve emitir uma mensagem de encerramento do programa e finalizar.
                // exit(0); // Não precisa, por causa do while que coloquei depois
            printf("\n MIGreat Flights agradece a preferência, até a próxima :)\n\n");

            break;
        default:
            printf("\n**Opção inexistente, por favor escolha uma opção válida**\n\n");
            break;
        }
    }

    return 0;
}

//------------------------- Funções  -------------------------//

void menu_principal()
{
    printf("/--------------------------------------------------------------------/\n");
    printf("/------------/ MIGreat Flights Gerenciador de Passagens /------------/\n");
    printf("/--------------------------------------------------------------------/\n\n");
    printf("Menu de opções:\n");

    printf("1- Listar todas as passagens.\n");
    printf("2- Pesquisar uma passagem.\n");
    printf("3- Cadastrar uma passagem.\n");
    printf("4- Editar uma passagem.\n");
    printf("5- Excluir uma passagem.\n");
    printf("6- Sair do programa.\n");

    printf("\nEscolha a sua operação digitando um número correspondente: ");
}

void checkfile(FILE *arq)
{
    if (arq == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        // return 1; // Sair do programa com código de erro
    }
}

int ler_e_printar_ntotal_passagens(FILE *arq, int numeropassagens)
{ // Retorna 1 se foi lido, e lê um inteiro do arquivo
    if (fscanf(arq, "%d", &numeropassagens) == 1)
    {
        // Imprime o valor lido
        printf("Seu número de passagens é: %d\n", numeropassagens);
        return numeropassagens;
    }
    else
    {
        printf("Não foi possível ler o arquivo.\n");
    }
}

void pular_n_linhas(FILE *arq, char line[], int nlinhas)
{
    // Lê e descarta as duas primeiras linhas
    for (int i = 0; i < nlinhas; i++)
    {
        fgets(line, 100, arq); // PQ SIZEOF BUGA TUDO AQUI?
    }
    /* Lê e descarta a primeira linha (nesse caso, o enter que sobrou do fscanf)
    fgets(line, sizeof(line), arq);
    // Lê e descarta a segunda linha
    fgets(line, sizeof(line), arq);
    // printf("%s", line);*/
}

void lista_as_passagens(FILE *arq, char line[], int numeropassagens, struct Passagem *tickets)
{
    for (int i = 0; i < numeropassagens; i++)
    {
        fgets(line, 100, arq);

        // Usa strtok para dividir a linha em tokens
        char *token = strtok(line, ";");

        // Converte e atribui os valores aos campos da estrutura
        tickets[i].id = atoi(token);

        token = strtok(NULL, ";");
        strcpy(tickets[i].cod_origem, token);

        token = strtok(NULL, ";");
        strcpy(tickets[i].cod_destino, token);

        token = strtok(NULL, ";");
        strcpy(tickets[i].cid_origem, token);

        token = strtok(NULL, ";");
        strcpy(tickets[i].cid_destino, token);

        token = strtok(NULL, ";");
        strcpy(tickets[i].data, token);

        token = strtok(NULL, ";");
        strcpy(tickets[i].hora_partida, token);

        token = strtok(NULL, ";");
        strcpy(tickets[i].hora_chegada, token);

        token = strtok(NULL, ";");
        tickets[i].valor = atol(token);

        // Imprime tudo
        printf("\nPassagem de numero %d\n", i + 1);

        printf("id: %d\n", tickets[i].id);
        printf("codigo origem: %s\n", tickets[i].cod_origem);
        printf("codigo destino: %s\n", tickets[i].cod_destino);
        printf("cidade origem: %s\n", tickets[i].cid_origem);
        printf("cidade destino: %s\n", tickets[i].cid_destino);
        printf("data: %s\n", tickets[i].data);
        printf("hora partida: %s\n", tickets[i].hora_partida);
        printf("hora chegada: %s\n", tickets[i].hora_chegada);
        printf("valor: %ld\n", tickets[i].valor);
        printf("\n");
    }
}
