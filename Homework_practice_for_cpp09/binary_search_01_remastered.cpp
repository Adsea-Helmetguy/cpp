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

/* return the position of where to insert the insert_element */
size_t	binary_search_ft(std::vector<int>& main, size_t start, size_t end, int insert_element, size_t pair_size)
{
	std::cout << GREEN << "\nStart: " << RT << start << std::endl;
	std::cout << GREEN << "end: " << RT << end << std::endl;
	std::cout << GREEN << "insert ele: " << RT << insert_element << std::endl;
	if (start >= end || (start + (pair_size - 1) >= end))
		return (start);

	std::cout << YELLOW << "  Comparing (start[" << RT << start << YELLOW << "] = " \
		<< RT << main[start] << YELLOW << " || " << "end[" << RT << end \
		<< YELLOW << "] = " << RT << main[end] << YELLOW << ")" << RT << std::endl;

	size_t	binary_location = 0;	
	size_t	total_pairs_inrange = ((end - start + 1) / pair_size);
	size_t	midpoint = start + ((total_pairs_inrange / 2) * pair_size) - 1;

//How many pair_size in range?
	// std::cout << CYAN << "Pairs value: " << RT << pair_size << std::endl;
	std::cout << CYAN << "Total pair_size in this range: " << RT << total_pairs_inrange << std::endl;

//calucating the midpoint values
	std::cout << YELLOW << "midpoint[" << midpoint << "] = " << RT << main[midpoint] << std::endl;

	if (insert_element < main[midpoint])
		return binary_search_ft(main, start, midpoint, insert_element, pair_size);
	else
		return binary_search_ft(main, midpoint + 1, end, insert_element, pair_size);
	return (binary_location);
};

int main(void)
{
	std::vector<int> main = { 1, 3, 5, 7, 9, 11, 55, 100 };
	std::vector<int> pend = { 0, 2, 4, 6, 8, 10, 29, 42 };
	size_t	binary_location = 0;
	size_t	pair_size = 4;

	std::cout << "\n\nBEFORE" << std::endl;
	std::cout << GREEN << "MAIN" << RT << std::endl;
	print_vector(main);

	for (size_t i = (pair_size - 1); i < pend.size(); i += pair_size)
	{
		std::cout << YELLOW << "\nstarting at pend[" << RT << i << \
			YELLOW << "] = " << RT << pend[i] << std::endl;
		binary_location = (binary_search_ft(main, 0, (main.size() - 1), pend[i], pair_size));
		main.insert(main.begin() + binary_location, \
			(pend.begin() + (i - (pair_size - 1))), pend.begin() + i + 1);
		for (size_t loop = 0; loop < pair_size; loop++)
			pend[i - loop] = -1;
		std::cout << RED << "MAIN" << RT << std::endl;
			print_vector_pairs(main, pair_size);
		std::cout << "-------------------------------------------\n" << std::endl;
	}
	std::cout << "\n\nAFTER" << std::endl;
	std::cout << RED << "MAIN" << RT << std::endl;
	print_vector_pairs(main, pair_size);
	std::cout << RED << "\nPend" << RT << std::endl;
	print_vector_pairs(pend, pair_size);
	return (0);
};
