/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:57:50 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/05 16:40:19 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern &src) {
	std::cout << "Intern copy constructor" << std::endl;
	(void)src;
}

Intern &Intern::operator=(const Intern &src) {
	std::cout << "Intern assignment operator" << std::endl;
	(void)src;
	return *this;
}

Intern::~Intern() {
	std::cout << "Intern detructor" << std::endl;
}

AForm	*Intern::makeShrub(std::string target) {
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeRobot(std::string target) {
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makePres(std::string target) {
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string nameForm, std::string target) {
	std::string	forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*make[3])(std::string) = {&Intern::makeShrub, &Intern::makeRobot, &Intern::makePres};
	int	i;
	for (i = 0; i < 3 && nameForm != forms[i]; i++);
	if (i == 3)
		throw Intern::FormNotExistException();
	std::cout << "Intern creates " << nameForm << std::endl;
	return (this->*make[i])(target);
}