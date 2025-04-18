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
# include <ctime> //ctime

# define RT	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define CYAN	"\033[0;36m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"
# define microseconds 1000
# define us 1000000


//PmergeMe main folder
bool	PmergeMe_vector(int argc, char **argv);

//print_mainpend.cpp
void	print_deque_AFTER(std::deque<int> &vector);
void	print_AFTER(std::vector<int> &vector);
void	comparing_startVend(std::vector<int>& main, size_t start, size_t end, size_t pair_size);
size_t	binary_search_ft(std::vector<int>& main, size_t start, size_t end, int insert_element, size_t pair_size);
size_t	jacob_number(size_t n);
void	convert_pend_to_negative(std::vector<int> &pend, size_t old_jacob, size_t n, size_t pair_size);
void	print_mainpend(std::vector<int> &main, std::vector<int> &pend, size_t pair_size, size_t before_after);
void	insert_firstpair(std::vector<int> &main, std::vector<int> &pend, size_t &pair_size);
void	update_new_jacob(size_t &old_jacob, size_t &old_jacobsthal, size_t &n, size_t &jacobsthal);


//step4_splitpairs
void	binary_search_ft(std::vector<int> &main, \
			size_t start, size_t end, int insert_element);
void	adding_mainpend(std::vector<int> &sorter, std::vector<int> &main, 
				std::vector<int> &pend, size_t power);
std::vector<int>	sorting_mainpend_chain(std::vector<int> &sorter, std::vector<int> &leftover, \
									size_t power);

//step5_finalsort
size_t	jacob_number(size_t	n);
void	final_sort(std::vector<int> &sorter, std::vector<int> &pend);

//++print_values folder++
	//	binary_leftover.cpp
void	add_leftover(std::vector<int> &main, std::vector<int> &leftover, size_t &pair_size);
void	leftover_jacob(size_t &old_jacob, size_t &old_jacobsthal, \
					size_t &n, size_t &jacobsthal);
void	binaryinsert_leftover(std::vector<int> &main, std::vector<int> &leftover, size_t pair_size);
size_t	binary_search_leftover(std::vector<int>& main, \
					size_t start, size_t end, int insert_element, size_t pair_size);
	//	print_mainpend.cpp
void	print_vector_pairs(std::vector<int>& vector, size_t pair_size, int mp);



//deque_version
void	deque_recursive(std::deque<int> &sorter, int level);
void	pushing_sort(std::deque<int> &sorter, int argc, char **argv);
int		counting_total_pair_deque(std::deque<int> &sorter, std::deque<int> &leftover, int power);

//alt_binary.cpp
std::deque<int>	deque_mainpend_chain(std::deque<int> &sorter, std::deque<int> &leftover, \
	size_t power);
void	deque_binaryinsert(std::deque<int> &main, std::deque<int> &pend, size_t pair_size);
void	deque_adding(std::deque<int> &sorter, std::deque<int> &main, 
	std::deque<int> &pend, size_t power);

//alt_mainpend.cpp
void	comparing_deque(std::deque<int>& main, size_t start, size_t end, size_t pair_size);
size_t	binary_deque_ft(std::deque<int>& main, size_t start, size_t end, int insert_element, size_t pair_size);
void	deque_to_negative(std::deque<int> &pend, size_t old_jacob, size_t n, size_t pair_size);
void	insertdeque_firstpair(std::deque<int> &main, std::deque<int> &pend, size_t &pair_size);



//helper
int	convert_token(std::string string);
#endif
