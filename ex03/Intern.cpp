#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// CONSTRUCTORS & DESTRUCTORS

Intern::Intern()
{
	//std::cout << "Intern default constructor called\n";
}

Intern::Intern(const Intern &copy)
{
	//std::cout << "Intern copy constructor called\n";
	*this = copy;
}

Intern::~Intern()
{
	//std::cout << "Intern default destructor called\n";
}

// OPERATORS

Intern&	Intern::operator=(const Intern &copy)
{
	//std::cout << "Intern copy assignment operator called\n";
	(void)copy;
	return (*this);
}

// MEMBER FUNCTIONS

AForm*	Intern::shrubberyCreation(std::string &formTarget) const
{
	return new ShrubberyCreationForm(formTarget);
}

AForm*	Intern::robotomyRequest(std::string &formTarget) const
{
	return new RobotomyRequestForm(formTarget);
}

AForm*	Intern::presidentialPardon(std::string &formTarget) const
{
	return new PresidentialPardonForm(formTarget);
}

AForm*	Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string	formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm		*(Intern::*formCreators[3])(std::string &)const ={&Intern::presidentialPardon, \
				&Intern::robotomyRequest, \
				&Intern::shrubberyCreation};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "The Intern created a " << formName << " form!" << std::endl;
			return (this->*formCreators[i])(formTarget);
		}
	}
	throw UnexistingForm();
}

// EXCEPTIONS

const char*	Intern::UnexistingForm::what() const throw()
{
	return ("the Intern doesnt't know the Form name");
}