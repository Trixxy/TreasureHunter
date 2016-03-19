#include <cmath>
#include "position.hpp"

namespace cprogame{

/**
 * Default constructor, initialized to (0,0)
 */
Position::Position():x(0),y(0){}

/**
 * Constructor that initilize position to (x, y)
 */
Position::Position(const unsigned & _x, const unsigned & _y):x(_x),y(_y){}

/**
 * Resets position to the specified values
 */
void Position::set_pos(const unsigned & _x, const unsigned & _y){
	x = _x;
	y = _y;
}


/**
 * Returns the manhattan distance between two positions.
 */
unsigned int Position::operator-(const Position & other){
	return std::abs(x-other.x)+std::abs(y-other.y);
}

/**
 * Returns a modifier to the specified position parameter.
 */ 
unsigned int & Position::operator()(const POS_DIM & pd){
	return pd?y:x;
}

/**
 * Accessor to the specified position parameter.
 */
const unsigned int & Position::operator()(const POS_DIM & pd) const{
	return pd?y:x;
}

bool Position::operator==(const Position & other){
	return x == other.x && y == other.y;
}

} //namespace cprogame
