#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <stdio.h>
# include <iostream>
# include <string.h>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &a);
		~ShrubberyCreationForm() ;

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &copy);

		void	action()const;
};

#endif