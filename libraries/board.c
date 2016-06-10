#include "definitions.h"
#include "board.h"

void DrawBoard(Players Player1, Players Player2)
{
    int i, j, k, n1;
    char n2;
    printf("    ");

    for (j = 0, n2 = 'A'; j < (2 * MAP_SIZE); n2++, j++) {
     printf(" %c ", n2);

        if (j == (MAP_SIZE - 1)) {
            printf("\t   ");
            n2 = '@';
        }
    }

    for (i = 0, n1 = 1; i < MAP_SIZE; i++, n1++) {
        printf("\n %2d ", n1);
        for (j = 0; j < MAP_SIZE; j++) {
            printf(" %c ", map1[i][j]);
            if (j == (MAP_SIZE - 1)) {
                printf("\t%2d ", n1);
                for (k = 0; k < MAP_SIZE; k++)
                    printf(" %c ", map2[i][k]);
            }
        }
    }
    printf("\n");

}
