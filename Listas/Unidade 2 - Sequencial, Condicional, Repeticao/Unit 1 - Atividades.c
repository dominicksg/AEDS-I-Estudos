// ACT 5 cubo, raiz quadrada, raiz cúbica, seno, cosseno

#include <math.h>
#include <stdio.h>

int main(void)
{
  double n1, cubo, raizq, raizc, sen, cossn;
  printf("Digite um numero: ");
  scanf("%lf", &n1);
  cubo = n1 * n1 * n1;
  raizq = sqrt(n1);
  raizc = cbrt(n1);
  sen = sin(n1);
  cossn = cos(n1);
  printf("O número ao cubo é: %lf\nA raiz é: %lf\nA raiz cubica é: %lf\nO seno é: %lf\nO coseno é: %lf", cubo, raizq, raizc, sen, cossn);

  return 0;
}

/*ACT 4 Media ponderada 4n pesos 1,2,3,4
#include <stdio.h>

int main(void) {
  float n1, n2, n3, n4, denominador, soma;
  printf("Digite os quatro números que serão tirados a média ponderada: ");
  scanf("%f %f %f %f", &n1, &n2, &n3, &n4);
  denominador = n1+n2+n3+n4;
  soma = (n1+(n2*2)+(n3*3)+(n4*4))/denominador;
  printf("A média ponderada é: %f", soma);
  return 0;
}*/

/*#ACT 02 OPT
#include <stdio.h>

int main(void) {
int n1, n2;
printf("digite um numero: ");
scanf("%d", &n1);
printf("digite um numero: ");
scanf("%d", &n2);
n2 = n1 + n2;
printf("digite um numero: ");
scanf("%d", &n1);
n2 = (n1 + n2)/3;
printf("a soma é: %d", n2);

  return 0;
}*/

/*#ACT 02 Media aritmetica de 3 numeros
include <stdio.h>

int main(void) {
int n1, n2, soma;
printf("digite um numero: ");
scanf("%d", &n1);
printf("digite um numero: ");
scanf("%d", &n2);
printf("digite um numero: ");
scanf("%d", &soma);
soma = (n1 + n2 + soma)/3;
printf("a soma é: %d", soma);

  return 0;
}*/

/*#ACT 01 OPT
#include <stdio.h>

int main(void) {
  int n1, n2;
  printf("digite um numero: ");
  scanf("%d", &n1);
  printf("digite um numero: ");
  scanf("%d", &n2);
  n2 = n1 + n2;
  printf("digite um numero: ");
  scanf("%d", &n1);
  n2 = n1 + n2;
  printf("a soma é: %d", n2);

return 0;
}*/

/*#ACT 01 Soma e produto de 3 numeros
#include <stdio.h>

int main(void) {
int n1, n2, n3, produto, soma;
  printf("digite um numero: ");
  scanf("%d", &n1);
  printf("digite um numero: ");
  scanf("%d", &n2);
  printf("digite um numero: ");
  scanf("%d", &n3);
  soma = n1 + n2 + n3;
  produto = n1*n2*n3;
  printf("A soma de %d %d e %d é: %d\nE o produto é: %d", n1, n2, n3, soma,
produto);

  return 0;
}*/