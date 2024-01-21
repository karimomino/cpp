#include "Serializer.hpp"


Serializer::Serializer(/* args */)
{
}

Serializer::~Serializer()
{
}


uintptr_t    Serializer::serialize( Data *data ) {
    return ( reinterpret_cast< uintptr_t >( data ) );
}

Data*   Serializer::deserialize( uintptr_t data ) {
    return ( reinterpret_cast< Data* >( data ) );
}