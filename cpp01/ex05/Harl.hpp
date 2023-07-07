/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:26:17 by kamin             #+#    #+#             */
/*   Updated: 2023/07/07 12:26:18 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
class	Harl
{
private:
	 void	 debug( void );
	 void	 info( void );
	 void	 warning( void );
	 void	 error( void );


public:
	 Harl();
	 ~Harl();

	 void	complain( std:: string level );

};

typedef void (Harl::*fun_ptr) ( void );