#include "Span.hpp"

Span::Span( unsigned int n ) : _max( n ) { }

Span::Span( const Span& src ) {
    *this = src;
}

Span& Span::operator=( Span const &rhs ) {
    if ( this != &rhs ) {
        this->_max = rhs._max;
        const std::list<int> *rhsList = rhs.getList();
        for (std::list<int>::const_iterator it = rhsList->begin(); it != rhsList->end(); it++)
            this->_list.push_back(*it);
    }
    return *this;
}

Span::~Span( void ) {}


void Span::addNumber( int num ) {
    if ( _list.size() >= _max )
        throw std::out_of_range("List is full");
    _list.push_back( num );
}

void Span::addNumber( std::list<int>::const_iterator begin, std::list<int>::const_iterator end ) {
    if ( _list.size() > _max )
        throw std::out_of_range("List is full");
    _list.insert( _list.end(), begin, end );
}

const std::list< int >* Span::getList( void ) const {
    return &_list;
}

unsigned int    Span::longestSpan( void ) const {
    if ( _list.size() < 2 )
        throw std::out_of_range("Not enough elements to calculate");
    return ( *std::max_element( _list.begin(), _list.end() ) - *std::min_element( _list.begin(), _list.end() ) );
}

unsigned int Span::shortestSpan( void ) const {
    if ( _list.size() < 2 )
        throw std::out_of_range("Not enough elements to calculate");

    std::list<int> sorted(_list);
    sorted.sort();
    std::list<int>::const_iterator i = sorted.begin();
    i++;

    unsigned int  min = -1;
    for (; i != sorted.end(); i++)
    {
        int x = *i;
        int y = *(--i);
        i++;
        if (static_cast<unsigned int>(x - y) < min)
            min = x - y;
    }
    
    sorted.sort();
    
    return min;
}

std::ostream& operator<<( std::ostream& os, const Span& span ) {
    for ( std::list<int>::const_iterator it = span.getList()->begin(); it != span.getList()->end(); ++it )
        os << *it << " ";
    return os;
}