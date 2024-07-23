/*C Lista Funções Ex. 3
Escreva um procedimento que recebe 3 valores reais X, Y e Z correspondentes ao
lado de um triângulo e exibe qual o tipo de triângulo (equilátero, isósceles,
escaleno), caso o triângulo seja válido.

Para que X, Y e Z formem um triângulo, é necessário que cada lado do triângulo
seja menor do que a soma dos outros dois lados. Caso o triângulo seja inválido,
o procedimento deve imprimir “Triangulo invalido”.

Faça um programa que lê triângulos (isto é, os lados do triângulo) e, para cada
triângulo, aciona o procedimento. A entrada de dados é finalizada quando
informado o valor -1.

Formato da entrada: conjunto de linhas, onde cada linha traz os lados de um
triângulo separados por espaço, sendo a última linha com -1.
1. 1 1 1
2. 2 2 3
3. 3 4 5
4. 1 2 3
5. -1

Formato da saída: conjunto de linhas, cada linha com a classificação do
triângulo correspondente: “equilátero”, “isósceles” ou “escaleno”.
1. equilatero
2. isoceles
3. escaleno
4. Triangulo invalido*/

/*
#include <stdio.h>
void tipo(double x, double y, double z) {
  if ((x < y + z) && (y < x + z) && (z < x + y)) {
    if (x == y && y == z) {
      printf("equilatero\n");
    } else if (x == y || x == z || y == z) {
      printf("isoceles\n");
    } else {
      printf("escaleno\n");
    }
  } else {
    printf("Triangulo invalido\n");
  }
}

int main(void) {
  double a, b, c;

  scanf("%lf", &a);
  while (a != -1) {
    scanf("%lf %lf", &b, &c);
    tipo(a, b, c);
    scanf("%lf", &a);
  }
  return 0;
}
*/
/*
  scanf("%d", &x);
  while (x > 0) {
    scanf("%d %d", &y, &z);
    tipo(x, y, z);
    scanf("%d", &x);
  }

  return 0;
}
*/
/*
  scanf("%d %d %d", &x, &y, &z);
  while (x > 0) {
    tipo(x, y, z);
    scanf("%d", &x);
    if (x < 0) {
      break;
    }
    scanf("%d", &y);
    scanf("%d", &z);
  }
  return 0;
}
*/
// scanf("%d %d %d", &x, &y, &z);
/*------------------------------------------------------------------*/
/*C Lista Funções. Ex4
  Faça um procedimento que recebe a nota de um aluno, identifica e exibe o seu
conceito, conforme a tabela abaixo.

  Faça um programa que lê a média de N alunos, acionando o procedimento para
cada um deles. N é fornecido pelo usuário.


  Nota	------- Conceito
  Até 39	-------- F
  40 a 59	-------- E
  60 a 69	-------- D
  70 a 79	-------- C
  80 a 89	-------- B
  a partir de 90 - A


  Formato da entrada: primeira linha contém N, próximas N linhas contendo a nota
de cada aluno.
1.  10
2.  39
3.  40
4.  49
5.  60
6.  69
7.  70
8.  79
9.  80
10.  89
11.  90

  Formato da saída: N linhas com o conceito de cada aluno
1.F
2.E
3.E
4.D
5.D
6.C
7.C
8.B
9.B
10.A*/

/*
#include <stdio.h>

void getgrade(int nota) {
  if (nota <= 39)
    printf("F\n");

  else if (nota > 39 && nota <= 59)
    printf("E\n");

  else if (nota > 59 && nota <= 69)
    printf("D\n");

  else if (nota > 69 && nota <= 79)
    printf("C\n");

  else if (nota > 79 && nota <= 89)
    printf("B\n");

  else if (nota >= 90)
    printf("A\n");
}

int main(void) {
  int n;

  scanf("%d", &n);
  int notas[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &notas[i]);
  }

  for (int i = 0; i < n; i++) {
    getgrade(notas[i]);
  }
  return 0;
}
*/

/*
scanf("%d", &n);
for (int i=0; i<n; i++){
  scanf("%d", &grade);
  getgrade(grade);
}
}
*/
/*------------------------------------------------------------------*/
/*C Lista de Funções. Ex. 8
  Faça uma função que calcule e retorne a nota final de um aluno. Para isso, a
  função deve receber as 3 notas do aluno e uma letra. Se a letra for ‘A’, a
  nota final do aluno é calculada como a média aritmética das notas; se for
  ‘P’, a nota final é a média ponderada das notas, considerando pesos iguais a
  5, 3 e 2.

  Faça um programa que leia as 3 notas de N alunos e o tipo de média a ser
  utilizada. Armazene as notas em uma matriz. O programa deve imprimir as três
  notas e a nota final de cada aluno. Para a nota final, o programa deve
  acionar a função criada.

  N deve ser informado pelo usuário.


  Formato da entrada: primeira linha contém N e o tipo de média, próximas N
  linhas contêm as 3 notas de cada aluno por linha.

  1-8 P
  2-2.3 5 7.1
  3-2 1.5 3.2
  4-10 2.6 6
  5-1.9 10 9.5
  6-5 5 5
  7-7.2 3.6 2.2
  8-3 2.4 4
  9-5 3.7 2

  Formato da saída: N linhas, cada linha contendo as três notas e a nota final
  de um aluno.

  1-2.30 5.00 7.10 4.07
  2-2.00 1.50 3.20 2.09
  3-10.00 2.60 6.00 6.98
  4-1.90 10.00 9.50 5.85
  5-5.00 5.00 5.00 5.00
  6-7.20 3.60 2.20 5.12
  7-3.00 2.40 4.00 3.02
  8-5.00 3.70 2.00 4.01
  */

/*
#include <stdio.h>

float fgrade(float na, float nb, float nc, char tipomedia) {
  float nf;
  if (tipomedia == 'A') {
    nf = (na + nb + nc) / 3;
    return nf;
  }
  if (tipomedia == 'P') {
    nf = ((na * 5) + (nb * 3) + (nc * 2)) / 10;
    return nf;
  }
  return nf;
}

int main(void) {
  int n;
  char tpmedia;


  scanf("%d %c", &n, &tpmedia);
  float notasalunos[n][3];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%f", &notasalunos[i][j]);
    }
  }
  for (int i = 0; i < n; i++) {
    float notaf = fgrade(notasalunos[i][0], notasalunos[i][1],
                         notasalunos[i][2], tpmedia);

    printf("%.2f %.2f %.2f %.2f\n", notasalunos[i][0], notasalunos[i][1],
           notasalunos[i][2], notaf);
  }
  return 0;
}
*/

/*
    float notasa = notasalunos[i][0];
    float notasb = notasalunos[i][1];
    float notasc = notasalunos[i][2];
    float notaf = fgrade(notasa, notasb, notasc, tpmedia);

    printf("%.2f %.2f %.2f %.2f\n", notasa, notasb, notasc, notaf);
  }
}
*/

/*------------------------------------------------------------------*/

/*C Lista de Funções - Ex. 9
  A prefeitura de uma cidade fez uma pesquisa entre os seus habitantes,
  coletando dados sobre o salário e número de dependentes dos adultos. Crie
  uma função que recebe o salário e a quantidade de dependentes de cada
  adulto da cidade e retorna a renda per capita da população. Use o seguinte
  protótipo para sua função:

  double calcularRendaPerCapita(int n, double salarios[], int
  dependentes[]);

  onde n é o total de adultos, salarios guarda os salarios de cada um dos
  adultos, e dependentes guarda o número de dependentes de cada um dos
  adultos. Crie um programa para ler os dados (total de adultos, salários e
  quantidades de dependentes por adulto), chamar a função e imprimir a renda
  per capita.

  Formato da entrada: primeira linha contém a quantidade de adultos n,
  próximas n linhas contêm o salário de cada adulto, próximas n linhas
  contêm o número de dependentes de cada adulto.

    1.3
    2.1850
    3.4500
    4.2700
    5.1
    6.3
    7.2

  Formato da saída: única linha contendo a renda per capita da cidade com 2
  casas decimais.
  1.1005.56*/

/*
#include <stdio.h>

double calcularRendaPerCapita(int nn, double sal[], int dep[]) {
  double RendaPerCapita;
  double rendatotal, deptotal;
  for (int i = 0; i < nn; i++) {
    rendatotal += sal[i];
    deptotal += dep[i];
  }
  RendaPerCapita = rendatotal / (nn + deptotal);
  return RendaPerCapita;
}

int main(void) {
  int n;

  scanf("%d", &n);
  double salarios[n];
  int dependentes[n];

  for (int i = 0; i < n; i++) {
    scanf("%lf", &salarios[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &dependentes[i]);
  }
  double RendaPCapita = calcularRendaPerCapita(n, salarios, dependentes);
  printf("%.2lf", RendaPCapita);

  return 0;
}

*/
/*------------------------------------------------------------------*/ /*
   C Lista String. Ex

 Ler uma string de no máximo 500 caracteres e criar uma nova string com seu
 inverso, isto é, a última letra da primeira string será a primeira na nova
 string e assim sucessivamente.

 Formato da entrada: única linha contendo a string a ser lida.
   )nietsniE treblA( .otiecnocerp mu euq od omota mu rargetnised licaf siam
 E !acope etsirT

 Formato da saída: única linha contendo a string invertida.
   Triste epoca! E mais facil desintegrar um atomo do que um preconceito.
 (Albert Einstein)
 */

/*
#include <stdio.h>
#include <string.h>

int main(void) {
char s1[500], s2[500];

fgets(s1, sizeof(s1), stdin);

// Calcula o tamanho da string, descontando o caractere '\n' do final.
//int tamanho = strlen(s1) - 1;
//s1[strcspn(s1, "\n")] = '\0'; // Remove a quebra de linha do final, no vetor [] estara o "\n"
int tamanho = strlen(s1);


// Inverte a string copiando os caracteres do final para o início
for (int i = 0; i < tamanho; i++) {
s2[i] = s1[tamanho - 1 - i];
}
// Adiciona o caractere nulo no final da string invertida
s2[tamanho] = '\0';

printf("%s\n", s2);

return 0;
}
*/
/*------------------------------------------------------------------*/ /*
 C Lista String. Ex 4
 Ler uma string S de no máximo 100 caracteres e, em seguida, um conjunto de
 N caracteres (entre A e z - consista se o caractere está nesse intervalo).

 Para cada um dos N caracteres, mostrar quantas vezes ele apareceu na string
 lida e em quais posições. Maiúsculas e minúsculas são indiferentes.

 Formato da entrada: primeira linha contém a string S, segunda linha contém
 N, próximas N linhas contém um caractere cada.
 1-O rato roeu a roupa do rei
 de Roma.
 2-4
 3-r
 4-A
 5-z
 6-O

 Formato da saída: N linhas contendo, cada, o número de ocorrências do
 caractere na string S seguido das posições em que ocorre em S, separados
 por espaço.

 1-  5 2 7 14 23 30
 2-  4 3 12 18 33
 3-  0
 4-  7 0 5 8 15 21 31 41*/

/*
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  int n;
  char s1[100];
  int nvezes[100];

  fgets(s1, sizeof(s1), stdin);
  scanf("%d", &n);
  char s2[n];
  int pos[n][100];

  for (int i = 0; i < n; i++) {
    scanf(" %c", &s2[i]);
    // Use um espaço em branco antes de %c para evitar consumir um caractere
em
    // branco ou nova linha pendente
  }
  for (int j = 0; j < n; j++) {
    nvezes[j] = 0; // Inicialize o contador para cada caractere de s2
    for (int i = 0; i < strlen(s1); i++) {
      if (s1[i] == s2[j] || s1[i] == toupper(s2[j]) ||
      s1[i] == tolower(s2[j])) {
        pos[j][nvezes[j]] = i;
        nvezes[j]++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", nvezes[i]);
    for (int j = 0; j < nvezes[i]; j++) {
      printf("%d ", pos[i][j]);
    }
    printf("\n"); // Quebra de linha após cada conjunto de saída
  }
}
*/

// tem da forma em que printa após o for, sem precisar do pos[n]

/*------------------------------------------------------------------*/ /*
C Lista String. Ex9

Ler uma string S1 de no máximo 200 caracteres. Em seguida, leia outra string
S2 de no máximo 3 caracteres. Informe quantas vezes a segunda string aparece
na primeira string, e diga as posições iniciais em que ela aparece.


Formato da entrada: primeira linha contém a string S1, segunda linha contém
a string S2.

1-  No meio do caminho tinha uma pedra, tinha uma pedra no meio do caminho,
tinha uma pedra, no meio do caminho tinha uma pedra. (Carlos Drummond de
Andrade)
2-io


Formato da saída: única linha contendo o número de ocorrências de S2 em S1,
seguido das posições iniciais de S2 em S1, separados por espaço.
1-3 5 57 94
  */

/*
#include <stdio.h>
#include <string.h>

int main(void) {
  char s1[200], s2[3];
  int posicoes[200];

  fgets(s1, sizeof(s1), stdin);
  fgets(s2, sizeof(s2), stdin);

  int contagem =
      0; // Variável para contar o número de vezes que S2 aparece em S1

  // Percorre S1 em busca de S2
  for (int i = 0; i < strlen(s1); i++) {
    if (strncmp(s1 + i, s2, 2) == 0) {
      posicoes[contagem] = i;
      contagem++;
    }
  }

    printf("%d ", contagem);
  for (int i = 0; i < contagem; i++) {
    printf("%d ", posicoes[i]);
  }
  printf("\n");
}
*/

/*------------------------------------------------------------------*/ /*

C Lista de String. Ex10
  Leia um conjunto indeterminado de palavras e, ao final, informe qual foi a
maior palavra e a menor palavra digitada, em tamanho e lexicograficamente.

  O critério de parada de leitura é a palavra ser igual a “-1”.

  Formato da entrada: uma palavra por linha, sendo a última linha igual a
-1.

1-  gato
2-  cachorro
3-  elefante
4-  girafa
5-  tigre
6-  onça
7-  macaco
8-  leão
9-  pássaro
10-  vaca
11-  -1

  Formato da saída: primeira linha contendo a maior palavra em tamanho,
segunda linha contendo a menor palavra em tamanho, terceira linha contendo a
maior palavra lexicográfica e quarta linha contendo a menor palavra
lexicográfica.

1-cachorro
2-gato
3-vaca
4-cachorro
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

  char str1[30];
  char maior[30];
  char menor[30];
  char maiorAlf[30];
  char menorAlf[30];

  int aux = 0;
  fgets(str1, 30, stdin);
  // printf("%s\n", str1);

  for (int k = 0; k < 30; k++)
  {
    if (str1[k] == '-' && str1[k + 1] == '1')
    {
      aux = -1;
    }
  }
  // printf("%d", aux);

  if (aux != -1)
  {
    strcpy(maiorAlf, str1);
    strcpy(menorAlf, str1);
    strcpy(maior, str1);
    strcpy(menor, str1);
  }

  for (int i = aux; i != -1;)
  {
    fgets(str1, 30, stdin);
    for (int k = 0; k < 30; k++)
    {
      if (str1[k] == '-' && str1[k + 1] == '1')
      {
        i = -1;
      }
    }

    if (i != -1)
    {
      // printf("passei/n");

      int resultadoMaior = strcmp(str1, maiorAlf);
      int resultadoMenor = strcmp(str1, menorAlf);

      // printf("%d\n", resultadoMaior);
      // printf("%d", resultadoMenor);

      if (resultadoMaior > 0)
      {
        strcpy(maiorAlf, str1);
      }
      if (resultadoMenor < 0)
      {
        strcpy(menorAlf, str1);
      }

      // printf("%s", maiorAlf);
      // printf("%s", menorAlf);

      int testetamanho = strlen(str1);
      int testetamanho2 = strlen(maior);
      // printf("%d %d\n", testetamanho, testetamanho2);

      if ((testetamanho - 1) > (testetamanho2 - 1))
      {
        // puts("passei\n");
        strcpy(maior, str1);
        // printf("teste %s", maior);
      }
      if (strlen(str1) < strlen(menor))
      {
        strcpy(menor, str1);
      }

      // printf("%s", maior);
      // printf("%s", menor);

      for (int j = 0; j < 30; j++)
      {
        str1[j] = 0;
      }
    }
    else
    {
      printf("%s", maior);
      printf("%s", menor);
      printf("%s", maiorAlf);
      printf("%s", menorAlf);
    }
  }

  return 0;
}

// Printa a string buscando o "\0" no for
/*
#include <stdio.h>
#include <string.h>

int main(void) {
  char s1[100];

  fgets(s1, sizeof(s1), stdin);

  for (int i = 0; s1[i] != '\0'; i++) {
    printf("%c", s1[i]);
  }

  return 0;
}
*/