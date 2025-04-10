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

void	print_vector(std::vector<int>& vector)
{
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << "," << std::flush;
	std::cout << std::endl;
}

void	print_vector_pairs(std::vector<int>& vector, size_t pairs)
{
	size_t	loop = 0;

	std::cout << YELLOW << "(" << RT << std::flush;
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	{
		if (loop != 0 && loop % pairs == 0)
			std::cout << YELLOW << ") (" << RT << std::flush;
		std::cout << *it << std::flush;
		if ((loop + 1) % pairs != 0 && (loop < vector.size() - 1))
			std::cout << ", " << std::flush;
		loop++;
	}
	std::cout << YELLOW << ")" << RT << std::endl;
}

/* return the position of where to insert the insert_element */
size_t	binary_search_ft(std::vector<int>& main, size_t start, size_t end, int insert_element, size_t pairs)
{
	std::cout << GREEN << "\nStart: " << RT << start << std::endl;
	std::cout << GREEN << "end: " << RT << end << std::endl;
	std::cout << GREEN << "insert ele: " << RT << insert_element << std::endl;
	if (start >= end || (start + (pairs - 1) >= end))
		return (start);

	std::cout << YELLOW << "  Comparing (start[" << RT << start << YELLOW << "] = " \
		<< RT << main[start] << YELLOW << " || " << "end[" << RT << end \
		<< YELLOW << "] = " << RT << main[end] << YELLOW << ")" << RT << std::endl;

	size_t	binary_location = 0;	
	size_t	total_pairs_inrange = ((end - start + 1) / pairs);
	size_t	midpoint = start + ((total_pairs_inrange / 2) * pairs) - 1;

//How many pairs in range?
	std::cout << CYAN << "Total pairs in this range: " << RT << total_pairs_inrange << std::endl;

//calucating the midpoint values
	std::cout << YELLOW << "midpoint[" << midpoint << "] = " << RT << main[midpoint] << std::endl;

	if (insert_element < main[midpoint])
		return binary_search_ft(main, start, midpoint, insert_element, pairs);
	else
		return binary_search_ft(main, midpoint + 1, end, insert_element, pairs);
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

void	convert_pend_to_negative(std::vector<int> &pend, size_t jacob, size_t old_jacob, size_t pairs)
{
	for (int loop = jacob; loop > old_jacob; loop--)
	{
		for (int pair = 0; pair < pairs; pair++)
		{
			pend[(loop * pairs) - 1 - pair] = -1;
		}
	}
}

void	print_mainpend(std::vector<int> &main, std::vector<int> &pend, size_t pairs)
{
	std::cout << RED << "MAIN" << RT << std::endl;
	print_vector_pairs(main, pairs);
	std::cout << RED << "\nPend" << RT << std::endl;
	print_vector_pairs(pend, pairs);
};

int main(void)
{
// ---------------------------elements--------------------------------------
	std::vector<int> main = { 1, 3, 5, 7, 9, 11, 55, 100 };
	std::vector<int> pend = { 0, 2, 4, 6, 8, 10, 29, 42 };

	size_t	pairs = 2;
	size_t	binary_location = 0;

	size_t	old_jacob = 1;
	size_t	old_jacobsthal = 1;
	size_t	n = 3;
	size_t	jacobsthal = jacob_number(n);

	//inserted first pair and check if (pend.size() > jacob = 3)
	size_t	num_of_pairs_inserted = 1;
	size_t	endpoint = ((3 + num_of_pairs_inserted) * pairs) - 1;
	size_t	startpoint = (pairs * 2) - 1;\
	size_t	counter = 1;
// ---------------------------elements--------------------------------------

	if (startpoint < (pend.size() - 1) && ((pairs * 3) - 1) < pend.size() - 1)
		startpoint = (pairs * 3) - 1;

	binary_location = (binary_search_ft(main, 0, endpoint, pend[(pairs - 1)], pairs));
	main.insert(main.begin() + binary_location, \
		(pend.begin() + ((pairs - 1) - (pairs - 1))), pend.begin() + (pairs - 1) + 1);
	convert_pend_to_negative(pend, 1, 0, pairs);
	print_mainpend(main, pend, pairs);
	while (!pend_checkall_negative(pend))
	{
		for (size_t j = (jacobsthal * pairs) - 1; 
			((j > (old_jacobsthal * pairs) - 1)); j -= pairs)
		{
			std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>------" << std::endl;
			std::cout << YELLOW << "\nstarting at pend[" << RT << j << \
				YELLOW << "] = " << RT << pend[j] << std::endl;
			while (j > (pend.size() - 1))//optimise this in one line-yx-
				j--;
			std::cout << RED << "-------------------------------------------" << std::endl;
			std::cout << RED << "J = " << RT << j << std::endl;
			std::cout << RED <<  "-------------------------------------------" << RT << std::endl;
			endpoint = ((n + num_of_pairs_inserted) * pairs) - 1;
			binary_location = (binary_search_ft(main, 0, endpoint, pend[j], pairs));
			main.insert(main.begin() + binary_location, \
				(pend.begin() + j - (pairs - 1)), pend.begin() + j + 1);//+1 cause end iterator
			//main.insert(main.begin() + binary_location, \
			//	(pend.begin() + ((pairs - 1) - (pairs - 1))), pend.begin() + (pairs - 1) + 1);
			counter++;
			print_mainpend(main, pend, pairs);
		}
		num_of_pairs_inserted += counter;
		counter = 0;
		convert_pend_to_negative(pend, n, old_jacob, pairs);
		old_jacob = n;
		old_jacobsthal = jacobsthal;
		jacobsthal = jacob_number(++n);
		std::cout << YELLOW << "-------------------------------------------" << std::endl;
		std::cout << "n = " << n << " | Jacobsthal = " << RT << jacobsthal << std::endl;
		std::cout << YELLOW <<  "-------------------------------------------" << RT << std::endl;
		std::cout << "------<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n" << std::endl;
	}

































/*
	std::vector<int> main = { 1, 3, 5, 7, 9, 11, 55, 100 };
	std::vector<int> pend = { 0, 2, 4, 6, 8, 10, 29, 42 };

	size_t	pairs = 2;
	size_t	old_jacob = 1;
	size_t	jacob = 3;
	size_t	num_of_pairs_inserted = 1;
	size_t	end_point = ((jacob + num_of_pairs_inserted) * pairs) - 1;
	size_t	binary_location = 0;


	binary_location = (binary_search_ft(main, 0, end_point, pend[(pairs - 1)], pairs));
	main.insert(main.begin() + binary_location, \
		(pend.begin() + ((pairs - 1) - (pairs - 1))), pend.begin() + (pairs - 1) + 1);
	for (size_t i = (pairs - 1); i < pend.size(); i += pairs)
	{
		std::cout << RED << "Jacob's value: " << jacob << RT << std::endl;
		for (size_t j = jacob; (j > old_jacob) && j < pend.size(); j--)
		{
			std::cout << YELLOW << "\nstarting at pend[" << RT << i << \
				YELLOW << "] = " << RT << pend[j] << std::endl;
			end_point = ((j + num_of_pairs_inserted) * pairs) - 1;
			binary_location = (binary_search_ft(main, 0, end_point, pend[j], pairs));
			main.insert(main.begin() + binary_location, \
				(pend.begin() + (j - (pairs - 1))), pend.begin() + j + 1);
			num_of_pairs_inserted++;
			std::cout << RED << "MAIN" << RT << std::endl;
			print_vector_pairs(main, pairs);
			for (size_t loop = 0; loop < pairs; loop++)
				pend[j - loop] = -1;
			std::cout << "-------------------------------------------\n" << std::endl;
		}
		if (num_of_pairs_inserted > jacob)
		{
			old_jacob = jacob;
			jacob = jacob_number(num_of_pairs_inserted);
		}
	}
*/
	print_mainpend(main, pend, pairs);
	return (0);
}


