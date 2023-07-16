#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
    std::cout << "Derived " << this->_type << " constructor called" << std::endl;
}

Cat::~Cat( void ) {
    std::cout << "Derived " << this->_type << " destructor called" << std::endl;
}

Cat::Cat( const Cat& original ) : Animal() {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = original;
}

Cat& Cat::operator=( const Cat& rhs ) {
    std::cout << "Cat assignment operator called" << std::endl;
    
    if ( this != &rhs )
        this->_type = rhs._type;

    return *this;
}

void    Cat::makeSound( void ) const {
    std::cout << "*Meow*" << std::endl;
}