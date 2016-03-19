#include "potion.hpp"

namespace cprogame{

Potion::Potion(Game * _game_ptr):Item(_game_ptr, Item::POTION, "P"){
}

void Potion::use(){
	game_ptr->player_colored = !game_ptr->player_colored;
}

} // namespace cprogame
