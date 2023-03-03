#include "PhoneBook.hpp"

PhoneBook::PhoneBook(/* args */)
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::welcome(void) const {
	std::cout << std::endl;
	std::cout << "\033[1;41mWelcome to The PhoneBook\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "--------------USAGE---------------" << std::endl;
	std::cout << "ADD\t: To add a contact." << std::endl;
	std::cout << "SEARCH\t: To search for a contact." << std::endl;
	std::cout << "EXIT\t: to quite the PhoneBook." << std::endl;
	std::cout << "----------------------------------" << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::addContact(void) {
	static int  i;
	this->_contacts[i % 8].init();
	this->_contacts[i % 8].setIndex(i % 8);
	i++;
}

void	PhoneBook::printContacts(void) const {
	std::cout << "------------- PHONBOOK CONTACTS -------------" << std::endl;
	std::cout << "|" << std::setw(10) << "     index" << std::flush;
    std::cout << "|" << std::setw(10) << "First Name" << std::flush;
    std::cout << "|" << std::setw(10) << " Last Name" << std::flush;
    std::cout << "|" << std::setw(10) << "  Nickname" << std::flush;
    std::cout << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for (size_t i = 0; i < 8; i++) {
		this->_contacts[i].view(i);
	}
	std::cout << std::endl;
}

int	 PhoneBook::_readInput() const {
	int	 input = -1;
	bool	valid = false;
	do
	{
		std::cout << "Please enter the contact index: " << std::flush;
		std::cin >> input;
		if (std::cin.good() && (input >= 0 && input <= 8)) {
			valid = true;
		} else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "\033[1;31mInvalid index.\033[0m" << std::endl;
		}
	} while (!valid);
	return (input);
}

void	PhoneBook::search(void) const {
	int i = this->_readInput();
	this->_contacts[i].display(i);
}