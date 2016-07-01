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
void build_player(int mode, int index, char name[])
{
  Players player, player2;
  int i;

  dom_head();

  printf(

  "	<body id=\"mapa\">\n"
  "		<div id=\"document-container\">\n"
  "			<div id=\"header-container\">\n"
  "				<h1 id=\"header-title\"></h1>\n"
  "			</div>\n"
  "      <div id=\"board-container\">\n"

  );

  if (mode == 1) {
    init_map(&player2);
    build_map(&player2, AI_NAME);
    hide_ships(&player2);
    create_log(&player2, (index + 1), AI_NAME);
  }

  init_map(&player);
  strcpy(player.name, name);
  build_map(&player, (&player)->name);
  add_board(&player, mode, index, 0);
  hide_ships(&player);
  create_log(&player, index, (&player)->name);


  printf(
  "  		</div>\n"
  "		</div>\n"
  "	</body>\n"
  "</html>\n"
  );

}

/* get player logs */
void get_log(Players *player, int n)
{

  int i, j, vis;
  char filename[2][20] = {"player1.log", "player2.log"}, line[100], query[30], param[50], pres;
  FILE *stream;

  stream = fopen(filename[n], "r");

  while (fgets(line, 100, stream)) {
    if (sscanf(line, "[%[^]]]: %[^\n]", query, param)) {
      if (strcmp(query, "username") == 0) {
        strcpy(player->name, param);
      } else if (strcmp(query, "board") == 0) {
        sscanf(param, "POSY=%d POSX=%d PRES=%c VIS=%d", &i, &j, &pres, &vis);
        player->map[i][j].presentation = pres;
        player->map[i][j].isVisible = vis;
      } else if (strcmp(query, "score") == 0) {
        player->score = atoi(param);
      }
    }
  }

  fclose(stream);

}

/* write player logs */
void create_log(Players *player, int n, char name[])
{

  int i, j;
  char filename[2][20] = {"player1.log", "player2.log"};
  FILE *stream;

  stream = fopen(filename[n], "w");

  fprintf(stream, "[username]: %s\n", name);
  fprintf(stream, "[score]: %d\n", player->score);
  for (i = 0; i < MAP_SIZE; i++)
    for(j = 0; j < MAP_SIZE; j++)
      fprintf(stream, "[board]: POSY=%d POSX=%d PRES=%c VIS=%d \n", i, j, player->map[i][j].presentation, player->map[i][j].isVisible);

  fclose(stream);

}

/* generate a random map */
void build_map(Players *player, char *name)
{
  int i, x, y, flag, pos;
  strcpy(player->name, name);
  x = 0;
  for (i = 1, flag = 0; i <= SUBMARINE; flag = 0, ++i) {
    do {
      x = rand() % MAP_SIZE;
      y = rand() % MAP_SIZE;
      flag = check_pos(x, y, 1, 1, pos, 1, player);
    } while (flag);
    pos_s(x, y, 1, 1, pos, 'S', player);
  }

  for (i = 1, flag = 0; i <= BATTLESHIP; flag = 0, ++i) {
    do {
      x = rand() % MAP_SIZE;
      y = rand() % MAP_SIZE;
      flag = check_pos(x, y, 2, 2, pos, 1, player);

    } while (flag);
    pos_s(x, y, 2, 2, pos, 'B', player);
  }

  for (i = 1, flag = 0; i <= CRAISER; flag = 0, ++i) {
    do {
      x = rand() % MAP_SIZE;
      y = rand() % MAP_SIZE;
      pos = rand() % 2;
      flag = check_pos(x, y, 1, 2, pos, 1, player);

    } while (flag);
    pos_s(x, y, 1, 2, pos, 'C', player);
  }

  for (i = 1, flag = 0; i <= DESTROYER; flag = 0, ++i) {
    do {
      x = rand() % MAP_SIZE;
      y = rand() % MAP_SIZE;
      pos = rand() % 2;
      flag = check_pos(x, y, 1, 4, pos, 1, player);

    } while (flag);
    pos_s(x, y, 1, 4, pos, 'D', player);
  }

  for (i = 1, flag = 0; i <= AIRCRAFT; flag = 0, ++i) {
    do {
      x = rand() % MAP_SIZE;
      y = rand() % MAP_SIZE;
      pos = rand() % 2;
      flag = check_pos(x, y, 1, 5, pos, 1, player);

    } while (flag);
    pos_s(x, y, 1, 5, pos, 'A', player);
  }

}
