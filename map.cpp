#include <fstream>
#include <ncurses.h>
#include "map.hpp"
#include "tile.hpp"
#include <cstdio>
#include <stdexcept>
#include "exception.hpp"
#include <iostream>
#include "game.hpp"
#include "position.hpp"

namespace cprogame {

Map::Map(Game * _game_ptr) :
		meta_door(10),
		game_ptr(_game_ptr),
		doors(std::vector<std::shared_ptr<Door> >()),
		tiles(std::vector<std::vector<std::shared_ptr<Tile> > >()),
		player_pos(Position()) {
}

void Map::load(const std::string & path) {

	tiles.clear();
	game_ptr->items.clear();

	std::ifstream file_stream(path, std::ifstream::in);
	for (std::string line; std::getline(file_stream, line);) {
		if(line[0] == '$'){
			if(line[1]<'1' || line[1]>'9'){
				std::string error_msg = "Bad map meta data: \n\t"+line;
				exit(1);
//				throw Exception(error_msg.c_str());
			}
			//Very ugly implicit conversion, but very safe
//			std::cerr << "debug: " << line << std::endl;
			meta_door.at(0).assign(line.substr(3));
		}else{
			tiles.push_back(std::vector<std::shared_ptr<Tile> >());
			for (unsigned int i = 0; i < line.size(); ++i) {
				switch (line[i]) {
				case 'T':
					game_ptr->items.push_back(std::make_pair(Position(i, tiles.size()-1), std::make_shared<Treasure>(game_ptr)));
					tiles[tiles.size() - 1].push_back(std::make_shared<Tile>(Tile::GROUND));
					break;
				case 'P':
					game_ptr->items.push_back(std::make_pair(Position(i, tiles.size()-1), std::make_shared<Potion>(game_ptr)));
					tiles[tiles.size() - 1].push_back(std::make_shared<Tile>(Tile::GROUND));
					break;
				case 'K':
					game_ptr->items.push_back(std::make_pair(Position(i, tiles.size()-1), std::make_shared<Key>(game_ptr)));
					tiles[tiles.size() - 1].push_back(std::make_shared<Tile>(Tile::GROUND));
					break;
				case '@':
					player_pos.set_pos(i, tiles.size()-1);
					/* no break */
				case ' ':
					tiles[tiles.size() - 1].push_back(std::make_shared<Tile>(Tile::GROUND));
					break;
				case '#':
					tiles[tiles.size() - 1].push_back(std::make_shared<Tile>(Tile::WALL));
					break;
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
				case '7':
				case '8':
				case '9':
					auto door_ptr = std::make_shared<Door>(meta_door[line[i]-'1']);
					tiles[tiles.size() - 1].push_back(door_ptr);
					doors.push_back(door_ptr);
					break;
				}
			}
		}
	}

	file_stream.close();
}

std::shared_ptr<Tile> Map::get_tile(const unsigned int & x,
		const unsigned int & y) const {
	return tiles[y][x];
}

const Door & Map::get_door(const unsigned int & x,
			const unsigned int & y) const {
	if(tiles[y][x]->get_type() != Tile::DOOR)
		throw Exception("Srsly? Ain't no door here...");
	return *static_cast<Door *>(tiles[y][x].get());
}

std::vector<std::shared_ptr<Door> > & Map::get_doors(){
	return doors;
}

Position Map::get_player_pos(){
	return player_pos;
}

void Map::print() const {
	move(0, 0);
	for (auto & line : tiles) {
		for (auto & tile : line) {
			printw("%c", tile->get_type());
		}
		printw("\n");
	}
}

} // cprogame
