#ifndef FORM_HPP
# define FORM_HPP
# include <stdio.h>
# include <iostream>
# include <string.h>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool		_signed;
		const int	_gradeToSign;
		const int	_gradeToExec;

	public:
		Form();
		Form(std::string name, int gradeToSign, int gradeToExec);
		Form(const Form &a);
		~Form();

		std::string	getName() const;
		bool		getSigned() const;
		int	getGradeToSign() const;
		int	getGradeToExec() const;
	
		Form&	operator=(const Form &copy);

		void	checkLimits();
		void	beSigned(Bureaucrat &bureaucrat);

	class	GradeTooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class	GradeTooLowException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class	AlreadySigned: public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &stream, const Form &right);

#endif