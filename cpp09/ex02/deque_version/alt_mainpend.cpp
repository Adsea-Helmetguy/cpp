
#include "PmergeMe.hpp"

void	comparing_deque(std::deque<int>& main, size_t start, size_t end, size_t pair_size)
{
	std::cout << YELLOW << "  Comparing (start[" << RT << std::flush;
	
	for (size_t i = 0; i != (start + pair_size); i++)
	{
		std::cout << i << std::flush;
		if ((i + 1) != (start + pair_size))
			std::cout << ", " << std::flush;
	}
	std::cout << YELLOW << "] = (" << RT << std::flush;
	for (size_t i = 0; i < (start + pair_size); i++)
	{
		std::cout << main[i] << std::flush;
		if ((i + 1) != (start + pair_size))
			std::cout << ", " << std::flush;
	}
	std::cout << YELLOW << ")" << RT << std::flush;

	std::cout << YELLOW << " || " << "end[" << RT << std::flush;
	for (size_t i = end - (pair_size - 1); i < end + 1; i++)
	{
		std::cout << i << std::flush;
		if ((i + 1) != end + 1)
			std::cout << ", " << std::flush;
	}
	std::cout << YELLOW << "] = (" << RT << std::flush;
	for (size_t i = end - (pair_size - 1); i < end + 1; i++)
	{
		std::cout << main[i] << std::flush;
		if ((i + 1) != end + 1)
			std::cout << ", " << std::flush;
	}
	std::cout << YELLOW << ")" << RT << std::endl;
};

/* return the position of where to insert the insert_element */
size_t	binary_deque_ft(std::deque<int>& main, size_t start, size_t end, int insert_element, size_t pair_size);
{
	if (start + (pair_size - 1) >= end)
		return (start);

	size_t	binary_location = 0;	
	size_t	total_pairs_inrange = ((end - start + 1) / pair_size);
	size_t	midpoint = start + ((total_pairs_inrange / 2) * pair_size) - 1;

	//comparing_startVend(main, start, end, pair_size);
	if (insert_element < main[midpoint])
		return binary_search_ft(main, start, midpoint, insert_element, pair_size);
	else
		return binary_search_ft(main, midpoint + 1, end, insert_element, pair_size);
	return (binary_location);
};

void	deque_to_negative(std::deque<int> &pend, size_t old_jacob, size_t n, size_t pair_size)
{
	for (size_t loop = n; loop > old_jacob; loop--)
	{
		for (size_t pair = 0; pair < pair_size; pair++)
		{
			pend[(loop * pair_size) - 1 - pair] = -1;
		}
	}
}

void	insertdeque_firstpair(std::deque<int> &main, std::deque<int> &pend, size_t &pair_size)
{
	if (!pend.empty())
	{
		main.insert(main.begin(), pend.begin(), pend.begin() + pair_size);
		deque_to_negative(pend, 0, 1, pair_size);
	}
};