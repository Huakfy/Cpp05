/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:44:55 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/04 12:39:21 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void) {
	//test 1 -> 0
	Bureaucrat a("a",1);
	std::cout << a << std::endl;
	a.decrement();
	std::cout << a << std::endl;
	a.increment();
	std::cout << a << std::endl;
	try {
		a.increment();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << a << std::endl;

	std::cout << std::endl;

	//test 150 -> 151
	Bureaucrat b("b", 150);
	std::cout << b << std::endl;
	b.increment();
	std::cout << b << std::endl;
	b.decrement();
	std::cout << b << std::endl;
	try {
		b.decrement();
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << b << std::endl;

	std::cout << std::endl;

	//test création à 0
	try {
		Bureaucrat c("c", 0);
		std::cout << c << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	//test création à 151
	try {
		Bureaucrat d("d", 151);
		std::cout << d << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	//test canon
	std::cout << std::endl;
	Bureaucrat e("e", 1);
	std::cout << e << std::endl;
	Bureaucrat f(e);
	std::cout << f << std::endl;
	Bureaucrat g;
	std::cout << g << std::endl;
	g = f;
	std::cout << g << std::endl;

	std::cout << std::endl;
}