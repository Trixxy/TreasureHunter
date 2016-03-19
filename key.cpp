#include "key.hpp"

namespace cprogame{

Key::Key(Game * _game_ptr):Item(_game_ptr, Item::KEY, "K"){
}

void Key::use(){
	for(auto door : game_ptr->get_map().get_doors()){
		door->unlock();
	}
}

} // namespace cprogame
