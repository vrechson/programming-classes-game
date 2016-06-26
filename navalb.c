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
  enum modes { MODE1 = 1, MODE2 };

  srand((unsigned) time(NULL));

  printf("%s%c%c\n", "Content-Type:text/html;charset=iso-8859-1", 13, 10);

//    init_map(&player1);
//    init_map(&player2);
//    init_map(&player3);
//    init_map(&player4);

    query = getenv("QUERY_STRING");
    if ((sscanf(query, "player=%d&posx=%d&posy=%d", &n, &x, &y)) == 3) {
      for (i = 0; i < 3; i++);
    } else if (sscanf(query, "mode=%d&build=%d&name=%49[^\n]s", &players, &curr, name) >= 2) {
      if(name == NULL) {
        strcpy(name, "player");
      }
      if (players == 1) {
        if(curr == PLAYER1) {
          build_player(MODE1, PLAYER1, name);
        } else {
          show_menu();
        }
      } else if (players == 2) {
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
    } else {
      show_menu();
    }
    return 0;




  return 0;
}
