#include "Bureaucrat.hpp"

void	decrementation_test(Bureaucrat &unlucky_one)
{
	std::cout << "\n----- Decrementation -----\n";
	try
	{
		unlucky_one.decrementGrade();
		unlucky_one.decrementGrade();
		std::cout << "I shouldn't print this!";
	}
	catch (std::exception & exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
	std::cout << unlucky_one;
}

void	incrementation_test(Bureaucrat &lucky_one)
{
	std::cout << "\n----- Incrementation -----\n";
	try
	{
		lucky_one.incrementGrade();
		lucky_one.incrementGrade();
		std::cout << "I shouldn't print this!";
	}
	catch (std::exception & exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
	std::cout << lucky_one;
}

void	instantiation_tests()
{
	std::cout << "\n----- Invalid instantiations -----\n";
	try
	{
		Bureaucrat Mauricio("Mauricio", -1);
		std::cout << "I shouldn't print this!";
	}
	catch (std::exception & exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
	try
	{
		Bureaucrat Juliano("Juliano", 1000);
		std::cout << "I shouldn't print this!";
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
		Bureaucrat Mario("Mario", 149);
		Bureaucrat Luis("Luis", 2);
		std::cout << "\n----- Initial values -----\n";
		std::cout << Mario;
		std::cout << Luis;

		decrementation_test(Mario);
		incrementation_test(Luis);
		instantiation_tests();
	}
	catch (std::exception & exception)
	{
		std::cout << "Exception: " << exception.what() << std::endl;
	}
}