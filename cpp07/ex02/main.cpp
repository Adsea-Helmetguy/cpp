#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
	std::cout << GREEN << "\n\n\n---------------------------------\n" \
		<< "|\tPersonal Test 1\t\t|\n" \
		<< "---------------------------------\n" \
		<< RT << std::endl;
	{
		std::cout << "--------Constructors Created:--------" << std::endl;
		Array<int> numbers(MAX_VAL);	//constructor with 750 arrays.
		int* mirror = new int[MAX_VAL];	//creates int pointer with allocated memory.
		std::cout << "------Constructors Created ends------\n\n\n" << std::endl;

		srand(time(NULL));	// randomise values inside for loop.

		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
			std::cout << "numbers[" \
				<< GREEN << i << RT \
				<< "] =  \"" << numbers[i] << "\".	" \
				<< RED << "VS	" << RT << "mirror[" \
				<< GREEN << i << RT << "] = \"" \
				<< mirror[i] << "\""<< std::endl;
			std::cout << "------------------------------------" \
				<< "------------------------------" << std::endl;
		}

		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			 if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return (1);
			}
		}

		try
		{
			std::cout << "numbers[-2] = 0;" << std::endl;
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << MAG << e.what() << RT << std::endl;
		}
		try
		{
			std::cout << "numbers[MAX_VAL] = 0;" << std::endl;
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << MAG << e.what() << RT << std::endl;
		}
		try
		{
			std::cout << "numbers[MAX_VAL] = 0;" << std::endl;
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << MAG << e.what() << RT << std::endl;
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}

		//final test
		std::cout << "\n\n\nfinal test(numbers):" << numbers << std::endl;
		std::cout << RED << "***MIRROR GONE!!" << RT << std::endl;
		delete [] mirror;
		//delete deletes a single object
		//while delete [] deletes ARRAYS of objects!
		// so if your pointer got tons of array, delete with delete []
	}



















	std::cout << GREEN << "\n\n\n---------------------------------\n" \
		<< "|\tPersonal Test 2\t\t|\n" \
		<< "---------------------------------\n" \
		<< RT << std::endl;
	{
		std::cout << "--------Constructors Created:--------" << std::endl;
		int*	a = new int();
		std::cout << "Value of a: " << YELLOW << *a << RT << std::endl;
		Array<int>* empty = new Array<int>();
		(void)empty;
		std::cout << *empty << std::endl;
		std::cout << "------Constructors Created ends------\n\n\n" << std::endl;
		
		delete a;	//cause you created 'new
		delete empty;	//cause you created 'new'
	}

















	std::cout << GREEN << "\n\n\n---------------------------------\n" \
		<< "|\tPersonal Test 3\t\t|\n" \
		<< "---------------------------------\n" \
		<< RT << std::endl;
	{
		std::cout << "--------Constructors Created:--------" << std::endl;
		unsigned int	max_value = 0;
		
		Array<int> numbers(max_value);	//constructor with 750 arrays.
		int* mirror = new int[max_value];	//creates int pointer with allocated memory.
		std::cout << "------Constructors Created ends------\n\n\n" << std::endl;

		srand(time(NULL));	// randomise values inside for loop.

		for (unsigned int i = 0; i < max_value; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
			std::cout << "numbers[" \
				<< GREEN << i << RT \
				<< "] =  \"" << numbers[i] << "\".	" \
				<< RED << "VS	" << RT << "mirror[" \
				<< GREEN << i << RT << "] = \"" \
				<< mirror[i] << "\""<< std::endl;
			std::cout << "------------------------------------" \
				<< "------------------------------" << std::endl;
		}

		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			 if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return (1);
			}
		}

		try
		{
			std::cout << "numbers[-2] = 0;" << std::endl;
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << MAG << e.what() << RT << std::endl;
		}
		try
		{
			std::cout << "numbers[MAX_VAL] = 0;" << std::endl;
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << MAG << e.what() << RT << std::endl;
		}
		try
		{
			std::cout << "numbers[MAX_VAL] = 0;" << std::endl;
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << MAG << e.what() << RT << std::endl;
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}

		//final test
		std::cout << "\n\n\nfinal test(numbers):" << numbers << std::endl;
		std::cout << RED << "***MIRROR GONE!!" << RT << std::endl;
		delete [] mirror;
		//delete deletes a single object
		//while delete [] deletes ARRAYS of objects!
		// so if your pointer got tons of array, delete with delete []
	}






/*
	std::cout << GREEN << "\n\n\n---------------------------------\n" \
		<< "|\tOfficial Test 1\t\t|\n" \
		<< "---------------------------------\n" \
		<< RT << std::endl;
	{
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
	
		srand(time(NULL));
	
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
	
		//SCOPE
		{
				Array<int> tmp = numbers;
				Array<int> test(tmp);
		}
	
		for (int i = 0; i < MAX_VAL; i++)
		{
			 if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
	
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	
		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
	}
*/
	return (0);
}
