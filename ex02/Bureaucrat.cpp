#include "Bureaucrat.hpp"

// CONSTRUCTORS & DESTRUCTORS

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	//std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	//std::cout << "Bureaucrat custom constructor called\n";
	checkLimits();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy._name)
{
	//std::cout << "Bureaucrat copy constructor called\n";
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	//std::cout << "Bureaucrat default destructor called\n";
}

// OPERATORS

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &copy)
{
	//std::cout << "Bureaucrat copy assignment operator called\n";
	_grade = copy._grade;
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &right)
{
	stream << "The Bureaucrat " << right.getName() << " has a grade of " << right.getGrade() << std::endl;
	return (stream);
}

// GETTERS

int	Bureaucrat::getGrade()const
{
	return (_grade);
}

const std::string	Bureaucrat::getName()const
{
	return (_name);
}

// MEMBER FUNCTIONS

void	Bureaucrat::checkLimits()
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "The Bureaucrat " << _name \
		<< " has successfully signed the " << form.getName() << " Form" << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cout << "The Bureaucrat " << _name << " couldn't sign the " \
		<< form.getName() << " Form because " << exception.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << "The Bureaucrat " << _name \
		<< " has executed the " << form.getName() << " Form" << std::endl;
	}
	catch (std::exception &exception)
	{
		std::cerr << "The Bureaucrat " << _name << " couldn't execute the " \
		<< form.getName() << " Form because " << exception.what() << std::endl;
	}
}

// EXCEPTIONS

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("the Bureaucrat grade is too high");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("the Bureaucrat grade is too low");
}