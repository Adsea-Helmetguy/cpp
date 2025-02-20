/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlow <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:34:13 by mlow              #+#    #+#             */
/*   Updated: 2024/09/30 10:34:18 by mlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

static void	ft_tolower(char &arr)
{
	arr = std::tolower(static_cast<unsigned char>(arr));
};

static void	ft_toupper(char &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
};

static void	function(std::string &a)
{
	std::cout << "You wrote here: \"" << YELLOW << a << "\"." << RT << std::endl; 
};

//::iter --means its my own version of the function--.
int main()
{
	std::cout << "\n\n\n" << std::endl;
	std::cout << MAG << "-Test 1-(big small num)" << RT << std::endl;
	{
		char	a[] = {'A', 'B', 'C'};
		size_t	arr_len = (sizeof(a) / sizeof(a[0]));
		//sizeof(a): Gives the total byte size of the array.
		//sizeof(a[0]): Gives the byte size of a single element in the array.
		//by dividing them e.g: 
		// (total byte) 9 / 3 (one element byte) == 3 (total elements)

		std::cout << "Original:" <<
		"\n\ta[0]: " << a[0] <<
		"\n\ta[1]: " << a[1] <<
		"\n\ta[2]: " << a[2] <<
		"\n" << std::endl;

		::iter(a, arr_len, ft_tolower);

		std::cout << "Changed:" <<
		"\n\ta[0]: " << a[0] <<
		"\n\ta[1]: " << a[1] <<
		"\n\ta[2]: " << a[2] <<
		"\n" << std::endl;

		::iter(a, 2, ft_toupper);

		std::cout << "Changed:" <<
		"\n\ta[0]: " << a[0] <<
		"\n\ta[1]: " << a[1] <<
		"\n\ta[2]: " << a[2] <<
		"\n" << std::endl;
	}

	std::cout << "\n\n\n" << std::endl;
	std::cout << MAG << "-Test 2-(const char *)" << RT << std::endl;
	{
		std::string	array[5];
		size_t		arr_len = 5;

		//----------init array----------
		array[0] = "This";
		array[1] = "is";
		array[2] = "a";
		array[3] = "array";
		array[4] = "string";
		//----------init array----------

		std::cout << "Original:" <<
		"\n\ta: " << array[0] <<
		"\n" << std::endl;
		
		iter(array, arr_len, function);
		//::iter(&a, arr_len, function);
	}

//
/*
	std::cout << "\n\n\n" << std::endl;
	std::cout << MAG << "-Test 2-(int)" << RT << std::endl;
	{
		std::string	*a = "Chicken Box";
		size_t		arr_len = a.size();

		std::cout << "Original:" <<
		"\n\ta: " << a <<
		"\n" << std::endl;
		
		iter(a, arr_len, function);
	}
*/
};

/*
//instantiated function template
static void	function(const char *array)
{
	std::cout << "You wrote here: \"" << YELLOW << "\"." << RT << std::endl; 
};

//void	iter(T *array, size_t array_length, void function(T *array))
int	main(void)
{
	{
		std::cout << "\n\n-starting test_1 for iter-" << std::endl;
		char		array[] = {'A', 'B', 'C'};
		size_t		array_length = array.size();

		iter(array, array_length, function(array));
	}
	return (0);
};
*/
