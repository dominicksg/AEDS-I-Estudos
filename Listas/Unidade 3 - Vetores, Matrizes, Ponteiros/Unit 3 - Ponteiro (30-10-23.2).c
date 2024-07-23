/*------------------------------------------------*/
/*
  1. Escreva um programa em C que leia dois inteiros, armazenando-os em
  variáveis. O programa deve comparar os endereços das variáveis e exibir o
  maior deles.
*/

/*
#include <stdio.h>

int main(void) {
  int int1, int2;
  scanf("%d %d", &int1, &int2);

  if (&int1 > &int2)
    printf("%p", &int1);

  else if (&int1 < &int2)
    printf("%p", &int2);

  return 0;
}
*/

/*------------------------------------------------*/
/*
2. Explique cada uma das expressões a seguir, indicando a diferença entre elas:
p++; (*p)++; *(p++);
Qual informação se refere a expressão *(p+10)?
*/
//  p++ isso incrementa o ponteiro p1 em uma unidade. Isso significa que p1
//  agora apontará para a próxima posição de memória.

//  (*p)++ o valor apontado por p (ou seja, o valor na posição de memória para a
//  qual p aponta) é incrementado em 1 unidade. O ponteiro em si não é alterado,
//  apenas o valor apontado é modificado.

//  *(p++) ou *p++ O valor apontado por p é modificado antes de p ser
//  incrementado em 1 unidade. Isso significa que primeiro a operação de
//  desreferenciamento (*) é realizada, modificando o valor na posição de
//  memória para a qual p aponta, e em seguida, p é incrementado para apontar
//  para a próxima posição de memória

// O valor apontado por p é modificado antes de andar 10 casas com o vetor e
// apresentar o valor daquela casa

/*------------------------------------------------*/
/*
3. Se o endereço de uma variável valor foi atribuído a um ponteiro valorPtr,
quais alternativas são verdadeiras? Justifique sua resposta.
a) valor = =&valorPtr
  -b) valor = = *valorPtr
  -c) valorPtr = = &valor
d) valorPtr = = *valor
*/

/*------------------------------------------------*/
/*
4. Identifique o erro no programa a seguir, de modo que seja exibido o valor 10
na tela. #include <stdio.h> int main()
{
int x, *p, **q;
p = &x;
q = &p;
x = 10;
printf("\n%d\n", &q);
return(0);
}
*/

/*
#include <stdio.h>
int main() {
  int x, *p, **q;
  p = &x;
  q = &p;
  x = 10;
  printf("%d", **q);
  return (0);
}
*/

/*------------------------------------------------*/
/*
5. Escreva um programa em C que declare variáveis para armazenar um valor
inteiro, um valor real e um caracter. Deve existir no programa ponteiros
associados a cada um deles. O programa deve solicitar novos dados para as
variáveis e elas devem ser modificadas usando os respectivos ponteiros. Exiba os
endereços e os conteúdos de todas as variáveis e ponteiros antes e após a
alteração.
*/
/*
#include <stdio.h>

int main(void) {
  int int1 = 5, *ptrint1 = &int1;
  float racional1 = 5.2, *ptrrac = &racional1;
  char caracter1 = 'h', *ptrcar = &caracter1;

  printf("Endereço dos ponteiros\n");
  printf("%p\n", &ptrint1);
  printf("%p\n", &ptrrac);
  printf("%p\n", &ptrcar);

  printf("\nValor dos ponteiros\n");
  printf("%p\n", ptrint1);
  printf("%p\n", ptrrac);
  printf("%p\n", ptrcar);

  printf("\nValor dos ponteiros\n");
  printf("%d\n", *ptrint1);
  printf("%f\n", *ptrrac);
  printf("%c\n", *ptrcar);

  printf("\nEndereço das variaveis\n");
  printf("%p\n", &int1);
  printf("%p\n", &racional1);
  printf("%p\n", &caracter1);

  printf("\nValor das variaveis\n");
  printf("%d\n", int1);
  printf("%f\n", racional1);
  printf("%c\n\n", caracter1);

  //-----------Codigo-----------//
  scanf("%d", &int1);
  scanf("%f", &racional1);
  scanf(" %c", &caracter1);
  //-----------Codigo-----------//

  printf("\n\nEndereço dos ponteiros\n");
  printf("%p\n", &ptrint1);
  printf("%p\n", &ptrrac);
  printf("%p\n", &ptrcar);

  printf("\nValor dos ponteiros\n");
  printf("%p\n", ptrint1);
  printf("%p\n", ptrrac);
  printf("%p\n", ptrcar);

  printf("\nEndereço das variaveis\n");
  printf("%p\n", &int1);
  printf("%p\n", &racional1);
  printf("%p\n", &caracter1);

  printf("\nValor das variaveis\n");
  printf("%d\n", int1);
  printf("%f\n", racional1);
  printf("%c\n", caracter1);

  return 0;
}
*/
/*------------------------------------------------*/
/*
6. Observe os dois programas a seguir, Código 1 e Código 2. Qual. É a diferença
entre eles? Qual é o valor impresso para ptr em cada um dos códigos? Porque?
*/

/*------------------------------------------------*/
/*
7. Mostre na tabela a seguir todas as alterações dos conteúdos das variáveis
(teste de mesa) e identifique qual será a saída do programa em C para os valores
lidos (x = 5 e y = 6). int main ()
{
int x, y;
int *px = &x;
int *py = &y;
scanf(“%d”,&x);
scanf(“%d”,&y);
px = py;
*py = (*py) * (*px);
*px = *px + 2;
printf(“x = %d, y = %d”, x, y);
return 0;
}
*/

// x = 5, y = 38

/*------------------------------------------------*/
/*
8. Crie um programa em C que:
a) Aloque dinamicamente 5 números inteiros
b) Peça para o usuário digitar os 5 números e armazene no espaço alocado
c) Mostre na tela os 5 números
d) Libere a memória alocada
*/

/*
#include <stdio.h>
#include <stdlib.h>

int main(void){

  // Aloque dinamicamente espaço para 5 números inteiros
  int *numeros = (int *)malloc(5 * sizeof(int));

  // Peça para o usuário digitar os 5 números e armazene no espaço alocado

  printf("Digite 5 números inteiros:\n");
  for (int i = 0; i < 5; i++) {
      scanf("%d", &numeros[i]);
  }

  // Mostre na tela os 5 números
  printf("Os números digitados são:\n");
  for (int i = 0; i < 5; i++) {
      printf("%d\n", numeros[i]);
  }

  // Libere a memória alocada
  free(numeros);


  return 0;
}
*/

/*------------------------------------------------*/
/*
9. Faça um programa em C que solicite ao usuário a quantidade de alunos de uma
turma e leia a nota de cada aluno, armazenando-a em memória alocada
dinamicamente. A nota é um número real de dupla precisão (double). Imprima todas
as notas e também a média das notas
*/

/*

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int tam;
  double media = 0;

  scanf("%d", &tam);

  double *notas = (double *)malloc(tam * sizeof(double));

  for (int i = 0; i < tam; i++) {
    scanf("%lf", &notas[i]);
    media += notas[i];
  }

  media = media / tam;

  printf("%lf", media);

  for (int i = 0; i < tam; i++) {
    printf("%lf", notas[i]);
  }

  free(notas);

  return 0;
}
*/

/*------------------------------------------------*/
/*
10. Faça um programa em C para armazenar em memoria um total de 30 valores do
tipo inteiro, usando a função de alocação dinâmica de memória CALLOC:
a) Atribua para os primeiros 10 inteiros os valores de 1 a 10.
b) Atribua para os últimos 10 inteiros os valores de 10 a 1.
c) Exiba na tela os 30 números.

*/

/*
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *valores;
    int i;

    // Alocar memória para um array de 30 inteiros
    valores = (int *)calloc(30, sizeof(int));

    if (valores == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Atribuir os valores de 1 a 10 aos primeiros 10 inteiros
    for (i = 0; i < 10; i++) {
        valores[i] = i + 1;
    }

    // Atribuir os valores de 10 a 1 aos últimos 10 inteiros
    for (i = 20; i < 30; i++) {
        valores[i] = 10 - (i - 20);
    }

    // Exibir os 30 números
    for (i = 0; i < 30; i++) {
        printf("%d ", valores[i]);
    }

    // Liberar a memória alocada
    free(valores);

    return 0;
}

*/

/*------------------------------------------------*/
/*
11. Crie um programa em C que:
a) Aloque dinamicamente 5 números inteiros
b) Peça para o usuário digitar os 5 números e armazene no espaço alocado
c) Imprima os endereços onde foram armazenados os 5 números
d) Realoque um espaço para digitais mais 5 números inteiros
e) Peça para o usuário digitar novos 5 números e armazene no novo espaço alocado
f) Imprima os endereços onde foram armazenados os 10 números
g) Mostre na tela os 10 números
h) Libere a memória alocada.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *numeros1 = (int *)malloc(5 * sizeof(int));

  if (numeros1 == NULL)
  {
    printf("Erro na alocação de memória.\n");
    return 1;
  }

  printf("Digite 5 números inteiros:\n");
  for (int i = 0; i < 5; i++)
  {
    scanf("%d", &numeros1[i]);
  }

  printf("Endereços dos 5 números alocados dinamicamente:\n");
  for (int i = 0; i < 5; i++)
  {
    printf("%p\n", &numeros1[i]);
  }

  int *numeros2 = (int *)realloc(numeros1, 10 * sizeof(int));

  if (numeros2 == NULL)
  {
    printf("Erro no realocamento de memória.\n");
    free(numeros1);
    return 1;
  }

  printf("Digite mais 5 números inteiros:\n");
  for (int i = 5; i < 10; i++)
  {
    scanf("%d", &numeros2[i]);
  }

  printf("Endereços dos 10 números alocados dinamicamente:\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%p\n", (void *)&numeros2[i]);
  }

  printf("Os 10 números digitados são:\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%d\n", numeros2[i]);
  }

  free(numeros2);

  return 0;
}

/*------------------------------------------------*/
/*
12. A alocação dinâmica de memória permite trabalhar com matrizes de formas
diferentes, a saber: • Utilizando um ponteiro simples. • Utilizando um arranjo
de ponteiro. • Utilizando um ponteiro para ponteiro
*/

/*------------------------------------------------*/
/*

//Para visualizar o funcionamento de ponteiros:

#include <stdio.h>

int main(void) {
  int a = 7, b = 8, c = 9, d = 10;
  int *p1 = &a, *p2 = &b, *p3 = &c, *p4 = &d;
  int n = 4;

  for (int i = 0; i < n; i++) {
    p1++;
    *p2++=1;
    *(p3++)=2; //mesma coisa do de cima, já que o "++" tem uma prioridade maior
de leitura do que "*"
    (*p4)++;
  }
  return 0;
}
*/
