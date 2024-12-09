#include "Form.hpp"

// CONSTRUCTORS & DESTRUCTORS

Form::Form() : _name("Default"), _signed(0), _gradeToSign(150) ,_gradeToExec(150)
{
	//std::cout << "Form default constructor called\n";
}

Form::Form(std::string name, int gradeToSign, int gradeToExec)
: _name(name), _signed(0), _gradeToSign(gradeToSign) ,_gradeToExec(gradeToExec)
{
	//std::cout << "Form default constructor called\n";
	checkLimits();
}

Form::Form(const Form &copy)
: _name(copy._name), _signed(0), _gradeToSign(copy._gradeToSign) ,_gradeToExec(copy._gradeToExec)
{
	//std::cout << "Form copy constructor called\n";
}

Form::~Form()
{
	//std::cout << "Form default destructor called\n";
}

// GETTERS

std::string	Form::getName()const
{
	return (_name);
}

bool	Form::getSigned() const
{
	return (_signed);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExec() const
{
	return (_gradeToExec);
}

// OPERATORS

Form&	Form::operator=(const Form &copy)
{
	//std::cout << "Form copy assignment operator called\n";
	_signed = copy._signed;
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, const Form &right)
{
	stream << "The Form " << right.getName() << " requires a grade of " \
	<< right.getGradeToSign() << " to be signed, " << right.getGradeToExec() \
	<< " to be executed and it has ";
	if (!right.getSigned())
		stream << "not ";
	stream << "been signed." << std::endl;
	return (stream);
}

// MEMBER FUNCTIONS

void	Form::checkLimits()
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (_signed)
		throw AlreadySigned();
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	_signed = 1;
}

// EXCEPTIONS

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("A Form grade is too high");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("A Form grade is too low");
}

const char*	Form::AlreadySigned::what() const throw()
{
	return ("The Form has already been signed");
}
