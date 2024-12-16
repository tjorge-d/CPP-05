#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	AForm *form[3] = {NULL, NULL, NULL};
	try
	{
		Intern		Anibal;
		Bureaucrat	Elon("Elon", 2);

		form[0] = Anibal.makeForm("shrubbery creation", "Pentagon");
		form[1] = Anibal.makeForm("robotomy request", "C-3PO");
		form[2] = Anibal.makeForm("presidential pardon", "Socrates");
		
		std::cout << std::endl << "Signing forms..." << std::endl;
		Elon.signForm(*form[0]);
		Elon.signForm(*form[1]);
		Elon.signForm(*form[2]);

		std::cout << std::endl << "Executing forms..." << std::endl;
		Elon.executeForm(*form[0]);
		std::cout << std::endl;
		Elon.executeForm(*form[1]);
		std::cout << std::endl;
		Elon.executeForm(*form[2]);
		std::cout << std::endl;

		for (int i = 0; i < 3; i++)
		{
			if (form[i])
				delete form[i];
		}
	}
	catch (std::exception & exception)
	{
		for (int i = 0; i < 3; i++)
		{
			if (form[i])
				delete form[i];
		}
		std::cout << "Exception: " << exception.what() << std::endl;
	}

	try
	{
		AForm		*wrong;
		Intern		Alfredo;
		Bureaucrat	Bruno("Bruno", 2);

		wrong = Alfredo.makeForm("What is this?", "No one cares");

		Bruno.signForm(*wrong);
		Bruno.executeForm(*wrong);
		delete wrong;
	}
	catch (std::exception & exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
}