#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <iostream>

# define RT	"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define CYAN	"\033[0;36m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"

void	print_vector_pairs(std::vector<int>& vector, size_t pair_size)
{
	size_t	loop = 0;

	std::cout << YELLOW << "(" << RT << std::flush;
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		if (loop != 0 && loop % pair_size == 0)
			std::cout << YELLOW << ") (" << RT << std::flush;
		std::cout << *it << std::flush;
		if ((loop + 1) % pair_size != 0 && (loop < vector.size() - 1))
			std::cout << ", " << std::flush;
		loop++;
	}
	std::cout << YELLOW << ")" << RT << std::endl;
}

void	comparing_startVend(std::vector<int>& main, size_t start, size_t end, size_t pair_size)
{
	std::cout << YELLOW << "  Comparing (start[" << RT << std::flush;
	
	for (int i = 0; i != (start + pair_size); i++)
	{
		std::cout << i << std::flush;
		if ((i + 1) != (start + pair_size))
			std::cout << ", " << std::flush;
	}
	std::cout << YELLOW << "] = (" << RT << std::flush;
	for (int i = 0; i < (start + pair_size); i++)
	{
		std::cout << main[i] << std::flush;
		if ((i + 1) != (start + pair_size))
			std::cout << ", " << std::flush;
	}
	std::cout << YELLOW << ")" << RT << std::flush;

	std::cout << YELLOW << " || " << "end[" << RT << std::flush;
	for (int i = end - 1; i < end + 1; i++)
	{
		std::cout << i << std::flush;
		if ((i + 1) != end + 1)
			std::cout << ", " << std::flush;
	}
	std::cout << YELLOW << "] = (" << RT << std::flush;
	for (int i = end - 1; i < end + 1; i++)
	{
		std::cout << main[i] << std::flush;
		if ((i + 1) != end + 1)
			std::cout << ", " << std::flush;
	}
	std::cout << YELLOW << ")" << RT << std::endl;
};

/* return the position of where to insert the insert_element */
size_t	binary_search_ft(std::vector<int>& main, size_t start, size_t end, int insert_element, size_t pair_size)
{
	if (start >= end || (start + (pair_size - 1) >= end))
		return (start);

	size_t	binary_location = 0;	
	size_t	total_pairs_inrange = ((end - start + 1) / pair_size);
	size_t	midpoint = start + ((total_pairs_inrange / 2) * pair_size) - 1;

	comparing_startVend(main, start, end, pair_size);

	std::cout << CYAN << "    Total pair_size in this range: " << RT << total_pairs_inrange << std::endl;
	std::cout << YELLOW << "    midpoint[" << midpoint << "] = " << RT << main[midpoint] << std::endl;
	if (insert_element < main[midpoint])
		return binary_search_ft(main, start, midpoint, insert_element, pair_size);
	else
		return binary_search_ft(main, midpoint + 1, end, insert_element, pair_size);
	return (binary_location);
};

size_t	jacob_number(size_t n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacob_number(n - 1) + 2 * jacob_number(n - 2));
};

int	pend_checkall_negative(std::vector<int> pend)
{
	for (size_t i = 0; i < pend.size(); i++)
	{
		if (pend[i] != -1)
			return (0);//false
	}
	return (1);//true
};

void	convert_pend_to_negative(std::vector<int> &pend, size_t old_jacob, size_t n, size_t pair_size)
{
	for (int loop = n; loop > old_jacob; loop--)
	{
		for (int pair = 0; pair < pair_size; pair++)
		{
			pend[(loop * pair_size) - 1 - pair] = -1;
		}
	}
}

void	print_mainpend(std::vector<int> &main, \
		std::vector<int> &pend, size_t pair_size, size_t before_after)
{
	if (before_after == 0)
	{
		std::cout << "\n------<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" \
			<< std::endl;
		std::cout << GREEN << "---->BEFORE: " << std::endl;
	}
	else if (before_after == 1)
	{
		std::cout << GREEN << "\n---->AFTER: " << std::endl;
	}
	std::cout << RED << "MAIN" << RT << std::endl;
	print_vector_pairs(main, pair_size);
	std::cout << RED << "Pend" << RT << std::endl;
	print_vector_pairs(pend, pair_size);
};


void	insert_firstpair(std::vector<int> &main, std::vector<int> &pend, \
			size_t &pair_size, size_t &binary_location, size_t &endpoint)
{
	print_mainpend(main, pend, pair_size, 0);
	main.insert(main.begin(), (pend.begin()), pend.begin() + pair_size);
	convert_pend_to_negative(pend, 0, 1, pair_size);
};

void	update_new_jacob(std::vector<int> &main, std::vector<int> &pend, \
		size_t &old_jacob, size_t &old_jacobsthal, size_t &n, size_t &jacobsthal, size_t &pair_size)
{
	old_jacob = n;
	old_jacobsthal = jacobsthal;
	jacobsthal = jacob_number(++n);
	print_mainpend(main, pend, pair_size, 1);
	std::cout << YELLOW << "-------------------------------------------" << std::endl;
	std::cout << "n = " << n << " | Jacobsthal = " << RT << jacobsthal << std::endl;
	std::cout << YELLOW <<  "-------------------------------------------" << RT << std::endl;
};

int main(void)
{
// ---------------------------elements--------------------------------------
	std::vector<int> main = { 1, 3, 5, 7, 9, 11, 55, 100 };
	std::vector<int> pend = { 0, 2, 4, 6, 8, 10, 29, 42 };

	size_t	pair_size = 2;
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

	insert_firstpair(main, pend, pair_size, binary_location, endpoint);
	//while (!pend_checkall_negative(pend))
	//cause the current issue is you have two (-1, -1) because firstpair was not considered
	// and one extra pair was inserted cause the for loop only happened 2 times.
	// the for loop will make it loop 4 times, and you have extra 2.
	for (size_t i = pend.size(); i > 0 && i <= pend.size(); i -= pair_size)//create a while loop to --
	{
		print_mainpend(main, pend, pair_size, 0);
		for (size_t j = (jacobsthal * pair_size) - 1; 
			((j > (old_jacobsthal * pair_size) - 1)); j -= pair_size)
		{
			std::cout << YELLOW << "\nstarting at pend[" << RT << j << \
				YELLOW << "] = " << RT << pend[j] << std::endl;
			if (j > (pend.size() - 1))
				j = (pend.size() - 1);
			endpoint = ((n + num_of_pairs_inserted) * pair_size) - 1;
			binary_location = (binary_search_ft(main, 0, endpoint, pend[j], pair_size));
			main.insert(main.begin() + binary_location, \
				(pend.begin() + j - (pair_size - 1)), pend.begin() + j + 1);//+1 cause end iterator
			counter++;
		}
		num_of_pairs_inserted += counter;
		counter = 0;
		convert_pend_to_negative(pend, old_jacob, n, pair_size);
		update_new_jacob(main, pend, old_jacob, old_jacobsthal, n, jacobsthal, pair_size);
	}
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
	return (0);
}


