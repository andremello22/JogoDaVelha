#include <stdio.h>
#include <stdlib.h>
using namespace std;

// aqui eu criei a função tabuleiro com a matriz casas2 para ser impresso o
// tabuleiro na tela

void tabuleiro(char casas2[3][3]) {
  system("clear");

  printf("\n");
  printf("\t %c | %c | %c \n", casas2[0][0], casas2[0][1], casas2[0][2]);
  printf("\t------------\n");
  printf("\t %c | %c | %c \n", casas2[1][0], casas2[1][1], casas2[1][2]);
  printf("\t------------\n");
  printf("\t %c | %c | %c \n", casas2[2][0], casas2[2][1], casas2[2][2]);
};

int main() {
  // matriz para o tabuleiro
  char casas[3][3] = {
      {'1', '2', '3'},

      {'4', '5', '6'},
      {'7', '8', '9'},
  };

  char res;
  int cont, l, c, vez = 0, i, j;

  // usei a estrutura de repetição do while para que ao fim da partida o usuário
  // posso sair ou reiniciar

  do {
    // usei dois for encadeados para zerar o tabuleiro
    cont = 1;
    for (i = 0; i <= 2; i++) {
      for (j = 0; j <= 2; j++)
        casas[i][j] = ' ';
    };

    do {
      // usei a estrutura de repetição do while que o jogo rodasse dentro desse
      // loop

      tabuleiro(casas);
      // chamei a função tabuleiro com a matriz casas dentro

      if (vez % 2 == 0) {
        printf("\n\n jogador X \n");

      } else {
        printf("\n\n jogador O\n");
      };

      printf("digite a linha: ");
      scanf("%i", &l);
      printf("digite a coluna: ");
      scanf("%i", &c);

      if (l < 1 || c < 1 || l > 3 || c > 3) {
        l = 0;
        c = 0;
      } else if (casas[l - 1][c - 1] != ' ') {

        l = 0;
        c = 0;
      }

      else {

        if (vez % 2 == 0) {
          casas[l - 1][c - 1] = 'X';

        } else {
          casas[l - 1][c - 1] = 'O';
        };

        vez++;
        cont++;
      };
      if (casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X') {
        cont = 11;
      };
      if (casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X') {
        cont = 11;
      };
      if (casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X') {
        cont = 11;
      };
      if (casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X') {
        cont = 11;
      };
      if (casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X') {
        cont = 11;
      };
      if (casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X') {
        cont = 11;
      };
      if (casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X') {
        cont = 11;
      };
      if (casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X') {
        cont = 11;
      };

      if (casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O') {
        cont = 12;
      };
      if (casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O') {
        cont = 12;
      };
      if (casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O') {
        cont = 12;
      };
      if (casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O') {
        cont = 12;
      };
      if (casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O') {
        cont = 12;
      };
      if (casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O') {
        cont = 12;
      };
      if (casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O') {
        cont = 12;
      };

      if (casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O') {
        cont = 12;
      };

    } while (cont <= 9);
    tabuleiro(casas);
    if (cont == 10) {
      printf("\njogo empatado!!\n");
    };

    if (cont == 11) {
      printf("\njogador X vencedor!!\n");
    };
    if (cont == 12) {
      printf("\njogador O vencedor!!\n");
    };
    printf("\ndeseja jogar novamente ? [S/N]\n");
    scanf("%s", &res);

  } while (res == 's' || res == 'S');

  getchar();
  return (0);
}