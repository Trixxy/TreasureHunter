#include "tile.hpp"

namespace cprogame{

Tile::Tile(const TYPE & _type):type(_type){}

const Tile::TYPE & Tile::get_type() const{
	return type;
}

/**
 * TODO, hardcoded, may be passed as a parameter in map meta data.
 */
bool Tile::is_blocking() const {
	return type == WALL;
}

Door::Door(const std::string & _path):Tile(Tile::DOOR), path(_path), state(LOCKED){}

bool Door::is_locked() const {
	return state == LOCKED;
}

bool Door::is_blocking() const{
	return is_locked();
}

void Door::lock(){
	state = LOCKED;
}

void Door::unlock(){
	state = UNLOCKED;
}

std::string Door::get_path() const{
	return path;
}

} // namespace cprogame
