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

void buildPlayer(Players *player, Players *player2);
void buildIA(Players *player);

#endif
