/*
 * This file must contain all functions related to the game board construction.
 */

/*
 *	Libraries
 ***********************************************************************/
#ifndef _BOARD_H_
#define _BOARD_H_

#include "definitions.h"
//hahaha
void DrawBoard(Players *player1, Players *player2);
void InitializeMap(Players *player1, Players *player2);
int Letter2Num(int *x);
int CheckDisponibility(int *x, int y, int height, int width, Players *player);
int Positioning(int x, int y, int height, int width, char style, Players *player);


#endif
