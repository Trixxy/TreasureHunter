#ifndef _CPROG_ACTOR_HPP_
#define _CPROG_ACTOR_HPP_

#include <vector>
#include <memory>
#include "item.hpp"
#include "position.hpp"

namespace cprogame{

class Actor{
	Position pos;
	std::string name;
//	std::vector<std::shared_ptr<Item> > inventory;

public:
	Actor();

};

} // namespace cprogame

#endif
