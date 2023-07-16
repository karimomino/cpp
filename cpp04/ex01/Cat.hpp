
#ifndef CAT_HPP

    #define CAT_HPP
    #include "Animal.hpp"
    #include "Brain.hpp"

    class Cat : public Animal
    {
        private:
            Brain*  _brain;
        public:
            Cat( void );
            ~Cat( void );
            
            Cat( const Cat& original );
            Cat& operator=(const Cat& rhs);

            void   makeSound( void ) const;
    };

#endif