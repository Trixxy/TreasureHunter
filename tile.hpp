#ifndef _CPROG_TILE_HPP_
#define _CPROG_TILE_HPP_

#include <string>

namespace cprogame{

class Tile{
public:
	enum TYPE{
		WALL = '#',
		GROUND = ' ',
		DOOR = '|'
	};
private:
	TYPE type;

public:
	Tile(const TYPE &);

	const TYPE & get_type() const;
	virtual bool is_blocking() const;

}; //class Map

/**
 * TODO Should be taken out to a separate impl from defs.
 */
class Door : public Tile{
public:
	enum STATE{
		LOCKED = 1,
		UNLOCKED = 2
	};
private:
	std::string path;
	STATE state;
public:
	Door(const std::string & _path);

	bool is_locked() const;

	virtual bool is_blocking() const;

	void lock();

	void unlock();

	std::string get_path() const;
};

} // namespace cprogame

#endif
