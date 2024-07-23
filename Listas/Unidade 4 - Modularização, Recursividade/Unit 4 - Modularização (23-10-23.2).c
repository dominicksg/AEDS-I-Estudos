/*2. Faça uma função que recebe um valor inteiro e retorna -1 caso o valor seja
negativo, 1 caso seja positivo e 0 caso seja nulo. Crie um programa para testar
sua função.*/

#include <stdio.h>

int ex2(int numero);

int main() {
  int num, aux;
  printf("Digite um numero: ");

  scanf("%d", &num);
  aux = ex2(num);
  if (aux == -1) {
    printf("O número é negativo");
  } else if (aux == 1) {
    printf("O número é positivo");
  } else {
    printf("O numero é nulo");
  }
  return 0;
}

int ex2(int numero) {
  if (numero < 0) {
    return -1;
  }
  if (numero > 0) {
    return 1;
  }
  if (numero == 0) { // retornar 0 anyway
    return 0;
  }
  return 0;
}

//--------------------------------------------------//