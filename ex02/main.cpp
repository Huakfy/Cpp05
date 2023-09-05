/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:44:55 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/05 15:44:40 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	std::cout << "Shrubbery testing" << std::endl;
	std::cout << std::endl;

	ShrubberyCreationForm *a = new ShrubberyCreationForm("Jardin");

	std::cout << std::endl;

	//unsigned
	Bureaucrat b("b", 146);
	b.executeForm(*a);

	std::cout << std::endl;

	//level too low to sign
	std::cout << b << std::endl;
	b.signForm(*a);

	std::cout << std::endl;

	//sign but can't execute
	b.increment();
	std::cout << b << std::endl;
	b.signForm(*a);
	b.executeForm(*a);

	std::cout << std::endl;

	//increment to 137 and execute
	for (int i = 145; i > 137; i--)
		b.increment();
	std::cout << b << std::endl;
	b.executeForm(*a);

	std::cout << std::endl;

	//delete shrubbery form
	delete a;

//-------------------------------------------------------------------------------------------------

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Robotomy testing" << std::endl;
	std::cout << std::endl;

	RobotomyRequestForm *c = new RobotomyRequestForm("Robocop");

	std::cout << std::endl;

	//level too low to sign
	std::cout << b << std::endl;
	b.signForm(*c);

	std::cout << std::endl;

	//increment to 72 and sign
	for (int i = 137; i > 72; i--)
		b.increment();
	std::cout << b << std::endl;
	b.signForm(*c);

	std::cout << std::endl;

	//level too low to execute
	b.executeForm(*c);

	std::cout << std::endl;

	//increment to 45 and execute
	for (int i = 72; i > 45; i--)
		b.increment();
	std::cout << b << std::endl;
	b.executeForm(*c);

	std::cout << std::endl;

	//test robotomy 2
	b.executeForm(*c);

	std::cout << std::endl;

	//delete robotomy form
	delete c;

//-------------------------------------------------------------------------------------------------

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Presidential Pardon testing" << std::endl;
	std::cout << std::endl;

	PresidentialPardonForm *d = new PresidentialPardonForm("Robocop");

	std::cout << std::endl;

	//level too low to sign
	std::cout << b << std::endl;
	b.signForm(*d);

	std::cout << std::endl;

	//increment to 25 and sign
	for (int i = 45; i > 25; i--)
		b.increment();
	std::cout << b << std::endl;
	b.signForm(*d);

	std::cout << std::endl;

	//level too low to execute
	b.executeForm(*d);

	std::cout << std::endl;

	//increment to 5 and execute
	for (int i = 25; i > 5; i--)
		b.increment();
	std::cout << b << std::endl;
	b.executeForm(*d);

	std::cout << std::endl;

	delete d;

	std::cout << std::endl;
}