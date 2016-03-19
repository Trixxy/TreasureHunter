#ifndef _CPROG_POSITION_HPP_
#define _CPROG_POSITION_HPP_

namespace cprogame{

class Position{
	unsigned int x, y;

public:
	/**
	 * Enumeration of the dimentions in this position.
	 * Namely, X and Y dimentions
	 */
	enum POS_DIM{
		X_POS = 0,
		Y_POS = 1
	};

	/**
	 * Default constructor, initialized to (0,0)
	 */
	Position();

	/**
	 * Constructor that initilize position to the specified parameters
	 */
	Position(const unsigned &, const unsigned &);

	/**
	 * Resets position to the specified values
	 */
	void set_pos(const unsigned &, const unsigned &);

	/**
	 * Returns the manhattan distance between two positions.
	 */
	unsigned int operator-(const Position &);

	/**
	 * Returns a modifier to the specified position parameter.
	 */ 
	unsigned int & operator()(const POS_DIM &);

	/**
	 * Accessor to the specified position parameter.
	 */
	const unsigned int & operator()(const POS_DIM &) const;

	bool operator==(const Position &);

}; // class position

} // namespace cprogame

#endif
