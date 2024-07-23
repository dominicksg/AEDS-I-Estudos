#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[100];
    char str2[200];
    FILE *arquivo = fopen("arquivo.txt", "r");
    FILE *arquivo2 = fopen("arquivo2.txt", "r");
    FILE *arquivo3 = fopen("arquivo3.txt", "w");

    while (fgets(str1, 100, arquivo) != NULL)
    {
        fgets(str2, 100, arquivo2);
        strcat(str1, str2);
        fprintf(arquivo3, "%s", str1);
    }

    fclose(arquivo);
    fclose(arquivo2);
    fclose(arquivo3);

    return 0;
}