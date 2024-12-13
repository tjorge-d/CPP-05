#include "RobotomyRequestForm.hpp"

// CONSTRUCTORS & DESTRUCTORS

RobotomyRequestForm::RobotomyRequestForm() :
AForm("Robotomy Request", "Default", 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
AForm("Robotomy Request", target, 72, 45)
{
	std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : 
AForm(copy._name, copy._target, copy._gradeToSign,  copy._gradeToExec)
{
	std::cout << "RobotomyRequestForm copy constructor called\n";
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm default destructor called\n";
}

// OPERATORS

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	std::cout << "RobotomyRequestForm copy assignment operator called\n";
	_signed = copy._signed;
	return (*this);
}

// MEMBER FUNCTIONS

void	RobotomyRequestForm::action()const
{

	std::cout << "BrrrrrRRRrrrRRRRRRrRrRRRRRrrrrRrrrrr!!!" << std::endl;
	if (rand() % 2)
		std::cout << _target << "HAS SUCCESSFULLY BEEN ROBOTOMIZED!" << std::endl;
	else
		std::cout << "THE ROBOTOMIZATION PROCCESS HAS FAILED!" << std::endl;
}
