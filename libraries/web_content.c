/*
*	Libraries
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "web_content.h"
/*
*	FUnctions
***********************************************************************/
void dom_head()
{
  printf(

  "<!DOCTYPE html>\n"
  "<html>\n"
  "	<head>\n"
  "		<title>Batalha Naval</title>\n"
  "		<meta charset=\"UTF-8\">\n"
  "		<script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js\" integrity=\"sha384-0mSbJDEHialfmuBBQP6A4Qrprq5OVfW37PRR3j5ELqxss1yVqOtnepnHVP9aJ7xS\" crossorigin=\"anonymous\"></script>\n"
  "		<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css\" integrity=\"sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7\" crossorigin=\"anonymous\">\n"
  "		<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap-theme.min.css\" integrity=\"sha384-fLW2N01lMqjakBkx3l/M9EahuwpSfeNvV63J5ezn3uZzapT0u7EYsXMjQV+0En5r\" crossorigin=\"anonymous\">\n"
  "		<link rel=\"stylesheet\" type=\"text/css\" href=\"../css/navalb.css\">\n"
  "		<link href=\"https://maxcdn.bootstrapcdn.com/font-awesome/4.6.3/css/font-awesome.min.css\" rel=\"stylesheet\" integrity=\"sha384-T8Gy5hrqNKT+hzMclPo118YTQO6cYprQmhrYwIiQ/3axmI1hQomh7Ud2hPOy8SP1\" crossorigin=\"anonymous\">\n"
  "		<link href=\"http://fonts.googleapis.com/css?family=Lato:400,700\" rel=\"stylesheet\" type=\"text/css\">\n"
  "	</head>\n"

  );
}

void show_menu()
{

  dom_head();

  printf(

  "	<body id=\"menu\">\n"
  "		<div id=\"document-container\">\n"
  "			<div id=\"header-container\">\n"
  "				<h1 id=\"header-title\">Batalha naval</h1>\n"
  "			</div>\n"
  "			<div id=\"menu-container\">\n"
  "				<div id=\"header-menu\"></div>\n"
  "				<div id=\"buttons-container\">\n"
  "					<div id=\"single-player\" class=\"button-container\">\n"
  "           <a href=\"?build=single\">\n"
  "             <button type=\"sub\" class=\"button-dialog\" >Single Player</button>\n"
  "           </a>\n"
  "					</div>\n"
  "           <a href=\"?build=multi\">\n"
  "             <button type=\"sub\" class=\"button-dialog\" >Multi Player</button>\n"
  "           </a>\n"
  "					</div>\n"
  "				</div>\n"
  "			</div>\n"
  "		</div>\n"
  "	</body>\n"
  "</html>\n"

  );

}

void player_builder(Players *player)
{

  int i, j;

  dom_head();

  printf(

  "	<body id=\"mapa\">\n"
  "		<div id=\"document-container\">\n"
  "			<div id=\"header-container\">\n"
  "				<h1 id=\"header-title\"></h1>\n"
  "			</div>\n"
  "      <div id=\"board-container\">\n"
  "				<div id=\"map2\" class=\"ship-board\">\n"
  "					<div id=\"player2-name\" class=\"name-container\">\n"
  "						<div>\n"
  "	            <input id=\"Player2-input\" class=\"input-properties\" placeholder=\"Insira seu nome\" autocomplete=\"off\" type=\"text\"></input>\n"
  "							<button type=\"button\" class=\"button-dialog name-dialog\"><a class=\"fa fa-angle-right\"></a></button>\n"
  "						</div>\n"
  "						<div class=\"player-name\">\n"
  "							<span id=\"player2-span\"></span>\n"
  "						</div>\n"
  "          </div>\n"
  "          <div id=\"map-container\" class=\"map-container-box\">\n"
  "            <table>\n"
  "              <tr class=\"map-line map-letters\">\n"
  "                <td class=\"map-n coor\"></td>\n"
  "                <td class=\"map-n  coor\">A</td>\n"
  "                <td class=\"map-n  coor\">B</td>\n"
  "                <td class=\"map-n  coor\">C</td>\n"
  "                <td class=\"map-n  coor\">D</td>\n"
  "                <td class=\"map-n  coor\">E</td>\n"
  "                <td class=\"map-n  coor\">F</td>\n"
  "                <td class=\"map-n  coor\">G</td>\n"
  "                <td class=\"map-n  coor\">H</td>\n"
  "                <td class=\"map-n  coor\">I</td>\n"
  "                <td class=\"map-n  coor\">J</td>\n"
  "              </tr>\n"

  );

  for (i = 1; i <= MAP_SIZE; ++i) {
    printf(
    "              <tr class=\"map-line\">\n"
    "                <td class=\"map-n\">%d</td>\n", i
    );

    for (j = 1; j <= MAP_SIZE; ++j) {

      if (LEVEL && player->map[i - 1][j - 1].presentation != WATER && player->map[i - 1][j - 1].presentation != EMPTY) {

        if(player->map[i - 1][j - 1].isVisible) {
          printf(
          "                <td class=\"map-column orange\">%c</td>\n", SHOT
          );
        } else {
          printf(
          "                <td class=\"map-column\">%c</td>\n", WATER
          );
        }

      } else {

        if(player->map[i - 1][j - 1].isVisible) {
          printf(
          "                <td class=\"map-column orange\">%c</td>\n", player->map[i - 1][j - 1].presentation
          );
        } else {
          printf(
          "                <td class=\"map-column\">%c</td>\n", WATER
          );
        }

      }

    }

    printf(
    "              </tr>\n"
    );

  }

  printf(

  "            </table>\n"
  "          </div>\n"
  "					<div id=\"button233r243\" class=\"generate-map\">\n"
  "           <a href=\"?build=single\">\n"
  "					  	<button type=\"button\" class=\"button-dialog gen-map\">Gerar novo mapa</button>\n"
  "					</div>\n"
  "					<div id=\"button233r243\" class=\"generate-map\">\n"
  "						<button type=\"button\" class=\"button-dialog jogar\">Jogar</button>\n"
  "					</div>\n"
  "        </div>\n"
  "  		</div>\n"
  "		</div>\n"
  "	</body>\n"
  "</html>\n"

  );
}
