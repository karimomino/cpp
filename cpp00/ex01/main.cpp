#include "PhoneBook.hpp"
#include <limits>
#include <iostream>

int main(void) {
	PhoneBook book;
	std::string input = "";
	book.welcome();
	while (input.compare("EXIT")) {
		if (input.compare("ADD") == 0)
			book.addContact();
		else if (input.compare("SEARCH") == 0) {
			book.printContacts();
			book.search();
		}
		else{
			if (input != "")
				std::cout << "\033[1;31mInvalid command.\033[0m" << std::endl;
		}
		std::cout << "COMMAND> " << std::flush;
		std::cin >> input;
	}
	return 0;
}