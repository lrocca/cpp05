/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:55:24 by lrocca            #+#    #+#             */
/*   Updated: 2021/12/08 02:52:41 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>

const std::string	Intern::names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
const CF			Intern::forms[3] = {&Intern::ShrubberyCreation, &Intern::RobotomyRequest, &Intern::PresidentialPardon};

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
	*this = other;
}

Intern&	Intern::operator=(const Intern& other) {
	if (this != &other) {}
	return *this;
}

Form*	Intern::ShrubberyCreation(const std::string& target) const {
	return new ShrubberyCreationForm(target);
}

Form*	Intern::RobotomyRequest(const std::string& target) const {
	return new RobotomyRequestForm(target);
}

Form*	Intern::PresidentialPardon(const std::string& target) const {
	return new PresidentialPardonForm(target);
}

Form	*Intern::makeForm(const std::string& form, const std::string& target) const {
	for (int i = 0; i < 3; i++)
		if (names[i] == form)
			return (this->*(forms[i]))(target);
	std::cerr << "<Intern> No form matches " << form
		<< ". May I bring you a coffee instead?" << std::endl;
	return NULL;
}
