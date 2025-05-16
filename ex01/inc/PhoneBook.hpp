/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/05/15 19:21:04 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
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

	void	add_contact(Contact new_contact);
	void	print_all () const;
	void	print_a_contact (int index) const;
	int 	get_count(void) const;
	
};

#endif

