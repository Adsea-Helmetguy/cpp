#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <string>//std::string

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class WrongCat : public WrongAnimal
{
protected:

public:
	WrongCat();//(init fixed point to 0) : _fixedpoint_value(0);
	WrongCat(const std::string& name);
	virtual ~WrongCat();

	std::string	getType() const;
};

#endif
