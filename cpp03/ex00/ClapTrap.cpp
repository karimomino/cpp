#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " joined the world!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << this->_name << " disconnected." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &original)
{
	std::cout << "ClapTrap " << original._name << " spawned a clone." << std::endl;
	*this = original;
}

ClapTrap&   ClapTrap::operator=( const ClapTrap& rhs ) {
	if ( this != &rhs ) {
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

void	ClapTrap::attack( std::string const& target )
{
	if (target.empty())
		std::cout << "[ " << _name << " ] you have went crazy, attacking nothing" << std::endl;
	else if (_hitPoints == 0)
		std::cout << "[ " << _name << " ] can't attack, you are dead!" << std::endl;
	else if (_energyPoints < 1)
		std::cout << "[ " << _name << " ] can't attack, you are out of energy!" << std::endl;
	else {
		std::cout << "[ " << _name << " ] you attack " << target << ", dealing " << _attackDamage << " damage!" << std::endl;
		_energyPoints--;
	}
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (_hitPoints <= amount)
	{
		std::cout << "[ " << _name << " ] you died, release spirit!" << std::endl;
		_hitPoints = 0;
	}
	else if (amount > 0) {
		std::cout << "[ " << _name << " ] you took " << amount << " damage!" << std::endl;
		_hitPoints -= amount;
	} else if (amount == 0) {
		std::cout << "[ " << _name << " ] you dodged attack!" << std::endl;
	}
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (_hitPoints == 0)
		std::cout << "[ " << _name << " ] can't heal, you are dead!" << std::endl;
	else if (_energyPoints < 1)
		std::cout << "[ " << _name << " ] can't heal, you are out of energy!" << std::endl;
	else {
		std::cout << "[ " << _name << " ] you healed for " << amount << " hit points!" << std::endl;
		_energyPoints--;
		_hitPoints += amount;
	}
}