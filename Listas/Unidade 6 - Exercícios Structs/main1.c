// 1-------------------------------------------------------------------------------------------------//
#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct Adress
{
    char rua[200];
    int casaN;
} Adress;

typedef struct Customer
{
    char nome[100];
    char telefone[15];
    Adress endereco;
} Customer;

Customer Register(Customer);
void PrintCustomer(Customer);

int main(void)
{
    setlocale(LC_ALL, "Portuguese_Brazil");
    Customer cliente1;
    // Customer cliente2;

    cliente1 = Register(cliente1);
    // cliente2 = Register(cliente2);

    PrintCustomer(cliente1);
    // PrintCustomer(cliente2);

    return 0;
}

Customer Register(Customer a)
{
    printf("Digite o nome do cliente: \n");
    fgets(a.nome, 100, stdin);

    printf("Digite o numero do cliente: \n");
    fgets(a.telefone, 100, stdin);
    //scanf("%s", a.telefone);
    // getchar(); // consumir o caractere de nova linha remanescente do scanf

    printf("Digite o endereco (Bairro e Rua) do cliente: ");
    fgets(a.endereco.rua, 200, stdin);
    //a.endereco.rua[strcspn(a.endereco.rua, "\n")] = '\0';

    printf("Digite o Numero da casa do cliente: ");
    scanf("%d", &a.endereco.casaN);    
    getchar(); // consumir o caractere de nova linha remanescente
    return a;
}

void PrintCustomer(struct Customer a)
{
    printf("\no Nome e: %s", a.nome);
    printf("o Numero e: %s\n", a.telefone);
    printf("O Endereco e: %s, %d\n\n", a.endereco.rua, a.endereco.casaN);
}

// 2-------------------------------------------------------------------------------------------------//

/*
#include <stdio.h>

typedef struct Adress
{
    char rua[100];
    char bairro[100];
    int numero;

} Adress;

typedef struct Cliente
{
    char nome[100];
    Adress endereco;
    int telefone;

} Cliente;

Cliente cadastrocliente();
void print_cliente(Cliente);

int main()
{

    Cliente c1 = cadastrocliente();
    // Cliente c2 = cadastrocliente();

    print_cliente(c1);
    // print_cliente(c2);

    return 0;
}

void print_cliente(Cliente c)
{
    printf("\nO nome e: %s\n", c.nome);
    printf("O numero e: %d\n", c.telefone);
    printf("O Bairro e: %s\n", c.endereco.bairro);
    printf("A Rua e: %s\n", c.endereco.rua);
    printf("O numero da casa e: %d\n", c.endereco.numero);
}

Cliente cadastrocliente()
{
    Cliente c;
    printf("Digite o nome\n");
    scanf(" %[^\n]", c.nome);
    printf("Digite o numero\n");
    scanf("%d", &c.telefone);
    printf("Digite o Bairro\n");
    scanf(" %[^\n]", c.endereco.bairro);
    printf("Digite a Rua\n");
    scanf(" %[^\n]", c.endereco.rua);
    printf("Digite o Numero da Casa\n");
    scanf("%d", &c.endereco.numero);
    return c;
}
*/