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
void build_player(Players *player)
{
  int i, x, y, flag, next, map, rot;
  char x_c;

/*  if (strcmp(player->name, NULL) == 0)
    strcpy(player->name, "undefined"); */

  build_ai(player, player->name);
  player_builder(player);
  return;
  //system(CLEAR);
  printf("Vamos começar! Insira seu nome: ");
  scanf(" %49[^\n]s", player->name);
  // system(CLEAR);

  if (SHOW_MAP)
    draw_map(player);
  printf("Digite 1 para gerar seu mapa randomicamente e 0 para construir um manualmente: ");
  scanf(" %d", &map);

  if (map) {
    build_ai(player, player->name);
    return;
  }
  printf("Certo %s, vamos configurar seu mapa! primeiro posicione seu(s) %d submarino(s) (1 casa de espaço).\n", player->name, SUBMARINE);
  for (i = 1, flag = 0; i <= SUBMARINE; i++, flag = 0) {
    do {
      printf("por favor, insira a linha(letra) e a coluna(número) do seu %d submarino, respectvamente: ", i);
      scanf(" %c %d", &x_c, &y);
      x = carac_2_num(x_c);
      flag = check_pos(x, y, 1, 1, 0, 0, player);
    } while (flag);
    pos_s(x, y, 1, 1, 0, 'S', player);
  }

  printf("Agora vamos posicionar seu(s) %d battleship(s).\n", BATTLESHIP);
  for (i = 1, flag = 0; i <= BATTLESHIP; i++, flag = 0) {
    do {
      printf("Por favor, insira a linha e a coluna do seu %d battleship: ", i);
      scanf(" %c %d", &x_c, &y);
      x = carac_2_num(x_c);
      flag = check_pos(x, y, 2, 2, 0, 0, player);

    } while (flag);
    pos_s(x, y, 2, 2, 0, 'B', player);
  }

  printf("O próximo passo é alocar seu(s) %d craiser(s).\n", CRAISER);
  for (i = 1, flag = 0; i <= CRAISER; i++, flag = 0) {
    do {
      printf("Por favor, insira a linha e a coluna do seu %d craiser: ", i);
      scanf(" %c %d", &x_c, &y);
      printf("você deseja rotacionar seu barco? (1 para sim, 0 para não): ");
      scanf(" %d", &rot);
      x = carac_2_num(x_c);

      flag = check_pos(x, y, 1, 2, rot, 0, player);

    } while (flag);

    pos_s(x, y, 1, 2, rot, 'C', player);
  }

  printf("Partimos então para seu(s) %d destroyer(s).\n", DESTROYER);
  for (i = 1, flag = 0; i <= DESTROYER; i++, flag = 0) {
    do {
      printf("Por favor, insira a linha e a coluna do seu %d destroyer: ", i);
      scanf(" %c %d", &x_c, &y);
      printf("você deseja rotacionar seu barco? (1 para sim, 0 para não): ");
      scanf(" %d", &rot);
      x = carac_2_num(x_c);

      flag = check_pos(x, y, 1, 4, rot, 0, player);

    } while (flag);

    pos_s(x, y, 1, 4, rot, 'D', player);
  }

  printf("Para finalizar inserimos seu(s) %d aircraft(s).\n", AIRCRAFT);
  for (i = 1, flag = 0; i <= AIRCRAFT; i++, flag = 0) {
    do {
      printf("Por favor, insira a linha e a coluna do seu %d aircraft: ", i);
      scanf(" %c %d", &x_c, &y);
      printf("você deseja rotacionar seu barco? (1 para sim, 0 para não): ");
      scanf(" %d", &rot);
      x = carac_2_num(x_c);

      flag = check_pos(x, y, 1, 5, rot, 0, player);

    } while (flag);

    pos_s(x, y, 1, 5, rot, 'A', player);
  }

  next = 3;
  while (next != 1) {
    if (!next) {
      init_map(player);
      build_player(player);
    }
    printf("Mapa finalizado, digite 1 para continuar e 0 para refazer seu tabuleiro: ");
    scanf(" %d", &next);
  }

  hide_ships(player);

}
void build_ai(Players *player, char *name)
{
  int i, x, y, flag, pos;
  strcpy(player->name, name);
  x = 0;
  for (i = 1, flag = 0; i <= SUBMARINE; i++, flag = 0) {
    do {
      x = rand() % MAP_SIZE;
      y = rand() % MAP_SIZE;
      pos = rand() % 2;
      flag = check_pos(x, y, 1, 1, pos, 1, player);
    } while (flag);
    pos_s(x, y, 1, 1, pos, 'S', player);
  }

  for (i = 1, flag = 0; i <= BATTLESHIP; i++, flag = 0) {
    do {
      x = rand() % MAP_SIZE;
      y = rand() % MAP_SIZE;
      flag = check_pos(x, y, 2, 2, pos, 1, player);

    } while (flag);
    pos_s(x, y, 2, 2, pos, 'B', player);
  }

  for (i = 1, flag = 0; i <= CRAISER; i++, flag = 0) {
    do {
      x = rand() % MAP_SIZE;
      y = rand() % MAP_SIZE;
      pos = rand() % 2;
      flag = check_pos(x, y, 1, 2, pos, 1, player);

    } while (flag);
    pos_s(x, y, 1, 2, pos, 'C', player);
  }

  for (i = 1, flag = 0; i <= DESTROYER; i++, flag = 0) {
    do {
      x = rand() % MAP_SIZE;
      y = rand() % MAP_SIZE;
      pos = rand() % 2;
      flag = check_pos(x, y, 1, 4, pos, 1, player);

    } while (flag);
    pos_s(x, y, 1, 4, pos, 'D', player);
  }

  for (i = 1, flag = 0; i <= AIRCRAFT; i++, flag = 0) {
    do {
      x = rand() % MAP_SIZE;
      y = rand() % MAP_SIZE;

      flag = check_pos(x, y, 1, 5, pos, 1, player);

    } while (flag);
    pos_s(x, y, 1, 5, pos, 'A', player);
  }

//  hide_ships(player);
}

Players *guess_eng(Players *player1, Players *player2, int ia)
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
      x = carac_2_num(x_c);
      flag = hit_pos(x, y, player2);
      system(CLEAR);
      if (flag) {
        g_p1 = 0;
        count_p1++;
        if (count_p1 == TOTAL_SLOTS)
          return player1;
        draw_board(player1, player2);
        printf("%s acertou uma posição, jogue novamente: ", player1->name);
        guess = 1;
      } else {
        g_p1 = 1;
        guess = 0;
        draw_board(player1, player2);
      }
    } else {
      if (!ia) {
        if (g_p2) {
          printf("É a vez do jogador: %s.", player2->name);
          printf(" Insira as coordenadas para bombardear: ");
        }
        scanf(" %c %d", &x_c, &y);
        x = carac_2_num(x_c);
        flag = hit_pos(x, y, player1);
        system(CLEAR);
        if (flag) {
          g_p2 = 0;
          count_p2++;
          if (count_p2 == TOTAL_SLOTS)
            return player2;
          draw_board(player1, player2);
          printf("%s acertou uma posição, jogue novamente: ",  player2->name);
          guess = 0;
        } else {
          g_p2 = 1;
          guess = 1;
          draw_board(player1, player2);
        }
      } else {
        if (g_p2) {
          printf("%s fez seu lance.", player2->name);
        }

        flag = ai_hit_pos(player1);
        system(CLEAR);
        if (flag) {
          g_p2 = 0;
          count_p2++;
          if (count_p2 == TOTAL_SLOTS)
            return player2;
          draw_board(player1, player2);
          printf("%s acertou uma posição!", player2->name);
          guess = 0;
        } else {
          count_p2 = 1;
          guess = 1;
          draw_board(player1, player2);
        }
      }
    }
  }
}
