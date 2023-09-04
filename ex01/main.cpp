/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:44:55 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/04 17:19:39 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	//grade too high
	try {
		Form a("a", 0, 1);
		std::cout << a << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form a("a", 1, 0);
		std::cout << a << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	//grade too low
	try {
		Form a("a", 151, 1);
		std::cout << a << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		Form a("a", 1, 151);
		std::cout << a << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	Form f("f", 1, 1);
	std::cout << f << std::endl;

	Bureaucrat b("b", 2);
	std::cout << b << std::endl;
	//grade too low to sign
	b.signForm(f);
	std::cout << f << std::endl;

	std::cout << std::endl;

	//increment and sign
	b.increment();
	std::cout << b << std::endl;
	b.signForm(f);
	std::cout << f << std::endl;

	std::cout << std::endl;

	//already signed
	b.signForm(f);
	std::cout << f << std::endl;

	std::cout << std::endl;
}