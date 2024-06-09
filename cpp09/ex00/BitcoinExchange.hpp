/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 02:40:39 by abel-hid          #+#    #+#             */
/*   Updated: 2024/02/16 00:50:38 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP


#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

class BitcoinExchange
{
    private:
        std::map<std::string, float> csvData;
    public:
        void    setMap(std::string line);
        void   printMap();
        
        std::string findClosestDate(const std::string str);

        int good_input(std::string str);


        void exchange(std::ifstream &input);
        int check_value(std::string value);
        
        
};

#endif