#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "board.h"

void DrawBoard(Players *player1, Players *player2)
{
  int i, j, k;
  char l;

  system(CLEAR);
// precisa de ajuste
  for (i = 0; i <= MAP_SIZE; i++, printf("\n"))
    for (j = 0, l = 'A'; j <= (2 * MAP_SIZE) + 1; j++)
      if (i == 0) {
        if(j == MAP_SIZE + 1) {
          l = 'A';
          printf("\t");
        }
        if (j && j != (MAP_SIZE + 1))
          printf("%3c", l++);
        else
          printf("%3c", ' ');
      } else {
        if(j == 0 || j == MAP_SIZE + 1) {
          if (j == 0)
            printf("%3d", i);
          else
            printf("\t%3d", i);
        } else {
          if( j <= MAP_SIZE)
            printf("%3c", player1->map[i - 1][j - 1].presentation);
          else if (j == ((2 * MAP_SIZE) + 1))
            printf("%3c", player2->map[i - 1][j - MAP_SIZE - 2].presentation);
          else
            printf("%3c", player2->map[i - 1][j - MAP_SIZE - 1].presentation);
        }

      }
}

void DrawMap(Players *player)
{
  int i, j, k;

  system(CLEAR);
  for (i = 0, k = 64, printf("\n"); i <= MAP_SIZE; i++, k++, printf("\n"))
    for (j = 0; j <= MAP_SIZE; j++)
      if(i == 0 && j)
        printf("%3d", j);
      else if(i != 0 && j == 0)
        printf("%3c", k);
      else if(i != 0)
        printf("%3c", player->map[i - 1][j - 1].presentation);
      else
        printf("%3c", ' ');
  printf("\n");
}

void InitializeMap(Players *player1, Players *player2)
{
  int i, j;
  for (i = 0; i < MAP_SIZE; i++)
    for (j = 0; j < MAP_SIZE; j++) {
      player1->map[i][j].presentation = WATER;
      player2->map[i][j].presentation = WATER;
      player1->map[i][j].isVisible = 0;
      player2->map[i][j].isVisible = 0;
    }
}

int Letter2Num(int *x) {
  if (*x > 64 && *x <= (64 + MAP_SIZE)) {
    *x -= 64;
  } else if ((*x > 96) && *x <= (96 + MAP_SIZE)) {
    *x -= 96;
  } else {
    printf("A posição solicitada não obedece aos limites do mapa. tente uma nova posição.\n");
    return 1;
  }

  return 0;
}

int CheckDisponibility(int *x, int y, int height, int width, Players *player)
{
  int i, j;

  if(Letter2Num(x))
    return 1;
  for (i = 0; i < height; i++)
    for (j = 0; j < width; j++)
      if (((y + j - 1) > (MAP_SIZE - 1)) || ((*x + i - 1) > (MAP_SIZE - 1))) {
        printf("A posição solicitada não obedece aos limites do mapa. tente uma nova posição.\n");
        return 1;
      } else if ( player->map[*x + i - 1][y + j - 1].presentation != WATER) {
        printf("A posição solicitada já foi ocupada por outro barco. tente uma nova posição.\n");
        return 1;
      }
      //printf("[debug]: %d %d %d", (y + j - 1), (*x + i - 1), MAP_SIZE);
  return 0;
}

int Positioning(int x, int y, int height, int width, char style, Players *player)
{
  int i, j;

  for (i = 0; i < height; i++)
    for (j = 0; j < width; j++) {
      player->map[x + i - 1][y + j - 1].presentation = style;
    }

  if (SHOW_MAP)
    DrawMap(player);

}
