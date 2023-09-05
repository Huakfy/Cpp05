/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:44:55 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/05 16:43:55 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void) {
	AForm	*f;
	Intern	i;

	std::cout << std::endl;

	f = i.makeForm("robotomy request", "Bender1");

	std::cout << std::endl;

	delete f;

	std::cout << std::endl;

	f = i.makeForm("shrubbery creation", "Bender2");

	std::cout << std::endl;

	delete f;

	std::cout << std::endl;

	f = i.makeForm("presidential pardon", "Bender3");

	std::cout << std::endl;

	delete f;

	std::cout << std::endl;

	try {
		f = i.makeForm("zeaf", "Bender");
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
}