#include <stdio.h>

int main(void)
{
    int qtdveiculos;
    float aluguel;

    scanf("%d", &qtdveiculos);

    scanf("%f", &aluguel);
    float faturamento_anual = (qtdveiculos / 3) * 12 * aluguel;
    float multa_mes = ((qtdveiculos / 10) * 20) / 100 * aluguel;
    float manutencao = ((qtdveiculos * 2) / 100) * 600;

    printf("Valor faturamento ano: %f\n", faturamento_anual);
    printf("Valor multa mes: %f \n", multa_mes);
    printf("Valor manutencao ano: %f\n", manutencao);

    FILE *arquivo = fopen("arquivo.txt", "w");
    fprintf(arquivo, "%.2f\n%.2f\n%.2f", faturamento_anual, multa_mes, manutencao);
    fclose(arquivo);

    return 0;
}