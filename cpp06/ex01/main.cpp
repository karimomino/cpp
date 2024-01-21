#include "Serializer.hpp"
#include <iostream>


int main( void )
{
    Data *data = new Data;

    data->iban = "01293923123123";
    data->balance = 3000000;
    data->isActive = true;

    uintptr_t x = Serializer::serialize(data);

    std::cout << Serializer::deserialize(x)->iban << std::endl;
    std::cout << Serializer::deserialize(x)->balance << std::endl;
    std::cout << Serializer::deserialize(x)->isActive << std::endl;

    delete data;

    return EXIT_SUCCESS;
}