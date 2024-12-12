#ifndef AFORM_HPP
# define AFORM_HPP
# include <stdio.h>
# include <iostream>
# include <string.h>
# include <fstream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		const std::string	_name;
		const std::string	_target;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		AForm();
		AForm(std::string name, std::string target, int gradeToSign, int gradeToExec);
		AForm(const AForm &a);
		~AForm();

		std::string	getName() const;
		std::string	getTarget() const;
		bool		getSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;
	
		AForm&	operator=(const AForm &copy);

		void			checkLimits();
		void			beSigned(Bureaucrat &bureaucrat);
		void			execute(Bureaucrat const & executor) const;
		virtual void	action()const = 0;

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
	class	NotSigned: public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &stream, const AForm &right);

#endif