#include <stdio.h>

typedef struct Car
{
    char marca[30];
    char modelo[30];
    char cor[20];
    int ano;
} Car;

Car register_car(Car);
void print_carro(Car);

int main(void)
{
    Car Carro[2];

    Carro[0] = register_car(Carro[0]);
    //Carro[1] = register_car(Carro[1]);

    print_carro(Carro[0]);
    //print_carro(Carro[1]);

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
    scanf("%d%c", &a.ano);
    //scanf("%d[^\n]", &a.ano);

    // scanf("%d", &a.ano);
    //getchar();

    return a;
}

void print_carro(struct Car a)
{
    printf("A marca do carro e %s\n", a.marca);
    printf("O modelo do carro e %s\n", a.modelo);
    printf("A cor do carro e %s\n", a.cor);
    printf("O ano do carro e %d\n", a.ano);
}
