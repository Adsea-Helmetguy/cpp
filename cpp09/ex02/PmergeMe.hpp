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

extern int	num_comparison;

//PmergeMe main folder && printing
void	PmergeMe_vector(int argc, char **argv);
void	print_vector_pairs(std::vector<long long>& vector, size_t pair_size, int mp);
void	comparing_startVend(std::vector<long long>& main, size_t start, size_t end, size_t pair_size);
void	print_mainpend(std::vector<long long> &main, std::vector<long long> &pend, size_t pair_size, size_t before_after);

//--general
long long   convert_token(std::string string);
double	timer_in_ms(clock_t &time);
size_t	jacob_number(size_t n);
void	update_new_jacob(size_t &old_jacob, size_t &old_jacobsthal, size_t &n, size_t &jacobsthal);

//--vector
void	timer_for_recursion_vector(std::vector<long long> &sorter, int argc);
void	pushing_sort_vector(std::vector<long long> &sorter, int argc, char **argv);
void	print_vector_AFTER(std::vector<long long> &vector, double timer_end, int argc);
void	sortinside_pairs_vector(std::vector<long long> &sorter, size_t power, int pair_counter);
void	start_recursive_sort_vector(std::vector<long long> &sorter, int level);
int		counting_total_pair_vector(std::vector<long long> &sorter, std::vector<long long> &leftover, int power);
std::vector<long long>	sorting_mainpend_chain_vector(std::vector<long long> &sorter, std::vector<long long> &leftover, size_t power);
void	insert_firstpair_vector(std::vector<long long> &main, std::vector<long long> &pend, size_t &pair_size);
size_t	binary_search_leftover_vector(std::vector<long long>& main, size_t start, size_t end, int insert_element, size_t pair_size);
void	add_leftover_vector(std::vector<long long> &main, std::vector<long long> &leftover, size_t &pair_size);

//--deque
void	PmergeMe_deque(int argc, char **argv);
void	timer_for_recursion_deque(std::deque<long long> &sorter, int argc);
void	start_recursive_sort_deque(std::deque<long long> &sorter, int level);
void	pushing_sort_deque(std::deque<long long> &sorter, int argc, char **argv);
void	print_deque_AFTER(std::deque<long long> &deque, double timer_end, int argc);
int		counting_total_pair_deque(std::deque<long long> &sorter, std::deque<long long> &leftover, int power);
void	add_leftover_deque(std::deque<long long> &main, std::deque<long long> &leftover, size_t &pair_size);
void	insert_firstpair_deque(std::deque<long long> &main, std::deque<long long> &pend, size_t &pair_size);
void	sortinside_pairs_deque(std::deque<long long> &sorter, size_t power, int pair_counter);
void	binaryinsert_mainpend_deque(std::deque<long long> &main, std::deque<long long> &pend, size_t pair_size);
std::deque<long long>	sorting_mainpend_chain_deque(std::deque<long long> &sorter, std::deque<long long> &leftover, size_t power);
void	adding_mainpend_deque(std::deque<long long> &sorter, std::deque<long long> &main, std::deque<long long> &pend, size_t power);
size_t	binary_search_ft_deque(std::deque<long long>& main, size_t start, size_t end, int insert_element, size_t pair_size);
size_t	binary_search_leftover_deque(std::deque<long long>& main, size_t start, size_t end, int insert_element, size_t pair_size);

#endif
