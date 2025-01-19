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

ShrubberyCreationForm::ShrubberyCreationForm()
{

};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name)
{

};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
{

};

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form)
{

};

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "Destructor called for ShrubberyCreationForm" << RESET << std::endl;
};


//-----------------------------------------------------------------------

//https://stackoverflow.com/questions/478075/creating-files-in-c
ShrubberyCreationForm& ShrubberyCreationForm::execute(Bureaucrat const & executor)
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
                  ***********                   \
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