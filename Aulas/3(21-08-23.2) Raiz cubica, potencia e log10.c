#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // raiz cubica, potencial e log10
  double raizc, potencia, logdez, numero;
  printf("Digite um numero: ");
  scanf("%lf", &numero);
  potencia = pow(numero, 2);
  raizc = cbrt(numero);
  logdez = log10(numero);
  printf("A raiz cubica de %lf é: %.2lf\n", numero, raizc);
  printf("A potencia é: %.lf\n", potencia);
  printf("O log10 é: %.2lf\n", logdez);

  // POTENCIA
  // double potencia, expoente, numero;
  // printf("Digite um número e seu expoente: ");
  // scanf("%lf %lf", &numero, &expoente);
  // potencia = pow(numero, expoente);
  // printf("A potencia de %.2lf com expoente %lf é: %.2lf", numero, expoente,
  //        potencia);

  // Nome e idade
  /*
  char nome[20];
  int idade;
  printf("Digite o nome: ");
  fgets(nome, 20, stdin);
  puts("Digite a idade: ");
  scanf("%d", &idade);
  printf("O nome e a idade são respectivamente: %s%d", nome, idade);
  */

  return 0;
}