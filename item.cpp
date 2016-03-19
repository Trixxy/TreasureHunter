#include "item.hpp"

namespace cprogame{

	Item::~Item(){
		/* Nothing to clean */
	}

	Item::Item(Game * _game_ptr, const ITEM_TYPE  & _type, const std::string & _name)
		:game_ptr(_game_ptr),
		 type(_type),
		 name(_name){};

	/**
	 * Returns type of item.
	 */
	const Item::ITEM_TYPE & Item::get_type() const{
		return type;
	}

	/**
	 * Returns name of item.
	 */
	const std::string & Item::get_name() const{
		return name;
	}

} // cprogame
