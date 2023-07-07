/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:11:18 by kamin             #+#    #+#             */
/*   Updated: 2023/07/07 11:11:18 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type) {
	this->setType(type);
}

Weapon::~Weapon() {}

const std::string& Weapon::getType( void ) const {
	return ( this->type );
}

void	Weapon::setType( std::string newType ) {
	this->type = newType;
}