/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:11:11 by kamin             #+#    #+#             */
/*   Updated: 2023/07/07 11:11:12 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB
{
private:
	std::string	_name;
	Weapon*		_weapon;

public:
	HumanB( std::string name );
	~HumanB();

	void	attack( void ) const;
	void	setWeapon( Weapon& weapon );
};
