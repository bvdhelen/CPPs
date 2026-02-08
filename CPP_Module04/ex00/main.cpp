/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 17:58:17 by eldiaz-c          #+#    #+#             */
/*   Updated: 2026/02/04 12:14:31 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const Animal	*meta = new Animal();
    const Animal	*j = new Dog();
    const Animal	*i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

	delete meta;
	delete j;
	delete i;
	
    return (0);
}


//	MAIN GOOD ANIMALS
/*int	main(void)
{
	std::cout << "=== Creating animals ===" << std::endl;
	
	const Animal	*meta = new Animal();
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();
	
	std::cout << std::endl;
	
	std::cout << "meta type: " << meta->getType() << std::endl;
	std::cout << "dog type: " << dog->getType() << std::endl;
	std::cout << "cat type: " << cat->getType() << std::endl;

	std::cout << std::endl;

	meta->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;
	std::cout << "=== Deleting animals ===" << std::endl;
	
	delete meta;
	delete dog;
	delete cat;

	return (0);
}*/

//	MAIN GOOD-WRONG ANIMALS
/*int	main(void)
{
	std::cout << "=== Correct polymorphism ===" << std::endl;
	
	const Animal	*a = new Dog();
	const Animal	*b = new Cat();

	a->makeSound();
	b->makeSound();

	delete a;
	delete b;
	
	std::cout << std::endl;
	std::cout << "=== Wrong polymorphism ===" << std::endl;
	
	const WrongAnimal	*wb = new WrongCat();

	wb->makeSound();

	delete wb;
	
	return (0);
}*/
