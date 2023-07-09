/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:52:54 by kamin             #+#    #+#             */
/*   Updated: 2023/07/09 08:29:21 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP

	#define SED_HPP
	#include <iostream>
	#include <fstream>
	#include <vector>
	#include <stdlib.h>
	#include <sstream>




	class Sed
	{
	private:
		std::string _inFile;
		std::string _outFile;
		std::string					_findAndReplace( std::string str , std::string replace , const std::string delim );

	public:
		Sed( std::string filename );
		~Sed();

		void	replace( std::string s1, std::string s2 );
	};

#endif