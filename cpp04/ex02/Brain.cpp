#include "Brain.hpp"

Brain::Brain( void ) {
    std::cout << "Brain created." << std::endl;
}

Brain::~Brain( void ) {
    std::cout << "Brain destroyed." << std::endl;
}

Brain::Brain( const Brain& original ) {
    std::cout << "Brain copy constructor called." << std::endl;
    *this = original;
}

Brain& Brain::operator=( const Brain& original ) {
    if ( this != &original ) {
        for ( int i = 0; i < 100; i++ ) {
            this->_ideas[i] = original._ideas[i];
        }
    }
    std::cout << "Brain copy assignment called." << std::endl;
    return *this;
}
