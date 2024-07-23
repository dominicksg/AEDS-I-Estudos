#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h> // Permitir caractere especial
#include <stdlib.h>

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

int main(void)
{
    int npassagens;
    char linha[100];
    FILE *arquivo;
    setlocale(LC_ALL, "Portuguese_Brazil"); // Permitir caractere especial

    arquivo = fopen("D:/Douglas/Pessoal/Coding/University/AEDS 1/Trabalho Milhas/passagens.txt", "r");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1; // Sair do programa com código de erro
    }

    // Área para testes

    // Área para testes

    // Fecha o arquivo
    fclose(arquivo);

    return 0;
}
// Atenção: Para cada operação, abrir o arquivo, realizar o processamento (ler/gravar) e fechar o arquivo.

// códigos que não foram usados (reserva)

/*Pesquisar ID
#include <stdio.h>
#include <string.h>

void pesquisar_terceiro_dado(const char *caminho_arquivo, const char *terceiro_dado) {
    FILE *arquivo = fopen(caminho_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    char linha[100];  // Ajuste o tamanho conforme necessário
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        char *token = strtok(linha, ";");
        int count = 0;

        while (token != NULL) {
            if (count == 2 && strcmp(token, terceiro_dado) == 0) {
                // Remover ';' e imprimir a linha correspondente
                printf("%s", token);
                break;
            }

            token = strtok(NULL, ";");
            count++;
        }
    }

    fclose(arquivo);
}

int main() {
    const char *caminho_arquivo = "caminho/do/seu/arquivo.txt";
    const char *terceiro_dado_pesquisa = "zyx";
    pesquisar_terceiro_dado(caminho_arquivo, terceiro_dado_pesquisa);

    return 0;
}
*/

/*
ID
    int searchn;
    scanf("%d", &searchn);

    for (int i = 0; i < npassagens; i++)
    {
        if (searchn == passagens[i].id)
        {
            printf("id: %d\n", passagens[i].id);
            printf("codigo origem: %s\n", passagens[i].cod_origem);
            printf("codigo destino: %s\n", passagens[i].cod_destino);
            printf("cidade origem: %s\n", passagens[i].cid_origem);
            printf("cidade destino: %s\n", passagens[i].cid_destino);
            printf("data: %s\n", passagens[i].data);
            printf("hora partida: %s\n", passagens[i].hora_partida);
            printf("hora chegada: %s\n", passagens[i].hora_chegada);
            printf("valor: %ld\n", passagens[i].valor);
            printf("\n");
            break;
        }
    }
    */

/*
Aeroporto
    scanf("%s", &searchstr);
 for (int i = 0; i < npassagens; i++)
 {
     for (int j = 0; j < sizeof(passagens[i].cod_origem); j++)
     {
         passagens[i].cod_origem[j] = tolower(passagens[i].cod_origem[j]);
     }

     for (int j = 0; j < sizeof(searchstr); j++)
     {
         searchstr[j] = tolower(searchstr[j]);
     }

     if (strcmp(passagens[i].cod_origem, searchstr) == 0)
     {
         printf("id: %d\n", passagens[i].id);
         printf("codigo origem: %s\n", passagens[i].cod_origem);
         printf("codigo destino: %s\n", passagens[i].cod_destino);
         printf("cidade origem: %s\n", passagens[i].cid_origem);
         printf("cidade destino: %s\n", passagens[i].cid_destino);
         printf("data: %s\n", passagens[i].data);
         printf("hora partida: %s\n", passagens[i].hora_partida);
         printf("hora chegada: %s\n", passagens[i].hora_chegada);
         printf("valor: %ld\n", passagens[i].valor);
         printf("\n");
         break;
     }
 }
*/

/* GUARDAR PASSAGENS BUGADO
for (int i = 0; i < npassagens; i++)
{
fgets(linha, 100, arquivo);

char *token = strtok(linha, ";");
passagens[i].id = atoi(token);

token = strtok(NULL, ";");
strcpy(passagens[i].cod_origem, token);

token = strtok(NULL, ";");
strcpy(passagens[i].cod_destino, token);

token = strtok(NULL, ";");
strcpy(passagens[i].cid_origem, token);

token = strtok(NULL, ";");
strcpy(passagens[i].cid_destino, token);

token = strtok(NULL, ";");
strcpy(passagens[i].data, token);

token = strtok(NULL, ";");
strcpy(passagens[i].hora_partida, token);

token = strtok(NULL, ";");
strcpy(passagens[i].hora_chegada, token);

token = strtok(NULL, ";");
passagens[i].valor = atol(token);
}
*/

/*DELETA COM BASE NO ID
if (aux != npassagens)
{
    printf("Deseja excluir realmente essa passagem? (S/N)\n");
    scanf(" %c", &letra);

    if (tolower(letra) == 'n')
    {
        return 0;
    }
    else if (tolower(letra) == 's')
    {
        // Ler cada linha do arquivo
        while (fgets(linha, 1000, arquivo) != NULL)
        {
            // Verificar se a linha começa com o número fornecido
            int linha_numero;
            sscanf(linha, "%d", &linha_numero);

            if (linha_numero != searchn)
            {
                // Se não for o número desejado, escrever no arquivo de saída
                fprintf(arquivo_temp, "%s", linha);
            }
        }
        printf("Operação realizada com sucesso.");
    }
    else if ((tolower(letra) != 's') && (tolower(letra) != 'n'))
    {
        printf("Digita direito bocó");
    }
}
* /