/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:39:39 by kamin             #+#    #+#             */
/*   Updated: 2023/07/09 08:33:59 by kamin            ###   ########.fr       */
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
        Zombie( std::string name );
        ~Zombie();
        void    announce( void );
        Zombie* newZombie( std::string name );
        void    randomChump( std::string name );

    };

Zombie  *newZombie( std::string name );
void    randomChump( std::string name );

#endif