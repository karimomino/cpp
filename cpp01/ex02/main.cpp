/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:46:29 by kamin             #+#    #+#             */
/*   Updated: 2023/07/07 10:46:30 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main( void )
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPtr = &str;
	std::string &stringRef = str;

	std::cout << "ADDRESS OF str: " << &str << std::endl;
	std::cout << "ADDRESS OF stringPtr: " << stringPtr << std::endl;
	std::cout << "ADDRESS OF stringRef: " << &stringRef << std::endl;
	std::cout << "VALUE OF str: " << str << std::endl;
	std::cout << "VALUE OF stringPtr: " << *stringPtr << std::endl;
	std::cout << "VALUE OF stringRef: " << stringRef << std::endl;

	return 0;
}