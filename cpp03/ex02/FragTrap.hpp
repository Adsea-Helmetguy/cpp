/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:42:49 by mlow              #+#    #+#             */
/*   Updated: 2024/10/14 16:14:24 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
#define FragTrap_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>//std::string

// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class FragTrap : public ClapTrap
{
private:

public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(FragTrap& copyname);
	FragTrap&	operator=(const FragTrap& other);
	~FragTrap();
//
	void	attack(const std::string& target);
//
//
//New function added!
	void	highFivesGuys(void);
//
};

#endif
