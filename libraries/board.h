/*
 * This file must contain all functions related to the game board construction.
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
void DrawBoard(Players *player1, Players *player2);
void DrawMap(Players *player);
void InitializeMap(Players *player);
void HideThings(Players *player);
int Letter2Num(int *x);
int CheckDisponibility(int *x, int y, int height, int width, int rotation, int ia, Players *player);
void Positioning(int x, int y, int height, int width, int rotation, char style, Players *player);

#endif
