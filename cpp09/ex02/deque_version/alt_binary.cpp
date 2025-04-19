#include "PmergeMe.hpp"

void	deque_adding(std::deque<int> &sorter, std::deque<int> &main, 
			std::deque<int> &pend, size_t power)
{
	size_t	size_loop = 0;

	//std::cout << GREEN << "RESCURSIVE power: " << power << RT << std::endl;
	while (size_loop < sorter.size())
	{
		for (size_t i = (size_loop); i < (size_loop + (power / 2)); i++)//second pair
			pend.push_back(sorter[i]);
		for (size_t i = (size_loop) + (power / 2); i < (size_loop + power); i++)//first pair
			main.push_back(sorter[i]);
		size_loop += (power);
	}
};

void	deque_binaryinsert(std::deque<int> &main, std::deque<int> &pend, size_t pair_size)
{
// ---------------------------elements--------------------------------------
	size_t	binary_location = 0;

	size_t	old_jacob = 1;
	size_t	old_jacobsthal = 1;
	size_t	n = 3;
	size_t	jacobsthal = jacob_number(n);

	//inserted first pair and check if (pend.size() > jacob = 3)
	size_t	num_of_pairs_inserted = 1;
	size_t	endpoint = ((3 + num_of_pairs_inserted) * pair_size) - 1;
	size_t	counter = 0;
// ---------------------------elements--------------------------------------

	if (!main.empty() && !pend.empty())
	{
		while (num_of_pairs_inserted < (pend.size() / pair_size))//create a while loop to --
		{
			for (size_t j = (jacobsthal * pair_size) - 1;
				j > (old_jacobsthal * pair_size) - 1; j -= pair_size)
			{
				if (j > (pend.size() - 1))
					j = (pend.size() - 1);
				endpoint = ((jacobsthal + num_of_pairs_inserted) * pair_size) - 1;
				binary_location = (binary_deque_ft(main, 0, endpoint, pend[j], pair_size));
				main.insert(main.begin() + binary_location, \
					(pend.begin() + j - (pair_size - 1)), pend.begin() + j + 1);//+1 cause end iterator
				counter++;
			}
			num_of_pairs_inserted += counter;
			counter = 0;
			deque_to_negative(pend, old_jacob, n, pair_size);
			update_new_jacob(old_jacob, old_jacobsthal, n, jacobsthal);
		}
	}
};

size_t	deque_search_leftover(std::deque<int>& main, size_t start, size_t end, int insert_element, size_t pair_size)
{
	size_t	binary_location = 0;	
	size_t	total_pairs_inrange = ((end - start + 1) / pair_size);

	if (start + (pair_size - 1) >= end)
			return (start);
	
	size_t	midpoint = start + ((total_pairs_inrange / 2) * pair_size) - 1;

	if (total_pairs_inrange == 1 && midpoint < main.size() && (insert_element > main[midpoint]))
		return (start + pair_size);
	//if (start + (pair_size - 1) >= end)
	//		return (start);
	if (insert_element < main[midpoint])
		return deque_search_leftover(main, start, midpoint, insert_element, pair_size);
	else
		return deque_search_leftover(main, midpoint + 1, end, insert_element, pair_size);
	return (binary_location);
};

void	deque_leftover(std::deque<int> &main, std::deque<int> &leftover, size_t &pair_size)
{
	size_t	binary_location = 0;
	size_t	endpoint = (main.size() - 1);

	if (!leftover.empty())
	{
		binary_location = (deque_search_leftover(main, 0, endpoint, leftover[pair_size - 1], pair_size));
		main.insert(main.begin() + binary_location, leftover.begin(), leftover.end());
		//deque_to_negative(leftover, 0, 1, pair_size);
	}
};

std::deque<int>	deque_mainpend_chain(std::deque<int> &sorter, std::deque<int> &leftover, \
							size_t power)
{
// ---------------------------elements--------------------------------------
	std::deque<int>	main;
	std::deque<int>	pend;
	size_t	pair_size = power / 2;
// ---------------------------elements--------------------------------------

	//print_vector_pairs(sorter, pair_size, 0);
	deque_adding(sorter, main, pend, power);
	insertdeque_firstpair(main, pend, pair_size);
	deque_binaryinsert(main, pend, pair_size);
	deque_leftover(main, leftover, pair_size);
	return (main);
};
