/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:59:56 by abel-hid          #+#    #+#             */
/*   Updated: 2024/02/16 03:09:21 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int is_digit(char **av)
{
    int i = 1;
    std::string str;
    while (av[i] != NULL)
    {
        int j = 0;
        str = av[i];
        if(str.empty())
            return (0);
        while (av[i][j] != '\0')
        {
            if (av[i][j] < '0' || av[i][j] > '9')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}


int is_sorted(char **av)
{
    int i = 1;
    while (av[i] != NULL)
    {
        if (av[i + 1] == NULL)
            return (1);
        if (std::atoi(av[i]) > std::atoi(av[i + 1]))
            return (0);
        i++;
    }
    return (1);
}

int is_positive(char **av)
{
    int i = 1;
    while (av[i] != NULL)
    {
        if (std::atoi(av[i]) < 0)
            return (0);
        i++;
    }
    return (1);
}

int is_sorted(std::vector<int> &vec)
{
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i] > vec[i + 1])
            return (0);
    }
    return (1);
}



void std_vector(std::vector<std::string> &vec ,std::string odd)
{
    std::vector<std::pair<std::string, std::string> > pair;
    std::vector<int> main_chain;
    std::vector<int> pend_chain;
    std::vector<std::string> jacobsthal;
    
    set_pairs(vec, pair);
    merge_sort_pairs(pair);
    // print_pairs(pair);
    set_main_chain(main_chain, pair);
    set_pend_chain(pend_chain, pair);
    set_jacobsthal(jacobsthal, pend_chain);
    // print_main_chain(main_chain);
    // print_pend_chain(pend_chain);
    sorting(main_chain, pend_chain, jacobsthal, odd);
    // print_jacobsthal(jacobsthal);
     print_main_chain(main_chain);
    
}

void std_deque(std::deque<std::string> &deq, std::string odd)
{
    std::deque<std::pair<std::string, std::string> > pair;
    std::deque<int> main_chain;
    std::deque<int> pend_chain;
    std::deque<std::string> jacobsthal;

    set_pairs(deq, pair);
    merge_sort_pairs(pair);
    // print_pairs(pair);
    set_main_chain(main_chain, pair);
    set_pend_chain(pend_chain, pair);
    set_jacobsthal(jacobsthal, pend_chain);
    // print_main_chain(main_chain);
    // print_pend_chain(pend_chain);
    sorting(main_chain, pend_chain, jacobsthal, odd);
    // print_jacobsthal(jacobsthal);
    // print_main_chain(main_chain);
}

int main(int ac, char** av)
{
    std::vector<std::string> vec;
    std::deque<std::string> deq;
    std::string odd;
    bool is_odd = false;

    odd = "";
    if (ac == 1 || !is_positive(av) || !is_digit(av))
    {
        std::cout << "Error" << std::endl;
        return 0;
    }
    if(is_sorted(av) == 1)
    {
        std::cout << "already sorted" << std::endl;
        return 0;
    }

    try
    {
        std::cout << "Before: ";
        for (int i = 1; i < ac; i++)
        {
            vec.push_back(av[i]);
            deq.push_back(av[i]);
            std::cout << av[i] << " ";
        }
        std::cout << std::endl;

        if (vec.size() == 0)
            return 0;
        if (vec.size() % 2 != 0)
        {
            odd = vec.back();
            odd = deq.back();
            deq.pop_back();
            vec.pop_back();
            is_odd = true;
        }
        
        clock_t start = clock();
        std_vector(vec, odd);
        clock_t end = clock();
        double time_taken = double(end - start) / CLOCKS_PER_SEC;
        if(is_odd)
        {
            vec.push_back(odd);
        }
        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << std::fixed  << time_taken * 1000000 << " us" << std::endl;

        start = clock();
        std_deque(deq, odd);
        end = clock();
        time_taken = double(end - start) / CLOCKS_PER_SEC;
        if(is_odd)
        {
            deq.push_back(odd);
        }
        std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << std::fixed  << time_taken * 1000000 << " us" << std::endl;
    
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error" << '\n';
    }
}
