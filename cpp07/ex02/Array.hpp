#pragma once

#include <iostream>

template < typename T >
class Array {

private:
    T*              _arr;
    unsigned int    _size;

public:
    Array( void ) : _arr( new T() ), _size( 0 ) { };
    Array( unsigned int n ) : _arr( new T[n] ), _size( n ) { };
    Array( const Array& rhs ) : _arr( new T[rhs.size()] ), _size( rhs.size() ) { *this = rhs; };

    Array& operator=( const Array& rhs ) {
        if ( this != &rhs ) {
            delete [] _arr;
            _arr = new T[rhs.size()];
            _size = rhs._size;
            for ( unsigned int i( 0 ); i < _size; i++ )
                _arr[i] = rhs._arr[i];
        }
        return *this;
    }

    T& operator[]( unsigned int i ) const {
        if ( i >= _size )
            throw std::out_of_range("Index out of range");
        return _arr[i];
    }

    unsigned int  size( void ) const { return _size; }

    ~Array( void ) { delete [] _arr; }
};