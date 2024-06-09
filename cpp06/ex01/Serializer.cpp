/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:12:15 by abel-hid          #+#    #+#             */
/*   Updated: 2024/02/04 17:19:45 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer::Serializer(Serializer const &s)
{
    *this = s;
}

Serializer &Serializer::operator=(Serializer const &s)
{
    (void)s;
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}

void Serializer::convert()
{
    Data data;
    Serializer s;
    data.n = 42;
    data.c = 'a';
    data.b = true;
    data.s1 = "Hello";
    data.s2 = "World";
    uintptr_t raw = s.serialize(&data);
    Data* ptr = s.deserialize(raw);
    std::cout << "n: " << ptr->n << std::endl;
    std::cout << "c: " << ptr->c << std::endl;
    std::cout << "b: " << ptr->b << std::endl;
    std::cout << "s1: " << ptr->s1 << std::endl;
    std::cout << "s2: " << ptr->s2 << std::endl;
}


