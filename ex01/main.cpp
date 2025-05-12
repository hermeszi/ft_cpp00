/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/05/12 19:49:36 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
using std::getline;

#include "inc/Contact.hpp"
#include "inc/PhoneBook.hpp"

int main(int argc, char *argv[])
{
	string	user_input;
	Contact	first_contact;

	(void) argv;
	if (argc != 1)
		return (1);
	
	while (true)
	{
		cout << "enter first name: ";
		if (!std::getline(std::cin, user_input))
		{
			std::cout << "\nInput ended (Ctrl+D received). Exiting." << std::endl;
			std::cin.clear();
			exit(1);
		}
		if (first_contact.set_first_name(user_input))
			continue;
		cout << endl;
		break;
	}
	while (true)
	{
		cout << "enter last name: ";
		if (!std::getline(std::cin, user_input))
		{
			std::cout << "\nInput ended (Ctrl+D received). Exiting." << std::endl;
			std::cin.clear();
			exit(1);
		}
		if (first_contact.set_last_name(user_input))
			continue;
		cout << endl;
		break;
	}
	while (true)
	{
		cout << "enter nickname: ";
		if (!std::getline(std::cin, user_input))
		{
			std::cout << "\nInput ended (Ctrl+D received). Exiting." << std::endl;
			std::cin.clear();
			exit(1);
		}
		if (first_contact.set_nickname(user_input))
			continue;
		cout << endl;
		break;
	}
	while (true)
	{
		cout << "enter number: ";
		if (!std::getline(std::cin, user_input))
		{
			std::cout << "\nInput ended (Ctrl+D received). Exiting." << std::endl;
			std::cin.clear();
			exit(1);
		}
		if (first_contact.set_number(user_input))
			continue;
		cout << endl;
		break;
	}
	while (true)
	{
		cout << "enter darkest secret: ";
		if (!std::getline(std::cin, user_input))
		{
			std::cout << "\nInput ended (Ctrl+D received). Exiting." << std::endl;
			std::cin.clear();
			exit(1);
		}
		if (first_contact.set_darkest_secret(user_input))
			continue;
		cout << endl;
		break;
	}
	cout << "<<Entry ok>>" << endl;

	cout << "first name: " << first_contact.get_first_name() << "\n";
	cout << "last name: " << first_contact.get_last_name() << "\n";
	cout << "nickname: " << first_contact.get_nickname() << "\n";
	cout << "number: " << first_contact.get_number() << "\n";
	cout << "darkest secret: " << first_contact.get_darkest_secret() << "\n";
	cout << endl;
	
	return (0);
}