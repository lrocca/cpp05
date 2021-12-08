/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrocca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:55:28 by lrocca            #+#    #+#             */
/*   Updated: 2021/12/08 02:43:30 by lrocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern;

typedef Form* (Intern::*CF)(const std::string&) const;

class Intern {
	private:
		static const std::string	names[3];
		static const CF				forms[3];

		Form*	ShrubberyCreation(const std::string& target) const;
		Form*	RobotomyRequest(const std::string& target) const;
		Form*	PresidentialPardon(const std::string& target) const;
	public:
		Intern();
		~Intern();
		Intern(const Intern& other);

		Intern&	operator=(const Intern& other);

		Form*	makeForm(const std::string& form, const std::string& target) const;
};

#endif
