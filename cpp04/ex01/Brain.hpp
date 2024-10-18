/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:58:07 by mlow              #+#    #+#             */
/*   Updated: 2024/10/16 13:58:09 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

# include <iostream>
# include <string>//std::string

# define RESET   "\033[0m"
# define RED     "\033[31m"//Red
# define YELLOW  "\033[33m"//Yellow
# define BLUE    "\033[34m"//Blue

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Brain
{
private:
	std::string	ideas[100];
public:
	Brain();
	Brain(const Brain &other);
	Brain&	operator=(const Brain &other);
	~Brain();
	
	void	idea_member(int idea_number, std::string input_ideas);
	void	obtain_idea(int idea_number);
};

#endif
