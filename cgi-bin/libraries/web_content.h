/*
 * This file must contain all functions game board related.
 */

/*
 *	Libraries
 ***********************************************************************/
#ifndef _WEB_CONTENT_H_
#define _WEB_CONTENT_H_

#include <stdarg.h>
#include "definitions.h"
#include "board.h"
/*
 *	Prototypes
 ***********************************************************************/
void dom_head();
void show_menu();
void add_board(Players *player, int mode, int index, int link);
void draw_board();
void we_have_a_winner();
#endif
