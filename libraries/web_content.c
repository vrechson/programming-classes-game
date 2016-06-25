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
void show_menu()
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

void player_builder()
{

  int i;

  printf("%s%c%c\n", "Content-Type:text/html;charset=iso-8859-1", 13, 10);

  printf(

  "<!DOCTYPE html>"
  "<html>"
  "	<head>"
  "		<title>Mapas</title>"
  "		<meta charset=\"UTF-8\">"
  "		<script src=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js\" integrity=\"sha384-0mSbJDEHialfmuBBQP6A4Qrprq5OVfW37PRR3j5ELqxss1yVqOtnepnHVP9aJ7xS\" crossorigin=\"anonymous\"></script>"
  "		<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css\" integrity=\"sha384-1q8mTJOASx8j1Au+a5WDVnPi2lkFfwwEAa8hDDdjZlpLegxhjVME1fgjWPGmkzs7\" crossorigin=\"anonymous\">"
  "		<link rel=\"stylesheet\" href=\"https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap-theme.min.css\" integrity=\"sha384-fLW2N01lMqjakBkx3l/M9EahuwpSfeNvV63J5ezn3uZzapT0u7EYsXMjQV+0En5r\" crossorigin=\"anonymous\">"
  "		<link rel=\"stylesheet\" type=\"text/css\" href=\"css/navalb.css\">"
  "		<link href=\"https://maxcdn.bootstrapcdn.com/font-awesome/4.6.3/css/font-awesome.min.css\" rel=\"stylesheet\" integrity=\"sha384-T8Gy5hrqNKT+hzMclPo118YTQO6cYprQmhrYwIiQ/3axmI1hQomh7Ud2hPOy8SP1\" crossorigin=\"anonymous\">"
  "		<link href='http://fonts.googleapis.com/css?family=Lato:400,700' rel='stylesheet' type='text/css'>"
  "	</head>"
  "	<body id=\"mapa\">"
  "		<div id=\"document-container\">"
  "			<div id=\"header-container\">"
  "				<h1 id=\"header-title\"></h1>"
  "			</div>"
  "      <div id=\"board-container\">"
  "				<div id=\"map2\" class=\"ship-board\">"
  "					<div id=\"player2-name\" class=\"name-container\">"
  "						<div>"
  "	            <input id=\"Player2-input\" class=\"input-properties\" placeholder=\"Insira seu nome\" autocomplete=\"off\" type=\"text\"></input>"
  "							<button type=\"button\" class=\"button-dialog name-dialog\"><a class=\"fa fa-angle-right\"></a></button>"
  "						</div>"
  "						<div class=\"player-name\">"
  "							<span id=\"player2-span\"></span>"
  "						</div>"
  "          </div>"
  "          <div id=\"map-container\" class=\"map-container-box\">"
  "            <table>"
  "              <tr class=\"map-line map-letters\">"
  "                <td class=\"map-n coor\"></td>"
  "                <td class=\"map-n  coor\">A</td>"
  "                <td class=\"map-n  coor\">B</td>"
  "                <td class=\"map-n  coor\">C</td>"
  "                <td class=\"map-n  coor\">D</td>"
  "                <td class=\"map-n  coor\">E</td>"
  "                <td class=\"map-n  coor\">F</td>"
  "                <td class=\"map-n  coor\">G</td>"
  "                <td class=\"map-n  coor\">H</td>"
  "                <td class=\"map-n  coor\">I</td>"
  "                <td class=\"map-n  coor\">J</td>"
  "              </tr>"

  );

  for (i = 1; i <= 10; ++i) {
    printf(
    "              <tr class=\"map-line\">"
    "                <td class=\"map-n\">%d</td>"
    "                <td class=\"map-column\"></td>"
    "                <td class=\"map-column\"></td>"
    "                <td class=\"map-column\"></td>"
    "                <td class=\"map-column\"></td>"
    "                <td class=\"map-column\"></td>"
    "                <td class=\"map-column\"></td>"
    "                <td class=\"map-column\"></td>"
    "                <td class=\"map-column\"></td>"
    "                <td class=\"map-column\"></td>"
    "                <td class=\"map-column\"></td>"
    "              </tr>", i
    );
  }

  printf(

  "            </table>"
  "          </div>"
  "					<div id=\"button233r243\" class=\"generate-map\">"
  "						<button type=\"button\" class=\"button-dialog gen-map\">Gerar novo mapa</button>"
  "					</div>"
  "					<div id=\"button233r243\" class=\"generate-map\">"
  "						<button type=\"button\" class=\"button-dialog jogar\">Jogar</button>"
  "					</div>"
  "        </div>"
  "  		</div>"
  "		</div>"
  "	</body>"
  "</html>"

  );
}
