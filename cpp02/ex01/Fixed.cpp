#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointVal(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : _fixedPointVal( n << _fractionalBits ) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float n ) : _fixedPointVal( roundf( n * ( 1 << _fractionalBits ) ) ) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &original ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed& Fixed::operator=( const Fixed &rhs ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &rhs )
		this->_fixedPointVal = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	return this->_fixedPointVal;
}

void	Fixed::setRawBits( int const raw ) {
	this->_fixedPointVal = raw;
}

float   Fixed::toFloat( void ) const {
	return static_cast<float>( this->getRawBits() ) / ( 1 << _fractionalBits );
}

int	 Fixed::toInt( void ) const {
	return this->_fixedPointVal >> _fractionalBits;
}

std::ostream & operator<<( std::ostream & out, Fixed const & in ) {
	out << in.toFloat();
	return out;
}