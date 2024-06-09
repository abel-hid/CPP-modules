/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-hid <abel-hid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:29:06 by abel-hid          #+#    #+#             */
/*   Updated: 2023/11/04 19:38:49 by abel-hid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP


# include <iostream>

class Brain
{
   private:
    std::string ideas[100];
    public:
        Brain();
        ~Brain();
        Brain(Brain const &brain);
        Brain &operator=(Brain const &brain);
        void setIdeas(std::string idea);
};


#endif