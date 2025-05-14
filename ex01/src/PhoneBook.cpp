/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/05/14 20:52:16 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

using std::cout;
using std::endl;
using std::setw;
using std::string;

PhoneBook::PhoneBook()
{
	count = 0;
}

PhoneBook::~PhoneBook()
{
}

string PhoneBook::truncate(const string& str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}
void PhoneBook::add_contact(Contact new_contact)
{
	int	index = count % MAX_CONTACTS;
	
	contacts[index] = new_contact;
	count++;

	cout << "Contact added at index " << index;
	if (count > MAX_CONTACTS)
		cout << " (overwriting)";
	cout << std::endl;
}

void PhoneBook::search_contacts() const
{
	int total = (count < MAX_CONTACTS) ? count : MAX_CONTACTS;
	
	cout	<< std::right
			<< std::setw(10) << "Index"			<< "|"
			<< std::setw(10) << "First Name"	<< "|"
			<< std::setw(10) << "Last Name" 	<< "|"
			<< std::setw(10) << "Nickname"  	<< "|\n";

	for (int i = 0; i < total; ++i)
	{
		cout	<< std::right
				<< std::setw(10) << i + 1 << "|"
				<< std::setw(10) << truncate(contacts[i].get_first_name()) << "|"
				<< std::setw(10) << truncate(contacts[i].get_last_name()) << "|"
				<< std::setw(10) << truncate(contacts[i].get_nickname()) << "|\n";
	}
	cout << endl;
}
