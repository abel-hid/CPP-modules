/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:44:23 by abel-hid          #+#    #+#             */
/*   Updated: 2024/02/04 17:48:01 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"


// base class
Base::Base()
{
}

Base::~Base()
{
}

Base::Base(Base const &base)
{
    *this = base;
}

Base &Base::operator=(Base const &base)
{
    if(this != &base)
        *this = base;
    return (*this);
}

// A class
A::A()
{  
}

A::~A()
{
}

A::A(A const &a)
{
    *this = a;
}

A &A::operator=(A const &a)
{
    if(this != &a)
        *this = a;
    return (*this);
}

// B class
B::B()
{    
}

B::~B()
{
}

B::B(B const &b)
{
    *this = b;
}

B &B::operator=(B const &b)
{
    if(this != &b)
        *this = b;
    return (*this);
}

// C class

C::C()
{    
}

C::~C()
{
}

C::C(C const &c)
{
    *this = c;
}

C &C::operator=(C const &c)
{
    if(this != &c)
        *this = c;
    return (*this);
}

// functions
 
Base *generate(void)
{
    int i = rand() % 3;
    if(i == 0)
        return (new A());
    else if(i == 1)
        return (new B());
    else
        return (new C());
}

void identify(Base *p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{
    if(dynamic_cast<A*>(&p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;
}