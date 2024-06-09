/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 00:01:09 by abel-hid          #+#    #+#             */
/*   Updated: 2024/02/16 02:10:44 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac , char **av)
{
    try
    {
    
        std::ifstream csv_file("./data.csv");
        std::ifstream input(av[1]);
        if (!csv_file.is_open())
        {
            std::cout << "Error: could not open file." << std::endl;
            return (1);
        }
        if (!input.is_open() || ac != 2)
        {
            std::cout << "Error: could not open file." << std::endl;
            return (1);
        }
        
        BitcoinExchange b;
        std::string line;
        getline(csv_file, line);
        if(line != "date,exchange_rate")
        {
            std::cout << "Error: invalid file format." << std::endl;
            return (1);
        }
        while(getline(csv_file, line))
        {
            b.setMap(line);
        }

        b.exchange(input);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
   
    return (0);
}