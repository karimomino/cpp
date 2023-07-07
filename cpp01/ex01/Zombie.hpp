/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:49:34 by kamin             #+#    #+#             */
/*   Updated: 2023/07/07 09:49:34 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string _name;

public:
	Zombie();
	~Zombie();
	void	announce( void );
	Zombie* newZombie( std::string name );
	void	setName( std::string name );

};

Zombie*	zombieHorde( int N, std::string name );

#endif