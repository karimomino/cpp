/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:11:11 by kamin             #+#    #+#             */
/*   Updated: 2023/07/09 08:32:26 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP

	#define HUMANB_HPP
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

#endif
