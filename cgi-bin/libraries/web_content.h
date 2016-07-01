/*
 * This file must contain all functions around document object view building.
 */

/*
 *	Libraries
 ***********************************************************************/
#ifndef _WEB_CONTENT_H_
#define _WEB_CONTENT_H_

#include "definitions.h"
#include "board.h"
#include "players.h"

/*
 *	Prototypes
 ***********************************************************************/
void dom_head(); /* html page head */
void show_menu(); /* displays initial page */
void add_board(Players *player, int mode, int index, int link); /* displays player board on screen */
void draw_board(); /* draw gameboard on screen */
void we_have_a_winner(); /* displayer winner screen */

#endif
