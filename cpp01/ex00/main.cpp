/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:39:27 by kamin             #+#    #+#             */
/*   Updated: 2023/07/07 09:39:29 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
    std::string name;

    std::cout << "Creating zombie on the stack." << std::endl;
    std::cout << "Zombie name: " << std::flush;
    std::cin >> name;
    Zombie zombie_stack(name);
    zombie_stack.announce();
    std::cout << std::endl;
    
    std::cout << "Creating zombie on the heap." << std::endl;
    std::cout << "Zombie name: " << std::flush;
    std::cin >> name;
    Zombie *zombie_heap = newZombie(name);
    zombie_heap->announce();
    delete zombie_heap;
    std::cout << std::endl;

    std::cout << "Creating random zombie" << std::endl;
    randomChump("Niño");
    return 0;
}