/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 10:00:34 by kamin             #+#    #+#             */
/*   Updated: 2023/07/09 10:00:35 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP

	#define FIXED_HPP
	#include <iostream>

	class Fixed
	{
	private:
		int					_fixedPointVal;
		static const int	_fractionalBits = 8;

	public:
		Fixed( );
		Fixed( const Fixed &original );
		Fixed& operator=( const Fixed &rhs );
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const bits );
	};

#endif