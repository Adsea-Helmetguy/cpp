/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:11:38 by mlow              #+#    #+#             */
/*   Updated: 2025/03/25 15:13:10 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PMERGEME_HPP
#define PMERGEME_HPP

# include <string>//std::string
# include <iostream>//std::cout/endl;
# include <sstream>// std::stringstream
# include <algorithm>//std::swap() usage in PmergeMe.cpp
# include <cmath> //for pow() usage in PmergeMe.cpp
# include <algorithm> // for std::reverse used in split_pairs.cpp
# include <vector>
# include <deque>

# define RT	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define CYAN	"\033[0;36m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"


//PmergeMe main folder
bool	start_PmergeMe(int argc, char **argv);

//step4_splitpairs
void	sorting_mainpend_chain(std::vector<int> &sorter, std::vector<int> &leftover);
void	print_mainchain(std::vector<int> &sorter);
void	print_pendchain(std::vector<int> &leftover);

//step5_finalsort
void	final_sort(std::vector<int> &sorter, std::vector<int> &leftover);

#endif
