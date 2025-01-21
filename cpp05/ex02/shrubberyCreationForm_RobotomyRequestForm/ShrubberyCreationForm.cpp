/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:28 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:30 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(145, 137)
{
	//Required grades:_requiredGrades(145), _execGrades(137)
	
};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name) : AForm(name, 145, 137)
{

};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy)
{

};

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form)
{
	if (this != &form)
	{
		//const _name, cannot be copied over
		this->setBool(form.getBool());
		std::cout << YELLOW << "Copy assignment(operator=) called" << RESET << std::endl;
	}
  else
		std::cout << "DON'T DO ZAT! Don't self-assign!!!" << std::endl;
	return (*this);
};

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "Destructor called for ShrubberyCreationForm" << RESET << std::endl;
};


//-----------------------------------------------------------------------

//https://stackoverflow.com/questions/478075/creating-files-in-c
void	ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	if (executor.getFormsigned() == false || executor.getGrade() > 137)
	{
		std::cout << RED << "Unfortunate but you didnt sign nor get enough grades" \
			<< RESET << std::endl;
	};
	std::ofstream outfile("<target>_shrubbery.txt");
	outfile << "\
                                                 \
                       O                         \
                      ***                        \
                     **O**                       \
                    *******                      \
                   *********                     \
                  ***********                    \
                   ******o**                     \
                  ***********                    \
                 ****o********                   \
                ***************                  \
               ****o***o********                 \
              *******************                \
            ***********************              \
               *****O***********                 \
              **********o********                \
             ****************o****               \
            **O********************              \
           ***********o********O****             \
         *****************************           \
             *********************               \
            ***o*******************              \
           ***********o*******o*****             \
          ***************************            \
         ***********************O*****           \
        ***O***************************          \
      ***********************************        \
           *************************             \
          *******o********o**********            \
         *****************************           \
        **************o****************          \
       *************************O*******         \
      *****O*****************************        \
    **************o************************      \
          ***************************            \
         *************o***************           \
        ***********o*******************          \
       **************************O******         \
      ***o******************O************        \
    ***o***********o****************o******      \
                      ###                        \
                      ###                        \
                      ###                        \
                  ###########                    \
                  ###########   " << std::endl;

	outfile.close();
};



//-----------------------------------------------------------------------
//-----------------------------------------------------------------------
std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& form)
{
    std::cout << "printing all form's information: " << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << "Form's _name: " << GREEN << form.getName() << RESET \
        << std::endl;
    if (form.getBool() == 0)
        std::cout << "Form's _isTheFormSigned: " << RED << "\"Not Signed\"" \
            << RESET << std::endl;
    else
        std::cout << "Form's _isTheFormSigned: " << GREEN << "\"Signed\"" \
            << RESET << std::endl;
    std::cout << "Form's _requiredGrades: " << GREEN << form.getrequiredGrades() \
        << RESET << std::endl;
	std::cout << "Form's _execGrades: " << GREEN << form.getexecGrades() \
        << RESET << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return (os);
};
//-----------------------------------------------------------------------
//-----------------------------------------------------------------------