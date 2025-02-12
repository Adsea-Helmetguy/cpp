/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
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
	std::cout << GREEN << "I AM NOW CREATING A Shrubbery." \
		<< RESET << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name) : AForm(name, 145, 137)
{
	std::cout << GREEN << "I AM NOW CREATING A Shrubbery. " \
		<< "WITH A NAME CALLED: " << RESET << name << std::endl;
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
		std::cout << YELLOW << "ShrubberyCreationForm Copy assignment(operator=) called" \
            << RESET << std::endl;
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
//-----------------------------------------------------------------------
//https://stackoverflow.com/questions/478075/creating-files-in-c
void	ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
    std::string filename;

	if (this->getBool() == false || executor.getGrade() > 137)
	{
		std::cout << RED << "Unfortunate but you didnt sign nor get enough grades" \
			<< RESET << std::endl;
        return ;
	};
    std::cout << MAG << "Making a shrubbery.txt file" << RESET << std::endl;
    filename = executor.getName() + "_shrubbery.txt";
	std::ofstream outfile(filename.c_str());
    if (!outfile)
    {
        std::cerr << RED << "Error: Could not open file " << filename << " for writing." << RESET << std::endl;
        return;
    }
	outfile << "\n\
                                                 \n\
                       O                         \n\
                      ***                        \n\
                     **O**                       \n\
                    *******                      \n\
                   *********                     \n\
                  ***********                    \n\
                   ******o**                     \n\
                  ***********                    \n\
                 ****o********                   \n\
                ***************                  \n\
               ****o***o********                 \n\
              *******************                \n\
            ***********************              \n\
               *****O***********                 \n\
              **********o********                \n\
             ****************o****               \n\
            **O********************              \n\
           ***********o********O****             \n\
         *****************************           \n\
             *********************               \n\
            ***o*******************              \n\
           ***********o*******o*****             \n\
          ***************************            \n\
         ***********************O*****           \n\
        ***O***************************          \n\
      ***********************************        \n\
           *************************             \n\
          *******o********o**********            \n\
         *****************************           \n\
        **************o****************          \n\
       *************************O*******         \n\
      *****O*****************************        \n\
    **************o************************      \n\
          ***************************            \n\
         *************o***************           \n\
        ***********o*******************          \n\
       **************************O******         \n\
      ***o******************O************        \n\
    ***o***********o****************o******      \n\
                      ###                        \n\
                      ###                        \n\
                      ###                        \n\
                  ###########                    \n\
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
