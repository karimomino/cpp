#ifndef WRONGANIMAL_HPP

    #define WRONGANIMAL_HPP
    #include <iostream>

    class WrongAnimal
    {
        protected:
            std::string _type;

        public:
            WrongAnimal( void );
            WrongAnimal( std::string type );
            virtual ~WrongAnimal( void );

            WrongAnimal( const WrongAnimal& original );
            WrongAnimal& operator=( const WrongAnimal& rhs );

            void            makeSound( void ) const;
            std::string     getType( void ) const; 
    };

#endif