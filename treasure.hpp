#ifndef _CPROG_TREASURE_HPP_
#define _CPROG_TREASURE_HPP_

#include <memory>
#include "item.hpp"
#include "game.hpp"

namespace cprogame{

class Treasure : public Item{
public:

	Treasure(Game * _game_ptr);

	/**
	 * Uses the item
	 */
	virtual void use();
};

} // namespace cprogame

#endif
