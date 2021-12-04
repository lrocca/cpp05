/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:35:33 by lrocca            #+#    #+#             */
/*   Updated: 2021/12/04 03:09:47 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

		Form	formino("formino", 42, 42);
		Form	formone("formone", 1, 1);

		std::cout << formino;
		std::cout << formone;

		burro.signForm(formino);
		burro.signForm(formone);

		Form	formetto("formetto", 1000, 1);
	}
	catch (std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}
