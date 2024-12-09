#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <stdio.h>
# include <iostream>
# include <string.h>
# include <fstream>

class Bureaucrat
{
	private:
		const std::string	_name;
		int 				_grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &a);
		~Bureaucrat() ;

		Bureaucrat&	operator=(const Bureaucrat &copy);

		int					getGrade()const;
		const std::string	getName()const;

		void	checkLimits();
		void	incrementGrade();
		void	decrementGrade();

	class	GradeTooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class	GradeTooLowException: public std::exception
	{
		virtual const char* what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &right);

#endif