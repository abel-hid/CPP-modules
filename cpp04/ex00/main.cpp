/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:57:00 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/08 20:56:26 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    const WrongAnimal* wrongcat = new WrongCat();
    const WrongAnimal * wronganimal = new WrongAnimal();
    std::cout << wrongcat->getType() << " " << std::endl;
    wrongcat->makeSound();
    wronganimal->makeSound();

    delete meta;
    delete j;
    delete i;
    delete wrongcat;
    delete wronganimal;


    return 0;
}