#ifndef INTERN_HPP
# define INTERN_HPP
# include <stdio.h>
# include <iostream>
# include <string.h>
# include <fstream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern
{
	private:
		AForm*	shrubberyCreation(std::string &formTarget) const;
		AForm*	robotomyRequest(std::string &formTarget) const;
		AForm*	presidentialPardon(std::string &formTarget) const;

	public:
		Intern();
		Intern(const Intern &a);
		~Intern();

		Intern&	operator=(const Intern &copy);

		AForm*	makeForm(std::string formName, std::string formTarget);

	class	UnexistingForm: public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif