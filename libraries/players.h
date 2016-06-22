/*
 * This file must contain all functions related to the game player construction and manuitence.
 */

/*
 *	Libraries
 ***********************************************************************/
#ifndef _PLAYERS_H_
#define _PLAYERS_H_

#include "definitions.h"
#include "board.h"

/*
 *	Protypes
 ***********************************************************************/
void buildPlayer(Players *player);
void buildIA(Players *player,  char *name);
Players *guessEngine(Players *player1, Players *player2, int ia);

#endif
