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

static void	printInt(int &x)
{
	static size_t index;

	std::cout << "Array[" << index++ \
		<< "] value: " GREEN << x << RT << std::endl;
};

static void	ft_tolower(char &arr)
{
	arr = std::tolower(static_cast<unsigned char>(arr));
};

static void	ft_toupper(char &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
};

static void	function(std::string a)
{
	std::cout << "You wrote here: \"" << YELLOW << a << RT << "\"." << std::endl;
};

//Don't put (*a), you want to pass a single char not a single pointer
static void	function_char(const char &a)
{
	std::cout << "You wrote here: \"" << YELLOW << a << RT << "\"." << std::endl;
};

//::iter --means its my own version of the function--.
int main()
{
	std::cout << "\n\n\n" << std::endl;
	std::cout << MAG << "-Test 1-(int elements)" << RT << std::endl;
	{
		int a[] = {11, 22, 33, 44, 55};
		size_t	arr_len = (sizeof(a) / sizeof(a[0]));
		//sizeof(a): Gives the total byte size of the array.
		//sizeof(a[0]): Gives the byte size of a single element in the array.
		//by dividing them e.g: 
		// (total byte) 9 / 3 (one element byte) == 3 (total elements)

		//----------------------print out array---------------------------
		std::cout << "Original:" << std::endl;
		for (size_t i = 0; i < arr_len; i++)
			std::cout << "\ta[" << i << "]: " << a[i] << std::endl;
		std::cout << "\n" << std::endl;
		//----------------------print out array---------------------------

		::iter(a, arr_len, printInt);
		
	}

	std::cout << "\n\n\n" << std::endl;
	std::cout << MAG << "-Test 2-(big small char)" << RT << std::endl;
	{
		char	a[] = {'A', 'B', 'C'};
		size_t	arr_len = (sizeof(a) / sizeof(a[0]));

		//----------------------print out array---------------------------
		std::cout << "Original:" << std::endl;
		for (size_t i = 0; i < arr_len; i++)
			std::cout << "\ta[" << i << "]: " << a[i] << std::endl;
		std::cout << "\n" << std::endl;
		//----------------------print out array---------------------------

		::iter(a, arr_len, ft_tolower);

		//----------------------print out array---------------------------
		std::cout << "Changed:" << std::endl;
		for (size_t i = 0; i < arr_len; i++)
			std::cout << "\ta[" << i << "]: " << a[i] << std::endl;
		std::cout << "\n" << std::endl;
		//----------------------print out array---------------------------

		::iter(a, 2, ft_toupper);

		//----------------------print out array---------------------------
		std::cout << "Changed:" << std::endl;
		for (size_t i = 0; i < arr_len; i++)
			std::cout << "\ta[" << i << "]: " << a[i] << std::endl;
		std::cout << "\n" << std::endl;
		//----------------------print out array---------------------------
	}

	std::cout << "\n\n\n" << std::endl;
	std::cout << MAG << "-Test 3-(std::string array pointer)" << RT << std::endl;
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

		//----------------------print out array---------------------------
		std::cout << "Original:" << std::endl;
		for (size_t i = 0; i < arr_len; i++)
			std::cout << "\ta[" << i << "]: " << array[i] << std::endl;
		std::cout << "\n" << std::endl;
		//----------------------print out array---------------------------
		
		::iter(array, arr_len, function);
	}

	std::cout << "\n\n\n" << std::endl;
	std::cout << MAG << "-Test 4-(const char *)" << RT << std::endl;
	{
		const char	a[] = "Chicken Box";
		size_t		arr_len = (sizeof(a) / sizeof(a[0])) - 1;

		//----------------------print out array---------------------------
		std::cout << "test4 const char!!!:" << std::endl;
		for (size_t i = 0; i < arr_len; i++)
			std::cout << "\ta[" << i << "]: " << a[i] << std::endl;
		std::cout << "\n" << std::endl;
		//----------------------print out array---------------------------

		::iter(a, arr_len, function_char);
	}

	std::cout << "\n\n\n" << std::endl;
	return (0);
};

