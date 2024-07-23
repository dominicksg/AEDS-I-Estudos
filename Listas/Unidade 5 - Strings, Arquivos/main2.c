#include <stdio.h>

void gravatexto(FILE *arq, char texto[])
{

    fprintf(arq, "%s", texto);
}

int main(void)
{
    FILE *arquivo = fopen("arquivo.txt", "w");
    char string[100];

    fgets(string, sizeof(string), stdin);
    gravatexto(arquivo, string);

    return 0;
}