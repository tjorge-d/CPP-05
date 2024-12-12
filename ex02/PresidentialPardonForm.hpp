#ifndef PRESITENTIALPARDONFORM_HPP
# define PRESITENTIALPARDONFORM_HPP
# include <stdio.h>
# include <iostream>
# include <string.h>
# include <fstream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &a);
		~PresidentialPardonForm() ;

		PresidentialPardonForm&	operator=(const PresidentialPardonForm &copy);

		void	action()const;
};

#endif