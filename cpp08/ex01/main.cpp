/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 03:53:25 by abel-hid          #+#    #+#             */
/*   Updated: 2023/12/20 11:22:42 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iostream>
#include <vector>
#include <limits>
#include <stdexcept>

class Span {
private:
    unsigned int N;
    std::vector<int> numbers;

public:

    Span(unsigned int N) 
    {
        this->N = N;
    }

    void addNumber(int num) 
    {
        if (numbers.size() >= N) 
        {
            throw std::out_of_range("no more space to add numbers");
        }
        numbers.push_back(num);
    }

    
    int shortestSpan()  
    {
        if (numbers.size() < 2) 
        {
            throw std::logic_error("need at least 2 numbers to find span");
        }

       unsigned int min = std::numeric_limits<unsigned int>::max();

       for (size_t i = 0 ; i < numbers.size() ; i++)
       {
            for (size_t j = i + 1 ; j < numbers.size() ; j++)
            {
                unsigned int min_span;
                min_span = std::abs(numbers[i] - numbers[j]);
                min = std::min(min , min_span);
            }
       }
            return (min);
    }

    int longestSpan() 
    {
        if (numbers.size() < 2) {
             throw std::logic_error("need at least 2 numbers to find span");
        }

       unsigned int max = 0;

        for (size_t i = 0; i < numbers.size(); i++) 
        {
            for (size_t j = i + 1; j < numbers.size(); j++) 
            {
                unsigned int max_span = std::abs(numbers[i] - numbers[j]);
                max = std::max(max, max_span);
            }
        }
        return max;
    }
};

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(5);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}