/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:22:53 by abel-hid          #+#    #+#             */
/*   Updated: 2023/10/17 06:08:33 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string replace_string(std::string &line, std::string &s2, std::string &s1)
{
    std::string new_line;
    int len = s1.length();
    int i = 0;
    while(line[i])
    {
        if(line[i] == s1[0])
        {
            if(line.substr(i, len) == s1)
            {
                new_line += s2;
                i += len;
            }
            else
            {
                new_line += line[i];
                i++;
            }
        }
        else
        {
            new_line += line[i];
            i++;
        }
    }
    return (new_line);
}

void replace(std::string &str, std::string &s1, std::string &s2)
{
    std::ifstream ifs(str);
    std::ofstream ofs(str + ".replace");

    std::string line;

    if (!ifs.is_open() || !ofs.is_open())
    {
        std::cout << "Error: file not found\n";
        return ;
    }

    while(std::getline(ifs, line))
    {
        if(line.find(s1) != std::string::npos)
            line = replace_string(line, s2, s1);
        ofs << line << std::endl;
    }
    ofs.close();
    ifs.close();
}