//Primos entre numeros
#include <stdio.h>

int main(void) {

  int num1, num2;
  int numero, divisores = 0, primos = 0;

  do {
    
    printf("Num1: ");
    scanf("%i", &num1);
    printf("Num2: ");
    scanf("%i", &num2);

    for (int y = num1; y < num2; y++) {
      divisores = 0;
      numero = y;
      for (int i = 2; i <= numero / 2; i++) {
        if (numero % i == 0) {
          divisores++;
        }
      }
      if (divisores == 0)
        primos++;
    }

    printf("Tem %i primos entre %i e %i\n\n", primos, num1, num2);

  } while (numero != -1);
}


//Se um numero é primo ou não//
/*#include <stdio.h>

int main(void) {
  int numero, divisores = 0;
  
  do {
    divisores = 0;
    printf("\nNúmero: ");
    scanf("%i", &numero);

    for (int i = 2; i <= numero/2; i++) {
      if (numero % i == 0) {
        divisores++;
      }
    }

    if (divisores == 0)
      printf("O número %i É primo.\n", numero);
    else
      printf("O número %i NÃO é primo.\n", numero);
  } while (numero != -1);
}*/


//Ajuste de preço
/*#include <stdio.h>

int main(void) {
  float preco, aumento;
  int categoria;
  char situacao;

  printf("Digite o preço: ");
  scanf("%f", &preco);
  printf("Digite a situação: ");
  scanf(" %c", &situacao);
  printf("Digite a categoria: ");
  scanf("%i", &categoria);

  if (preco <= 25) {
    switch (categoria) {
    case 1:
      aumento = preco * 0.05;
      break;
    case 2:
      aumento = preco * 0.08;
      break;
    case 3:
      aumento = preco * 0.1;
      break;
    }
  } else {
    if (categoria == 1)
      aumento = preco * 0.12;
    else if (categoria == 2)
      aumento = preco * 0.15;
    else
      aumento = preco * 0.18;
  }

  float imposto;
  if (categoria == 2 || situacao == 'r' || situacao == 'R')
    imposto = preco * 0.05;
  else
    imposto = preco * 0.08;

  // resposta
  printf("\nImposto = %.2f", imposto);
  printf("\nAumento = %.2f", aumento);
}*/