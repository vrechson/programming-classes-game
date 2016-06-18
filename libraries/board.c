/*
 *	Libraries
 ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "board.h"

/*
 *	FUnctions
 ***********************************************************************/
void DrawBoard(Players *player1, Players *player2)
{
  int i, j, k, l;

  system(CLEAR);
  printf("\n");

  for (i = 0, k = 64; i <= MAP_SIZE; i++, k++, printf("\n"))
    for (j = 0, l = 1; j <= ((2 * MAP_SIZE) + 1); j++)
      if (!i && j) {
        if (j == (MAP_SIZE + 1)) {
          l = 1;
          printf("\t");
          printf("%3c", ' ');
        } else {
          printf("%3d", l++);
        }
      } else if (i && (!j || j == (MAP_SIZE + 1))){
        if (j == MAP_SIZE + 1)
          printf("\t");
        printf("%3c", k);
      } else if (i && j) {
        if(j <= MAP_SIZE) {
          if (LEVEL && player2->map[i - 1][j - 1].presentation != WATER && player2->map[i - 1][j - 1].presentation != EMPTY) {
            if(player1->map[i - 1][j - 1].isVisible)
              printf("%3c", SHOT);
            else
              printf("%3c", player1->map[i - 1][j - 1].background);
          } else {
            if(player1->map[i - 1][j - 1].isVisible)
              printf("%3c", player1->map[i - 1][j - 1].presentation);
            else
              printf("%3c", player1->map[i - 1][j - 1].background);
          }
        } else {
          if (LEVEL && player2->map[i - 1][j - MAP_SIZE - 2].presentation != WATER && player2->map[i - 1][j - MAP_SIZE - 2].presentation != EMPTY)
            if(player2->map[i - 1][j - MAP_SIZE - 2].isVisible)
              printf("%3c", SHOT);
            else
              printf("%3c", player2->map[i - 1][j - MAP_SIZE - 2].background);
          else
            if(player2->map[i - 1][j - 1].isVisible)
              printf("%3c", player2->map[i - 1][j - MAP_SIZE - 2].presentation);
            else
              printf("%3c", player2->map[i - 1][j - MAP_SIZE - 2].background);
        }
      } else {
        printf("%3c", ' ');
      }

    printf("\n");

}

void DrawMap(Players *player)
{
  int i, j, k;

  system(CLEAR);
  for (i = 0, k = 64, printf("\n"); i <= MAP_SIZE; i++, k++, printf("\n"))
    for (j = 0; j <= MAP_SIZE; j++)
      if(i == 0 && j) {
        printf("%3d", j);
      } else if(i != 0 && j == 0) {
        printf("%3c", k);
      } else if(i != 0) {
        if(LEVEL && player->map[i - 1][j - 1].presentation != WATER && player->map[i - 1][j - 1].presentation != EMPTY) {
          if (player->map[i - 1][j - 1].isVisible)
            printf("%3c", SHOT);
          else
            printf("%3c", player->map[i - 1][j - 1].background);
        } else {
          if (player->map[i - 1][j - 1].isVisible)
            printf("%3c", player->map[i - 1][j - 1].presentation);
          else
            printf("%3c", player->map[i - 1][j - 1].background);
        }
      } else {
        printf("%3c", ' ');
      }
  printf("\n");
}

void InitializeMap(Players *player)
{
  int i, j;
  for (i = 0; i < MAP_SIZE; i++)
    for (j = 0; j < MAP_SIZE; j++) {
      player->map[i][j].presentation = WATER;
      player->map[i][j].background = WATER;
      player->map[i][j].isVisible = 1;
    }
}

void HideThings(Players *player)
{
  int i, j;

  for (i = 0; i < MAP_SIZE; i++)
    for (j = 0; j < MAP_SIZE; j++)
      player->map[i][j].isVisible = 0;

}

int Letter2Num(int *x) {
  if (*x > 64 && *x <= (64 + MAP_SIZE))
    *x -= 64;
  else if ((*x > 96) && *x <= (96 + MAP_SIZE))
    *x -= 96;
  else
    return 1;

  return 0;
}

int CheckDisponibility(int *x, int y, int height, int width, int rotation, int ia, Players *player)
{
  int i, j, aux;

  if (rotation) {
    aux = height;
    height = width;
    width = aux;
  }

  if(!ia)
    if (Letter2Num(x)) {
      printf("A posição solicitada não obedece aos limites do mapa. tente uma nova posição.\n");
      return 1;
    }

  for (i = 0; i < height; i++)
    for (j = 0; j < width; j++)
      if (((y + j - 1) > (MAP_SIZE - 1)) || ((*x + i - 1) > (MAP_SIZE - 1))) {
        if (!ia)
          printf("A posição solicitada não obedece aos limites do mapa. tente uma nova posição.\n");
        return 1;
      } else if ( player->map[*x + i - 1][y + j - 1].presentation != WATER) {
        if (!ia)
          printf("A posição solicitada já foi ocupada por outro barco. tente uma nova posição.\n");
        return 1;
      }
      //printf("[debug]: %d %d %d", (y + j - 1), (*x + i - 1), MAP_SIZE);
  return 0;
}

void Positioning(int x, int y, int height, int width, int rotation, char style, Players *player)
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

  if (SHOW_MAP)
    DrawMap(player);

}

int PosBombing(int *x, int y, Players *player)
{
  Letter2Num(x);
  if (player->map[*x][y].presentation != WATER || player->map[*x][y].presentation != EMPTY) {
    player->map[*x][y].isVisible = 1;
    return 1;
  } else {
    player->map[*x][y].presentation = EMPTY;
    player->map[*x][y].background = EMPTY;
    return 0;
  }

}

int IABombing(Players *player)
{
  volatile int count = -1, x, y;
  int index1, index2;

  srand((unsigned) time(NULL));

  count++;

  if (count) {
    index1 = rand() % 2;
    index2 = rand() % 2;

    if (!index1)
      index1 = -1;
    if (!index2)
      index2 = -1;
    if (x == (MAP_SIZE - 1))
      index1 = -1;
    if (y == (MAP_SIZE - 1))
      index2 = -1;

    if (player->map[x + index1][y + index2].presentation != WATER || player->map[x + index1][y + index2].presentation != EMPTY) {
      player->map[x + index1][y + index2].isVisible = 1;
      return 1;
    } else {
      count = -1;
      player->map[x + index1][y + index2].presentation = EMPTY;
      player->map[x + index1][y + index2].background = EMPTY;
      return 0;
    }
  } else {
    x = rand() % MAP_SIZE;
    y = rand() % MAP_SIZE;
    if (player->map[x + index1][y + index2].presentation != WATER || player->map[x + index1][y + index2].presentation != EMPTY) {
      player->map[x + index1][y + index2].isVisible = 1;
      return 1;
    } else {
      player->map[x + index1][y + index2].presentation = EMPTY;
      player->map[x + index1][y + index2].background = EMPTY;
      return 0;
    }
  }

}
