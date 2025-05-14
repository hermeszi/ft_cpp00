/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/05/14 20:24:47 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <iostream>

#include "Contact.hpp"

class PhoneBook
{
private:
	static const int	MAX_CONTACTS = 8;
	Contact				contacts[MAX_CONTACTS];
	int					count;
	
	std::string truncate(const std::string& str) const;
public:
	PhoneBook();
	~PhoneBook();

	void add_contact(Contact new_contact);
	void search_contacts() const;
};

#endif

