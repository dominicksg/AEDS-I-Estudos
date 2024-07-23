#include <stdio.h>
#include <stdlib.h>

// Crie um programa em C que:
// a) Aloque dinamicamente 5 numeros inteiros
// b) Solicite a digitacao de 5 numeros e armazene no espaco alocado
// c) Imprima os numeros e os enderecos onde foram alocados
// d) Libere memoria
// e) Realoque espaco para mais 5 numeros inteiros
// f) Solicite a digitacao de mais 5 numeros
// g) Imprima o conteudo e o endereco dos 10 numeros

int main(void) {
  int *ptr;
  int n = 5;

  // Guardar tamanho memoria
  ptr = (int *)malloc(n * sizeof(int));

  // Preencher memoria
  for (int i = 0, *p = ptr; i < n; p++, i++) {
    scanf("%d", p);
  }

  // Printar
  for (int i = 0; i < 5; i++) {
    printf("%d\n", *(ptr + i));
  }
  printf(".\n");

  // Aumentar memoria
  ptr = (int *)realloc(ptr, 8 * sizeof(int));

  // Preencher nova memoria
  for (int i = 0, *p = ptr + 5; i < 3; p++, i++) {
    scanf("%d", p);
  }
  // Printar
  for (int i = 0; i < 8; i++) {
    printf("%d\n", *(ptr + i));
  }
  printf(".\n");

  free(ptr);

  return 0;
}
// for (int *p = ptr; p != NULL; p++) {
//   scanf("%d", ptr);
// }