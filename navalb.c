/*
 * navalb is a game developed in C
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
//#include <time.h>
#include "libraries/board.h"
#include "libraries/definitions.h"

int main(int argc, char *argv[])
{
    Players player1, player2;
    int players, i, j;

    //srand((unsigned) time(NULL));
    system(CLEAR);
    //CleanMap(&player1);
    //CleanMap(&player2);
    //DrawBoard(player1, player2);

    printf("Welcome to %s version %.2f\n", argv[0], VERSION);
    do {
      printf("Please, select the number of players(1/2): ");
      scanf("%d", &players);
      if (players < 1 || players > 2)
        printf("Ok, you must choose one or two players, try again.\n");
    } while (players < 1 || players > 2);

    if (players == 1) {
      buildPlayer(player1);
      buildIA(player2);
    } else {
      buildPlayer(player1);
      buildPlayer(Player2);
    }



    memset(player1.map, WATER, MAP_SIZE * MAP_SIZE * sizeof(char));

    return 0;
}
