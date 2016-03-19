#ifndef _CPROG_MAP_HPP_
#define _CPROG_MAP_HPP_

#include <vector>
#include <string>
#include "tile.hpp"
#include "position.hpp"
#include <memory>
#include <cstdlib>

namespace cprogame{

class Game; //forward reference


class Map{
	std::vector<std::string> meta_door;
	std::vector<std::shared_ptr<Door> > doors;
	Position player_pos;

	Game * game_ptr;
public:
	std::vector<std::vector<std::shared_ptr<Tile> > > tiles;
	/**
	 * Default constructor
	 */
	Map(Game * _game_ptr);

	/**
	 * Loads map from file.
	 */
	void load(const std::string &);

	/**
	 * Renders the map to screen
	 */
	void print() const;

	std::shared_ptr<Tile> get_tile(const unsigned int &, const unsigned int &) const;
	const Door & get_door(const unsigned int &, const unsigned int &) const;

	std::vector<std::shared_ptr<Door> > & get_doors();

	Position get_player_pos();

}; // class Map

} // namespace cprogame

#endif
