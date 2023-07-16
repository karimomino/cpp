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

    //specific tests
    std::cout << std::endl << "###################################### ARRAY TEST ######################################" << std::endl;
    const int n = 10;
    std::cout << std::endl << "################### ARRAY CREATION ###################" << std::endl;
    Animal **n_animals = new Animal*[n];
    std::cout << std::endl << "################### ARRAY ENDED    ###################" << std::endl;

    std::cout << std::endl << std::endl << "################### ANIMALS CREATION ###################" << std::endl;
    for (size_t i = 0; i < n/2; i++)
    {
        n_animals[i] = new Dog();
    }
    for (size_t i = n/2; i < n; i++)
    {
        n_animals[i] = new Cat();
    }

    std::cout << "################### ANIMALS END    ###################" << std::endl << std::endl;
    
    for (size_t i = 0; i < n; i++)
    {
        delete n_animals[i];
        std::cout << std::endl;
    }
    delete[] n_animals;

    Cat pur;
    std::cout << std::endl;
    Cat shta(pur);


    return 0;

}