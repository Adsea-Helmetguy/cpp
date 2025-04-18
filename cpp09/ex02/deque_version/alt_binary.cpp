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
				binary_location = (binary_search_ft(main, 0, endpoint, pend[j], pair_size));
				main.insert(main.begin() + binary_location, \
					(pend.begin() + j - (pair_size - 1)), pend.begin() + j + 1);//+1 cause end iterator
				counter++;
			}
			num_of_pairs_inserted += counter;
			counter = 0;
			convert_pend_to_negative(pend, old_jacob, n, pair_size);
			update_new_jacob(old_jacob, old_jacobsthal, n, jacobsthal);
		}
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
	adding_mainpend(sorter, main, pend, power);
	insert_firstpair(main, pend, pair_size);
	binaryinsert_mainpend(main, pend, pair_size);
	add_leftover(main, leftover, pair_size);
	return (main);
};