#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

# include "Brain.hpp"
# include "WrongAnimal.hpp"
# include <iostream>
# include <string>//std::string

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class WrongCat : public WrongAnimal
{
private:
	Brain*	_Brain;
public:
	WrongCat();//(init fixed point to 0) : _fixedpoint_value(0);
	WrongCat(const std::string& name);
	WrongCat(const WrongCat &other);
	WrongCat&	operator=(const WrongCat &other);
	~WrongCat();

	std::string	getType() const;
	void		makeSound() const;
};

#endif
