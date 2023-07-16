#include "Dog.hpp"

Dog::Dog( void ) : Animal( "Dog" ) {
    std::cout << "Derived " << this->_type << " constructor called" << std::endl;
    try {
        this->_brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Dynamic memory allocation failed : " << e.what() << std::endl;
    }
}

Dog::~Dog( void ) {
    std::cout << "Derived " << this->_type << " destructor called" << std::endl;
    delete _brain;
}

Dog::Dog( const Dog& original ) : Animal() {
    std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = NULL;
    *this = original;
}

Dog& Dog::operator=( const Dog& rhs ) {
    std::cout << "Dog assignment operator called" << std::endl;
    
    if ( this != &rhs ) {
        this->_type = rhs.getType();
        if (this->_brain != NULL)
            delete _brain;
        try {
            this->_brain = new Brain(*rhs._brain);
        } catch (const std::bad_alloc& e) {
            std::cout << "Dynamic memory allocation failed : " << e.what() << std::endl;
        }
    }

    return *this;
}

void    Dog::makeSound( void ) const {
    std::cout << "*Bark*" << std::endl;
}