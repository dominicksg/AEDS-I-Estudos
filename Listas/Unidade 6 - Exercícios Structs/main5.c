#include <stdio.h>

typedef struct Product
{
    int cod;
    char nome[100];
    float preco;

} Product;

Product ler_produto(Product);
void print_produto(Product);
float media_produtos(Product n[], int);

int main(void)
{
    int numprodutos;
    printf("Quantos produtos deseja cadastrar?\n");
    scanf("%d", &numprodutos);

    Product produto[numprodutos];

    for (int i = 0; i < numprodutos; i++)
    {
        printf("Cadastre o produto %d\n", i + 1);
        produto[i] = ler_produto(produto[i]);
    }

    for (int i = 0; i < numprodutos; i++)
    {
        print_produto(produto[i]);
    }

    float media = media_produtos(produto, numprodutos);

    printf("A media e: %.2f", media);

    return 0;
}

void print_produto(Product n)
{
    printf("O cod e: %d\n", n.cod);
    printf("O nome e: %s\n", n.nome);
    printf("O preco e: %.2f\n", n.preco);
}

Product ler_produto(Product n)
{
    printf("Digite o cod\n");
    scanf("%d", &n.cod);
    printf("Digite o nome\n");
    scanf(" %99[^\n]", n.nome); // Lê até 99 caracteres ou até encontrar uma nova linha
    printf("Digite o preco\n");
    scanf("%f", &n.preco);

    return n;
}

float media_produtos(Product n[], int numero)
{
    float soma = 0.0;

    for (int i = 0; i < numero; i++)
    {
        soma += n[i].preco;
    }
    return soma / numero;
}
