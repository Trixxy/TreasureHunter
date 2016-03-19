#include "treasure.hpp"

namespace cprogame{

Treasure::Treasure(Game * _game_ptr):Item(_game_ptr, Item::TREASURE, "T"){

}

void Treasure::use(){
	game_ptr->game_over = true;
}

} // namespace cprogame
