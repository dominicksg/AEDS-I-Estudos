/*Digite a opção desejada
1)Somar dois números
2)Calcular a raiz quadrada de um número*/
/*#include <math.h>
#include <stdio.h>

int main(void) {
  int menu;
  float n1, n2;
  printf("Escolha a sua operação:\n\n\t\t1-Somar dois números\n\t\t"
         "2-Calcular a raiz quadrada de um número\n\nDigite a opção desejada: ");
  scanf("%d", &menu);
  switch (menu){
    case 1:
    printf("Digite dois números: ");
    scanf("%f %f", &n1, &n2);
    n1 = n1 + n2;
    printf("A soma dos números é: %f", n1);
    break;
    case 2:
    printf("Digite um número: ");
    scanf("%f", &n1);
    n2 = sqrt(n1);
    printf("A raiz quadrada de %.0lf é: %.2lf", n1, n2);
    break;  
    default:
    printf("\tSABE LER NAO?");
  }
  return 0;
}*/


#include <math.h>
#include <stdio.h>

int main(void) {
  int menu;
  printf("Escolha a sua operação:\n\n\t\t1-Somar dois números\n\t\t"
         "2-Calcular a raiz quadrada de um número\n\nDigite a opção desejada: ");
  scanf("%d", &menu);
  if (menu == 1) {
    int n1, n2;
    printf("Digite dois números: ");
    scanf("%d %d", &n1, &n2);
    n1 = n1 + n2;
    printf("A soma dos números é: %d", n1);
  } else if (menu == 2) {
    double n1, n2;
    printf("Digite um número: ");
    scanf("%lf", &n1);
    n2 = sqrt(n1);
    printf("A raiz quadrada de %.0lf é: %.2lf", n1, n2);
  }
  if (menu != 1 && menu != 2)
    printf("\tSABE LER NAO?");
  return 0;
}

/*Leia um numero inteiro e mostre se o numero é par ou impar
#include <stdio.h>

int main(void) {
  int numero;
  printf("Digite um número: ");
  scanf("%d", &numero);
  if (numero % 2 == 1) {
    printf("O número é impar");
  } else {
    printf("O número é par");
  }
  return 0;
}*/