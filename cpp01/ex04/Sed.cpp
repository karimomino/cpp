/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:52:56 by kamin             #+#    #+#             */
/*   Updated: 2023/07/09 08:29:28 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string filename) : _inFile(filename){
	this->_outFile = this->_inFile + ".replace";
}

Sed::~Sed ( void ) {

}

std::string Sed::_findAndReplace( std::string str , std::string replace , const std::string delim ) {
	std::stringstream ss;
	
	std::string word;

	size_t pos = 0;
	while ((pos = str.find(delim)) != std::string::npos) {
		word = str.substr(0, pos);
		ss << word + replace;
		str.erase(0, pos + delim.length());
	}
	pos = str.find(delim);
	word = str.substr(0, pos);
	ss << word;
	return ( ss.str() );
}

void			Sed::replace( std::string toFind, std::string replace) {
	std::ifstream	in;
	in.open(this->_inFile.c_str() , std::ios::in);
	std::string content;
	
	if (in.is_open()) {
		if (std::getline(in, content, '\0')) {
			std::ofstream	out;
			out.open(this->_outFile.c_str() , std::ios::out);
			if ( toFind.compare( "" ) )
				out << _findAndReplace( content , replace , toFind);
			else
				out << content;
			out.close();

		} else {
			std::cerr << "Empty file found." << std::endl;
		}
		in.close();
	} else {
		std::cerr << "Unable to open the file." << std::endl;
	}
}