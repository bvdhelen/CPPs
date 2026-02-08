/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:58:17 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/08 21:24:39 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

/*
int main(void)
{
    const Animal	*j = new Dog();
    const Animal	*i = new Cat();

	delete j;
	delete i;
	
    return (0);
}*/

/*
int main(void)
{
	const Animal	*animals[10];

	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();
	
	for (int i = 0; i < 10; i++)
		delete animals[i];
}*/

int	main(void)
{
	std::cout << "===== Creating animals array =====" << std::endl;
	
	const int	size = 10;
	Animal	*animals[size];

	for (int i = 0; i < (size / 2); i++)
		animals[i] = new Dog();
	
	for (int i = (size / 2); i < size; i++)
		animals[i] = new Cat();
	
	std::cout << std::endl;
	std::cout << "===== Deleting animals array =====" << std::endl;
	for (int i = 0; i < size; i++)
		delete animals[i];
	
	std::cout << std::endl;
	std::cout << "===== Testing deep copy =====" << std::endl;
	
	Dog	original;
	Dog	copy(original);
	std::cout << std::endl;
	std::cout << "===== End of program =====" << std::endl;

	return (0);
}
