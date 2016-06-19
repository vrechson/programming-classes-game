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
  char x_c;

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
      scanf(" %c %d", &x_c, &y);
      x = Letter2Num(x_c);
      flag = CheckDisponibility(x, y, 1, 1, 0, 0, player);
    } while (flag);
    Positioning(x, y, 1, 1, 0, 'S', player);
  }

  printf("Agora vamos posicionar seu(s) %d battleship(s).\n", BATTLESHIP);
  for (i = 1, flag = 0; i <= BATTLESHIP; i++, flag = 0) {
    do {
      printf("Por favor, insira a linha e a coluna do seu %d battleship: ", i);
      scanf(" %c %d", &x_c, &y);
      x = Letter2Num(x_c);
      flag = CheckDisponibility(x, y, 2, 2, 0, 0, player);

    } while (flag);
    Positioning(x, y, 2, 2, 0, 'B', player);
  }

  printf("O próximo passo é alocar seu(s) %d craiser(s).\n", CRAISER);
  for (i = 1, flag = 0; i <= CRAISER; i++, flag = 0) {
    do {
      printf("Por favor, insira a linha e a coluna do seu %d craiser: ", i);
      scanf(" %c %d", &x_c, &y);
      x = Letter2Num(x_c);

      flag = CheckDisponibility(x, y, 1, 2, 0, 0, player);

    } while (flag);

    Positioning(x, y, 1, 2, 0, 'C', player);
  }

  printf("Partimos então para seu(s) %d destroyer(s).\n", DESTROYER);
  for (i = 1, flag = 0; i <= DESTROYER; i++, flag = 0) {
    do {
      printf("Por favor, insira a linha e a coluna do seu %d destroyer: ", i);
      scanf(" %c %d", &x_c, &y);
      x = Letter2Num(x_c);

      flag = CheckDisponibility(x, y, 1, 4, 0, 0, player);

    } while (flag);

    Positioning(x, y, 1, 4, 0, 'D', player);
  }

  printf("Para finalizar inserimos seu(s) %d aircraft(s).\n", AIRCRAFT);
  for (i = 1, flag = 0; i <= AIRCRAFT; i++, flag = 0) {
    do {
      printf("Por favor, insira a linha e a coluna do seu %d aircraft: ", i);
      scanf(" %c %d", &x_c, &y);
      x = Letter2Num(x_c);

      flag = CheckDisponibility(x, y, 1, 5, 0, 0, player);

    } while (flag);

    Positioning(x, y, 1, 5, 0, 'A', player);
  }

  next = 3;
  while (next != 1) {
    if (!next) {
      InitializeMap(player);
      buildPlayer(player);
    }
    printf("Mapa finalizado, digite 1 para continuar e 0 para refazer seu tabuleiro: ");
    scanf(" %d", &next);
  }

  HideThings(player);

}
void buildIA(Players *player)
{
  int i, x, y, flag, pos;
  strcpy(player->name, "Mr. Robot");
  x = 0;
  for (i = 1, flag = 0; i <= SUBMARINE; i++, flag = 0) {
    do {
      x = rand() % MAP_SIZE;
      y = rand() % MAP_SIZE;
      pos = rand() % 2;
      flag = CheckDisponibility(x, y, 1, 1, pos, 1, player);
    } while (flag);
    Positioning(x, y, 1, 1, pos, 'S', player);
  }

  for (i = 1, flag = 0; i <= BATTLESHIP; i++, flag = 0) {
    do {
      x = rand() % MAP_SIZE;
      y = rand() % MAP_SIZE;
      pos = rand() % 2;
      flag = CheckDisponibility(x, y, 2, 2, pos, 1, player);

    } while (flag);
    Positioning(x, y, 2, 2, pos, 'B', player);
  }

  for (i = 1, flag = 0; i <= CRAISER; i++, flag = 0) {
    do {
      x = rand() % MAP_SIZE;
      y = rand() % MAP_SIZE;
      pos = rand() % 2;
      flag = CheckDisponibility(x, y, 1, 2, pos, 1, player);

    } while (flag);
    Positioning(x, y, 1, 2, pos, 'C', player);
  }

  for (i = 1, flag = 0; i <= DESTROYER; i++, flag = 0) {
    do {
      x = rand() % MAP_SIZE;
      y = rand() % MAP_SIZE;
      pos = rand() % 2;
      flag = CheckDisponibility(x, y, 1, 4, pos, 1, player);

    } while (flag);
    Positioning(x, y, 1, 4, pos, 'D', player);
  }

  for (i = 1, flag = 0; i <= AIRCRAFT; i++, flag = 0) {
    do {
      x = rand() % MAP_SIZE;
      y = rand() % MAP_SIZE;

      flag = CheckDisponibility(x, y, 1, 5, pos, 1, player);

    } while (flag);
    Positioning(x, y, 1, 5, pos, 'A', player);
  }

  HideThings(player);

}

Players *guessEngine(Players *player1, Players *player2, int ia)
{
  int y, x, guess = rand() % 2, flag, g_p1, g_p2, count_p1, count_p2;
  char x_c;

  g_p1 = g_p2 = 1;
  count_p1 = count_p2 = 0;
  while (1) {
    if (guess) {
      if (g_p1) {
        printf("É a vez do jogador: %s.", player1->name);
        printf(" Insira as coordenadas para bombardear: ");
      }
      scanf(" %c %d", &x_c, &y);
      x = Letter2Num(x_c);
      flag = PosBombing(x, y, player2);
      system(CLEAR);
      if (flag) {
        g_p1 = 0;
        count_p1++;
        if (count_p1 == TOTAL_SLOTS)
          return player1;
        DrawBoard(player1, player2);
        printf("%s acertou uma posição, jogue novamente: ");
        guess = 1;
      } else {
        g_p1 = 1;
        guess = 0;
        DrawBoard(player1, player2);
      }
    } else {
      if (!ia) {
        if (g_p2) {
          printf("É a vez do jogador: %s.", player2->name);
          printf(" Insira as coordenadas para bombardear: ");
        }
        scanf(" %c %d", &x_c, &y);
        x = Letter2Num(x_c);
        flag = PosBombing(x, y, player1);
        system(CLEAR);
        if (flag) {
          g_p2 = 0;
          count_p2++;
          if (count_p2 == TOTAL_SLOTS)
            return player2;
          DrawBoard(player1, player2);
          printf("%s acertou uma posição, jogue novamente: ",  player2->name);
          guess = 0;
        } else {
          count_p2 = 1;
          guess = 1;
          DrawBoard(player1, player2);
        }
      } else {
        if (g_p2) {
          printf("%s fez seu lance.", player2->name);
        }

        flag = IABombing(player1);
        system(CLEAR);
        if (flag) {
          g_p2 = 0;
          count_p2++;
          if (count_p2 == TOTAL_SLOTS)
            return player2;
          DrawBoard(player1, player2);
          printf("%s acertou uma posição!", player2->name);
          guess = 0;
        } else {
          count_p2 = 1;
          guess = 1;
          DrawBoard(player1, player2);
        }
      }
    }
  }
}
