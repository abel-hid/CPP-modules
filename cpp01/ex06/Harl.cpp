/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 06:25:12 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/17 06:27:23 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << "\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << "\n";
    std::cout << "\n";
}
void Harl::info(void)
{
    std::cout << "[ INFO ]" << "\n";
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
    std::cout << "\n";
}
void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << "\n";
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
    std::cout << "I’ve been coming here for years and you just started working here last month." << std::endl;
    std::cout << "\n";
}
void Harl::error(void)
{
    std::cout << "[ ERROR ]" << "\n";
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
    std::cout << "\n";
}

int Harl::get_index(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (level.compare(levels[i]) == 0)
            return (i);
    }
    return (-1);
}

void Harl::complain( std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for(int i = 0 ; i < 4; i++)
    {
        switch(get_index(level))
        {
            case 0:
                (this->*ptr[0])();

            case 1:
                (this->*ptr[1])();
                
            case 2:
                (this->*ptr[2])();
        
            case 3:
                (this->*ptr[3])();
                return ;
        }
    }
}