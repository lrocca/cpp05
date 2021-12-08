/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:35:33 by lrocca            #+#    #+#             */
/*   Updated: 2021/12/08 02:58:40 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// void	sectionTitle(const std::string& title) {
// 	std::cout	<< std::endl
// 				<< "*** " << title << " ***"
// 				<< std::endl << std::endl;
// }

int	main() {
	// sectionTitle("constructor");

	try {
		Bureaucrat	burro("burro", 42);
		std::cout << burro;

		ShrubberyCreationForm		formino("formino");
		RobotomyRequestForm			formone("formone");
		PresidentialPardonForm		formetto("formetto");

		std::cout << formino;
		std::cout << formone;

		burro.signForm(formino);
		burro.executeForm(formino);
		burro.signForm(formone);
		burro.executeForm(formone);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// TODO
	// grade too low to sign
	// grade too low to execute
	// form not signed
}
