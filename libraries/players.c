#include <stdio.h>
#include <string.h>
#include "players.h"


void buildPlayer(Players *player, Players *player2)
{
  int i, j, k, x, y, flag;
  char answer;
  printf("Hello Player! insert your name to start building your map: ");
  scanf("%30s", player->name);

  printf("Ok %s, lets set your board map! first step is positioning your %d submarine(s) (1 slot of space).\n", player->name, SUBMARINE);
  for (i = 1, flag = 0; i <= SUBMARINE; i++, flag = 0) {
    do {
      printf("please insert a line and column to set your %d submarine: ", i);
      scanf(" %c %d", &x, &y);
      flag = CheckDisponibility(&x, y, 1, 1, player);
    } while (flag);
    printf("%c\n", player->map[y][x].presentation);
    Positioning(x, y, 1, 1, 'S', player);
    printf("%c\n", player->map[y][x].presentation);
  }
  printf("Agora vamos posicionar seu(s) %d battleship(s).\n", BATTLESHIP);
  for (i = 1, flag = 0; i <= BATTLESHIP; i++, flag = 0) {
    do {
      printf("Por favor, insira a linha e a coluna do seu %d battleship: ", i);
      scanf(" %c %d", &x, &y);
      flag = CheckDisponibility(&x, y, 2, 2, player);

    } while (flag);
    Positioning(x, y, 2, 2, 'B', player);
  }
  DrawBoard(player, player2);
  printf("O próximo passo é alocar seu(s) %d craiser(s).\n", CRAISER);
  for (i = 1, flag = 0; i <= CRAISER; i++, flag = 0) {
    do {
      printf("Por favor, insira a linha e a coluna do seu %d craiser: ", i);
      scanf(" %c %d", &x, &y);

      flag = CheckDisponibility(&x, y, 1, 2, player);

    } while (flag);

    Positioning(x, y, 1, 2, 'C', player);
  }
  DrawBoard(player, player2);
  printf("Partimos então para seu(s) %d destroyer(s).\n", DESTROYER);
  for (i = 1, flag = 0; i <= DESTROYER; i++, flag = 0) {
    do {
      printf("Por favor, insira a linha e a coluna do seu %d destroyer: ", i);
      scanf(" %c %d", &x, &y);

      flag = CheckDisponibility(&x, y, 1, 4, player);

    } while (flag);

    Positioning(x, y, 1, 4, 'D', player);
  }
  DrawBoard(player, player2);
  printf("Para finalizar inserimos seu(s) %d aircraft(s).\n", AIRCRAFT);
  for (i = 1, flag = 0; i <= AIRCRAFT; i++, flag = 0) {
    do {
      printf("Por favor, insira a linha e a coluna do seu %d aircraft: ", i);
      scanf(" %c %d", &x, &y);

      flag = CheckDisponibility(&x, y, 1, 5, player);

    } while (flag);

    Positioning(x, y, 1, 5, 'A', player);
  }

}
void buildIA(Players *player)
{

}
