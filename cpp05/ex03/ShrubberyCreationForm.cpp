#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) : AForm( "ShrubberyCreationForm", 145, 137 ), _target( target ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& src ) : AForm( src ), _target( src._target ) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm& rhs ) {
    (void)rhs;
    return *this;
}

void    ShrubberyCreationForm::execute( const Bureaucrat& executor ) const {
    if ( this->getSigned() == false )
        throw AForm::NotSignedException();
    else if ( executor.getGrade() > this->getGradeToExecute() ) {
        throw AForm::GradeTooLowException();
    }

    std::ofstream file( this->_target + "_shrubbery" );

    file << "\n           *             ,\n                       _/^\\_\n                      <     >\n     *                 /.-.\\         *\n              *        `/&\\`                   *\n                      ,@.*;@,\n                     /_o.I %_\\    *\n        *           (`\'--:o(_@;\n                   /`;--.,__ `\')             *\n                  ;@`o % O,*`\'`&\\\n            *    (`\'--)_@ ;o %\'()\\      *\n                 /`;--._`\'\'--._O\'@;\n                /&*,()~o`;-.,_ `\"\"`)\n     *          /`,@ ;+& () o*`;-\';\\\n               (`\"\"--.,_0 +% @\' &()\\\n               /-.,_    ``\'\'--....-\'`)  *\n          *    /@%;o`:;\'--,.__   __.\'\\\n              ;*,&(); @ % &^;~`\"`o;@();         *\n              /(); o^~; & ().o@*&`;&%O\\\n        jgs   `\"=\"==\"\"==,,,.,=\"==\"===\"`\n           __.----.(\\-\'\'#####---...___...-----._\n         \'`         \\)_`\"\"\"\"\"`\n                 .--\' \')\n               o(  )_-\\\n                 `\"\"\"` `" << std::endl;
    file.close();
}