#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
    std::srand(std::time(0));

    try {
        Bureaucrat bureaucrat("some politician", 33);
        Bureaucrat bureaucrat2("fake politician", 150);
        Bureaucrat bureaucrat3("Top politician", 1);
        Bureaucrat bureaucrat4("Medium politician", 140);
        ShrubberyCreationForm form1("New New York");
        RobotomyRequestForm form2("Bender");
        PresidentialPardonForm form3("Mom");
        ShrubberyCreationForm form1_1("New New York");
        RobotomyRequestForm form2_1("Bender");
        PresidentialPardonForm form3_1("Mom");

        std::cout << "\n--------------- Shrubbery req: sign(145) exec(137) ---------------" << std::endl;
        bureaucrat.signForm(form1);
        bureaucrat.executeForm(form1);
        bureaucrat2.signForm(form1);
        bureaucrat2.executeForm(form1);
        bureaucrat3.signForm(form1);
        bureaucrat3.executeForm(form1);
        bureaucrat4.signForm(form1);
        bureaucrat4.executeForm(form1);

        std::cout << std::endl;
        bureaucrat.executeForm(form1_1);
        bureaucrat2.executeForm(form1_1);
        bureaucrat3.executeForm(form1_1);
        bureaucrat4.executeForm(form1_1);



        std::cout << "\n--------------- Robotomy req: sign(72) exec(45) ---------------" << std::endl;
        bureaucrat.signForm(form2);
        bureaucrat.executeForm(form2);
        bureaucrat2.signForm(form2);
        bureaucrat2.executeForm(form2);
        bureaucrat3.signForm(form2);
        bureaucrat3.executeForm(form2);
        bureaucrat4.signForm(form2);
        bureaucrat4.executeForm(form2);

        std::cout << std::endl;
        bureaucrat.executeForm(form2_1);
        bureaucrat2.executeForm(form2_1);
        bureaucrat3.executeForm(form2_1);
        bureaucrat4.executeForm(form2_1);

        
        std::cout << "\n--------------- Presidential req: sign(25) exec(1) ---------------" << std::endl;
        bureaucrat.signForm(form3);
        bureaucrat.executeForm(form3);
        bureaucrat2.signForm(form3);
        bureaucrat2.executeForm(form3);
        bureaucrat3.signForm(form3);
        bureaucrat3.executeForm(form3);
        bureaucrat4.signForm(form3);
        bureaucrat4.executeForm(form3);

        std::cout << std::endl;
        bureaucrat.executeForm(form3_1);
        bureaucrat2.executeForm(form3_1);
        bureaucrat3.executeForm(form3_1);
        bureaucrat4.executeForm(form3_1);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}