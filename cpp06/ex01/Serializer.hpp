/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 09:50:39 by abel-hid          #+#    #+#             */
/*   Updated: 2024/02/04 17:20:58 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP


#include <iostream>

struct Data
{
    int n;
    char c;
    bool b;
    std::string s1;
    std::string s2;
};

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(Serializer const &s);
        Serializer &operator=(Serializer const &s);
    
    public:
        uintptr_t serialize(Data* ptr);
        Data* deserialize(uintptr_t raw);
        static void convert();
};


#endif