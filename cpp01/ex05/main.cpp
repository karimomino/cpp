/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:26:02 by kamin             #+#    #+#             */
/*   Updated: 2023/07/07 12:26:02 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

static bool prompt_level( std::string &response )
{
	std::cout << "Enter a level: ";
	std::cin >> response;

	return ( std::cin.good() );
}

int main( void ) {
	Harl		harl;
	std::string response;

	while ( prompt_level( response ) && response != "exit" )
		harl.complain( response );

	return 0;
}