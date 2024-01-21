#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ) {
}

ScalarConverter::ScalarConverter( const ScalarConverter& src ) {
    *this = src;
}


ScalarConverter& ScalarConverter::operator=( const ScalarConverter& rhs ) {
    if ( this != &rhs ) {
        *this = rhs;
    }
    return *this;
}

static bool    isLiteral( const std::string & _str ) {
    if ( ( _str.compare( "nan" ) == 0 ) || ( _str.compare( "nanf" ) == 0 )
        || ( _str.compare( "+inf" ) == 0 ) || ( _str.compare( "+inff" ) == 0 ) 
        || ( _str.compare( "-inf" ) == 0 ) || ( _str.compare( "-inff" ) == 0 ) ) {
            return true;
    } 
    return false;
}

static void    printChar( const std::string & _str, const short type ) {
    long num;
    if (type == CHAR)
        num = _str[0];
    else
        num = std::strtol(_str.c_str() , NULL , 10 );
    std::cout << "Char: ";
    if ( type == LITERAL || ( !std::isprint( num ) && ( num >= 127 ) ) || num < 0) {
        std::cout << "Impossible";
    } else if ( !std::isprint( _str[0] ) ) {
        std::cout << "None displayable";
    } else {
        std::cout << "'" << static_cast<unsigned char>(static_cast<int>(num)) << "'";
    }
    std::cout << std::endl;
}

static void    printInt( const std::string & _str , const short type) {
    long num;
    if (type == CHAR)
        num = _str[0];
    else
        num = std::strtol(_str.c_str() , NULL , 10 );
    std::cout << "Int: ";
    if ( type == LITERAL || num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min() ) {
        std::cout << "Impossible";
    } else {
        std::cout << static_cast<int>(num);
    }
    std::cout << std::endl;
}

static bool    isChar( const std::string & _str ) {
    return _str.length() == 1 && std::isalpha( _str[0] ) && std::isprint( _str[0] );
}

static bool    isInt( const std::string & _str ) {
    int    i = 0;
    if ( _str[i] == '-' || _str[i] == '+' )
        i++;
    for ( ; i < ( int ) _str.length(); i++ ) {
        if ( !std::isdigit( _str[i] ) )
            return false;
    }
    return true;
}

static bool isDouble( const std::string & _str ) {

    if ( _str.find( '.' ) == std::string::npos || _str.find( '.' ) == 0 
        || _str.find( '.' ) == _str.length() - 1 )
        return false;
    int j = 0;
    int found = 0;
    if ( _str[j] == '-' || _str[j] == '+' )
        j++;
    for ( int i( j ); i < ( int ) _str.length(); i++ ) {
        if ( _str[i] == '.' )
            found++;
        if ( ( !std::isdigit( _str[i] ) && _str[i] != '.' ) || found > 1 )
            return false;
    }

    return true;
}

static bool    isFloat ( const std::string & _str ) {

    if ( _str.find( '.' ) == std::string::npos || _str.back() != 'f' 
        || _str.find( '.' ) == 0 || _str.find( '.' ) == _str.length() - 2 )
        return false;
    int found = 0;
    int j = 0;
    if ( _str[j] == '-' || _str[j] == '+' )
        j++;
    for ( int i( j ); i < ( int ) _str.length() - 1; i++ ) {
        if ( _str[i] == '.' )
            found++;
        if ( ( !std::isdigit( _str[i] ) && _str[i] != '.' ) || found > 1 )
            return false;
    }

    return true;
}

static void    printDouble( const std::string & _str , const short type) {
    double num;
    errno = 0;
    if (type == CHAR)
        num = _str[0];
    else
        num = std::strtod(_str.c_str() , NULL);
    std::cout << "Double: ";
    if ( _str.compare( "nan" ) == 0 || _str.compare( "nanf" ) == 0 ) {
        std::cout << "nan";
    } else if ( _str.compare( "+inff" ) == 0 || _str.compare( "+inf" ) == 0 ) {
        std::cout << "+inf";
    } else if ( _str.compare( "-inff" ) == 0 || _str.compare( "-inf" ) == 0 ) {
        std::cout << "-inf";
    } else if ( (_str.compare("0") && num == 0) || errno) {
        std::cout << "Impossible";
    } else {
        std::cout << static_cast<double>(num);
        if ( num - static_cast< int > ( num ) == 0 ) {
            std::cout << ".0";
        }
    }
    std::cout << std::endl;
}


static void    printFloat( const std::string & _str , const short type ) {
    double num;
    if (type == CHAR)
        num = _str[0];
    else
        num = std::strtod(_str.c_str() , NULL);
    std::cout << "Float: ";
    if ( _str.compare( "nan" ) == 0 || _str.compare( "nanf" ) == 0 ) {
        std::cout << "nan";
    } else if ( _str.compare( "+inff" ) == 0 || _str.compare( "+inf" ) == 0 ) {
        std::cout << "+inff";
    } else if ( _str.compare( "-inff" ) == 0 || _str.compare( "-inf" ) == 0 ) {
        std::cout << "-inff";
    } else if ( (_str.compare("0") && num == 0) || num > std::numeric_limits<float>::max() || errno ) {
        std::cout << "Impossible";
    } else {
        std::cout << static_cast<float>(num);
        if ( num - static_cast< int > ( num ) == 0 ) {
            std::cout << ".0";
        }
        std::cout << "f\n";
    }
    std::cout << std::endl;
}

static short getType( const std::string & _str ) {
    short type;

    if ( isLiteral(_str) )
        type = LITERAL;
    else if ( isInt( _str ) )
        type = INT;
    else if ( isDouble( _str ) )
        type = DOUBLE;
    else if ( isFloat( _str ) )
        type = FLOAT;
    else if ( isChar( _str ) )
        type = CHAR;
    else
        type = -1;
    return type;
}


void ScalarConverter::convert(const std::string &_str)
{
    short type = getType(_str);
    switch (type)
    {
    case -1:
        std::cout << "IMPOSSIBLE CONVERSION!!" << std::endl;
        break;
    default:
        printChar(_str , type);
        printInt(_str, type);
        printDouble(_str, type);
        printFloat(_str , type );
        break;
    }

}

