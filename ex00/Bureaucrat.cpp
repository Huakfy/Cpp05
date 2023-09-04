/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjourno <mjourno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 10:46:34 by mjourno           #+#    #+#             */
/*   Updated: 2023/09/04 12:19:32 by mjourno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << "Bureaucrat default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name), _grade(src._grade) {
	std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
	std::cout << "Bureaucrat assignment operator" << std::endl;
	if (this != &src)
		_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << _name << " destructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name), _grade(grade) {
	std::cout << "Bureaucrat " << _name << " constructor" << std::endl;
	if (_grade == 0) {
		_grade = 150;
		throw Bureaucrat::GradeTooLowException();
	} else if (_grade > 150) {
		_grade = 150;
		throw Bureaucrat::GradeTooHighException();
	}
}

std::string	Bureaucrat::getName() const {
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade() const {
	return (this->_grade);
}

void	Bureaucrat::increment() {
	this->_grade -= 1;
	if (_grade == 0) {
		_grade = 1;
		throw Bureaucrat::GradeTooLowException();
	}
}

void	Bureaucrat::decrement() {
	this->_grade += 1;
	if (_grade > 150) {
		_grade = 150;
		throw Bureaucrat::GradeTooHighException();
	}
}

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &src) {
	o << src.getName() << ", bureaucrat grade " << src.getGrade();
	return (o);
}