#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << RED << "WrongCat Default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const std::string& name) : WrongAnimal(name)
{
	std::cout << RED << "WrongCat class with std::string& name constructor called" \
	<< RESET << std::endl;
	std::cout << RED << "WrongCat class's type is called: " \
	<< RESET << this->type << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Deconstructor called for: " << this->type << std::endl;
}

//
//
//
//New function added!
std::string	WrongCat::getType(void) const
{
	return(this->type);
}