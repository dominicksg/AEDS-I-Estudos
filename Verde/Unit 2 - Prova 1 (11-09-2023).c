// Numeros primos entre dois numeros
/*#include <stdio.h>
int n1, n2, check = 0;

int main(void) {

  // pegando os dois numeros
  scanf("%d", &n1);
  scanf("%d", &n2);

  // dividindo os numeros que estão entre os numeros fornecidos
  for (int nmeio = n1; nmeio <= n2; nmeio++) {
    check = 0;
    // aumentando em 1 o divisor para dividir até ele mesmo
    for (int div = 1; div <= nmeio; div++) {
      if (nmeio % div == 0) { // dividindo
        check++; // se a divisao der 0, ele guardará um no contador
      }
    } // TODO NUMERO SERIA PRIMO SE FOSSE DIVIDIDO APENAS POR 1 ELE MESMO
    if (check == 2) { // se der 0 duas vezes (1 e ele mesmo) é primo.
      printf("\n%d ", nmeio);
    }
  }

  return 0;
}*/
/*-------------------------------------------------------*/
// Quantos numeros primos tem entre dois numeros

#include <stdio.h>

int main(void) {
  int n1, n2, primo = 0, check = 0;

  scanf("%d", &n1);
  scanf("%d", &n2);

  for (int nmeio = n1; nmeio <= n2; nmeio++) {
    check = 0;
    for (int div = 1; div <= nmeio; div++) {
      if (nmeio % div == 0) {
        check++;
      }
    }
    if (check == 2)
      primo++;
  }
  printf("Existem %d numeros primos entre %d e %d", primo, n1, n2);
  return 0;
}

/*-------------------------------------------------------*/

/*Um número primo é divisível somente por 1 e por ele mesmo. Faça um algoritmo
para identificar se um determinado número fornecido pelo usuário é primo ou
não. Exemplos de números primos: 2, 5, 7, 11, 13.

Entrada
Um número

Saída
1 Se o número for primo, 0 caso contrário*/

/*#include <stdio.h>

int main(void) {
  int n, cont = 0;
  scanf("%d", &n);
  if (n == 1) {
    printf("1");

  } else {
    for (int i = 1; i <= n; i++) {
      if (n % i == 0) {
        cont++;
      }
    }
    if (cont == 2) {
      printf("1");
    } else {
      printf("0");
    }
  }
  return 0;
}*/

/*-------------------------------------------------------*/

/*Faça um algoritmo que imprima a série de Fibonacci até o valor N fornecido
pelo usuário. A série de Fibonacci é mostrada abaixo.


1,1,2,3,5,8,13,21,...,N

Entrada
N

Saída
Termos da série da Fibonacci menores que N*/

/*#include <stdio.h>
int main(void) {
  int rep, n1 = 1, n2 = 0, proxN = 0;

  scanf("%d", &rep);
  for (; n1 < rep;) {
    printf("%d ", n1);
    proxN = n1 + n2;
    n2 = n1;
    n1 = proxN;
  }
  return 0;
}*/

/*-------------------------------------------------------*/

/*Em uma eleição presidencial existem quatro candidatos. Os votos são
informados por meio de código. Os códigos utilizados são:

1,2,3,4 - Votos para os respectivos candidatos
5 - Voto nulo
6 - Voto em branco


Faça um programa que calcule e mostre:

o total de votos para cada candidato;
o total de votos nulos;
a porcentagem de votos em branco sobre o total de votos.

Para finalizar o conjunto de votos digitados, deve-se informar o código zero.

Entrada
Sequência de números inteiros até encontrar o número zero

Saída
A saída deve conter três linhas:
A primeira linha contendo o total de votos de cada candidato.
A segunda linha o total de votos nulos.
A terceira linha com o percentual de votos em brancos*/

/*#include <stdio.h>

int main(void) {
  int voto, total=0, c1=0, c2=0, c3=0, c4=0, null=0;
  float b=0;

  scanf("%d", &voto);
  while (voto != 0) {
    switch (voto) {
    case 1:
      c1++;
      total++;
      scanf("%d", &voto);
      break;
    case 2:
      c2++;
      total++;
      scanf("%d", &voto);
      break;
    case 3:
      c3++;
      total++;
      scanf("%d", &voto);
      break;
    case 4:
      c4++;
      total++;
      scanf("%d", &voto);
      break;
    case 5:
      null++;
      total++;
      scanf("%d", &voto);
      break;
    case 6:
      b++;
      total++;
      scanf("%d", &voto);
      break;
    default:
      scanf("%d", &voto);
    }
  }
  b = ((100 * b) / total);
  printf("%d %d %d %d\n", c1, c2, c3, c4);
  printf("%d\n", null);
  printf("%.2f", b);
}*/

/*-------------------------------------------------------*/

/*A Olimpíada Municipal de Programação vai distribuir camisetas para os
melhores colocados, e por isso solicitou que os premiados informassem o
tamanho preferido da camiseta, entre os tamanhos pequeno e médio.

A empresa que confeccionou as camisetas, por uma falha, pode ter se enganado
na quantidade de camisetas para cada tamanho. Foram produzidas camisetas em
número suficiente para todos os premiados, mas talvez não do tamanho
preferido.

Dadas a lista com os tamanhos preferidos pelos premiados e a quantidade de
camisetas de cada tamanho produzidas pela empresa, escreva um programa para
determinar se todos os premiados receberão camisetas do tamanho escolhido.

Entrada
A primeira linha contém um inteiro N, o número de premiados. A segunda linha
contém N inteiros Ti, indicando os tamanhos solicitados pelos premiados, sendo
que Ti = 1 representa o tamanho pequeno e Ti = 2 representa o tamanho médio. A
terceira linha contém um inteiro P, o número de camisetas de tamanho pequeno
produzidas. A quarta e última contém um inteiro M, o número de camisetas de
tamanho médio produzidas.

Saída
Seu programa deve produzir uma única linha, contendo um único caractere, que
deve ser a letra maiúscula 'S' se todos os premiados serão atendidos com a
camiseta do tamanho que escolheram, ou a letra maiúscula 'N' caso contrário.*/

/*#include <stdio.h>
int main(void) {
  int p = 0, tt, ttp = 0, ttm = 0, tp, tm;
  scanf("%d", &p);

  for (int i = 0; i < p; i++) {
    scanf("%d", &tt);
    if (tt == 1) {
      ttp++;
    }
    if (tt == 2) {
      ttm++;
    }
  }
  scanf("%d", &tp);
  scanf("%d", &tm);

  if ((ttp >= tp) && (ttm >= tm)) {
    printf("S");
  } else {
    printf("N");
  }

  return 0;
}*/

/*-------------------------------------------------------*/

/*Cibele, Camila e Celeste são três irmãs inseparáveis. Estão sempre juntas e
adoram fazer esportes, ler, cozinhar, jogar no computador... Agora estão
aprendendo a programar computadores para desenvolverem seus próprios jogos.

Mas nada disso interessa para esta tarefa: estamos interessados apenas nas
suas idades. Sabemos que Cibele nasceu antes de Camila e Celeste nasceu depois
de Camila.

Dados três números inteiros indicando as idades das irmãs, escreva um programa
para determinar a idade de Camila.

Entrada A entrada é composta por três linhas, cada linha contendo um número
inteiro N, a idade de uma das irmãs.

Saída Seu programa deve produzir uma única linha, contendo um único número
inteiro, a idade de Camila.*/

/*#include <stdio.h>

int main(void) {
  int sis1, sis2, sis3;
  scanf("%d", &sis1);
  scanf("%d", &sis2);
  scanf("%d", &sis3);
  if ((sis1 < sis2 && sis2 < sis3) || (sis3 < sis2 && sis2 < sis1)) {
    printf("%d", sis2);
  }
  if ((sis2 < sis1 && sis1 < sis3) || (sis3 < sis1 && sis1 < sis2)) {
    printf("%d", sis1);
  }
  if ((sis1 < sis3 && sis3 < sis2) || (sis2 < sis3 && sis3 < sis1)) {
    printf("%d", sis3);
  }

  return 0;
}*/

/*-------------------------------------------------------*/

/*Escreva um programa em C que leia N números inteiros e exibe a soma dos
números ímpares. A quantidade N de números a serem lidos é informada pelo
usuário.

Entrada A entrada possui um valor inteiro N indicando a quantidade de casos de
teste. Os N números a serem lidos.

Saída A soma dos número ímpares*/

/*#include <stdio.h>

int main(void) {
  int n, numero, soma = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &numero);
    if (numero % 2 == 1) {
      soma = soma + numero;
    }
  }
  printf("%d", soma);
  return 0;
}*/

/*-------------------------------------------------------*/

/*Escreva um programa em C que enquanto o valor -1 não for digitado, leia
números fornecidos pelo usuário.

Seu programa deverá, ao final da entrada de dados, exibir quantos números
foram digitados e quantas vezes o número 5 foi informado.

Entrada
Sequência de números inteiros, sendo o último o número -1

Saída
Total de números digitados
Número de vezes que o número foi digitado*/

/*#include <stdio.h>

int main(void) {
  int numero = 0, qnt = 0, cinco = 0;
  scanf("%d", &numero);
    while (numero !=-1) {
      qnt++;
      if (numero == 5) {
        cinco++;
      }
      scanf("%d", &numero);
    }
    printf("%d %d", qnt, cinco);
  return 0;
}*/
/*-------------------------------------------------------*/
