/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:28 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _constant_name("Default_Bureaucrat"), _grade(150)
{
	std::cout << RED << "Bureaucrat Default constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name) : _constant_name(name), _grade(150)
{
	std::cout << RED << "Bureaucrat" << this->_constant_name \
	<< " constructor called" << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) 
	: _constant_name(other._constant_name), _grade(other._grade)
{
	std::cout << RED << "Bureaucrat copy constructor called" << RESET << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
	{
		std::cout << "Don't Self-assign!!" << std::endl;
		return *this;
	}
	//since it's a constant name, it cannot be copied.
	this->_grade = other._grade;
	std::cout << RED << "Bureaucrat copy assignment constructor called" << RESET << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Deconstructor " << RED << this->_constant_name << RESET << \
	" called: " << std::endl;
}

Bureaucrat::GradeTooHighException(const std::string& message) : _message(message)
{
};


Bureaucrat::GradeTooLowException(const std::string& message) : _message(message)
{
};















std::string		Bureaucrat::getName(void) const
{
	return(this->_constant_name);
}

std::string		Bureaucrat::getName() const
{
	return(this->_constant_name);
}

unsigned int	Bureaucrat::getGrade() const
{
	return(this->_grade);
}

void		Bureaucrat::incrementGrade()
{
    if (this->_grade <= 1)
        throw GradeTooHighException("Grade is too high! Cannot increment grade");
    this->_grade--;
}

void		Bureaucrat::decrementGrade()
{
    if (this->_grade >= 150)
        throw GradeTooLowException("Grade is too low! Cannot decrement grade");
    this->_grade++;
}























/*
Exception Classes here!
class Exception : public std::exception
{
private:
	std::string			_message;
public:
	virtual std::string	what();
};



const char*	Bureaucrat::GradeTooHighException::what() {
	return _message.c_str();
};
*/

//The what() member function satisfies the constraints specified for std::exception::what().
const char*	Bureaucrat::GradeTooHighException::what(void)
{
	return (_message.c_str());
};

const char*	Bureaucrat::GradeTooLowException::what(void)
{
	return (_message.c_str());
};

//Left and right shift, insertion («) operator
std::ostream& operator<<(std::ostream& out, const Bureaucrat& other)
{
	out << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (out);

}






