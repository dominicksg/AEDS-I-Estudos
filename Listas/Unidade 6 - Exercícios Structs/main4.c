#include <stdio.h>
#include <string.h>

typedef struct Car
{
    char marca[30];
    char modelo[30];
    char cor[20];
    int ano;
} Car;

Car register_car(Car);
void print_carro(Car);
Car tira_barraN(Car);
void arquivo_carro(Car, FILE *);
Car ler_arquivo(Car, FILE *);

int main(void)
{
    Car Carro[2];

    FILE *arquivo = fopen("arquivo.txt", "r");

    // fscanf(arquivo, "%s %s %s %d", Carro[0].marca, Carro[0].modelo, Carro[0].cor, &Carro[0].ano);
    Carro[0] = ler_arquivo(Carro[0], arquivo);
    Carro[1] = ler_arquivo(Carro[1], arquivo);

    print_carro(Carro[0]);
    print_carro(Carro[1]);

    fclose(arquivo);

    return 0;
}

Car register_car(Car a)
{
    printf("Digite a marca: ");
    // scanf(" %[^\n]", a.marca);
    fgets(a.marca, sizeof(a.marca), stdin);

    printf("Digite o modelo: ");
    // scanf(" %[^\n]", a.modelo);
    fgets(a.modelo, sizeof(a.modelo), stdin);

    printf("Digite a cor: ");
    // scanf(" %[^\n]", a.cor);
    fgets(a.cor, sizeof(a.cor), stdin);

    printf("Digite o ano: ");
    scanf("%d", &a.ano);
    getchar();

    // scanf("%d[^\n]", &a.ano);
    // scanf("%d%c", &a.ano);

    return a;
}

void print_carro(struct Car a)
{
    printf("A marca do carro e %s\n", a.marca);
    printf("O modelo do carro e %s\n", a.modelo);
    printf("A cor do carro e %s\n", a.cor);
    printf("O ano do carro e %d\n", a.ano);
}

Car tira_barraN(Car a)
{
    // char enter[] = {'\n'};

    int tamanho = strlen(a.marca);
    for (int i = 0; i < tamanho; i++)
    {
        if (a.marca[i] == '\n')
        {
            a.marca[i] = '\0';
        }
    }
    tamanho = strlen(a.modelo);

    for (int i = 0; i < tamanho; i++)
    {
        if (a.modelo[i] == '\n')
        {
            a.modelo[i] = '\0';
        }
    }
    tamanho = strlen(a.cor);

    for (int i = 0; i < tamanho; i++)
    {
        if (a.cor[i] == '\n')
        {
            a.cor[i] = '\0';
        }
    }
    return a;
}

void arquivo_carro(Car a, FILE *arquivo)
{
    fprintf(arquivo, "%s %s %s %d\n", a.marca, a.modelo, a.cor, a.ano);
}

Car ler_arquivo(Car a, FILE *arquivo)
{
    fscanf(arquivo, "%s %s %s %d", a.marca, a.modelo, a.cor, &a.ano);
    return a;
}