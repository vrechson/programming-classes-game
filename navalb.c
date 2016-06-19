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
#include "libraries/definitions.h"
#include "libraries/players.h"

/*
 *	Main
 ***********************************************************************/
int main(int argc, char *argv[])
{
  Players player1, player2, *winner;
  int players;

  srand((unsigned) time(NULL));
  // hi everyone
  system(CLEAR);
  InitializeMap(&player1);
  InitializeMap(&player2);
  DrawBoard(&player1, &player2);

  printf("Bem vindo ao %s, versão %.2f\n\n", argv[0], VERSION);

  do {
    printf("\n\nPor favor, escolha o número de jogadores[1/2]: ");
    scanf(" %d", &players);
    if (players < 1 || players > 2)
      printf("Você deve escolher entre um ou dois jogaroes, tente de novo.\n");
  } while (players < 1 || players > 2);

  if (players == 1) {
  //  buildPlayer(&player1);
    buildIA(&player2);
    DrawBoard(&player1, &player2);
    DrawBoard(&player1, &player2);
    winner = guessEngine(&player1, &player2, 1);
  } else {
    buildPlayer(&player1);
    buildPlayer(&player2);
    DrawBoard(&player1, &player2);
    winner = guessEngine(&player1, &player2, 0);
  }

  printf(" %s ganhou o jogo! deseja jogar novamente? (y/n)", winner->name);
  return 0;
}
