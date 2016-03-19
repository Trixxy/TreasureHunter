#ifndef _CPROG_POTION_HPP_
#define _CPROG_POTION_HPP_

#include <memory>
#include "item.hpp"
#include "game.hpp"

namespace cprogame{

class Potion : public Item{
public:
	Potion(Game * _game_ptr);
	/**
	 * Uses the item
	 */
	virtual void use();
};

} // namespace cprogame

#endif
