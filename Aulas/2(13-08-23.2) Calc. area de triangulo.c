#include <stdio.h>

int main(void) {
  float base, altura, area;
  printf("digite a base: ");
  scanf("%f", &base);
  printf("digite a altura: ");
  scanf("%f", &altura);
  area = (base * altura)/2;
  printf("o valor da area é: %.2f", area);
  
  /*printf("o valor de exemplo é: %i \ne o endereço de exemplo é : %p", exemplo, &exemplo);*/
  return 0;
}