// Usando vetor
/*#include <stdio.h>

int main(void) {
  float peso[5];
  float media, soma = 0;
  int menor, maior, imenor, imaior;
  for (int i = 0; i < 5; i++) {
    printf(" Insira o peso da %d pessoa: ", i + 1);
    scanf("%f", &peso[i]);
    soma = soma + peso[i];
  }
  for (int i = 0; i < 5; i++) {
    // media = ((peso[0] + peso[1] + peso[2] + peso[3] + peso[4]) / 5);
    printf("\nO peso da pessoa %d é: %.2f", i + 1, peso[i]);
  }
  media = soma / 5;
  menor = peso[0];
  maior = peso[0];
  printf("\n\nA media de pesos é %.2f\n", media);
  for (int i = 0; i < 5; i++) {
    if (maior < peso[i]) {
      maior = peso[i];
      imaior = i;
    } else if (menor > peso[i]) {
      menor = peso[i];
      imenor = i;
    }
  }
  printf("\nO maior é: %d e seu índice é: %d", maior, imaior);
  printf("\nO menor é: %d e seu índice é: %d", menor, imenor);

  return 0;
}*/

// Matriz
//  Escreva um programa para calcular a soma da diagonal principal de uma matriz
//  quadradas (10x10) de inteiros Seu programa deve possibilitar a entrada de
//  dados manualmente na matriz
#include <stdio.h>
int main(void)
{
  float soma = 0;
  int matriz[10][10];
  // entrada de dados da matriz
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      printf("Digite o conteúdo da linha %d coluna %d", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }
  // varrer a matriz e somar a diag principal
  for (int i = 0; i < 10; i++)
  {
    for (int j = 0; j < 10; j++)
    {
      if (i == j)
      {
        soma = soma = matriz[i][j];
      }
    }
  }
  printf("A soma da diagonal principal é: %d", soma);

  return 0;
}
/*for (int=0;i<10;i++){
soma = soma + matriz [i][i]


}





*/