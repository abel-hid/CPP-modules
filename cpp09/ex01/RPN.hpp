/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 04:21:36 by abel-hid          #+#    #+#             */
/*   Updated: 2024/02/16 02:54:27 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <list>
#include <sstream>


class RPN
{
    private:
        std::string str;
        std::list<int> list;
    public:
        RPN(std::string str);
        RPN();
        RPN(RPN const &rpn);
        RPN &operator=(RPN const &rpn);
        ~RPN();
        int is_digit(std::string &str);
        std::string update_str(std::string str);
        void calculate();
    
};


#endif