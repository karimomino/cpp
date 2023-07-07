/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:11:04 by kamin             #+#    #+#             */
/*   Updated: 2023/07/07 11:11:06 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack( void ) const {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}