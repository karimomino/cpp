#pragma once
#include <string>
#include <iostream>

struct Data
{
    std::string iban;
    int         balance;
    bool        isActive;
};

class Serializer
{
private:
    Serializer( void );
    ~Serializer();
public:
    static uintptr_t    serialize( Data *data );
    static Data*   deserialize( uintptr_t data );
};
