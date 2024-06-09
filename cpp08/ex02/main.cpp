/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 01:23:48 by abel-hid          #+#    #+#             */
/*   Updated: 2024/01/26 09:16:17 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <vector>
#include<deque>
#include <list>
#include <algorithm>

template <typename T, typename a = std::deque<T> >

class MutantStack : public std::stack<T, a >
{
public:
   typedef typename a::iterator iterator;

    iterator begin() 
    {
        return (this->c.begin()); 
    }
    iterator end()
    {
        return (this->c.end()); 
    }
    MutantStack()
    {
    }
    ~MutantStack()
    {
    }
    MutantStack(MutantStack const &src)
    {
        *this = src;
    }

    MutantStack &operator=(MutantStack const &rhs)
    {
        if (this != &rhs)
            std::stack<T, a >::operator=(rhs);
        return (*this);
    }
};


int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    std::cout <<"size: " << mstack.size() << std::endl;
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int > s(mstack);
    return 0;

}