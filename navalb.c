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
  Players player1, player2, *winner;
  int players;
  char answer = 'y', *get_p, arg[100];

  srand((unsigned) time(NULL));

  printf("%s%c%c\n", "Content-Type:text/html;charset=iso-8859-1", 13, 10);

  while (answer == 'y' || answer == 'Y') {
    //system(CLEAR);
    init_map(&player1);
    init_map(&player2);
    //draw_board(&player1, &player2);

    //printf("Bem vindo ao %s, versão %.2f\n\n", argv[0], VERSION);
    show_menu();
    get_p = getenv("QUERY_STRING");

    if (sscanf(get_p, "build=%s", arg) == 1) {
      if(strcmp(get_p, "single")) {
        build_player(&player1);
    //    build_ai(&player2);
      } else if (strcmp(get_p, "multi")) {
        build_player(&player1);
    //    build_player(&player2, AI_NAME);
      }
    }
    return 0;

    if (players == 1) {
      build_player(&player1);
      build_ai(&player2, "Mr. Robot");
      draw_board(&player1, &player2);
      winner = guess_eng(&player1, &player2, 1);
    } else {
      build_player(&player1);
      build_player(&player2);
      draw_board(&player1, &player2);
      winner = guess_eng(&player1, &player2, 0);
    }

    answer = 'j';
    printf("%s ganhou o jogo!\n\n", winner->name);
    while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N') {
      printf("deseja jogar novamente? (y/n): ");
      scanf(" %c", &answer);
    }
  }

  return 0;
}
