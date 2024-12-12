#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <stdio.h>
# include <iostream>
# include <string.h>
# include <fstream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &a);
		~RobotomyRequestForm() ;

		RobotomyRequestForm&	operator=(const RobotomyRequestForm &copy);

		void	action()const;
};

#endif