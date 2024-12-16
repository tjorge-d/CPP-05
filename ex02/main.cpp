#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	ShrubberyCreationForm_test(Bureaucrat &smart, Bureaucrat &not_smart)
{
	std::cout << "\n----- Shrubbery Creation Form -----\n";
	try
	{
		ShrubberyCreationForm	form("Palace");
		not_smart.signForm(form);
		smart.signForm(form);

		not_smart.executeForm(form);
		smart.executeForm(form);
	}
	catch (std::exception & exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
}

void	RobotomyRequestForm_test(Bureaucrat &smart, Bureaucrat &not_smart)
{
	std::cout << "\n----- Robotomy Request Form -----\n";
	try
	{
		RobotomyRequestForm	form("R2D2");
		not_smart.signForm(form);
		smart.signForm(form);

		not_smart.executeForm(form);
		smart.executeForm(form);
		smart.executeForm(form);
		smart.executeForm(form);
		smart.executeForm(form);
	}
	catch (std::exception & exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
}

void	PresidentialPardonForm_test(Bureaucrat &smart, Bureaucrat &not_smart)
{
	std::cout << "\n----- Presidential Pardon Form -----\n";
	try
	{
		PresidentialPardonForm	form("Rui Pinto");
		not_smart.signForm(form);
		smart.signForm(form);

		not_smart.executeForm(form);
		smart.executeForm(form);
	}
	catch (std::exception & exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
}

int main()
{
	try
	{
		Bureaucrat Albert("Albert", 1);
		Bureaucrat Donald("Donald", 150);
		std::cout << "\n\n----- Initial values -----\n";
		std::cout << Albert;
		std::cout << Donald;

		ShrubberyCreationForm_test(Albert, Donald);
		RobotomyRequestForm_test(Albert, Donald);
		PresidentialPardonForm_test(Albert, Donald);
	}
	catch (std::exception & exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
}