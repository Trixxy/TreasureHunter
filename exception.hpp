#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <exception>

/**
 * This class just extends the exception class from the std with a msg field
 * for easier bug hunting!
 */

class Exception: public std::exception {
	const char * msg;
	Exception() = delete;
public:
	Exception(const char * s) throw() : msg(s) {}
	const char * what() const throw () {
		return msg;
	}
};

#endif