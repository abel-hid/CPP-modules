/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 03:51:19 by abel-hid          #+#    #+#             */
/*   Updated: 2023/12/20 01:51:29 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <array>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
    typename T::iterator it;

    it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::exception();
    return (it);
}

int main(void)
{
    std::vector<int> v;
    std::vector<std::string> v1;
    std::array<int, 5> a;
    std::vector<int>::iterator it;

    for (int i = 0; i < 5; i++)
    {
        v.push_back(i);
        a[i] = i;
    }
    try
    {
        std::cout << *easyfind(v, 3) << std::endl;
        std::cout << *easyfind(a, 3) << std::endl;
        std::cout << *easyfind(v, 8) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }
    return (0);
}