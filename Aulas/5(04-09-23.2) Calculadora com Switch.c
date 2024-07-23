/*Se um aluno foi ou não aprovado em AEDS1, caso o aluno não tenha sido
 * aprovado, mas obteve nota maior ou igual a 40, ele pode fazer reavaliação.
 * Caso a média entre a nota final e a reavaliação seja maior ou igual a 60 ele
 * será aprovado*/

/*
#include <math.h>
#include <stdio.h>

int main(void) {
  int faltas, aulas;
  float nota1, nota2, porcentagem;
  printf("VERIFICADOR DE APROVAÇÃO");
  printf("\nDigite sua nota: ");
  scanf("%f", &nota1);
  printf("Digite o número de aulas: ");
  scanf("%d", &aulas);
  printf("\nDigite seu numero de faltas: ");
  scanf("%d", &faltas);
  porcentagem = (25 * aulas) / 100;
  if ((nota1 >= 60) && (faltas <= porcentagem)) {
    printf("Parabens, você foi aprovado!");
  } else if ((nota1 >= 40) && (faltas <= porcentagem)) {
    printf("\nFaça a reavaliação e digite sua nota: ");
    scanf("%f", &nota2);
    (nota1 = (nota1 + nota2) / 100);
    if (nota1 >= 60) {
      printf("Parabéns, você foi aprovado!");
    } else {
      printf("Você foi reprovado :(");
    }
  } else {
    printf("Você foi reprovado :(");
  }

  return 0;
}
*/

/*Escreva um programa em C que receba o código e o salário atual de um
 * colaborador e calcule o novo salário*/
#include <math.h>
#include <stdio.h>

int main(void)
{
  double salarioIN, salarioOUT, diff;
  int menu;
  menu = 0;
  printf("Digite um número de acordo com seu cargo:");
  printf("\n1 - Estagiario");
  printf("\n2 - D.Web");
  printf("\n3 - D.Mobile");
  printf("\n4 - Gerente de projeto");
  printf("\n5 - Diretores");
  printf("\nNúmero: ");
  scanf("%d", &menu);
  printf("\nDigite seu salario atual: ");
  scanf("%lf", &salarioIN);
  switch (menu)
  {
  case 1:
    salarioOUT = salarioIN * 1.25;
    diff = (salarioOUT - salarioIN);
    printf("Seu salario de estagiario era %.2lf e agora é: %.2lf, portanto "
           "teve um reajuste de: %.2lf",
           salarioIN, salarioOUT, diff);
    break;

  case 2:
    salarioOUT = salarioIN * 1.2;
    diff = (salarioOUT - salarioIN);
    printf("Seu salario de D.Web era %.2lf e agora é: %.2lf, portanto teve um "
           "reajuste de: %.2lf",
           salarioIN, salarioOUT, diff);
    break;

  case 3:
    salarioOUT = salarioIN * 1.15;
    diff = (salarioOUT - salarioIN);
    printf("Seu salario de D.Mobile era %.2lf e agora é: %.2lf, portanto teve "
           "um reajuste de: %.2lf",
           salarioIN, salarioOUT, diff);
    break;

  case 4:
    salarioOUT = salarioIN * 1.1;
    diff = (salarioOUT - salarioIN);
    printf("Seu salario de Gerente era %.2lf e agora é: %.2lf, portanto teve "
           "um reajuste de: %.2lf",
           salarioIN, salarioOUT, diff);
    break;

  case 5:
    salarioOUT = salarioIN * 1.3;
    diff = (salarioOUT - salarioIN);
    printf("Seu salario de Diretor era %.2lf e agora é: %.2lf, portanto teve "
           "um reajuste de: %.2lf",
           salarioIN, salarioOUT, diff);
    break;
  }

  return 0;
}

/*Alterar a Calculadora para utilizar switch. Além disso, exibir mensagem de
 * opção inválida e adicionar uma nova operação*/
/*#include <math.h>
#include <stdio.h>

int main(void) {
  int menus;
  double n2, n1;
  menus = 0;
  printf(
      "Escolha a sua operação:\n\n\t\t1-Somar dois números\n\t\t"
      "2-Calcular a raiz quadrada de um número\n\nDigite a opção desejada: ");
  scanf("%d", &menus);
  switch (menus) {
  case 1:
    printf("\nDigite dois números: ");
    scanf("%lf %lf", &n1, &n2);
    n1 = n1 + n2;
    printf("A soma dos números é: %.2lf", n1);
    break;
  case 2:
    printf("Digite um número: ");
    scanf("%lf", &n1);
    n2 = sqrt(n1);
    printf("A raiz quadrada de %.0lf é: %.2lf", n1, n2);
    break;
  default :
    printf("Opcao invalida");
  }
  return 0;
}*/