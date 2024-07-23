/*
//-------------------------------------------------------------------------//
C Warmup Maratona Q1

A prefeitura contratou um novo professor para ensinar as crianças do bairro a jogar tênis na quadra de tênis do parque municipal. O professor convidou todas as crianças do bairro interessadas em aprender a jogar tênis. Ao final do primeiro mês de aulas e treinamentos foi organizado um torneio em que cada participante disputou exatamente seis jogos.
O professor vai usar o desempenho no torneio para separar as crianças em três grupos, de forma a ter grupos de treino em que os participantes tenham habilidades mais ou menos iguais, usando o seguinte critério:

participantes que venceram 5 ou 6 jogos serão colocados no Grupo 1;
participantes que venceram 3 ou 4 jogos serão colocados no Grupo 2;
participantes que venceram 1 ou 2 jogos serão colocados no Grupo 3;
participantes que não venceram nenhum jogo não serão convidados a continuar com os treinamentos.

Dada uma lista com o resultado dos jogos de um participante, escreva um programa para determinar em qual grupo ele será colocado.

Entrada
A entrada consiste de seis linhas, cada linha indicando o resultado de um jogo do participante. Cada linha contém um único caractere: V se o participante venceu o jogo, ou P se o jogador perdeu o jogo. Não há empates nos jogos.
1.V
2.V
3.P
4.P
5.P
6.V

Saída
Seu programa deve produzir uma única linha na saída, contendo um único inteiro, identificando o grupo em que o participante será colocado. Se o participante não for colocado em nenhum dos três grupos seu programa deve imprimir o valor -1.
1.2

//-------------------------------------------------------------------------//
C Warmup Maratona Q2
A divisão de Suprimentos de Botas e Calçados do Exército comprou um grande número de pares de botas de vários tamanhos para seus soldados. No entanto, por uma falha de empacotamento da fábrica contratada, nem todas as caixas entregues continham um par de botas correto, com duas botas do mesmo tamanho, uma para cada pé. O sargento mandou que os recrutas retirassem todas as botas de todas as caixas para reembalá-las, desta vez corretamente.
Quando o sargento descobriu que você sabia programar, ele solicitou com a gentileza habitual que você escrevesse um programa que, dada a lista contendo a descrição de cada bota entregue, determina quantos pares corretos de botas poderão ser formados no total.

Entrada
A primeira linha da entrada contém um inteiro N indicando o número de botas individuais entregues.
Cada uma das N linhas seguintes descreve uma bota, contendo um número inteiro M e uma letra L, separados por um espaço em branco. M indica o número do tamanho da bota e L indica o pé da bota: L= ‘D’ indica que a bota é para o pé direito, L= ‘E’ indica que a bota é para o pé esquerdo.
1.6
2.38 E
3.39 E
4.40 D
5.38 D
6.40 D
7.37 E

Saída
Seu programa deve imprimir uma única linha contendo um único número inteiro indicando o número total de pares corretos de botas que podem ser formados.
1.1
*/

// Q1
/*
#include <stdio.h>

int main(void) {
  char jogos[6];
  int ganhou = 0;
  int perdeu = 0;

  for (int i = 0; i < 6; i++) {
    scanf(" %c", &jogos[i]);
    if (jogos[i] == 'V') {
      ganhou++;
    } else if (jogos[i] == 'P') {
      perdeu++;
    }
  }

  if (ganhou > 4) {
    printf("1");
  }
  if (ganhou == 3 || ganhou == 4) {
    printf("2");
  }
  if (ganhou == 1 || ganhou == 2) {
    printf("3");
  }
  if (ganhou == 0)
    printf("-1");

  return 0;
}
*/
//--------------------------------------------------------------------------//
// Q2

#include <stdio.h>

int main(void)
{
  int num;
  int currentsize;
  int currentpe;
  int pares = 0;

  scanf("%d", &num);
  int size[num];
  char pe[num];
  for (int i = 0; i < num; i++)
  {
    scanf("%d %c", &size[i], &pe[i]);
  }
  for (int i = 0; i < num; i++)
  {
    currentsize = size[i];
    currentpe = pe[i];
    for (int j = i + 1; j < num; j++)
    {
      if (currentsize == size[j] && currentpe != pe[j])
      {
        pares++;
        break;
      }
    }
  }

  printf("%d", pares);
  return 0;
}
