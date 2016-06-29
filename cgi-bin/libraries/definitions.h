/*
 * This file must contain all definitions concerning general configuration of the game.
 */

#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

/*
 *	Definitions
 ***********************************************************************/
/* ship configurations */
#define SUBMARINE 4 // 1 slot
#define BATTLESHIP 3 // 4 slot
#define CRAISER 3 // 2 slot
#define DESTROYER 2 // 4 slot
#define AIRCRAFT 1 // 5 slot

#define TOTAL_SLOTS ((SUBMARINE ) + (BATTLESHIP * 4) + (CRAISER * 2) + (DESTROYER * 4) + (AIRCRAFT * 5))

/* map settings */
#define LEVEL 0 // 0 - easy, 1 - hard
#define SHOW_MAP 1 // define if will show map when positioning a ship
#define MAP_SIZE 10 // size of the map
#define WATER 'X'
#define SHOT 'O'
#define EMPTY '*'
#define AI_NAME "Mr. Robot"

/* OS configurations */
#ifdef __unix__
  #define CLEAR "clear"
#elif defined(_WIN32) || defined(WIN32)
  #define CLEAR "cls"
#endif

#define VERSION 1.02

/*
 *	Types
 ***********************************************************************/
/* game types */

typedef struct {
  char presentation;
  int isVisible;
} board;

typedef struct Players {
    char name[50];
    int score;
    board map[MAP_SIZE][MAP_SIZE];
} Players;

#endif
