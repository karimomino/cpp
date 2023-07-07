/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:52:56 by kamin             #+#    #+#             */
/*   Updated: 2023/07/07 11:52:57 by kamin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(std::string filename) : _inFile(filename){
	this->_outFile = this->_inFile + ".replace";
}

Sed::~Sed ( void ) {

}


std::vector<std::string> Sed::_split_string( std::string str , const std::string delim ) {
	std::string word;
	std::vector<std::string> wordList;

	size_t pos = 0;
	while ((pos = str.find(delim)) != std::string::npos) {
		word = str.substr(0, pos);
		wordList.push_back(word);
		str.erase(0, pos + delim.length());
	}
	pos = str.find(delim);
	word = str.substr(0, pos);
	wordList.push_back(word);
	return ( wordList );
}

void			Sed::replace( std::string toFind, std::string replace) {
	std::ifstream	in;
	in.open(this->_inFile.c_str() , std::ios::in);
	std::string content;
	
	if (in.is_open()) {
		if (std::getline(in, content, '\0')) {
			std::ofstream	out;
			out.open(this->_outFile.c_str() , std::ios::out);
			std::vector<std::string> wordList = _split_string( content , toFind);
			std::vector<std::string>::iterator wordList_it = wordList.begin();
			while ( wordList_it != wordList.end() - 1 )
			{
				out << *wordList_it + replace;
				wordList_it++;
			}
			out << *wordList_it;
			out.close();

		} else {
			std::cerr << "Empty file found." << std::endl;
		}
		in.close();
	} else {
		std::cerr << "Unable to open the file." << std::endl;
		exit( 1 );
	}
}