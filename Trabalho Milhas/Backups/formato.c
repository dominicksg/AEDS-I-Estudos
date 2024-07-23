#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h> // Permitir caractere especial
#include <stdlib.h>

typedef struct Passagem
{
    int id;
    char cod_origem[4];
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
    int menumain = 0, menusearch = 0;
    int searchn = 0;
    int aux;
    int menu3;
    char searchstr[59];
    char linha[100];
    char letra;
    int contlinha = 0;
    FILE *arquivo_temp;
    setlocale(LC_ALL, "Portuguese_Brazil");

    FILE *arquivo = fopen("D:/Douglas/Pessoal/Coding/University/Semestre 1/AEDS 1/Trabalho Milhas/passagens.txt", "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    arquivo_temp = fopen("D:/Douglas/Pessoal/Coding/University/Semestre 1/AEDS 1/Trabalho Milhas/arquivo_temp.txt", "w");
    if (arquivo_temp == NULL)
    {
        perror("Erro ao abrir o arquivo temporário");
        exit(EXIT_FAILURE);
    }

    // Copy the contents of the original file to the temporary file
    // while ((letra = fgetc(arquivo)) != EOF)
    while ((letra = fgetc(arquivo)) != EOF)
    {
        fputc(letra, arquivo_temp);

        if (letra == '\n')
        {
            contlinha++;

            // Se copiou duas linhas, pare o loop
            if (contlinha == 2)
            {
                break;
            }
        }
    }

    fclose(arquivo_temp);

    fclose(arquivo);

    //--------------------------------------------------------------------------------------//
    arquivo = fopen("D:/Douglas/Pessoal/Coding/University/Semestre 1/AEDS 1/Trabalho Milhas/passagens.txt", "r");
    if (fscanf(arquivo, "%d", &npassagens) == 1)
    {
        printf("Deu bom.\n");
    }
    else
    {
        printf("Não foi possível ler o arquivo.\n");
        return 1; // Adicione um retorno de erro aqui
    }

    Passagem passagens[npassagens];

    for (int i = 0; i < 2; i++)
    {
        fgets(linha, 100, arquivo);
    }

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

    // Teste aqui

    // Teste aqui

    fclose(arquivo);

    return 0;
}
// Atenção: Para cada operação, abrir o arquivo, realizar o processamento (ler/gravar) e fechar o arquivo.
