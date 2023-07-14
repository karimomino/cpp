#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;

	std::cout << "ScavTrap " << _name << " joined the world!" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->_name << " disconnected." << std::endl;

}

void	ScavTrap::attack( std::string const& target ) {
	if (_hitPoints == 0)
		std::cout << "[ SCAVTRAP - " << _name << " ] can't attack, you are dead!" << std::endl;
	else if (_energyPoints < 1)
		std::cout << "[ SCAVTRAP - " << _name << " ] can't attack, you are out of energy!" << std::endl;
	else {
		std::cout << "[ SCAVTRAP - " << _name << " ] you attack " << target << ", dealing " << _attackDamage << " damage!" << std::endl;
		_energyPoints--;
	}
}

void	ScavTrap::guardGate() {
	std::cout << "[ SCAVTRAP - " << this->_name << " ] is now in Gate Keeper mode." << std::endl;
}