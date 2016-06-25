/*
 * This file must contain all functions related to the game player construction and manuitence.
 */

/*
 *	Libraries
 ***********************************************************************/
#ifndef _PLAYERS_H_
#define _PLAYERS_H_

#include <stdarg.h>
#include "definitions.h"
#include "board.h"
#include "web_content.h"

/*
 *	Protypes
 ***********************************************************************/
void build_game(int args, ...);
void build_ai(Players *player,  char *name);
Players *guess_eng(Players *player1, Players *player2, int ia);

#endif
