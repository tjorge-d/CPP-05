#include "AForm.hpp"

// CONSTRUCTORS & DESTRUCTORS

AForm::AForm() : 
_name("Default"), _target("Default"), _signed(0), _gradeToSign(150), _gradeToExec(150)
{
	//std::cout << "AForm default constructor called\n";
}

AForm::AForm(std::string name, std::string target, int gradeToSign, int gradeToExec)
: _name(name), _target(target), _signed(0), _gradeToSign(gradeToSign) ,_gradeToExec(gradeToExec)
{
	//std::cout << "AForm custom constructor called\n";
	checkLimits();
}

AForm::AForm(const AForm &copy)
: _name(copy._name), _target(copy._target), _signed(0), _gradeToSign(copy._gradeToSign) ,_gradeToExec(copy._gradeToExec)
{
	//std::cout << "AForm copy constructor called\n";
}

AForm::~AForm()
{
	//std::cout << "AForm default destructor called\n";
}

// GETTERS

std::string	AForm::getName()const
{
	return (_name);
}

std::string	AForm::getTarget()const
{
	return (_name);
}

bool	AForm::getSigned() const
{
	return (_signed);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExec() const
{
	return (_gradeToExec);
}

// OPERATORS

AForm&	AForm::operator=(const AForm &copy)
{
	//std::cout << "AForm copy assignment operator called\n";
	_signed = copy._signed;
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, const AForm &right)
{
	stream << "The " << right.getName() << " Form requires a grade of " \
	<< right.getGradeToSign() << " to be signed, " << right.getGradeToExec() \
	<< " to be executed and it has ";
	if (!right.getSigned())
		stream << "not ";
	stream << "been signed." << std::endl;
	return (stream);
}

// MEMBER FUNCTIONS

void	AForm::checkLimits()
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (_signed)
		throw AlreadySigned();
	if (bureaucrat.getGrade() > _gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	_signed = 1;
}

void	AForm::execute(Bureaucrat const & executor) const
{
	if (!_signed)
		throw NotSigned();
	if (executor.getGrade() > _gradeToExec)
		throw Bureaucrat::GradeTooLowException();
	action();
}

// EXCEPTIONS

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("a Form grade is too high");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("a Form grade is too low");
}

const char*	AForm::AlreadySigned::what() const throw()
{
	return ("the Form has already been signed");
}

const char*	AForm::NotSigned::what() const throw()
{
	return ("the Form is not signed");
}