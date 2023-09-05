/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:44:11 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/05 15:38:03 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _target("Default") {
	std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target) {
	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
	*this = src;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	std::cout << "RobotomyRequestForm assignment operator" << std::endl;
	(void)src;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm " << this->getName() << " destructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string name) : AForm("Robotomy Request Form", 72, 45), _target(name) {
	std::cout << "RobotomyRequestForm " << this->getName() << " constructor" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const & src) const {
	execCheck(src);
	std::cout << "*Bruits de perceuse*" << std::endl;
	if (rand() % static_cast<int>(2))
		std::cout << _target << " a été robotomisée avec succès" << std::endl;
	else
		std::cout << "L'opération sur " << _target << " à raté" << std::endl;
}