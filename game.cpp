#include <chrono>
#include <thread>
#include <iostream>
#include "game.hpp"
#include "exception.hpp"

namespace cprogame{

// desired frame rate
typedef std::chrono::duration<int, std::ratio<1, 60>> frame_duration;

Game::Game():player_colored(false),
		items(std::vector<std::pair<Position, std::shared_ptr<Item> > >()),
		map(Map(this)), player(Position()){};

void Game::update(){
	input();
	// Update actors, and other updateables
}

void Game::render(){
	//print map
	move(0,0);
	map.print();

	// Print player
	move(player(Position::Y_POS), player(Position::X_POS));
	if(player_colored){

		attron(COLOR_PAIR(1));
	}
	printw(player_colored?"*":"@");

	attroff(COLOR_PAIR(1));

	for(auto i = items.begin(); i != items.end(); ++i){
		move(i->first(Position::Y_POS),i->first(Position::X_POS));
		printw(i->second->get_name().c_str());
	}

	/**
	 * TODO PRINT ACTORS HERE LATER.
	 */

	//refresh
	refresh();			/* Print it on to the real screen */
}

/**
 * Loads a map, sadly it is hardcoded atm.
 */
void Game::init(){
	game_over = false;

	map.load("resources/map1.cg");

	player = map.get_player_pos(); //Not hardcoded, very nice.

	//Very ful hack
//	MapItem item;
//
//	item.p = Position(4,4);
//
//	std::shared_ptr<Item> p(Key(this));
//	std::shared_ptr<Key>(this);
//	std::make_shared<Item>();
//	item.i =
//	items.push_back(item);

//	std::pair<Position, std::shared_ptr<Item> >;


	/* INITIALIZE NCURSES */
	initscr();
	start_color();
	init_pair(1, COLOR_RED,COLOR_BLACK);
	curs_set(0);
	keypad(stdscr, TRUE);
	/* END OF NCURSES INITIALIZATION*/
}

void Game::clean(){
	endwin(); /* End ncurses session */
}

void Game::player_move(const Position & new_pos){
	auto new_tile = map.get_tile(new_pos(Position::X_POS), new_pos(Position::Y_POS));
	if(!new_tile->is_blocking()){
		player = new_pos;

		for(auto i = items.begin(); i != items.end(); ++i){
			if(i->first == new_pos){
				i->second->use();
				items.erase(i);
				break;
			}
		}

		if(new_tile->get_type() == Tile::DOOR){
			auto door = map.get_door(new_pos(Position::X_POS), new_pos(Position::Y_POS));

			erase();

			map.load(door.get_path());
			player = map.get_player_pos(); //Not hardcoded, very nice.
		}
	}else if(new_tile->get_type() == Tile::DOOR){
		//TODO check if I have the key then....
		//inventory[at_some_index]->use(Tile::DOOR);
	}
}

void Game::input(){
	int key = getch();
	switch(key){
		case KEY_DOWN:
			player_move(Position(player(Position::X_POS), player(Position::Y_POS)+1));
			break;
		case KEY_UP:
			player_move(Position(player(Position::X_POS), player(Position::Y_POS)-1));
			break;
		case KEY_LEFT:
			player_move(Position(player(Position::X_POS)-1, player(Position::Y_POS)));
			break;
		case KEY_RIGHT:
			player_move(Position(player(Position::X_POS)+1, player(Position::Y_POS)));
			break;
		case 'Q': case 'q':
			game_over = true;
			break;
		default:
			break;
	}
}

using std::chrono::system_clock;

Map & Game::get_map(){
	return map;
}

void Game::run(){

	init();
	render();

	//while game is not over
	while(!game_over){
		// calculate frame time
//		auto start_time = std::chrono::steady_clock::now();
//		auto end_time = start_time + frame_duration(1);
		
		// UPDATE:
		// execute one step of actions
		update();

		// RENDER
		// re-render the state so that the actions executed above is visible
		render();

		// ask all actors for actions



		// get end time
//		std::this_thread::sleep_until(end_time);
	}
	
	clean();
}



}
