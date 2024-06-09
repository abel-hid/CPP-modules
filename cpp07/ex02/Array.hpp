/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:17:36 by abel-hid          #+#    #+#             */
/*   Updated: 2024/02/07 18:44:52 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
template <typename T>
class Array
{
    private:
        T *array;
        size_t Size;
    public:
        Array() 
        {
            array = new T[0];
            Size = 0;
        }
        Array(unsigned int n)
        {
            try
            {
                array = new T[n];
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            Size = n;
        }
        Array(Array const & src) 
        {
            try
            {
                array = new T[src.Size];
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
            }
            
            Size = src.Size;
            for (unsigned int i = 0; i < Size; i++)
                array[i] = src.array[i];
        };
        ~Array()
        { 
            delete [] array; 
        };
        
        Array &operator=(Array const & src)
        {
            if (this != &src)
            {
                delete [] array;
                try
                {
                    array = new T[src.Size];
                }
                catch(const std::exception& e)
                {
                    std::cerr << e.what() << '\n';
                }
                Size = src.Size;
                for (unsigned int i = 0; i < Size; i++)
                    array[i] = src.array[i];
            }
            return *this;
        }
        T& operator[](unsigned int i)
        {
            if (i >= Size)
                throw std::runtime_error("index out of range");
            return array[i];
        }
        
        size_t size() const 
        { 
            return Size; 
        }
};

#endif