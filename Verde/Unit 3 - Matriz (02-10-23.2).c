/*C Lista de Vetores - Ex3
Faça um algoritmo que leia um vetor de N posições de números inteiros e
imprima o maior elemento do vetor e sua posição no vetor. Caso exista mais de
um elemento cujo valor seja o maior dentre todos, imprima a posição do último
elemento encontrado. N é lido pelo algoritmo.

Formato da entrada: primeira linha contém N, segunda linha contém os números
do vetor.

Formato saída: única linha contendo o maior elemento e sua posição.*/

/*
#include <stdio.h>

int main(void) {
  int n, nmaior = 0;
  int casa = 0;

  scanf("%d", &n);

  int vetor[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &vetor[i]);
    if (vetor[i] >= nmaior) {
      nmaior = vetor[i];
    }
  }
  for (int i = 0; i < n; i++) {
    if (vetor[i] == nmaior) {
      casa = i;
    }
  }

  printf("%d %d", nmaior, casa);
  return 0;
}
*/

/*----------------------------------------------------*/
/*C Lista de Vetores Ex. 9
Construa um algoritmo que preencha dois vetores de números inteiros de N
posições, e depois crie um terceiro vetor cujo conteúdo de cada posição é 1 se
os elementos dos dois vetores forem iguais nessa posição, ou 0 caso contrário.
N é digitado pelo usuário.

Formato da entrada: primeira linha contém N, segunda linha contém os números
do primeiro vetor, terceira linha contém os números do segundo vetor.

Formato saída: linha contendo os elementos do vetor resultante.*/

/*
#include <stdio.h>

int main(void) {
  int n, n1, n2;

  scanf("%d", &n);
  int vetor1[n], vetor2[n], vetor3[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &vetor1[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &vetor2[i]);
  }

  for (int i = 0; i < n; i++) {
    if (vetor1[i] == vetor2[i]) {
      vetor3[i] = 1;
    }
    if (vetor1[i] != vetor2[i]) {
      vetor3[i] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", vetor3[i]);
  }
  return 0;
}
*/

/*----------------------------------------------------*/
/*C Lista de Vetores - Ex12
Faça um algoritmo que preencha dois vetores de inteiros de N posições e
exiba um terceiro vetor resultante em que o elemento de uma posição é a soma
dos elementos de mesma posição dos outros dois vetores. N é lido pelo
algoritmo. Exemplo:

V1 = [10 27 3 -4 -6]
V2 = [ 0 -7 6 4 -5]
V1 = [10 20 9 0 -11]

Formato da entrada:
primeira linha contém N,
segunda linha contém os números do primeiro vetor,
terceira linha contém os números do segundo vetor.
1)5
2)-9 -3 4 -10 -1
3)7 -2 7 5 -1

Formato saída:
linha contendo os elementos do vetor resultante.
1)-2 -5 11 -5 -2*/

/*
#include <stdio.h>

int main(void) {
  int n;

  scanf("%d", &n);
  if (n < 0) {
    n = n - n - n; // transforma negativo em positivo
  }

  int vetor1[n], vetor2[n], vetor3[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &vetor1[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &vetor2[i]);
  }
  for (int i = 0; i < n; i++) {
    vetor3[i] = vetor1[i] + vetor2[i];
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", vetor3[i]); // printa o vetor
  }

  return 0;
}
*/

/*----------------------------------------------------*/
/*C Lista Vetores - Ex13
Faça um algoritmo que solicita que sejam digitados e armazenados N números
em um vetor de inteiros chamado vetorOriginal. Logo em seguida, o programa
deve guardar os N números de maneira invertida em outro vetor chamado
vetorInvertido. Apresentar os vetores vetorOriginal e vetorInvertido. N é
digitado pelo usuário.

Formato da entrada: primeira linha contém N, segunda linha contém os números
do vetor. 1)3 2)10 5 20

Formato saída: primeira linha contendo os elementos do vetor de entrada,
segunda linha contendo o vetor invertido 1)10 5 20 2)20 5 10*/
/*
#include <stdio.h>

int main(void) {
  int n;

  scanf("%d", &n);
  int vetorOriginal[n];
  int vetorInvertido[n];

  for (int i = 0; i < n; i++) {// GUARDANDO OS NUMEROS/PALAVRAS
    scanf("%d", &vetorOriginal[i]);
  }
  for (int i = 0; i < n; i++) {//INVERTENDO O VETOR
    vetorInvertido[i] = vetorOriginal[n - 1 - i];
  }
  for (int i = 0; i < n; i++) {// PRINTANDO RESULTADO
    printf("%d ", vetorOriginal[i]);
  }
  printf("\n");

  for (int i = 0; i < n; i++) {// PRINTANDO RESULTADO
    printf("%d ", vetorInvertido[i]);
  }

  return 0;
}
*/

/*----------------------------------------------------*/
/*C Lista de Vetores Ex. 14
Faça um algoritmo que leia dois vetores A e B de elementos numéricos, sendo
que A tem tamanho N e B tem tamanho M. O algoritmo deve concatenar A e B em um
vetor resultante C.

Imprima os vetores A, B e C. N e M devem ser digitados pelo usuário.

Formato da entrada:
primeira linha contém N e M;
segunda linha contém os números do primeiro vetor A;
terceira linha contém os números do segundo vetor B.
1)3 4
2)1 2 3
3)4 5 6 7

Formato saída:
primeira linha contendo os elementos do vetor A;
segunda linha contendo os elementos do vetor B;
terceira linha contendo os elementos do vetor resultante C.
1)1 2 3
2)4 5 6 7
3)1 2 3 4 5 6 7*/
/*
#include <stdio.h>

int main(void) {

  int N, M, L;

  scanf("%d %d", &N, &M);
  L = N + M;

  int vetorA[N], vetorB[M], vetorC[L];

  for (int i = 0; i < N; i++) {
    scanf("%d", &vetorA[i]);
    vetorC[i] = vetorA[i];
  }
  for (int i = 0; i < M; i++) {
    scanf("%d", &vetorB[i]);
    vetorC[N + i] = vetorB[i];
  }
  for (int i = 0; i < N; i++) {
    printf("%d ", vetorA[i]);
  }
  printf("\n");
  for (int i = 0; i < M; i++) {
    printf("%d ", vetorB[i]);
  }
  printf("\n");

  for (int i = 0; i < L; i++) {
    printf("%d ", vetorC[i]);
  }

  return 0;
}
*/

/*----------------------------------------------------*/
/*C Lista de Vetores Ex.15
Faça um algoritmo que carregue dois vetores de N elementos numéricos e
mostre um terceiro vetor resultante da intercalação desses dois vetores. N é
lido pelo algoritmo. Exemplo: Vetor1 3 5 4 2 2 Vetor2 7 15 20 0 18 Vetor3 3 7
5 15 4 20 2 0 2 18

Formato da entrada:
primeira linha contém N
segunda linha contém os números do primeiro vetor
terceira linha contém os números do segundo vetor.
1)5
2)3 5 4 2 2
3)7 15 20 0 18

Formato saída:
linha contendo os elementos do vetor resultante.
1)3 7 5 15 4 20 2 0 2 18*/
/*
#include <stdio.h>

int main(void) {
  int n, o, j = 0;

  scanf("%d", &n);
  o = n + n;

  int vetor1[n], vetor2[n], vetor3[o];

  for (int i = 0; i < n; i++) {
    scanf("%d", &vetor1[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &vetor2[i]);
  }
  for (int i = 0; i < o; i++) {
    vetor3[i] = vetor1[j];
    vetor3[i + 1] = vetor2[j];
    i++, j++;
  }

  for (int i = 0; i < o; i++) {
    printf("%d ", vetor3[i]);
  }

  return 0;
}
*/

/*----------------------------------------------------*/
/*C Lista de Vetores. Ex 16
  Uma turma tem N alunos. Faça um algoritmo para ler a idade de todos os
  alunos e logo em seguida imprimir: Total de alunos com idade menor ou igual a
  16 anos; Total de alunos com idade maior que 16 anos; Idade média da turma;
  Idade do aluno mais novo;
  Idade do aluno mais velho.

  N é lido pelo algoritmo.

  Formato da entrada:
  primeira linha contém N;
  N linhas contendo as idades.
  1)6
  2)19
  3)17
  4)13
  5)23
  6)15
  7)15

  Formato saída:
  uma linha para cada informação solicitada na ordem dada, com a média tendo 0
  casas decimais.
  1)3
  2)3
  3)17.00
  4)13
  5)23*/
/*
#include <stdio.h>

int main(void) {
  int n, totalmenor = 0, totalmaior = 0, novo, old;
  double media;

  scanf("%d", &n);

  int v[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    media += v[i];
    if (v[i] <= 16)
      totalmenor++;

    if (v[i] > 16)
      totalmaior++;

    if (i == 0 || novo > v[i])
      novo = v[i];

    if (old < v[i])
      old = v[i];
  }
  media = (media / n);

  printf("%d\n", totalmenor);
  printf("%d\n", totalmaior);
  printf("%.2f\n", media);
  printf("%d\n", novo);
  printf("%d\n", old);

  return 0;
}
*/

/*----------------------------------------------------*/
/*C Lista Matrizes. Ex 2
Faça um algoritmo que lê uma matriz de dimensões M x N e mostra o número de
elementos maiores que 15 e menores que 25, na ordem de caminhamento por linha
da matriz. M e N são digitados pelo usuário.

Formato da entrada:
primeira linha contém M e N,
as próximas linhas contêm os elementos da matriz.
1)4 4
2)1 2 3 4
3)15 25 10 30
4)21 22 23 24
5)5 6 7 8


Formato saída:
única linha contendo os elementos maiores que 15 e menores que 25.
1)21 22 23 24*/

/*
#include <stdio.h>

int main(void) {
  int x, y;

  scanf("%d %d", &x, &y);

  int mat[x][y];

  // Ler os elementos da matriz
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      scanf("%d", &mat[j][i]);
    }
  }
  // Mostrar os elementos maiores que 15 e menores que 25
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      if (mat[j][i] > 15 && mat[j][i] < 25) {
        printf("%d ", mat[j][i]);
      }
    }
  }

  return 0;
}
*/

/*----------------------------------------------------*/
/*C Lista de Matrizes. Ex 5
Faça um algoritmo que lê uma matriz M x N de números inteiros e apresenta as
somas dos elementos de cada linha da matriz. M e N são digitados pelo usuário.

Formato da entrada:
primeira linha contém M e N,
as próximas linhas contêm os elementos da matriz.
1)3 3
2)1 2 3
3)4 5 6
4)7 8 9

Formato saída:
única linha contendo as somas dos elementos de cada linha.
1)6 15 24*/

/*
#include <stdio.h>

int main(void) {
  int x, y;

  scanf("%d %d", &y, &x);
  int mat[y][x];

  // Ler os elementos da matriz
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      scanf("%d", &mat[i][j]);
    }
  }

  // Calcular e printar a soma
  for (int i = 0; i < y; i++) {
    int soma = 0;
    for (int j = 0; j < x; j++) {
      soma += mat[i][j];
    }
    printf("%d ", soma);
  }

  return 0;
}
*/

/*----------------------------------------------------*/
/*C Lista de Matriz Ex. 6
Faça um algoritmo que lê uma matriz M x N de números inteiros e apresenta os
produtos dos elementos de cada coluna da matriz. M e N são digitados pelo
usuário.

Formato da entrada:
primeira linha contém M e N, as próximas linhas contêm os elementos da matriz.
1)3 3
2)5
3)9
4)8
5)3
6)2
7)1
8)3
9)4
10)2

Formato saída:
única linha contendo os produtos dos elementos de cada coluna
1)45 72 16 */

/*
#include <stdio.h>

int main(void) {
  int x, y;

  scanf("%d %d", &y, &x);
  int mat[y][x];

  // Ler os elementos da matriz
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      scanf("%d", &mat[i][j]);
    }
  }
  // Calcular e printar o produto
  for (int j = 0; j < x; j++) {
    int prod = 1;
    for (int i = 0; i < y; i++) {
      prod *= mat[i][j];
    }
    printf("%d ", prod);
  }

  return 0;
}
*/

/*----------------------------------------------------*/
/*C Lista Matrizes. Ex. 10
Faça um algoritmo que lê duas matrizes A e B de dimensão M x N. O algoritmo
deve criar uma terceira matriz C igual à adição das duas matrizes, isto é, C = A
+ B. M e N são digitados pelo usuário. Formato da entrada:
1)2 3
2)1 2 0 3 4 5
3)9 1 23 6 2 12

Formato saída:
1)10 3 23
2)9 6 17 */
/*
#include <stdio.h>

int main(void) {
  int x, y;

  scanf("%d %d", &y, &x);

  int mA[y][x];
  int mB[y][x];
  int mC[y][x];

  // Preenche mA
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      scanf("%d", &mA[i][j]);
    }
  }

  // Preenche mB
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      scanf("%d", &mB[i][j]);
    }
  }

  // Soma
  for (int j = 0; j < x; j++) {
    for (int i = 0; i < y; i++) {
      mC[i][j] = mA[i][j] + mB[i][j];
    }
  }

  // Printa
  for (int i = 0; i < y; i++) {
    for (int j = 0; j < x; j++) {
      printf("%d ", mC[i][j]);
    }
    printf("\n"); // Quebra linha depois de cada linha de saída
  }

  return 0;
}
*/

/*----------------------------------------------------*/
/*C Lista de Matrizes. Ex 12
Faça um algoritmo que lê o nome de N alunos (guarde em um vetor) e suas M notas
em uma determinada disciplina (guarde-as em uma matriz), onde os valores de N e
M são fornecidos.
O algoritmo deve imprimir uma listagem dos alunos com suas
respectivas notas finais na disciplina e situação de aprovação.
A nota final do aluno é calculada como a soma das M notas.
A situação do aluno será aprovado (A) se a nota final for igual ou superior a
70, reprovado (R) se a nota final for inferior a 4, ou exame especial (E) se a
nota final for igual ou superior a 4 e inferior a 7.

Imprima, também, a média nas M notas para todos os alunos da disciplina.
Dica: crie um vetor para os
nomes dos alunos, uma matriz para as notas dos alunos, um vetor para as notas
finais dos alunos e um vetor para as médias das notas de todos os alunos.

Formato da entrada:
primeira linha contém N e M, as próximas N linhas contêm os nomes dos alunos (1
nome por linha), as próximas N linhas contêm as M notas de cada aluno por linha.
1)5 2
2)Carina Yamada
3)Mauricio Alencar
4)Rebeca Macedo
5)Ricardo Avila
6)Tomas Bonfim
7)50 30
8)11 40
9)46 50
10)30 38
11)10 23

Formato saída:
N linhas contendo, em cada linha, o nome, a nota final (1 casa decimal) e a
situação de aprovação do aluno (A, E ou R), próxima (última linha) contém a
média de cada uma das M notas de todos os alunos (1 casa decimal)
1)Carina Yamada 80.0 A
2)Mauricio Alencar 51.0 E
3)Rebeca Macedo 96.0 A
4)Ricardo Avila 68.0 A
5)Tomas Bonfim 33.0 R
6)29.4 36.2 */

#include <stdio.h>
int main(void)
{
  int x, y;
  scanf("%d %d", &y, &x);

  char nomes[y][100];
  double notas[y][x];
  double notasf[y];
  char situacao[y];
  double media[x];

  // Pega os nomes completos
  for (int i = 0; i < y; i++)
  {
    scanf(" %[^\n]", nomes[i]);
    // scanf("%s", nomes[i]); // isso só pega um nome
  }

  // Pega os nomes e as notas
  for (int i = 0; i < y; i++)
  {
    notasf[i] = 0.0; // inicializando com 0
    for (int j = 0; j < x; j++)
    {
      scanf("%lf", &notas[i][j]);
      notasf[i] += notas[i][j]; // Soma as notas
    }
    // Sequencia de ifs da situação do aluno
    if (notasf[i] >= 68.0)
    {
      situacao[i] = 'A';
    }
    else if (notasf[i] >= 40.0)
    {
      situacao[i] = 'E';
    }
    else
    {
      situacao[i] = 'R';
    }
  }

  // Tira a media
  for (int j = 0; j < x; j++)
  {
    double soma = 0.0; // Variável temporária para soma
    for (int i = 0; i < y; i++)
    {
      soma += notas[i][j];
    }
    media[j] = (soma / y); // Calcula a média
  }

  // Printa os nomes + notas finais
  for (int i = 0; i < y; i++)
  {
    printf("%s %.1f %c\n", nomes[i], notasf[i], situacao[i]);
  }

  for (int i = 0; i < x; i++)
  {
    printf("%.1lf ", media[i]); // Printa media
  }

  return 0;
}

/*
 //   printf("%c", nomes[i][j]);
if (notasf[j] >= 70) {
  printf("A");
}
if (notasf[j] <= 40) {
  printf("R");
}
if (notasf[j] >= 40 || notasf[x] < 70)
  printf("E");
  */

/*----------------------------------------------------*/
/*C Lista de Vetores. Ex. 11
Faça um algoritmo que carregue em um vetor os N primeiros termos da série de
Fibonacci, onde N é fornecido pelo usuário. Imprima o vetor.

Formato da entrada:
única linha contém N.
1)10

Formato saída:
linha contendo os elementos do vetor resultante.
1)1 2 3 5 8 13 21 34 55 89*/
/*
#include <stdio.h>

int main(void) {
  int n;

  scanf("%d", &n);
  int fib[n];
  fib[0] = 1; // O primeiro termo
  fib[1] = 2; // O segundo termo

  // Gerar os termos restantes da série de Fibonacci
  for (int i = 2; i < n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  // Printar os termos
  for (int i = 0; i < n; i++) {
    printf("%d ", fib[i]);
  }

  return 0;
}
*/