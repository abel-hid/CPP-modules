/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 05:57:04 by abel-hid          #+#    #+#             */
/*   Updated: 2024/02/12 02:35:23 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP


#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>
#include <utility>
#include <ctime>
#include <iomanip>

// std vector
void merge_sort_pairs(std::vector<std::pair<std::string, std::string> >& pair);
void print_main_chain(std::vector<int>& vec);
void print_pend_chain(std::vector<int>& vec);
void print_jacobsthal(std::vector<std::string>& vec);
void print_pairs(std::vector<std::pair<std::string, std::string> >& pair);
void set_pairs(std::vector<std::string>& vec, std::vector<std::pair<std::string, std::string> >& pair);
void set_pend_chain(std::vector<int>& pend_chain, std::vector<std::pair<std::string, std::string> >& pair);
void set_main_chain(std::vector<int>& main_chain, std::vector<std::pair<std::string, std::string> >& pair);
void set_jacobsthal(std::vector<std::string>& jacobsthal, std::vector<int>& pend_chain);
void sorting(std::vector<int> & main_chain , std::vector<int> & pend_chain , std::vector<std::string> & jacobsthal , std::string & odd);
// std deque

void merge_sort_pairs(std::deque<std::pair<std::string, std::string> >& pair);
void print_main_chain(std::deque<int>& vec);
void print_pend_chain(std::deque<int>& vec);
void print_jacobsthal(std::deque<std::string>& vec);
void print_pairs(std::deque<std::pair<std::string, std::string> >& pair);
void set_pairs(std::deque<std::string>& vec, std::deque<std::pair<std::string, std::string> >& pair);
void set_pend_chain(std::deque<int>& pend_chain, std::deque<std::pair<std::string, std::string> >& pair);
void set_main_chain(std::deque<int>& main_chain, std::deque<std::pair<std::string, std::string> >& pair);
void set_jacobsthal(std::deque<std::string>& jacobsthal, std::deque<int>& pend_chain);
void sorting(std::deque<int> & main_chain , std::deque<int> & pend_chain , std::deque<std::string> & jacobsthal , std::string & odd);
#endif
