/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 02:45:34 by abel-hid          #+#    #+#             */
/*   Updated: 2024/02/16 02:11:15 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


void BitcoinExchange::setMap(std::string line)
{
    std::string data;
    std::string value;
    data = line.substr(0, line.find(','));
    value = line.substr(line.find(',') + 1);
    csvData[data] = std::atof(value.c_str());
}

void BitcoinExchange::printMap()
{
    std::map<std::string, float>::iterator it = csvData.begin();
    while (it != csvData.end())
    {
        std::cout << it->first;
        if (it->second)
            std::cout << "," << it->second;
        std::cout << std::endl;
        it++;
    }
}

std::string BitcoinExchange::findClosestDate(const std::string str)
{
    std::string closestDate = "";
    std::map<std::string, float>::iterator it = csvData.begin();
    while (it != csvData.end())
    {
        if (it->first < str)
        {
            closestDate = it->first;
        }
        it++;
    }
    return closestDate;
}


int BitcoinExchange::good_input(std::string str)
{
    std::string delimiter = "-";
    std::istringstream stream(str);
    std::string token;

    if (str < "2009-01-02" || str > "2022-03-29")
        return 0;
    int i = 0;
    std::string year;
    std::string month;
    std::string day;
    while (getline(stream, token, '-'))
    {
        if(i == 0)
            year = token;
        if(i == 1)
            month = token;
        if(i == 2)
            day = token;
        i++;
    }
    
    if (year.size() != 4 || month.size() > 2 || day.size() > 2)
        return (0);
    else
    {
        if (year.size() == 4 && month.size() <= 2 && day.size() <= 2)
        {
            if(std::atoi(year.c_str()) > 2008 && std::atoi(year.c_str()) < 2023)
            {
                if(std::atoi(month.c_str()) > 0 && std::atoi(month.c_str()) < 13)
                {
                    int len = std::atoi(month.c_str()) ;
                    if (len == 1 || len == 3 || len  == 5 || len == 7 || len == 8 || len == 10 || len == 12)
                        if(std::atoi(day.c_str()) > 0 && std::atoi(day.c_str()) < 32)
                            return (1);
                    if (len == 2)
                    {
                        if(std::atoi(day.c_str()) > 0 && std::atoi(day.c_str()) < 30)
                            return (1);
                    }
                    else
                        if(std::atoi(day.c_str()) > 0 && std::atoi(day.c_str()) < 31)
                            return (1);
                }
            }
        }
    }
    return (0);
}

int BitcoinExchange::check_value(std::string value)
{
    int dot_count = 0;
    int i = 0;
    while (value[i])
    {
        if((value[i] == '-' && i != 0) || (value[i] == '-' && value[i + 1] == '.'))
            return (0);
        if(value[i] == '+' && i != 0)
            return (0);
        if(value[i] == '-' || value[i] == '+')
        {
            if(value[1] == '.')
                return (0);
            i++;
        }
        if (value[i] == '.')
        {
            if(i == 0)
                return (0);
            dot_count++;
            i++;
        }
        if (dot_count > 1)
            return (0);
        if (value[i] < '0' || value[i] > '9')
            return (0);
        i++;
    }
    return (1);
}


void BitcoinExchange::exchange(std::ifstream &input)
{

    std::string line;
    getline(input, line);
    if(line != "date | value")
    {
        std::cout << "Error: invalid file format." << std::endl;
        return;
    }
    
    
    
    while(getline(input, line))
    {
        std::string data;
        std::string value;

        data = line.substr(0, line.find(' '));
        value = line.substr(line.find('|') + 1);
        data.erase(std::remove(data.begin(), data.end(), ' '), data.end());
        value.erase(std::remove(value.begin(), value.end(), ' '), value.end());
        if(data == value)
            value = "";

        std::map<std::string, float>::iterator it1 = csvData.begin();
        while (it1 != csvData.end())
        {
                if (data == it1->first)
                {
                    if(std::atof(value.c_str())  < 0 && check_value(value) == 1)
                    {
                        std::cout << "Error: not a positive number."<< std::endl;
                        break;
                    }
                    else if (std::atof(value.c_str()) > 1000)
                    {
                        std::cout << "Error: too large a number."<< std::endl;
                        break;
                    }
                    if (value == "" || good_input(data) == 0 || check_value(value) == 0)
                    {
                        std::cout <<"Error: bad input => " << data << std::endl;
                        break;
                    }
                    std::cout << data << " => " << std::atof(value.c_str())  << " = " << it1->second * std::atof(value.c_str()) << std::endl;
                    break;
                }
                it1++;
            }
            
            if (it1 == csvData.end() && value != "")
            {
                std::string a = findClosestDate(data);
                if(std::atof(value.c_str())  < 0 && check_value(value) == 1)
                {
                    std::cout << "Error: not a positive number."<< std::endl;
                }
                else if (std::atof(value.c_str()) > 1000)
                {
                    std::cout << "Error: too large a number."<< std::endl;
                }
                else if (a != "" &&  check_value(value) == 1 && good_input(data) == 1)
                {
                    std::cout << data << " => " << std::atof(value.c_str())   << " = " << csvData[a] * std::atof(value.c_str()) << std::endl;
                }
                else
                {
                    std::cout << "Error: bad input => " << data << std::endl;
                }
            }
            if(value == "")
              std::cout << "Error: bad input => " << data << std::endl;
            
    }
}