/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 00:14:14 by abel-hid          #+#    #+#             */
/*   Updated: 2024/02/04 20:52:28 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &sc)
{
    *this = sc;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &sc)
{
    if(this != &sc)
    {
        this->i = sc.i;
        this->f = sc.f;
        this->d = sc.d;
        this->c = sc.c;
    }
    return (*this);
}



void ScalarConverter::set_i(int i)
{
    this->i = i;
}

void ScalarConverter::set_f(float f)
{
    this->f = f;
}

void ScalarConverter::set_d(double d)
{
    this->d = d;
}

void ScalarConverter::set_c(char c)
{
    this->c = c;
}



int ScalarConverter::get_i()
{
    return (this->i);
}

float ScalarConverter::get_f()
{
    return (this->f);
}

double ScalarConverter::get_d()
{
    return (this->d);
}

char ScalarConverter::get_c()
{
    return (this->c);
}



void ScalarConverter::convert(std::string str)
{
        ScalarConverter sc;
        try
        {
            if(str == "nan" || str == "inf" ||  str == "+inf" ||  str == "-inf" || str == "nanf" || str == "inff" ||  str == "+inff" ||  str == "-inff") 
            {
                sc.set_f(std::atof(str.c_str()));
                sc.set_d(std::strtod(str.c_str(), NULL));
                if(str == "nan" || str == "nanf")
                    std::cout << "char: impossible" << std::endl;
                else
                    std::cout << "char: Non displayable" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << sc.get_f() << "f" << std::endl;
                std::cout << "double: " << sc.get_f() << std::endl;
                return ;
            }
            if(str.length() == 1 && !isdigit(str[0]))
            {
                    sc.set_c(str[0]);
                    sc.set_i(static_cast<int>(sc.get_c()));
                    sc.set_f(static_cast<float>(sc.get_c()));
                    sc.set_d(static_cast<double>(sc.get_c()));
                std::cout << "char: '" << sc.get_c() << "'" << std::endl;
                std::cout << "int: " << sc.get_i() << std::endl;
                std::cout << "float: " << std::fixed << std::setprecision(1) << sc.get_f() << "f" << std::endl;
                std::cout << "double: " << std::fixed << std::setprecision(1) << sc.get_d() << std::endl;
                return ;
            }
            sc.set_d(std::strtod(str.c_str(), NULL));
            sc.set_f(std::atof(str.c_str()));
            sc.set_i(std::atoi(str.c_str()));
            sc.set_c(static_cast<char>(sc.get_i()));
            if(!isprint(sc.get_c()))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << sc.get_c() << "'" << std::endl;
            std::cout << "int: " << sc.get_i() << std::endl;
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << sc.get_f() << "f" << std::endl;
            std::cout << "double: " << sc.get_d() << std::endl;
            
        }
        catch(const std::exception& e)
        {
            std::cout << "Error" << std::endl;
        }
}