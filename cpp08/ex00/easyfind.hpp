#pragma once

#include <iostream>
#include <algorithm>


template < typename T >
void    easyfind( T& con, int val )
{
    typename T::iterator it = std::find(con.begin(), con.end(), val);

    if (it != con.end()) {
        std::cout << "Found at position: " << std::distance(con.begin(), it) << std::endl;
    } else {
        std::cerr << "Not found." << std::endl;
    }
}