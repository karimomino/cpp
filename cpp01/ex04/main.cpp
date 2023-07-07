/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:53:01 by kamin             #+#    #+#             */
/*   Updated: 2023/07/07 11:53:02 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

int main ( int ac, char **av )
{
    if (ac != 4) {
        std::cerr << "Usage: ./Sed <filename> <to_find> <replace>." << std::endl;
        return ( 1 );
    } else {
        Sed   sed(av[1]);
        sed.replace(av[2], av[3]);
    }
    return ( 0 );
}