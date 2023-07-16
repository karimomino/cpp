#include "Cat.hpp"

Cat::Cat( void ) : Animal("Cat") {
    std::cout << "Derived " << this->_type << " constructor called" << std::endl;
    try {
        this->_brain = new Brain();
    }
    catch (const std::bad_alloc& e) {
        std::cout << "Failed to allocate: " << e.what() << std::endl;
    }
}

Cat::~Cat( void ) {
    std::cout << "Derived " << this->_type << " destructor called" << std::endl;
    delete _brain;
}

Cat::Cat( const Cat& original ) : Animal(original.getType()) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->_brain = NULL;
    *this = original;
}

Cat& Cat::operator=( const Cat& rhs ) {
    std::cout << "Cat assignment operator called" << std::endl;
    
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

void    Cat::makeSound( void ) const {
    std::cout << "*Meow*" << std::endl;
}