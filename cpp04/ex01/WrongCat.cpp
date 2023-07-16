#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("Wrong Cat") {
    std::cout << "Derived " << this->_type << " constructor called" << std::endl;
}

WrongCat::~WrongCat( void ) {
    std::cout << "Derived " << this->_type << " destructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat& original ) : WrongAnimal() {
    std::cout << "Wrong Cat copy constructor called" << std::endl;
    *this = original;
}

WrongCat& WrongCat::operator=( const WrongCat& rhs ) {
    std::cout << "Wrong Cat assignment operator called" << std::endl;
    if ( this != &rhs ) {
        this->_type = rhs._type;
    }
    return *this;
}

void    WrongCat::makeSound( void ) const {
    std::cout << "Wrong *Meow*" << std::endl;
}