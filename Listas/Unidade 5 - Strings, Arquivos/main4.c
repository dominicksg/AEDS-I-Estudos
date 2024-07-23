#include <stdio.h>
#include <string.h>

int main(void)
{
    char linha[100];
    FILE *arquivo = fopen("arquivo.txt", "r");

    // fscanf e getc = EOF
    while (fgets(linha, 100, arquivo) != NULL)
    {
        printf("%s", linha);
    }

    fclose(arquivo);

    return 0;
}