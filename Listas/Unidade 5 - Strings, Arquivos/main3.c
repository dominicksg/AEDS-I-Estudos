#include <stdio.h>

main(void)
{
    int num = 0;
    char letra;

    FILE *arquivo = fopen("arquivo.txt", "r");

    // while (fscanf(arquivo, " %c", &letra) == 1) {
    while ((letra = fgetc(arquivo)) != EOF)
    {
        if (letra == 'a' || letra == "A")
            num++;
    }

    printf("A letra A apareceu %d vezes", num);
    return 0;
}