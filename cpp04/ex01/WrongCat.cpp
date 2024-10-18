#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << RED << "WrongCat Default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const std::string& name) : WrongAnimal()
{
	this->type = name;
	std::cout << RED << "WrongCat with std::string& name constructor called" \
	<< RESET << std::endl;
}

//COPY CONSTRUCTOR
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{
	*this = other; 
	std::cout << RED << "WrongCat copy constructor called" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	type = other.type;
	std::cout << RED << "WrongCat copy assignment constructor called" << RESET << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Deconstructor called for: " << this->type << std::endl;
}

//
//
//New member functions
std::string		WrongCat::getType(void) const
{
	return(this->type);
}

void	WrongCat::makeSound() const
{
	std::cout << BLUE << "Default WrongCat noises." << RESET << std::endl;
}
