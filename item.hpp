#ifndef _CPROG_ITEM_HPP_
#define _CPROG_ITEM_HPP_

#include <string> 
#include <memory>

namespace cprogame{

class Game; //forward reference

class Item{
public:
	enum ITEM_TYPE{
		KEY = 1,
		POTION = 2,
		TREASURE = 3
	};
protected:
	ITEM_TYPE type;
	std::string name;
	Game * game_ptr;
	Item(Game *, const ITEM_TYPE  &, const std::string &);
public:

	virtual ~Item();

	/**
	 * Uses the item
	 */
	virtual void use() = 0;

	/**
	 * Returns type of item.
	 */
	const ITEM_TYPE & get_type() const;

	/**
	 * Returns name of item.
	 */
	const std::string & get_name() const;

};

} // namespace cprogame

#endif
