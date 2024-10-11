/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:35:16 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:35:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

# include <iostream>
# include <string>//std::string
# include <fstream>



// ************************************************************************** //
//                               Contact Class                                //
// ************************************************************************** //

class Replace
{
public:
	Replace();
	~Replace();

private:
	std::string	_s1;//'_' added to mark it is a private member datatype
	std::string _s2;
};

#endif
