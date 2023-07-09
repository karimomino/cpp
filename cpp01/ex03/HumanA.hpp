/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:11:07 by kamin             #+#    #+#             */
/*   Updated: 2023/07/09 08:31:55 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP

	#define HUMANA_HPP
	#include "Weapon.hpp"

	class HumanA
	{
	private:
		std::string _name;
		Weapon&	 _weapon;

	public:
		HumanA( std::string name, Weapon& weapon );
		~HumanA();

		void	attack( void ) const;
	};
	
#endif