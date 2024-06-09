/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:34:59 by abel-hid          #+#    #+#             */
/*   Updated: 2024/02/07 18:37:26 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename F>
void iter(T array, size_t length, F f)
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

void f(char &c)
{
    std::cout << (char)toupper(c);
}

void fun(int &i)
{
    std::cout << i + 1;
}

#endif
