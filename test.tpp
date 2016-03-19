#include <string>
#include <iostream>
#include <ncurses.h>
#include "position.hpp"

void read_in_map(){


	// for (std::string line; std::getline(std::cin, line); ){
	// 	map.push_back(std::vector<unsigned char>());
	// 	maxw = std::max(line.size(), maxw);
	// 	y_cache = map.size()-1;
	// 	for (unsigned char c : line) {
	// 		switch(c) {
	// 			case '@':
	// 				playerpos = Pos(map[y_cache].size(), y_cache);
	// 				map[y_cache].push_back(Map::EMPTY);
	// 				break;
	// 			case '$':
	// 				boxes.push_back(Pos(map[y_cache].size(), y_cache));
	// 				map[y_cache].push_back(Map::EMPTY);
	// 				break;
	// 			case ' ':
	// 				map[y_cache].push_back(Map::EMPTY);
	// 				break;
	// 			case '#':
	// 				map[y_cache].push_back(Map::WALL);
	// 				break;
	// 			case '+':
	// 				playerpos = Pos(map[y_cache].size(), y_cache);
	// 				map[y_cache].push_back(Map::GOAL);
	// 				break;
	// 			case '*':
	// 				boxes.push_back(Pos(map[y_cache].size(), y_cache));
	// 				map[y_cache].push_back(Map::GOAL);
	// 				break;
	// 			case '.':
	// 				map[y_cache].push_back(Map::GOAL);
	// 				break;
	// 			default:
	// 				exit(1);
	// 				break;
	// 		}
	// 	}
	// }
}


int main()
{	

	std::string map[] = {
		"#####################",
		"#                   #",
		"#                   #",
		"#                   #",
		"#                   #",
		"#                   #",
		"#                   #",
		"#                   #",
		"#####################"
	};

	bool game_over = false;
	int x = 5, y = 5;

	initscr();			/* Start curses mode 		  */
	curs_set(0);
	keypad(stdscr, TRUE);

	for(int i = 0; i < 9; i++)
		printw("%s\n", map[i].c_str());


	while(!game_over){
		move(y, x);
		printw("@");

		refresh();			/* Print it on to the real screen */

		int key = getch();			/* Wait for user input */
		move(y, x);
		printw(" ");
		switch(key){
			case KEY_DOWN:
				y++;
				break;
            case KEY_UP:
            	y--;
            	break;
            case KEY_LEFT:
            	x--;
            	break;
            case KEY_RIGHT:
            	x++;
            	break;
            case 'Q': case 'q':
            	game_over = true;
            	break;
            default:
            	break;
		}
	}
	endwin();			/* End curses mode		  */

	return 0;
}