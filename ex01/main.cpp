#include "Bureaucrat.hpp"
#include "Form.hpp"

void	invalid_forms_test()
{
	std::cout << "\n----- Lesser Form -----\n";
	try
	{
		Form	Lesser("Lesser", 100, 20000);
		std::cout << "I shouldn't print this!";
	}
	catch (std::exception & exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}

	std::cout << "\n----- Greater Form -----\n";
	try
	{
		Form	Greater("Greater", -20000, 100);
		std::cout << "I shouldn't print this!";
	}
	catch (std::exception & exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
}

void	easy_form_test(Bureaucrat &lucky_one)
{
	std::cout << "\n----- Easy Form (success) -----\n";
	try
	{
		Form	Easy("Easy", 140, 145);
		std::cout << Easy;
		lucky_one.signForm(Easy);
		std::cout << Easy;
		lucky_one.signForm(Easy);
	}
	catch (std::exception & exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
}

void	hard_form_test(Bureaucrat &unlucky_one)
{
	std::cout << "\n----- Hard Form (not enough grade) -----\n";
	try
	{
		Form	Hard("Hard", 5, 10);
		std::cout << Hard;
		unlucky_one.signForm(Hard);
		std::cout << Hard;
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
		invalid_forms_test();

		Bureaucrat Paulo("Paulo", 130);
		std::cout << "\n\n----- Initial values -----\n";
		std::cout << Paulo;

		easy_form_test(Paulo);
		hard_form_test(Paulo);
	}
	catch (std::exception & exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
}