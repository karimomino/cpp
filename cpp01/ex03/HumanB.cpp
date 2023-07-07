/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:11:09 by kamin             #+#    #+#             */
/*   Updated: 2023/07/07 11:11:10 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name) {
	this->_weapon = NULL;
}

HumanB::~HumanB() {}

void	HumanB::setWeapon( Weapon& weapon ) {
	this->_weapon = &weapon;
}

void	HumanB::attack( void ) const {
	if (this->_weapon != NULL && this->_weapon->getType() != "") {
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	} else {
		std::cout << this->_name << " attacks with their fists." << std::endl;
	}
}