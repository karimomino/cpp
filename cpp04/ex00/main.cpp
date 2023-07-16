#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
    Animal *animal = new Animal();
    Animal *cat = new Cat();
    Animal *dog = new Dog();
    WrongAnimal *wrongcat = new WrongCat();
    WrongAnimal *w_animal = new WrongAnimal;

    animal->makeSound();
    cat->makeSound();
    dog->makeSound();
    wrongcat->makeSound();
    w_animal->makeSound();

    std::cout << std::endl;
    delete animal;
    std::cout << std::endl;
    delete cat;
    std::cout << std::endl;
    delete dog;
    std::cout << std::endl;
    delete wrongcat;
    std::cout << std::endl;
    delete w_animal;

    return 0;

}