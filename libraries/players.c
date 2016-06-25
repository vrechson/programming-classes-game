/*
 *	Libraries
 ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "players.h"


/*
 *	Functions
 ***********************************************************************/
void build_game(int args, ...)
{
  va_list ap;
  Players *player[4];
  int i;

  va_start(ap, args);

  dom_head();

  printf(

  "	<body id=\"mapa\">\n"
  "		<div id=\"document-container\">\n"
  "			<div id=\"header-container\">\n"
  "				<h1 id=\"header-title\"></h1>\n"
  "			</div>\n"
  "      <div id=\"board-container\">\n"

  );

  for (i = 0; i < args; ++i) {
    player[i] = va_arg(ap, Players *);
    build_ai(player[i], player[i]->name);
    add_board(player[i]);
  }

  printf(
  "  		</div>\n"
  "		</div>\n"
  "	</body>\n"
  "</html>\n"
  );



//  hide_ships(player);

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
