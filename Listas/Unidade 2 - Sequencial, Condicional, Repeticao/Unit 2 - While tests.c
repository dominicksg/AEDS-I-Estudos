// Loop média idades, parando com idade negativa

#include <stdio.h>

int main(void)
{
  int idade = 0;
  int cont = 0;
  float soma = 0;
  float media;
  printf("Digite a idade: ");
  scanf("%d", &idade);

  if (idade >= 0)
  {
    while (idade >= 0)
    {
      soma = soma + idade;
      cont++;
      printf("Digite a idade: ");
      scanf("%d", &idade);
    }
    media = soma / cont;
    printf("A média das idades é: %.2f", media);
  }
  else
  {
    printf("Não é posível dividir por 0");
  }
  return 0;
}

/*Loop média idades, parando com idade negativa
#include <stdio.h>

int main(void) {
  int idade = 0;
  int cont = -1;
  float soma = 0;
  float media;

  while (idade >= 0) {
    soma = soma + idade;
    cont++;
    printf("Digite a idade: ");
    scanf("%d", &idade);
  }
  media = soma / cont;
  printf("A média das idades é: %.2f", media);

  return 0;
}*/
