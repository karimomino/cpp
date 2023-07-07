/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:52:54 by kamin             #+#    #+#             */
/*   Updated: 2023/07/07 11:52:55 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

class Sed
{
private:
	std::string _inFile;
	std::string _outFile;
	std::vector<std::string> _split_string( std::string str , const std::string delim );

public:
	Sed( std::string filename );
	~Sed();

	void	replace( std::string s1, std::string s2 );
};

#endif