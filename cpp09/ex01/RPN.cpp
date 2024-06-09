/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 04:24:49 by abel-hid          #+#    #+#             */
/*   Updated: 2024/02/16 02:54:16 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(std::string str)
{
    this->str = str;
}
RPN::RPN(RPN const &rpn)
{
    *this = rpn;
}
RPN &RPN::operator=(RPN const &rpn)
{
    if(this != &rpn)
    {
        this->str = rpn.str;
        this->list = rpn.list;
    }
    return *this;
}

RPN::~RPN()
{
}

int RPN::is_digit(std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

RPN::RPN()
{
}

std::string RPN::update_str(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        while (i < str.size() && str[i] != ' ')
        {
            if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
            {
                str.insert(i, " ");
                str.insert(i + 2, " ");
                i += 2;
            }
            i++;
        }
    }
    return str;
}

void RPN::calculate()
{
        std::string tmp1;
        tmp1 = this->update_str(this->str);
        std::stringstream ss(tmp1);
        std::string tmp;

        while (ss >> tmp)
        {
            if (tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/")
            {
                if (this->list.size() < 2)
                    throw std::runtime_error("Error");
                else
                {
                    int a = this->list.back();
                    this->list.pop_back();

                    int b = this->list.back();

                    this->list.pop_back();
                    if (tmp == "+")
                        this->list.push_back(a + b);
                    else if (tmp == "-")
                        this->list.push_back(b - a);
                    else if (tmp == "*")
                        this->list.push_back(a * b);
                    else if (tmp == "/")
                    {
                        if (a == 0)
                            throw std::runtime_error("Error");
                        else
                            this->list.push_back(b / a);
                    }
                }
            }
            else
            {
                if (tmp.size() == 1 && !is_digit(tmp))
                    throw std::runtime_error("Error");
                else
                {
                    if(std::atoi(tmp.c_str()) < 0 || std::atoi(tmp.c_str()) > 9)
                            throw std::runtime_error("Error");
                    this->list.push_back(std::atoi(tmp.c_str()));
                }
            }
        }
        if (this->list.size() != 1)
        {
            throw std::runtime_error("Error");
        }
        else
            std::cout << this->list.back() << std::endl;
}
