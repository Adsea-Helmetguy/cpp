#include <vector>
#include <algorithm>
#include <string>
#include <iterator>
#include <iostream>

# define RT		"\033[0m"
# define RED	"\033[31m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define CYAN	"\033[0;36m"
# define GREEN	"\033[32m"
# define MAG	"\e[0;35m"

void	print_vector(std::vector<int>& vector)
{
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
        std::cout << *it << std::endl;
}

/* return the position of where to insert the insert_element */
size_t	binary_search_ft(std::vector<int>& main, size_t start, size_t end, int insert_element)
{
	if (start == end)
		return (start);

	size_t	midpoint = (start + end) / 2;
	size_t	found_location = 0;

	std::cout << "AT Value: " << RED << main[midpoint] << RT << std::endl;
	if (insert_element < main[midpoint])
		found_location = binary_search_ft(main, start, midpoint, insert_element);
	else
		found_location = binary_search_ft(main, midpoint + 1, end, insert_element);
	return (found_location);
}

int main(void)
{
	std::vector<int> main = { 1, 3, 5, 7, 9 };
	int pend = 2;

	std::cout << "\n\nBEFORE\n\n";
	print_vector(main);

	// insert pend into main
	size_t insert_position = binary_search_ft(main, 0, main.size(), pend);
	main.insert(main.begin() + insert_position, pend);

	std::cout << "\n\nAFTER\n\n";
	print_vector(main);

	return (0);
}