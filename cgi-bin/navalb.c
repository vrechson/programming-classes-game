/*
 * navalb is a game developed in C as part of algorithm classes
 *
 * The point of the game is guess positions (e.g. A-12, or C-1) looking for parts of the enemy ships
 * the user that discover first all the ships parts of his enemy win the game.
 */

/*
 *	Libraries
 ***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libraries/board.h"
#include "libraries/players.h"
#include "libraries/definitions.h"
#include "libraries/web_content.h"

/*
 *	Main
 ***********************************************************************/
int main(int argc, char *argv[])
{

  int players, curr, x, y, n, i;
  char name[50], *query;
  enum users { PLAYER1, PLAYER2 };
  enum modes { MODE1 = 1, MODE2, MODE3, MODE4, MODE5 };
  Players player1;

  srand((unsigned) time(NULL));

  printf("%s%c%c\n", "Content-Type:text/html;charset=iso-8859-1", 13, 10);
  query = getenv("QUERY_STRING");
//query = "mode=3";
//init_game();
  if ((sscanf(query, "mode=%d", &n) == 1 && (n == MODE5))) {
    we_have_a_winner();
  } else if ((sscanf(query, "mode=%d&player=%d&posx=%d&posy=%d", &n, &curr, &x, &y) == 4 && (n == MODE3 || n == MODE4))) {
    hit_pos(curr, x, y);
    draw_board();
  } else if (sscanf(query, "mode=%d&build=%d&name=%49[^\n]s", &players, &curr, name) >= 2) {
    if(name == NULL) {
      strcpy(name, "player");
    }
    if (players == MODE1) {
      if(curr == PLAYER1) {
        build_player(MODE1, PLAYER1, name);
      } else {
        show_menu();
      }
    } else if (players == MODE2) {
      if(curr == PLAYER1) {
        build_player(MODE2, PLAYER1, name);
      } else if (curr == PLAYER2) {
        build_player(MODE2, PLAYER2, name);
      } else {
        show_menu();
      }
    } else {
      show_menu();
    }
  } else if (sscanf(query, "mode=%d", &n) && (n == MODE3 || n == MODE4)) {
    init_game();
  } else {
    show_menu();
  }




  return 0;
}
