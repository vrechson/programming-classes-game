/*
 *	Libraries
 ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"

/*
 *	Functions
 ***********************************************************************/
void init_map(Players *player)
{
  int i, j;
  for (i = 0; i < MAP_SIZE; i++)
    for (j = 0; j < MAP_SIZE; j++) {
      player->map[i][j].presentation = EMPTY;
      player->score = 0;
      player->map[i][j].isVisible = 1;
    }
}

void hide_ships(Players *player)
{
  int i, j;

  for (i = 0; i < MAP_SIZE; i++)
    for (j = 0; j < MAP_SIZE; j++)
      player->map[i][j].isVisible = 0;

}


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

int check_pos(int x, int y, int height, int width, int rotation, int ia, Players *player)
{
  int i, j, aux;

  if (rotation) {
    aux = height;
    height = width;
    width = aux;
  }

  for (i = 0; i < height; i++)
    for (j = 0; j < width; j++)
      if (((y + j - 1) > (MAP_SIZE - 1)) || ((x + i - 1) >
       (MAP_SIZE - 1)) || ((y + j - 1) < 0) || ((x + i - 1) < 0)) {
        if (!ia)
          printf("A posição solicitada não obedece aos limites do mapa. tente uma nova posição.\n");
        return 1;
      } else if (player->map[x + i - 1][y + j - 1].presentation != EMPTY) {
        if (!ia)
          printf("A posição solicitada já foi ocupada por outro barco. tente uma nova posição.\n");
        return 1;
      }
      //printf("[debug]: %d %d %d", (y + j - 1), (x + i - 1), MAP_SIZE);
  return 0;
}

void pos_s(int x, int y, int height, int width, int rotation, char style, Players *player)
{
  int i, j, aux;

  if (rotation) {
    aux = height;
    height = width;
    width = aux;
  }

  for (i = 0; i < height; i++)
    for (j = 0; j < width; j++) {
      player->map[x + i - 1][y + j - 1].presentation = style;
    }

}

int hit_pos(int index, int x, int y)
{
  Players player1, player2;
  int ind;

  get_log(&player1, index);

  if (player1.map[y][x].presentation != EMPTY && player1.map[y][x].isVisible == 0) {
    if (index == 0)
      ind = 1;
    else
      ind = 0;

    get_log(&player2, ind);
    player2.score++;
    create_log(&player2, ind, player2.name);
    if (player2.score >= TOTAL_SLOTS)
      printf("<meta http-equiv=\"refresh\" content=0;url=\"?mode=5\">");
  }

  player1.map[y][x].isVisible = 1;
  create_log(&player1, index, player1.name);
}

void ai_hit_pos()
{
  Players player1, player2;
  int x, y, around[2] = {1, -1};
  char *query;


  query = getenv("QUERY_STRING");

  if ((sscanf(query, "mode=4&player=0&posx=%d&posy=%d", &x, &y) == 2)) {
    x += around[rand() % 2];
    y += around[rand() % 2];

    while (x >= MAP_SIZE || x < 0 || y < 0 || y >= MAP_SIZE) {
      x = rand() % MAP_SIZE;
      y = rand() % MAP_SIZE;
    }

  } else {
    x = rand() % MAP_SIZE;
    y = rand() % MAP_SIZE;
  }

  get_log(&player1, 0);

  if (player1.map[y][x].presentation != EMPTY && player1.map[y][x].isVisible == 0) {
    get_log(&player2, 1);
    player2.score++;
    create_log(&player2, 1, AI_NAME);
    if (player2.score >= TOTAL_SLOTS)
      printf("<meta http-equiv=\"refresh\" content=0;url=\"?mode=5\">");
  }

  player1.map[y][x].isVisible = 1;
  create_log(&player1, 0, player1.name);
}
