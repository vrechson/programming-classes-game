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
  Players player1, player2, player3, player4;
  int players;
  char answer = 'y', *get_p, arg[100];

  srand((unsigned) time(NULL));

  printf("%s%c%c\n", "Content-Type:text/html;charset=iso-8859-1", 13, 10);

    init_map(&player1);
    init_map(&player2);
    init_map(&player3);
    init_map(&player4);

    get_p = getenv("QUERY_STRING");

    if (sscanf(get_p, "build=%s", arg) == 1) {
      if(strcmp(arg, "single")) {
        build_game(1, &player1);
      } else if (strcmp(arg, "two")) {
        build_game(2, &player1, &player2);
      } else if (strcmp(arg, "three")) {
        build_game(3, &player1, &player2, &player3);
      } else if (strcmp(arg, "multi")) {
        build_game(4, &player1, &player2, &player3, &player4);
      } else {
        show_menu();
      }
    } else {
      show_menu();
    }
    return 0;




  return 0;
}
