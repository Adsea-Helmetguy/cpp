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

#include "serializer_file/Serializer.hpp"

int	main(void)
{
	//create a Data object and use serialize's function on it
	//reinterpret_cast
	{
		Data* originalData = new Data("test_1");
		uintptr_t serializedData = 0;
		Data* deserializedData = NULL;

		std::cout << "Before starting -test1-\n" \
			<< "(" << MAG << originalData << RESET << "): " \
			<< YELLOW << *originalData << RT \
			<< "Value of above: " << YELLOW << serializedData << RT << "\n\n" << std::endl;






		//------------------------------------------------------------------------------------
		// Serialize the pointer
		serializedData = Serializer::serialize(originalData);
		std::cout << "(" << MAG << originalData << RESET << "): " \
			<< YELLOW << *originalData << RT \
			<< "Value of above: " << YELLOW << serializedData << RT << "\n\n" << std::endl;

		 // Deserialize the pointer
		deserializedData = Serializer::deserialize(serializedData);
		std::cout << "(" << MAG << originalData << RESET << "): " \
			<< YELLOW << *originalData << RT \
			<< "Value of above: " << YELLOW << serializedData << RT << std::endl;
		//------------------------------------------------------------------------------------







		// Verify that the deserialized pointer is equal to the original
		if (originalData == deserializedData)
		{
			std::cout << GREEN << "Deserialization successful!" << RT << std::endl;
			std::cout << "Data name: " << GREEN << deserializedData->getName() 
				<< RT << std::endl;
			std::cout << "Data uint: " << deserializedData->getUInt() << std::endl;
		}
		else
			std::cout << RED << "Deserialization failed!" << RT << std::endl;
		delete originalData;
	}
	std::cout << "\n\n\n" << std::endl;
	return (0);
}


/*
#include <iostream>
#include "Serializer.hpp"

int main() {
    // Create a Data object
    Data* originalData = new Data();
    
    // Serialize the pointer
    uintptr_t serializedData = Serializer::serialize(originalData);
    std::cout << "Serialized data: " << serializedData << std::endl;

    // Deserialize the pointer
    Data* deserializedData = Serializer::deserialize(serializedData);

    // Verify that the deserialized pointer is equal to the original
    if (originalData == deserializedData) {
        std::cout << "Deserialization successful!" << std::endl;
        std::cout << "Data name: " << deserializedData->getName() << std::endl;
        std::cout << "Data uint: " << deserializedData->getUInt() << std::endl;
    } else {
        std::cout << "Deserialization failed!" << std::endl;
    }

    delete originalData;
    return 0;
}

*/
//links used:
/*
https://faculty.cs.niu.edu/~winans/CS501/Notes/strings.html#:~:text=You%20can%20obtain%20the%20length,valid%20characters%20in%20the%20string.
*/
