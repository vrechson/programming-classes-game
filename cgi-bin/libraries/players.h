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
#include "web_content.h"

/*
 *	Protypes
 ***********************************************************************/
void build_player(int mode, int index, char name[]);
void build_ai(Players *player,  char *name);
void get_log(Players *player, int n); /* get player logs */
void create_log(Players *player, int n, char name[]); /* write player logs */
void build_map(Players *player, char *name); /* generate a random map */

#endif
