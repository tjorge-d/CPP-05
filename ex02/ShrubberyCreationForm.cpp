#include "ShrubberyCreationForm.hpp"

// CONSTRUCTORS & DESTRUCTORS

ShrubberyCreationForm::ShrubberyCreationForm() :
AForm("Default", "Default", 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
AForm("Default", target, 145, 137)
{
	std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : 
AForm(copy._name, copy._target, copy._gradeToSign, _gradeToExec)
{
	std::cout << "ShrubberyCreationForm copy constructor called\n";
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm default destructor called\n";
}

// OPERATORS

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called\n";
	_signed = copy._signed;
	return (*this);
}

// MEMBER FUNCTIONS

void	ShrubberyCreationForm::action()const
{
	
}
