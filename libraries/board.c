#include <stdio.h>
#include <string.h>
#include "board.h"

void DrawBoard(Players Player1, Players Player2)
{


}

void CleanMap(Players *player)
{
  memset(player->map, WATER, MAP_SIZE * MAP_SIZE * sizeof(char));
}
