/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 06:05:39 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/17 06:09:10 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP


#include <iostream>
#include <fstream>
std::string replace_string(std::string &line, std::string &s2, std::string &s1);

void replace(std::string &str, std::string &s1, std::string &s2);

#endif