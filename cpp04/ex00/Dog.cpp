#include "Dog.hpp"

Dog::Dog( void ) : Animal( "Dog" ) {
    std::cout << "Derived " << this->_type << " constructor called" << std::endl;
}

Dog::~Dog( void ) {
    std::cout << "Derived " << this->_type << " destructor called" << std::endl;
}

Dog::Dog( const Dog& original ) : Animal() {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = original;
}

Dog& Dog::operator=( const Dog& rhs ) {
    std::cout << "Dog assignment operator called" << std::endl;
    
    if ( this != &rhs )
        this->_type = rhs._type;

    return *this;
}

void    Dog::makeSound( void ) const {
    std::cout << "*Bark*" << std::endl;
}