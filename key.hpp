#ifndef _CPROG_KEY_HPP_
#define _CPROG_KEY_HPP_

#include <memory>
#include "item.hpp"
#include "game.hpp"

namespace cprogame{

class Key : public Item{
public:

	Key(Game * _game_ptr);

	/**
	 * Uses the item
	 */
	virtual void use();
};

} // namespace cprogame

#endif
