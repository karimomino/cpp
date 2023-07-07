/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:49:23 by kamin             #+#    #+#             */
/*   Updated: 2023/07/07 09:49:25 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void ) {
	const int N = 4;
	Zombie *zombies = zombieHorde(N, "zombie");

	for (size_t i = 0; i < N; i++) {
		zombies[i].announce();
	}

	delete [] zombies;
	return 0;
}