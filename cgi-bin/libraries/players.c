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

  init_map(&player);
  strcpy(player.name, name);

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
    build_map(&player2, "Mr. Robot");
    create_log(&player2, (index + 1), "Mr. Robot");
  }

  build_map(&player, (&player)->name);
  add_board(&player, mode, index);
  create_log(&player, index, (&player)->name);


  printf(
  "  		</div>\n"
  "		</div>\n"
  "	</body>\n"
  "</html>\n"
  );

//  hide_ships(player);

}

void build_map(Players *player, char *name)
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

 //hide_ships(player);
}


void init_game() {
  Players player1, player2;

  get_log(&player1, 0);
  get_log(&player2, 1);

  draw_board(2, player1, player2);

}
