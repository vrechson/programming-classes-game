/*
 * This file must contain all functions game board related.
 */

/*
 *	Libraries
 ***********************************************************************/
#ifndef _BOARD_H_
#define _BOARD_H_

#include "definitions.h"

/*
 *	Prototypes
 ***********************************************************************/
void draw_board(Players *player1, Players *player2); /* draw entire board on screen */
void draw_map(Players *player); /* draw a single map on screen */
void init_map(Players *player); /* initialize a user map */
void hide_ships(Players *player); /* hide user ships */
void create_log(Players *player, int n, char name[]);
int carac_2_num(char x); /* return 0 for A, 1 for B, 2 for C and so on.. */
int check_pos(int x, int y, int height, int width, int rotation, int ia, Players *player); /* check disponibility of a position in the user map */
void pos_s(int x, int y, int height, int width, int rotation, char style, Players *player); /* allocate a position on the map */
int hit_pos(int x, int y, Players *player); /* attack a position */
int ai_hit_pos(Players *player); /* attack a position with AI */

#endif
