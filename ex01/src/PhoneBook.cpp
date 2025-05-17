/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/05/17 16:21:53 by myuen            ###   ########.fr       */
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
	size_t	index = count % MAX_CONTACTS;
	
	contacts[index] = new_contact;
	count++;
	cout << "... Contact added at index " << index + 1;
	if (count > MAX_CONTACTS)
		cout << " (overwriting)";
	cout << " ..." <<std::endl;

	if (count > MAX_CONTACTS * 100)
    	count = MAX_CONTACTS + (count % MAX_CONTACTS);
}

void PhoneBook::print_all(void) const
{
	int	total = (count < MAX_CONTACTS) ? count : MAX_CONTACTS;
	int	i = 0;
	
	for (i=0; i<45; i++)
		cout << "_";
	cout << endl;
		
	cout	<< "|"
			<< std::right
			<< setw(10) << "Index"			<< "|"
			<< setw(10) << "First Name"	<< "|"
			<< setw(10) << "Last Name" 	<< "|"
			<< setw(10) << "Nickname"  	<< "|"
			<< "\n";

	for (i=0; i < total; ++i)
	{
		cout	<< "|"
				<< std::right
				<< setw(10) << i + 1 << "|"
				<< setw(10) << truncate(contacts[i].get_first_name()) << "|"
				<< setw(10) << truncate(contacts[i].get_last_name()) << "|"
				<< setw(10) << truncate(contacts[i].get_nickname()) << "|"
				<< "\n";
	}
	
	for (i=0; i<45; i++)
		cout << "_";
	cout << endl;
}

int PhoneBook::get_count(void) const
{
	return (count);
}

void PhoneBook::print_a_contact(size_t index) const
{
	if (index < count)
	{
		cout << "========== Index " << index + 1 << " ==========\n";
		contacts[index].print_contact();
	}
}
