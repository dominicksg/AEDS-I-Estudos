/*
1. Escreva uma função recursiva que, dado dois números x e n, calcula o valor x∗n (x multiplicado por n). Não use o operador de multiplicação.

2. Escreva uma função que recebe um número inteiro e retorna o fatorial deste número usando a abordagem recursiva.

3. Escreva uma função recursiva que dado dois números x e n, calcula o valor xn (x elevo a n). Não use as funções de math.h.

4. Escreva uma função recursiva que calcula a soma de todos os elementos de um arranjo de números reais.
*/

// Ex1
/*
#include <stdio.h>

int multiplicacaoRecursiva(int y, int z) {
  // Caso base
  if (z == 0) {
    return 0;
  } else if (z > 0) {
    return y + multiplicacaoRecursiva(y, z - 1);
  } else {
    return -multiplicacaoRecursiva(y, -z);
  }
}

int main() {
  int w;
  int x;
  scanf("%d %d", &w, &x);

  int resultado = multiplicacaoRecursiva(w, x);
  printf("%d * %d = %d\n", w, x, resultado);

  return 0;
}
*/
//----------------------------------------------------------------//
// Ex2

/*
#include <stdio.h>

// Função para calcular o fatorial de um número inteiro
int calcularFatorial(int n) {
  // Caso base: O fatorial de 0 é 1
  if (n == 0) {
    return 1;
  }
  // Caso geral: O fatorial de n é n multiplicado pelo fatorial de (n-1)
  return n * calcularFatorial(n - 1);
}

int main() {
  int numero;
  printf("Digite um número inteiro: ");
  scanf("%d", &numero);

  int fatorial = calcularFatorial(numero);
  printf("O fatorial de %d é %d\n", numero, fatorial);

  return 0;
}
*/

//----------------------------------------------------------------//
// Ex3
/*
#include <stdio.h>

double power(double x, int n) {
    if (n == 0) {
        return 1.0;
    } else if (n > 0) {
        return x * power(x, n - 1);
    } else {
        // Tratamento para expoentes negativos
        return 1.0 / (x * power(x, -n - 1));
    }
}

int main() {
    double x;
    int n;
    printf("Digite o valor de x: ");
    scanf("%lf", &x);
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    double result = power(x, n);
    printf("%.2lf ^ %d = %.6lf\n", x, n, result);

    return 0;
}
*/

//----------------------------------------------------------------//
// Ex4

#include <stdio.h>

double soma_arranjo(double array[], int tamanho)
{
  // Caso base: quando o tamanho do arranjo é 0, a soma é 0.
  if (tamanho == 0)
  {
    return 0;
  }
  // Caso recursivo: a soma é o primeiro elemento do arranjo
  // mais a soma dos elementos restantes.
  return array[0] + soma_arranjo(array + 1, tamanho - 1);
}

int main()
{
  int tam;

  scanf("%d", &tam);
  double arr[tam];

  for (int i = 0; i < tam; i++)
  {
    scanf("%lf", &arr[i]);
  }

  double resultado = soma_arranjo(arr, tam);

  printf("A soma dos elementos do arranjo é: %.2lf\n", resultado);

  return 0;
}

//----------------------------------------------------------------//
