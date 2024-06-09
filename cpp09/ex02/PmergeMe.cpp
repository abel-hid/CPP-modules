/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:58:35 by abel-hid          #+#    #+#             */
/*   Updated: 2024/02/12 02:29:26 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// std vector
void merge_sort_pairs(std::vector<std::pair<std::string, std::string> >& pair)
{
    if (pair.size() <= 1)
        return;
    std::vector<std::pair<std::string, std::string> > right;
    std::vector<std::pair<std::string, std::string> > left;

    std::vector<std::pair<std::string, std::string> >::iterator it = pair.begin();
    size_t i = 0;
    while (it != pair.end())
    {
        if (i < pair.size() / 2)
            left.push_back(*it);
        else
            right.push_back(*it);
        it++;
        i++;
    }
    merge_sort_pairs(left);
    merge_sort_pairs(right);

    pair.clear();
    std::vector<std::pair<std::string, std::string> >::iterator left_it = left.begin();
    std::vector<std::pair<std::string, std::string> >::iterator right_it = right.begin();
    while (left_it != left.end() && right_it != right.end())
    {
        if (std::atoi(left_it->first.c_str()) < std::atoi(right_it->first.c_str()))
        {
            pair.push_back(*left_it);
            left_it++;
        }
        else
        {
            pair.push_back(*right_it);
            right_it++;
        }
    }
    while (left_it != left.end())
    {
        pair.push_back(*left_it);
        left_it++;
    }
    while (right_it != right.end())
    {
        pair.push_back(*right_it);
        right_it++;
    }
}

void print_main_chain(std::vector<int>& vec)
{
    std::cout << "After: ";
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end())
    {
        std::cout << *it;
        if (it + 1 != vec.end())
            std::cout << " ";
        it++;
    }
    std::cout << std::endl;
}

void print_pend_chain(std::vector<int>& vec)
{
    std::cout << "Pend chain: " << std::endl;
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end())
    {
        std::cout << *it;
        if (it + 1 != vec.end())
            std::cout << " ";
        it++;
    }
    std::cout << std::endl;
}

void print_jacobsthal(std::vector<std::string>& vec)
{
    std::cout << "Jacobsthal: " << std::endl;
    std::vector<std::string>::iterator it = vec.begin();
    while (it != vec.end())
    {
        std::cout << *it;
        if (it + 1 != vec.end())
            std::cout << " ";
        it++;
    }
    std::cout << std::endl;
}

void print_pairs(std::vector<std::pair<std::string, std::string> >& pair)
{
    std::cout << "Pairs: " << std::endl;
    std::vector<std::pair<std::string, std::string> >::iterator it = pair.begin();
    while (it != pair.end())
    {
        std::cout << it->first << " " << it->second << std::endl;
        it++;
    }
}

void set_pairs(std::vector<std::string>& vec, std::vector<std::pair<std::string, std::string> >& pair)
{
    std::vector<std::string>::iterator it = vec.begin();
    while (it != vec.end())
    {
        std::string first = *it;
        it++;
        if(it == vec.end())
            break;
        std::string second = *it;
        if (std::atoi(first.c_str()) < std::atoi(second.c_str()))
            std::swap(first, second);
        pair.push_back(std::make_pair(first, second));
        it++;
    }
}

void set_main_chain(std::vector<int>& main_chain, std::vector<std::pair<std::string, std::string> >& pair)
{
    std::vector<std::pair<std::string, std::string> >::iterator it = pair.begin();
    while (it != pair.end())
    {
        main_chain.push_back(std::atoi(it->first.c_str()));
        it++;
    }
}

void set_pend_chain(std::vector<int>& pend_chain, std::vector<std::pair<std::string, std::string> >& pair)
{
    std::vector<std::pair<std::string, std::string> >::iterator it = pair.begin();
    while (it != pair.end())
    {
        pend_chain.push_back(std::atoi(it->second.c_str()));
        it++;
    }
}

void set_jacobsthal(std::vector<std::string>& jacobsthal, std::vector<int>& pend_chain)
{
    int i = 0;
    while (1)
    {
        if (i == 0)
            jacobsthal.push_back("0");
        else if (i == 1)
            jacobsthal.push_back("1");
        else
        {
            std::string a = jacobsthal.back();
            jacobsthal.pop_back();
            std::string b = jacobsthal.back();
            jacobsthal.push_back(a);
            jacobsthal.push_back(std::to_string(std::atoi(a.c_str()) + 2 * std::atoi(b.c_str())));
            if ((std::atoi(a.c_str()) + 2 * std::atoi(b.c_str())) >= (int)pend_chain.size())
            {
                jacobsthal.pop_back();
                jacobsthal.push_back(std::to_string(pend_chain.size()));
                jacobsthal.erase(jacobsthal.begin());
                jacobsthal.erase(jacobsthal.begin());
                break;
            }
        }
        i++;
    }
}

void sorting(std::vector<int> & main_chain , std::vector<int> & pend_chain , std::vector<std::string> & jacobsthal , std::string & odd)
{

    std::vector<std::string>::iterator it = jacobsthal.begin();
    int position = std::atoi(it->c_str()) - 1;
    std::vector<int>::iterator insert_pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[position]);
    main_chain.insert(insert_pos, pend_chain[position]);
    it++;

       
    for (; it != jacobsthal.end(); it++) 
    {
        int index = position;
        position = std::atoi(it->c_str()) - 1;
        std::vector<int>::iterator insert_pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[position]);
        main_chain.insert(insert_pos, pend_chain[position]);
        position--;
        while (index < position)
        {
            std::vector<int>::iterator insert_pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[position]);
            main_chain.insert(insert_pos, pend_chain[position]);
            position--;
        }
        position = std::atoi(it->c_str()) - 1;
    }

    if(!odd.empty())
    {
        std::vector<int>::iterator insert_pos = std::lower_bound(main_chain.begin(), main_chain.end(), std::atoi(odd.c_str()));
        main_chain.insert(insert_pos, std::atoi(odd.c_str()));
    }
}

// std deque
void merge_sort_pairs(std::deque<std::pair<std::string, std::string> >& pair)
{
    if (pair.size() <= 1)
        return;
    std::deque<std::pair<std::string, std::string> > right;
    std::deque<std::pair<std::string, std::string> > left;

    std::deque<std::pair<std::string, std::string> >::iterator it = pair.begin();
    size_t i = 0;
    while (it != pair.end())
    {
        if (i < pair.size() / 2)
            left.push_back(*it);
        else
            right.push_back(*it);
        it++;
        i++;
    }
    merge_sort_pairs(left);
    merge_sort_pairs(right);

    pair.clear();
    std::deque<std::pair<std::string, std::string> >::iterator left_it = left.begin();
    std::deque<std::pair<std::string, std::string> >::iterator right_it = right.begin();
    while (left_it != left.end() && right_it != right.end())
    {
        if (std::atoi(left_it->first.c_str()) < std::atoi(right_it->first.c_str()))
        {
            pair.push_back(*left_it);
            left_it++;
        }
        else
        {
            pair.push_back(*right_it);
            right_it++;
        }
    }
    while (left_it != left.end())
    {
        pair.push_back(*left_it);
        left_it++;
    }
    while (right_it != right.end())
    {
        pair.push_back(*right_it);
        right_it++;
    }
}

void print_main_chain(std::deque<int>& vec)
{
    std::cout << "After: " ;
    std::deque<int>::iterator it = vec.begin();
    while (it != vec.end())
    {
        std::cout << *it;
        if (it + 1 != vec.end())
            std::cout << " ";
        it++;
    }
    std::cout << std::endl;
}

void print_pend_chain(std::deque<int>& vec)
{
    std::cout << "Pend chain: " << std::endl;
    std::deque<int>::iterator it = vec.begin();
    while (it != vec.end())
    {
        std::cout << *it;
        if (it + 1 != vec.end())
            std::cout << " ";
        it++;
    }
    std::cout << std::endl;
}

void print_jacobsthal(std::deque<std::string>& vec)
{
    std::cout << "Jacobsthal: " << std::endl;
    std::deque<std::string>::iterator it = vec.begin();
    while (it != vec.end())
    {
        std::cout << *it;
        if (it + 1 != vec.end())
            std::cout << " ";
        it++;
    }
    std::cout << std::endl;
}

void print_pairs(std::deque<std::pair<std::string, std::string> >& pair)
{
    std::cout << "Pairs: " << std::endl;
    std::deque<std::pair<std::string, std::string> >::iterator it = pair.begin();
    while (it != pair.end())
    {
        std::cout << it->first << " " << it->second << std::endl;
        it++;
    }
}

void set_pairs(std::deque<std::string>& vec, std::deque<std::pair<std::string, std::string> >& pair)
{
    std::deque<std::string>::iterator it = vec.begin();
    while (it != vec.end())
    {
        std::string first = *it;
        it++;
        if(it == vec.end())
            break;
        std::string second = *it;
        if (std::atoi(first.c_str()) < std::atoi(second.c_str()))
            std::swap(first, second);
        pair.push_back(std::make_pair(first, second));
        it++;
    }
   
}

void set_main_chain(std::deque<int>& main_chain, std::deque<std::pair<std::string, std::string> >& pair)
{
    std::deque<std::pair<std::string, std::string> >::iterator it = pair.begin();
    while (it != pair.end())
    {
        main_chain.push_back(std::atoi(it->first.c_str()));
        it++;
    }
}

void set_pend_chain(std::deque<int>& pend_chain, std::deque<std::pair<std::string, std::string> >& pair)
{
    std::deque<std::pair<std::string, std::string> >::iterator it = pair.begin();
    while (it != pair.end())
    {
        pend_chain.push_back(std::atoi(it->second.c_str()));
        it++;
    }
}

void set_jacobsthal(std::deque<std::string>& jacobsthal, std::deque<int>& pend_chain)
{
    int i = 0;
    while (1)
    {
        if (i == 0)
            jacobsthal.push_back("0");
        else if (i == 1)
            jacobsthal.push_back("1");
        else
        {
            std::string a = jacobsthal.back();
            jacobsthal.pop_back();
            std::string b = jacobsthal.back();
            jacobsthal.push_back(a);
            jacobsthal.push_back(std::to_string(std::atoi(a.c_str()) + 2 * std::atoi(b.c_str())));
            if ((std::atoi(a.c_str()) + 2 * std::atoi(b.c_str())) >= (int)pend_chain.size())
            {
                jacobsthal.pop_back();
                jacobsthal.push_back(std::to_string(pend_chain.size()));
                jacobsthal.erase(jacobsthal.begin());
                jacobsthal.erase(jacobsthal.begin());
                break;
            }
        }
        i++;
    }
}

void sorting(std::deque<int> &main_chain , std::deque<int> & pend_chain , std::deque<std::string> & jacobsthal , std::string & odd)
{

    std::deque<std::string>::iterator it = jacobsthal.begin();
    int position = std::atoi(it->c_str()) - 1;
    std::deque<int>::iterator insert_pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[position]);
    main_chain.insert(insert_pos, pend_chain[position]);
    it++;

       
    for (; it != jacobsthal.end(); it++) 
    {
        int index = position;
        position = std::atoi(it->c_str()) - 1;
        std::deque<int>::iterator insert_pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[position]);
        main_chain.insert(insert_pos, pend_chain[position]);
        position--;
        while (index < position)
        {
            std::deque<int>::iterator insert_pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[position]);
            main_chain.insert(insert_pos, pend_chain[position]);
            position--;
        }
        position = std::atoi(it->c_str()) - 1;
    }

    if(!odd.empty())
    {
        std::deque<int>::iterator insert_pos = std::lower_bound(main_chain.begin(), main_chain.end(), std::atoi(odd.c_str()));
        main_chain.insert(insert_pos, std::atoi(odd.c_str()));
    }
}