#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{	
	ClapTrap nino("niño");
	ScavTrap kamin("kamin");
	FragTrap frag("fragaz");

	//energy test
	for (size_t i = 0; i < 11; i++)
	{
		nino.attack("kamin");
	}
	std::cout << std::endl;
	for (size_t i = 0; i < 51; i++)
	{
		kamin.beRepaired(100);
	}
	std::cout << std::endl;
	for (size_t i = 0; i < 101; i++)
	{
		frag.beRepaired(100);
	}
	nino.beRepaired(100);
	nino.attack("hey");
	kamin.beRepaired(100);
	kamin.attack("hey");
	frag.beRepaired(100);
	frag.attack("hey");
	std::cout << std::endl;

	//death test
	nino.takeDamage(100);
	nino.beRepaired(10000);
	nino.attack("kamin");
	std::cout << std::endl;

	//copy constructor test
	ClapTrap clone(kamin);
	clone.attack("niño");
	std::cout << std::endl;

	//assignment operator test
	ClapTrap assigner("assigner");
	assigner = nino;
	assigner.attack("swagger");

	frag.highFive();


	return (0);
}