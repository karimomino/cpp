#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type( "Wrong Animal" ) {
    std::cout << this->_type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type( type ) {
    std::cout << "Wrong Animal " << this->_type << " constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {
    std::cout << "Wrong Animal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& original ) {
    std::cout << "Wrong Animal copy constructor called" << std::endl;
    *this = original;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& rhs ) {
    std::cout << "Wrong Animal assignment operator called" << std::endl;
    if ( this != &rhs ) {
        this->_type = rhs._type;
    }
    return *this;
}

void WrongAnimal::makeSound( void ) const {
    std::cout << "Wrong Animal makeSound called" << std::endl;
}

std::string    WrongAnimal::getType( void ) const {
    return this->_type;
}