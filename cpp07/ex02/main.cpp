#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
/*
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

		//Scope test
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
			//testing with the scope
			std::cout << "--TEST within \"SCOPE\", destructor occurs--" << std::endl;
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
		std::cout << "final test(numbers):" << numbers << std::endl;
		std::cout << RED << "***MIRROR GONE!!" << RT << std::endl;
		delete [] mirror;
		//delete deletes a single object
		//while delete [] deletes ARRAYS of objects!
		// so if your pointer got tons of array, delete with delete []
	}



















	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << GREEN \
		<< "\n\n\n--------------------------------------\n"
		<< "|Personal Test 2(Default constructor)|\n" \
		<< "--------------------------------------\n" \
		<< RT << std::endl;
	{
		std::cout << "--------Constructors Created:--------" << std::endl;
		int*	a = new int();
		std::cout << "Value of a: " << YELLOW << *a << RT << std::endl;

		Array<int>* empty = new Array<int>();
		std::cout << *empty << std::endl;
		std::cout << "------Constructors Created ends------" << std::endl;
		
		delete a;	//cause you created 'new
		delete empty;	//cause you created 'new'
	}

















	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << GREEN \
		<< "\n\n\n--------------------------------------\n"
		<< "|Personal Test 3(Array = 0)|\n" \
		<< "--------------------------------------\n" \
		<< RT << std::endl;
	{
		std::cout << "--------Constructors Created:--------" << std::endl;
		unsigned int	max_value = 0;
		
		Array<int> numbers(max_value);
		int* mirror = new int[max_value];
		std::cout << "------Constructors Created ends------\n\n\n" << std::endl;

		srand(time(NULL));

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

		for (unsigned int i = 0; i < max_value; i++)
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
			std::cout << "numbers[max_value] = 0;" << std::endl;
			numbers[max_value] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << MAG << e.what() << RT << std::endl;
		}

		for (unsigned int i = 0; i < max_value; i++)
		{
			numbers[i] = rand();
		}

		std::cout << "final test(numbers):" << numbers << std::endl;
		std::cout << RED << "***MIRROR GONE!!" << RT << std::endl;
		delete [] mirror;
	}






















	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << GREEN \
		<< "\n\n\n--------------------------------------\n"
		<< "|Personal Test 4(With Char)|\n" \
		<< "--------------------------------------\n" \
		<< RT << std::endl;
	{
		std::cout << "--------Constructors Created:--------" << std::endl;
		unsigned int	max_value = 750;
		
		Array<char> numbers(max_value + 1);
		char* mirror = new char[max_value + 1];
		std::cout << "------Constructors Created ends------\n\n\n" << std::endl;

		srand(time(NULL));

		for (unsigned int i = 0; i < max_value; i++)
		{
			const char value = static_cast<char>(rand() % (126 - 32 + 1) + 32);
			//std::ostringstream ss;//
			//ss << value;//saving as ascii value

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
		numbers[max_value] = '\0';
		mirror[max_value] = '\0';


		{
			Array<char> tmp = numbers;
			Array<char> test(tmp);
		}

		for (unsigned int i = 0; i < max_value; i++)
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
			numbers[-2] = 'C';
		}
		catch(const std::exception& e)
		{
			std::cerr << MAG << e.what() << RT << std::endl;
		}

		for (unsigned int i = 0; i < max_value; i++)
		{
			numbers[i] = rand();
		}

		std::cout << RED << "***MIRROR GONE!!" << RT << std::endl;
		delete [] mirror;
	}























	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << GREEN \
		<< "\n\n\n---------------------------------------------------------------\n"
		<< "| Personal Test 5 (const operator[] const(PDF last question)) |\n" \
		<< "---------------------------------------------------------------\n" \
		<< RT << std::endl;
	{
		std::cout << "--------Constructors Created:--------" << std::endl;
		const Array<int> number(1);
		std::cout << "------Constructors Created ends------\n\n\n" << std::endl;


		std::cout << "Value of created Array[0]: " \
			<< GREEN << number[0] << RT << std::endl;
	}













































*/
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << GREEN \
		<< "\n\n\n---------------------------------\n"
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
	return (0);
}
