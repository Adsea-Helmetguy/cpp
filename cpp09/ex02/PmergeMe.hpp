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

//print_values
void	print_vector_pairs(std::vector<int>& vector, size_t pair_size, int mp);

//helper_functions
void	comparing_startVend(std::vector<int>& main, size_t start, size_t end, size_t pair_size);
size_t	binary_search_ft(std::vector<int>& main, size_t start, size_t end, int insert_element, size_t pair_size);
size_t	jacob_number(size_t n);
int		pend_checkall_negative(std::vector<int> pend);
void	convert_pend_to_negative(std::vector<int> &pend, size_t old_jacob, size_t n, size_t pair_size);
void	print_mainpend(std::vector<int> &main, std::vector<int> &pend, size_t pair_size, size_t before_after);
void	insert_firstpair(std::vector<int> &main, std::vector<int> &pend, \
			size_t &pair_size, size_t &binary_location, size_t &endpoint);
void	update_new_jacob(std::vector<int> &main, std::vector<int> &pend, \
			size_t &old_jacob, size_t &old_jacobsthal, size_t &n, size_t &jacobsthal, size_t &pair_size);


//step4_splitpairs
void	sorting_mainpend_chain(std::vector<int> sorter, 
                std::vector<int> &leftover, size_t power);
void	print_mainchain(std::vector<int> &sorter);
void	print_pendchain(std::vector<int> &leftover);

//step5_finalsort
size_t	jacob_number(size_t	n);
void	final_sort(std::vector<int> &sorter, std::vector<int> &pend);

#endif
