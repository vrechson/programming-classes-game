/*
 *	Libraries
 ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "players.h"


/*
 *	Functions
 ***********************************************************************/
void buildPlayer(Players *player)
{
  int i, x, y, flag, next;

  system(CLEAR);
  printf("Vamos começar! Insira seu nome: ");
  scanf("%30s", player->name);
  system(CLEAR);

  if (SHOW_MAP)
    DrawMap(player);

  printf("Certo %s, vamos configurar seu mapa! primeiro posicione seu(s) %d submarino(s) (1 casa de espaço).\n", player->name, SUBMARINE);
  for (i = 1, flag = 0; i <= SUBMARINE; i++, flag = 0) {
    do {
      printf("por favor, insira a linha(letra) e a coluna(número) do seu %d submarino, respectvamente: ", i);
      scanf(" %c %d", &x, &y);
      flag = CheckDisponibility(&x, y, 1, 1, 0, player);
    } while (flag);
    Positioning(x, y, 1, 1, 0, 'S', player);
  }

  printf("Agora vamos posicionar seu(s) %d battleship(s).\n", BATTLESHIP);
  for (i = 1, flag = 0; i <= BATTLESHIP; i++, flag = 0) {
    do {
      printf("Por favor, insira a linha e a coluna do seu %d battleship: ", i);
      scanf(" %c %d", &x, &y);
      flag = CheckDisponibility(&x, y, 2, 2, 0, player);

    } while (flag);
    Positioning(x, y, 2, 2, 0, 'B', player);
  }

  printf("O próximo passo é alocar seu(s) %d craiser(s).\n", CRAISER);
  for (i = 1, flag = 0; i <= CRAISER; i++, flag = 0) {
    do {
      printf("Por favor, insira a linha e a coluna do seu %d craiser: ", i);
      scanf(" %c %d", &x, &y);

      flag = CheckDisponibility(&x, y, 1, 2, 0, player);

    } while (flag);

    Positioning(x, y, 1, 2, 0, 'C', player);
  }

  printf("Partimos então para seu(s) %d destroyer(s).\n", DESTROYER);
  for (i = 1, flag = 0; i <= DESTROYER; i++, flag = 0) {
    do {
      printf("Por favor, insira a linha e a coluna do seu %d destroyer: ", i);
      scanf(" %c %d", &x, &y);

      flag = CheckDisponibility(&x, y, 1, 4, 0, player);

    } while (flag);

    Positioning(x, y, 1, 4, 0, 'D', player);
  }

  printf("Para finalizar inserimos seu(s) %d aircraft(s).\n", AIRCRAFT);
  for (i = 1, flag = 0; i <= AIRCRAFT; i++, flag = 0) {
    do {
      printf("Por favor, insira a linha e a coluna do seu %d aircraft: ", i);
      scanf(" %c %d", &x, &y);

      flag = CheckDisponibility(&x, y, 1, 5, 0, player);

    } while (flag);

    Positioning(x, y, 1, 5, 0, 'A', player);
  }

  next = 3;
  while (next != 1) {
    if (!next)
      buildPlayer(player);
    printf("Mapa finalizado, digite 1 para continuar e 0 para refazer seu tabuleiro: ");
    scanf(" %d", &next);
  }

}
void buildIA(Players *player)
{

}
