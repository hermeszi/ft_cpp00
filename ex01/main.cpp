/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/05/14 20:54:54 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <cstdio>

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;
using std::getline;

#include "inc/Contact.hpp"
#include "inc/PhoneBook.hpp"

void	show_main_menu(void)
{
	cout << "\n		✴.·´¯`·.·★  🎀𝓜𝔂 𝓐𝔀𝓮𝓼𝓸𝓶𝓮 𝓟𝓱𝓸𝓷𝓮𝓑𝓸𝓸𝓴🎀  ★·.·`¯´·.✴\n";
	cout << "				░█▄▒▄█▒██▀░█▄░█░█▒█\n";
	cout << "				░█▒▀▒█░█▄▄░█▒▀█░▀▄█\n";
	cout << "\n";
	cout << "👉 Valid commands: ADD, SEARCH and EXIT";
	cout << endl;

}

string	get_input(const string& prompt)
{
	string	user_input;
	
	while (true)
	{
		cout << prompt;
		if (!std::getline(std::cin, user_input))
		{
			cout << "\ninput ended (Ctrl+D received)" << std::endl;
			cin.clear();
			clearerr(stdin);
			return ("");
		}
		if (user_input.length() < 1)
		{
			cout << "field cannot be empty\n";
			continue;
		}
		return (user_input);
	}
}
int	add_contact_ok(Contact& new_contact)
{
	string	user_input;
	
	while (true)
	{
		user_input = get_input("»»ᅳFirst Nameᅳ► ");
		if (user_input.empty())
			return (0);
		if (new_contact.set_first_name(user_input))
			continue;
		break;
	}
	while (true)
	{
		user_input = get_input("»»ᅳLast Nameᅳ► ");
		if (user_input.empty())
			return (0);
		if (new_contact.set_last_name(user_input))
			continue;
		break;
	}
	while (true)
	{
		user_input = get_input("»»ᅳNicknameᅳ► ");
		if (user_input.empty())
			return (0);
		if (new_contact.set_nickname(user_input))
			continue;
		break;
	}
	while (true)
	{
		user_input = get_input("»»ᅳ📱Numberᅳ► ");
		if (user_input.empty())
			return (0);
		if (new_contact.set_number(user_input))
			continue;
		break;
	}
	while (true)
	{
		user_input = get_input("»»ᅳDarkest🦇Secretᅳ► ");
		if (user_input.empty())
			return (0);
		if (new_contact.set_darkest_secret(user_input))
			continue;
		break;
	}
	cout << "<<Entry Ok>>" << endl;
	return (1);
}

int	main_menu_selection(string command, PhoneBook& phonebook)
{
	Contact new_contact;
	
	if (command.empty())
	{
		exit (1);
	}
	else if (command == "ADD")
	{
		if (add_contact_ok(new_contact))
		{
			phonebook.add_contact(new_contact);
		}
		else
			return (0);
		return (0);
	}
	else if (command == "SEARCH")
	{
		phonebook.search_contacts();
		return (0);
	}
	else if (command == "EXIT")
	{
		cout << "exit\n";
		return (1);
	}
	else
	{
		cout << "🈲Invalid Command\n";
		return (0);
	}

}

int	main(int argc, char *argv[])
{

	Contact	first_contact;
	PhoneBook phonebook_1;
	string	user_input;
	int		in_menu = 1;
	string	menu_choice;

	(void) argv;
	if (argc != 1)
		return (1);
	cout << "\033[2J\033[H";
	while (in_menu)
	{
		show_main_menu();
		if (main_menu_selection(get_input(">> "), phonebook_1) != 0)
			in_menu = 0;		
	}
	cout << "Bye!" << endl;
	exit (0);
	


	cout << "first name: " << first_contact.get_first_name() << "\n";
	cout << "last name: " << first_contact.get_last_name() << "\n";
	cout << "nickname: " << first_contact.get_nickname() << "\n";
	cout << "number: " << first_contact.get_number() << "\n";
	cout << "darkest secret: " << first_contact.get_darkest_secret() << "\n";
	cout << endl;
	
	return (0);
}