#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>//std::string
# include <cctype>
# include <iomanip> //for std::setw
# include <sstream>
# include <new>



// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Weapon
{
public:
    const std::string &getType() const;//for access
	void setType(std::string type);//for modify

private:
	std::string	type;
};
