#include "FragTrap.hpp"

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;

	std::cout << "FragTrap " << _name << " joined the world!" << std::endl;

}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " disconnected." << std::endl;

}

void    FragTrap::highFive( void ) {
    std::cout << "[FRAGTRAP - " << this->_name << " ] *high five* great job guys!!" << std::endl;
}