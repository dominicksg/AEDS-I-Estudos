#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h> // Permitir caractere especial

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

int ler_ntotal_passagens(FILE *, int);

void pular_n_linhas(FILE *, char[], int);

void guarda_as_passagens(FILE *, char[], int, struct Passagem *);

void printa_as_passagens(int, struct Passagem *);

void menu_pesquisa();

//------------------------- Funções Fim -------------------------//

int main(void)
{
    int npassagens;
    int menumain = 0, menusearch = 0, menuedit = 0;
    int searchn = 0, aux = 0, contlinha = 0;
    char searchstr[59];
    char linha[100];
    char letra;
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
        if (menumain == 1)
        { // Listar todas as passagens
          // Apresentar o total de passagens e uma listagem das passagens com todas as suas informações de forma estruturada e organizada. Após a listagem, retornar ao menu principal.

            FILE *arquivo = fopen("D:/Douglas/Pessoal/Coding/University/Semestre 1/AEDS 1/Trabalho Milhas/passagens.txt", "r");
            // Verifica se o arquivo foi aberto com sucesso
            checkfile(arquivo);

            // Imprime e retorna o número de passagens
            npassagens = ler_ntotal_passagens(arquivo, npassagens);
            printf("O número total de passagens é: %d\n", npassagens);

            // Cria uma variável de passagens, com o tamanho do número de passagens no arquivo
            Passagem passagens[npassagens];

            // Pula N linhas
            // Lembrar do problema com fgets
            pular_n_linhas(arquivo, linha, 2);

            // Agora, na terceira linha começa a ler ou processar os dados
            guarda_as_passagens(arquivo, linha, npassagens, passagens);
            printa_as_passagens(npassagens, passagens);

            // Fecha o arquivo
            fclose(arquivo);
        }
        //------------------------------ Início Menu Pesquisa ------------------------------//
        else if (menumain == 2)
        { // Pesquisar uma passagem
          // Após digitar a chave de pesquisa o programa deve exibir os dados das passagens ou informar que nenhuma passagem foi encontrada.
          // while ((menusearch < 1) || (menusearch > 5))
          //{

            FILE *arquivo = fopen("D:/Douglas/Pessoal/Coding/University/Semestre 1/AEDS 1/Trabalho Milhas/passagens.txt", "r");
            checkfile(arquivo);

            npassagens = ler_ntotal_passagens(arquivo, npassagens);

            Passagem passagens[npassagens];

            pular_n_linhas(arquivo, linha, 2);

            // Função de struct não funcionou aqui, nem seguindo o código do menumain==1.
            // Mesma função de 'guarda_as_passagens'
            // Agora funcionou, wtf?
            guarda_as_passagens(arquivo, linha, npassagens, passagens);

            menu_pesquisa();
            scanf("%d", &menusearch);
            printf("/--------------------------------------------------------------------/\n");

            if (menusearch == 1)
            {
                // ID da Passagem
                printf("Digite o ID: ");
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
                    /*else
                    {
                        printf("Não encontramos nenhuma passagem :(\n");
                    }*/
                }
                int searchn = 0;
            }
            if (menusearch == 2)
            {
                // Aeroporto de origem
                printf("Digite o Código de Origem: ");
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
            }
            if (menusearch == 3)
            {
                // Aeroporto destino
                printf("Digite o Código de destino: ");
                scanf("%s", &searchstr);

                for (int i = 0; i < npassagens; i++)
                {
                    for (int j = 0; j < sizeof(passagens[i].cod_destino); j++)
                    {
                        passagens[i].cod_destino[j] = tolower(passagens[i].cod_destino[j]);
                    }

                    for (int j = 0; j < sizeof(searchstr); j++)
                    {
                        searchstr[j] = tolower(searchstr[j]);
                    }

                    if (strcmp(passagens[i].cod_destino, searchstr) == 0)
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
            }
            if (menusearch == 4)
            {
                // Cidade origem
                printf("Digite a cidade origem: ");
                scanf(" %[^\n]", searchstr);

                // printf("%s", searchstr);
                // fgets(searchstr, 59, stdin);
                // fgets(searchstr, sizeof(searchstr), stdin);
                // printf("%s", searchstr);

                for (int i = 0; i < npassagens; i++)
                {
                    for (int j = 0; j < sizeof(passagens[i].cid_origem); j++)
                    {
                        passagens[i].cid_origem[j] = tolower(passagens[i].cid_origem[j]);
                    }

                    for (int j = 0; j < sizeof(searchstr); j++)
                    {
                        searchstr[j] = tolower(searchstr[j]);
                    }

                    if (strcmp(passagens[i].cid_origem, searchstr) == 0)
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
            }
            if (menusearch == 5)
            {
                // Cidade Destino
                printf("Digite a cidade destino: ");
                scanf(" %[^\n]", searchstr);

                for (int i = 0; i < npassagens; i++)
                {
                    for (int j = 0; j < sizeof(passagens[i].cid_destino); j++)
                    {
                        passagens[i].cid_destino[j] = tolower(passagens[i].cid_destino[j]);
                    }

                    for (int j = 0; j < sizeof(searchstr); j++)
                    {
                        searchstr[j] = tolower(searchstr[j]);
                    }

                    if (strcmp(passagens[i].cid_destino, searchstr) == 0)
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
            }
            if ((menusearch <= 0) || (menusearch >= 6)) // pq isso imprime duas vezes?
            {
                printf("\n**Opção inexistente, por favor escolha uma opção válida**\n\n");
                printf("/--------------------------------------------------------------------/\n");
            }
            //}
        }
        //------------------------------ Fim Menu Pesquisa ------------------------------//

        else if (menumain == 3)
        { // Cadastrar uma passagem
          // O usuário deve informar todas as informações necessárias para cadastrar uma passagem. O sistema deve validar a entrada de dados, solicitando ao usuário digitar novamente, caso necessário. Após cadastrar a passagem, o sistema deve emitir uma mensagem de passagem cadastrada e gravar o arquivo com as passagens. Retornar ao menu principal.

            FILE *arquivo = fopen("D:/Douglas/Pessoal/Coding/University/Semestre 1/AEDS 1/Trabalho Milhas/passagens.txt", "r");
            checkfile(arquivo);

            npassagens = ler_ntotal_passagens(arquivo, npassagens);

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

            printf("\ncodigo origem: %s\n", passagens[0].cod_origem);
            printf("codigo destino: %s\n", passagens[0].cod_destino);
            printf("cidade origem: %s\n", passagens[0].cid_origem);
            printf("cidade destino: %s\n", passagens[0].cid_destino);
            printf("data: %s\n", passagens[0].data);
            printf("hora partida: %s\n", passagens[0].hora_partida);
            printf("hora chegada: %s\n", passagens[0].hora_chegada);
            printf("valor: %ld\n\n", passagens[0].valor);

            pular_n_linhas(arquivo, linha, 2);

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
            printf("Operação realizada com sucesso.\n");
            fclose(arquivo);
        }
        else if (menumain == 4)
        { // Editar uma passagem
          // O programa deve solicitar que o usuário digite o ID da passagem a ser editada, apresentar as informações da passagem encontrada e solicitar ao usuário que digite as novas informações da passagem, exceto a chave. Após editar a passagem, o sistema deve emitir uma mensagem de passagem atualizada e gravar o arquivo com as passagens. Informar passagem não encontrada, caso a pesquisa não retorne nenhuma passagem. Retornar ao menu principal.

            FILE *arquivo = fopen("D:/Douglas/Pessoal/Coding/University/Semestre 1/AEDS 1/Trabalho Milhas/passagens.txt", "r");
            checkfile(arquivo);

            FILE *arquivo_temp = fopen("D:/Douglas/Pessoal/Coding/University/Semestre 1/AEDS 1/Trabalho Milhas/arquivo_temp.txt", "w");
            checkfile(arquivo_temp);

            // Copia o conteudo original para um arquivo temporario
            // while ((letra = fgetc(arquivo)) != EOF)
            while ((letra = fgetc(arquivo)) != EOF)
            {
                fputc(letra, arquivo_temp);

                if (letra == '\n')
                {
                    contlinha++;

                    // Se copiou duas linhas, para o loop
                    if (contlinha == 2)
                    {
                        break;
                    }
                }
            }

            fclose(arquivo);
            fclose(arquivo_temp);
            arquivo = fopen("D:/Douglas/Pessoal/Coding/University/Semestre 1/AEDS 1/Trabalho Milhas/passagens.txt", "r");
            checkfile(arquivo);

            //--------------------------------------------------------------------------------------//
            npassagens = ler_ntotal_passagens(arquivo, npassagens);

            Passagem passagens[npassagens];

            pular_n_linhas(arquivo, linha, 2);

            guarda_as_passagens(arquivo, linha, npassagens, passagens);

            fclose(arquivo);

            printf("Digite o ID: ");
            scanf("%d", &searchn);

            for (aux = 0; aux < npassagens; aux++)
            {
                if (searchn == passagens[aux].id)
                {
                    printf("id: %d\n", passagens[aux].id);
                    printf("codigo origem: %s\n", passagens[aux].cod_origem);
                    printf("codigo destino: %s\n", passagens[aux].cod_destino);
                    printf("cidade origem: %s\n", passagens[aux].cid_origem);
                    printf("cidade destino: %s\n", passagens[aux].cid_destino);
                    printf("data: %s\n", passagens[aux].data);
                    printf("hora partida: %s\n", passagens[aux].hora_partida);
                    printf("hora chegada: %s\n", passagens[aux].hora_chegada);
                    printf("valor: %ld\n", passagens[aux].valor);
                    printf("\n");
                    break;
                }
            }
            if (aux == npassagens)
            {
                printf("Passagem não encontrada.\n");
            }
            printf("O que gostaria de mudar?\n");

            printf("1- codigo origem.\n");
            printf("2- codigo destino.\n");
            printf("3- cidade origem.\n");
            printf("4- cidade destino.\n");
            printf("5- data.\n");
            printf("6- hora partida.\n");
            printf("7- hora chegada.\n");
            printf("8- valor.\n");

            printf("\nEscolha a sua operação digitando um número correspondente: ");

            scanf("%d", &menuedit);

            if (menuedit == 1)
            {
                printf("Digite o novo codigo origem: ");
                scanf("%s", &passagens[aux].cod_origem);
                // tolower
            }
            if (menuedit == 2)
            {
                printf("Digite o novo codigo destino: ");
                scanf("%s", &passagens[aux].cod_destino);
                // tolower
            }
            if (menuedit == 3)
            {
                printf("Digite a nova cidade origem: ");
                scanf("%s", &passagens[aux].cid_origem);
                // toupper
            }
            if (menuedit == 4)
            {
                printf("Digite a nova cidade destino: ");
                scanf("%s", &passagens[aux].cid_destino);
                // toupper
            }
            if (menuedit == 5)
            {
                printf("Digite a nova data: ");
                scanf("%s", &passagens[aux].data);
            }
            if (menuedit == 6)
            {
                printf("Digite a nova hora de partida: ");
                scanf("%s", &passagens[aux].hora_partida);
            }
            if (menuedit == 7)
            {
                printf("Digite a nova hora de chegada: ");
                scanf("%s", &passagens[aux].hora_chegada);
            }
            if (menuedit == 8)
            {
                printf("Digite o novo valor: ");
                scanf("%ld", &passagens[aux].valor);
            }

            // Reabrir o arquivo para escrita
            arquivo = fopen("D:/Douglas/Pessoal/Coding/University/Semestre 1/AEDS 1/Trabalho Milhas/passagens.txt", "w");
            checkfile(arquivo);

            arquivo_temp = fopen("D:/Douglas/Pessoal/Coding/University/Semestre 1/AEDS 1/Trabalho Milhas/arquivo_temp.txt", "r");
            checkfile(arquivo_temp);

            // Colocando as duas linhas no arquivo original
            while ((letra = fgetc(arquivo_temp)) != EOF)
            {
                fputc(letra, arquivo);
            }

            // Escrever as passagens modificadas de volta no arquivo
            for (int i = 0; i < npassagens; i++)
            {
                fprintf(arquivo, "%d;%s;%s;%s;%s;%s;%s;%s;%ld;\n",
                        passagens[i].id, passagens[i].cod_origem, passagens[i].cod_destino,
                        passagens[i].cid_origem, passagens[i].cid_destino, passagens[i].data,
                        passagens[i].hora_partida, passagens[i].hora_chegada, passagens[i].valor);
            }

            printf("\nProcedimento realizado com sucesso.\n");
            fclose(arquivo);
        }
        else if (menumain == 5)
        { // Excluir uma passagem
          // O programa deve solicitar que o usuário digite o ID da passagem a ser excluída, apresentar as informações da passagem encontrada e solicitar ao usuário que confirme a exclusão. Em caso afirmativo, excluir a passagem. Após excluir a passagem, o sistema deve emitir uma mensagem de passagem excluída e gravar o arquivo com as passagens. Informar passagem não encontrado, caso a pesquisa não retorne nenhuma passagem. Retornar ao menu principal.

            FILE *arquivo = fopen("D:/Douglas/Pessoal/Coding/University/Semestre 1/AEDS 1/Trabalho Milhas/passagens.txt", "r");
            checkfile(arquivo);

            npassagens = ler_ntotal_passagens(arquivo, npassagens);

            Passagem passagens[npassagens];

            pular_n_linhas(arquivo, linha, 2);

            guarda_as_passagens(arquivo, linha, npassagens, passagens);

            fclose(arquivo);

            printf("Digite o ID da passagem que deseja excluir: ");
            scanf("%d", &searchn);

            for (aux = 0; aux < npassagens; aux++)
            {
                if (searchn == passagens[aux].id)
                {
                    printf("id: %d\n", passagens[aux].id);
                    printf("codigo origem: %s\n", passagens[aux].cod_origem);
                    printf("codigo destino: %s\n", passagens[aux].cod_destino);
                    printf("cidade origem: %s\n", passagens[aux].cid_origem);
                    printf("cidade destino: %s\n", passagens[aux].cid_destino);
                    printf("data: %s\n", passagens[aux].data);
                    printf("hora partida: %s\n", passagens[aux].hora_partida);
                    printf("hora chegada: %s\n", passagens[aux].hora_chegada);
                    printf("valor: %ld\n", passagens[aux].valor);
                    printf("\n");
                    break;
                }
            }
            if (aux == npassagens)
            {
                printf("Passagem não encontrada.\n");
            }

            if (aux != npassagens)
            {
                printf("Deseja excluir realmente essa passagem? (S/N)\n");
                scanf(" %c", &letra);

                if (tolower(letra) == 'n')
                {
                    printf("Você cancelou a operação\n");
                }
                else if (tolower(letra) == 's')
                {
                    arquivo = fopen("D:/Douglas/Pessoal/Coding/University/Semestre 1/AEDS 1/Trabalho Milhas/passagens.txt", "w");
                    checkfile(arquivo);

                    // Colocando as duas linhas no arquivo original com a diminuição
                    if (searchn == passagens[0].id)
                        fprintf(arquivo, "%d\n%d\n", npassagens - 1, passagens[1].id);
                    else if (searchn != passagens[0].id)
                    {
                        fprintf(arquivo, "%d\n%d\n", npassagens - 1, passagens[0].id);
                    }

                    // Escrever as passagens modificadas de volta no arquivo
                    for (int i = 0; i < npassagens; i++)
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
                }
                else if ((tolower(letra) != 's') && (tolower(letra) != 'n'))
                {
                    printf("Digita direito bocó");
                }
            }

            fclose(arquivo);
        }
        else if (menumain == 6)
        { // Sair do Programa
            // O programa deve emitir uma mensagem de encerramento do programa e finalizar.
            // exit(0); // Não precisa, por causa do while que coloquei depois
            printf("\n MIGreat Flights agradece a preferência, até a próxima :)\n\n");
        }
        else if ((menusearch <= 0) || (menusearch >= 7)) // Pq se eu tirar o else, isso printa quando digito 6?
        {
            printf("\n**Opção inexistente, por favor escolha uma opção válida**\n\n");
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

int ler_ntotal_passagens(FILE *arq, int numeropassagens)
{ // Retorna 1 se foi lido, e lê um inteiro do arquivo
    if (fscanf(arq, "%d", &numeropassagens) == 1)
    {
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

void guarda_as_passagens(FILE *arq, char line[], int numeropassagens, struct Passagem *tickets)
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
    }
}

void printa_as_passagens(int numeropassagens, struct Passagem *tickets)
{
    // Imprime tudo
    for (int i = 0; i < numeropassagens; i++)
    {

        printf("\nPassagem %d\n", i + 1);

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

void menu_pesquisa()
{
    printf("\nEscolha por qual opção de busca deseja pesquisar:\n\n");
    printf("1- ID da passagem\n");
    printf("2- Aeroporto de origem\n");
    printf("3- Aeroporto destino\n");
    printf("4- Cidade origem\n");
    printf("5- Cidade Destino\n");
    printf("\nEscolha a sua operação digitando um número correspondente: ");
}

// Função tolower
// Função toupper

/*
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 50  // Tamanho máximo padrão

typedef struct {
    char cod_origem[MAX_STRING_LENGTH];
    char cod_destino[MAX_STRING_LENGTH];
    char cid_origem[MAX_STRING_LENGTH];
    char cid_destino[MAX_STRING_LENGTH];
    char data[MAX_STRING_LENGTH];
    char hora_partida[MAX_STRING_LENGTH];
    char hora_chegada[MAX_STRING_LENGTH];
    long int valor;
} Passagem;

// Função para validar entradas de strings com tamanho específico
int validarEntrada(char campo[], int tamanho, const char mensagem[]) {
    printf("%s", mensagem);
    scanf(" %[^\n]", campo);
    if (strlen(campo) == tamanho) {
        return 1;  // Entrada válida
    } else {
        printf("Entrada inválida. Por favor, digite exatamente %d caracteres.\n", tamanho);
        return 0;  // Entrada inválida
    }
}

int main() {
    Passagem passagens[1];  // Supondo que você está lidando com apenas uma passagem

    // Exemplo de uso para dois campos diferentes
    while (!validarEntrada(passagens[0].cod_origem, 5, "Digite o Código de Origem: "));
    while (!validarEntrada(passagens[0].cod_destino, 8, "Digite o Código de Destino (8 caracteres): "));

    // ... (continue com as outras entradas e validações)

    // Validar a entrada do valor
    while (1) {
        printf("\nDigite o valor da passagem: ");
        if (scanf("%ld", &passagens[0].valor) == 1) {
            // Entrada válida, saia do loop
            break;
        } else {
            // Limpar o buffer de entrada em caso de erro
            while (getchar() != '\n');
            printf("Entrada inválida. Por favor, digite um valor válido.\n");
        }
    }

    // Imprimir os resultados
    printf("\ncodigo origem: %s\n", passagens[0].cod_origem);
    printf("codigo destino: %s\n", passagens[0].cod_destino);
    // ... (continue com as outras impressões)

    printf("valor: %ld\n", passagens[0].valor);

    return 0;
}
*/