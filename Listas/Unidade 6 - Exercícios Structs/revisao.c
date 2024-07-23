#include <stdio.h>

typedef struct Car
{
    char marca[50];
    char modelo[50];
    int ano;
} Car;

Car cadastrocarro()
{
    Car carro;
    scanf(" %[^\n]", carro.marca);
    scanf(" %[^\n]", carro.modelo);
    scanf("%d", &carro.ano);
    return carro;
}

void printcarro(Car carro)
{
    printf("Marca: %s\n", carro.marca);
    printf("Modelo: %s\n", carro.modelo);
    printf("Ano: %d\n", carro.ano);
}

void fprintcarro(Car carro)
{
    FILE *arquivo = fopen("arquivo.txt", "a+");
    fprintf(arquivo, "%s %s %d\n", carro.marca, carro.modelo, carro.ano);
    fclose(arquivo);
}

Car flercarro(Car carro, FILE *arquivo)
{
    fscanf(arquivo, "%s %s %d", carro.marca, carro.modelo, &carro.ano);
    return carro;
}

int main()
{
    FILE *arquivo = fopen("arquivo.txt", "r");
    Car carro1 = flercarro(carro1, arquivo);
    Car carro2 = flercarro(carro2, arquivo);

    printcarro(carro1);
    printcarro(carro2);

    fclose(arquivo);

    return 0;
}
