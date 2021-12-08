/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:35:33 by lrocca            #+#    #+#             */
/*   Updated: 2021/12/08 02:59:49 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

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

		Intern	burrino;

		Form*	formino = burrino.makeForm("robotomy request", "Bender");
		Form*	formone = burrino.makeForm("presidential pardon", "lrocca");

		std::cout << *formino;
		std::cout << *formone;

		burro.signForm(*formino);
		burro.executeForm(*formino);
		burro.signForm(*formone);
		burro.executeForm(*formone);

		delete formino;
		delete formone;

		Form*	formaccio = burrino.makeForm("not a form", "you");
		std::cout << "formaccio address: " << formaccio << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// TODO
	// make Shrubbery
}
