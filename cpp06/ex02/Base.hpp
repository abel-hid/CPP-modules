/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:43:25 by abel-hid          #+#    #+#             */
/*   Updated: 2024/02/04 17:48:12 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>

class Base
{
    public:
        virtual ~Base();
        Base();
        Base(Base const &base);
        Base &operator=(Base const &base);
};

class A : public Base
{
    public:
        A();
        ~A();
        A(A const &a);
        A &operator=(A const &a);
    
};

class B : public Base
{
    public:
        B();
        ~B();
        B(B const &b);
        B &operator=(B const &b);
};

class C : public Base
{
    public:
        C();
        ~C();
        C(C const &c);
        C &operator=(C const &c);
};

Base *generate();
void identify(Base *p);
void identify(Base &p);

#endif