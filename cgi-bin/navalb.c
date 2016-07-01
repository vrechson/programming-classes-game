/*
 * navalb is a game developed in C as part of algorithm classes
 *
 * The point of the game is guess positions (e.g. A-12, or C-1) looking for parts of the enemy ships
 * the user that discover first all the ships parts of his enemy win the game.
 */

/*
 *	Libraries
 ***********************************************************************/
#include <stdio.h> /* i/o */
#include <stdlib.h> /* srand */
#include <string.h> /* string functions */
#include <time.h> /* time */
#include "libraries/board.h" /* game board related */
#include "libraries/players.h" /* players related */
#include "libraries/web_content.h" /* displays content in html */
#include "libraries/definitions.h" /* some general definitions */

/*
 *	Main
 ***********************************************************************/
int main(int argc, char *argv[])
{

  /* define main variables */
  int players, curr, x, y, n, i;
  char name[50], *query;
  enum users { PLAYER1, PLAYER2 };
  enum modes { MODE1 = 1, MODE2, MODE3, MODE4, MODE5 };
  Players player1;

  /* define rand seed */
  srand((unsigned) time(NULL));

  /* define http header */
  printf("%s%c%c\n", "Content-Type:text/html;charset=iso-8859-1", 13, 10);

  /* get enviroment parameters */
  query = getenv("QUERY_STRING");

  /* control game flow */
  if ((sscanf(query, "mode=%d", &n) == 1 && (n == MODE5))) {
    we_have_a_winner(); /* someone won the game */
  } else if ((sscanf(query, "mode=%d&player=%d&posx=%d&posy=%d", &n, &curr, &x, &y) == 4 && (n == MODE3 || n == MODE4))) {
    hit_pos(curr, x, y); /* take a guess */
    if (n == MODE4)
      ai_hit_pos(); /* ai also is playing */
    draw_board(); /* show the game */
  } else if (sscanf(query, "mode=%d&build=%d&name=%49[^\n]s", &players, &curr, name) >= 2) {
    if(name == NULL)
      strcpy(name, "player");

    if (players == MODE1) { /* man vs. machine */
      if(curr == PLAYER1) {
        build_player(MODE1, PLAYER1, name); /* build player scope */
      } else {
        show_menu(); /* wrong page */
      }
    } else if (players == MODE2) { /* man vs. man */
      if(curr == PLAYER1) {
        build_player(MODE2, PLAYER1, name);
      } else if (curr == PLAYER2) {
        build_player(MODE2, PLAYER2, name);
      } else {
        show_menu();
      }
    } else {
      show_menu();
    }
  } else if (sscanf(query, "mode=%d", &n) && (n == MODE3 || n == MODE4)) {
    draw_board();
  } else {
    show_menu();
  }

  return 0;
}
