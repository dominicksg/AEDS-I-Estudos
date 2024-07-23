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

    if (fscanf(arquivo, "%d", &npassagens) == 1)
    {
        printf("Deu bom.\n");
    }
    else
    {
        printf("Não foi possível ler o arquivo.\n");
        return 1; // Adicione um retorno de erro aqui
    }

    Passagem passagens[npassagens + 1];

    printf("Digite o Código de Origem: ");
    scanf(" %[^\n]", passagens[0].cod_origem);

    printf("\nDigite o Código de Destino: ");
    scanf(" %[^\n]", passagens[0].cod_destino);

    printf("\nDigite a Cidade Origem: ");
    scanf(" %[^\n]", passagens[0].cid_origem);

    printf("\nDigite a Cidade Destino: ");
    scanf(" %[^\n]", passagens[0].cid_destino);

    printf("\nDigite a data: ");
    scanf(" %[^\n]", passagens[0].data);

    printf("\nDigite a hora de partida: ");
    scanf(" %[^\n]", passagens[0].hora_partida);

    printf("\nDigite a hora de chegada: ");
    scanf(" %[^\n]", passagens[0].hora_chegada);

    printf("\nDigite o valor da passagem: ");
    scanf("%ld", &passagens[0].valor);

    // printf("id: %d\n", passagens[0].id);
    printf("codigo origem: %s\n", passagens[0].cod_origem);
    printf("codigo destino: %s\n", passagens[0].cod_destino);
    printf("cidade origem: %s\n", passagens[0].cid_origem);
    printf("cidade destino: %s\n", passagens[0].cid_destino);
    printf("data: %s\n", passagens[0].data);
    printf("hora partida: %s\n", passagens[0].hora_partida);
    printf("hora chegada: %s\n", passagens[0].hora_chegada);
    printf("valor: %ld\n", passagens[0].valor);
    printf("\n");

    for (int i = 0; i < 2; i++)
    {
        fgets(linha, 100, arquivo);
    }

    for (int i = 1; i < npassagens + 1; i++)
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
        
        if (passagens[i].id > menumain)
        {
            menumain = passagens[i].id;
            passagens[0].id = menumain + 1;
        }
    }

    fclose(arquivo);

    arquivo = fopen("D:/Douglas/Pessoal/Coding/University/Semestre 1/AEDS 1/Trabalho Milhas/passagens.txt", "w");

    fprintf(arquivo, "%d\n%d\n", npassagens + 1, passagens[0].id);

    // Escrever as passagens modificadas de volta no arquivo
    for (int i = 0; i < npassagens + 1; i++)
    {
        if (searchn != passagens[i].id)
        {
            fprintf(arquivo, "%d;%s;%s;%s;%s;%s;%s;%s;%ld;\n",
                    passagens[i].id, passagens[i].cod_origem, passagens[i].cod_destino,
                    passagens[i].cid_origem, passagens[i].cid_destino, passagens[i].data,
                    passagens[i].hora_partida, passagens[i].hora_chegada, passagens[i].valor);
        }
    }
    printf("Operação realizada com sucesso.");

    return 0;
}
// Atenção: Para cada operação, abrir o arquivo, realizar o processamento (ler/gravar) e fechar o arquivo.

// Função para validar entradas de strings com tamanho específico

/*
int validarEntrada(char campo[], int tamanho, const char mensagem[])
{
    printf("%s", mensagem);
    scanf(" %[^\n]", campo);
    if (strlen(campo) == tamanho)
    {
        return 1; // Entrada válida
    }
    else
    {
        printf("Entrada inválida. Por favor, digite exatamente %d caracteres.\n", tamanho);
        return 0; // Entrada inválida
    }
}
*/