/*
 * This file must contain all functions game board related.
 */

/*
 *	Libraries
 ***********************************************************************/
#ifndef _BOARD_H_
#define _BOARD_H_

#include "definitions.h"
#include "web_content.h"

/*
 *	Prototypes
 ***********************************************************************/
void draw_map(Players *player); /* draw a single map on screen */
void init_map(Players *player); /* initialize a user map */
void hide_ships(Players *player); /* hide user ships */
int check_pos(int x, int y, int height, int width, int rotation, int ia, Players *player); /* check disponibility of a position in the user map */
void pos_s(int x, int y, int height, int width, int rotation, char style, Players *player); /* allocate a position on the map */
int hit_pos(int index, int x, int y); /* attack a position */
void ai_hit_pos(); /* ai hit user positions */

#endif
