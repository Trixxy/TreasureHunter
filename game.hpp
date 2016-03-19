#ifndef _CPROG_GAME_HPP_
#define _CPROG_GAME_HPP_

#include <vector>
#include <tuple>
#include <ncurses.h>
#include <memory>
#include "actor.hpp"
#include "item.hpp"
#include "key.hpp"
#include "potion.hpp"
#include "treasure.hpp"
#include "map.hpp"
#include "position.hpp"

namespace cprogame{

class Game{
//	std::vector<Actor> actors;
	Map map;
	Position player; //Actually should be a player object, but just pos atm. TODO

	void update();
	void render();

	void init();
	void clean();
	void input();

	void player_move(const Position &);


public:
	std::vector<std::pair<Position, std::shared_ptr<Item> > > items;
	bool game_over;
	bool player_colored;
	Game();
	void run();

	Map & get_map();

}; // class Game

} // namespace cprogame

#endif
