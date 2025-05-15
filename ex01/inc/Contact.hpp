/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/05/15 16:41:49 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
private:
	std::string	first_name;
	std::string last_name;
	std::string nickname;
	std::string number;
	std::string darkest_secret;

public:
	Contact();
	~Contact();

	void print_contact (void) const;
	
	int	set_first_name(std::string input);
	int set_last_name(std::string input);
	int set_nickname(std::string input);
	int set_number(std::string input);
	int set_darkest_secret(std::string input);

	std::string	get_first_name() const;
	std::string get_last_name() const;
	std::string get_nickname() const;
	std::string get_number() const;
	std::string get_darkest_secret() const;
};

#endif