#include "PresidentialPardonForm.hpp"

// CONSTRUCTORS & DESTRUCTORS

PresidentialPardonForm::PresidentialPardonForm() :
AForm("Presidential Pardon", "Default", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
AForm("Presidential Pardon", target, 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : 
AForm(copy._name, copy._target, copy._gradeToSign,  copy._gradeToExec)
{
	std::cout << "PresidentialPardonForm copy constructor called\n";
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm default destructor called\n";
}

// OPERATORS

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	std::cout << "PresidentialPardonForm copy assignment operator called\n";
	_signed = copy._signed;
	return (*this);
}

// MEMBER FUNCTIONS

void	PresidentialPardonForm::action()const
{
	std::cout << "I hereby announce that Zaphod Beeblebrox has pardoned " << \
	_target << "!" << std::endl;
}
