/*
 * This file must contain all definitions concerning general configuration of the game.
 */

/* ship configurations */
#define SUBMARINE 4 // 1 slot
#define BATTLESHIP 3 // 4 slot
#define CRAISER 3 // 2 slot
#define DESTROYER 2 // 4 slot
#define AIRCRAFT 1 // 5 slot

#define TOTAL_SHIPS (SUBMARINE + BATTLESHIP + CRAISER + DESTROYER + AIRCRAFT)

/* map settings */
#define LEVEL 0 // 0 - easy, 1 - hard
#define MAP_SIZE 10 // size of the map
#define WATER 'X'
#define EMPTY '.'

/* game types */
typedef struct {
    int id;
    int type;
    int width;
    int height;
    int x;
    int y;
    int rotation;
    char style;
    int status;
} ship;

typedef struct Players {
    char name[30];
    char MAP[MAP_SIZE][MAP_SIZE];
    ship boats[TOTAL_SHIPS];
} Players;
