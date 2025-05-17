/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_helper.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/05/17 16:06:19 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"
#include "../inc/PhoneBook.hpp"
#include "../inc/ui_helper.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::istringstream;

bool	string_to_int(string& input, int& result)
{
    istringstream	iss(input);
	char			extra;

    if (!(iss >> result))
	{
        return false; //cout << "SS FAIL" << endl;
	}
    if (iss >> extra)
	{
        return false; //cout << "SS EXTRA CHARACTERS" << endl;
	}
    return true;
}
void	show_main_menu(void)
{
	cout << "\n";
	cout << "	▀▄▀▄▀▄Main Menu▄▀▄▀▄▀" << "\n";
	cout << "\n";
	cout << "▀▄▀▄Valid commands: ADD, SEARCH and EXIT▄▀▄▀" << "\n";
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
			cout << "\n--(Ctrl+D) EOF received--" << std::endl;
			cin.clear();
			clearerr(stdin);
			return ("");
		}
		if (user_input.length() < 1)
		{
			cout << "!-field cannot be empty-!" << "\n";
			continue;
		}
		return (user_input);
	}
}
int	add_contact(Contact& new_contact)
{
	string	user_input;
	
	cout << "	▀▄▀▄▀▄ ADD ▄▀▄▀▄▀" << "\n";
	while (true)
	{
		user_input = get_input("------First👦Name--►");
		if (user_input.empty())
			return (1);
		if (new_contact.set_first_name(user_input))
			continue;
		break;
	}
	while (true)
	{
		user_input = get_input("-------Last👧Name--►");
		if (user_input.empty())
			return (1);
		if (new_contact.set_last_name(user_input))
			continue;
		break;
	}
	while (true)
	{
		user_input = get_input("-------👶Nickname--►");
		if (user_input.empty())
			return (1);
		if (new_contact.set_nickname(user_input))
			continue;
		break;
	}
	while (true)
	{
		user_input = get_input("---------🕻Number🕽--►");
		if (user_input.empty())
			return (1);
		if (new_contact.set_number(user_input))
			continue;
		break;
	}
	while (true)
	{
		user_input = get_input("--Darkest🦇Secret--►");
		if (user_input.empty())
			return (1);
		if (new_contact.set_darkest_secret(user_input))
			continue;
		break;
	}
	cout << "... Input Received ..." << endl;
	return (0);
}

int search_contact(PhoneBook& phonebook)
{
	string  user_input;
	int		converted_input;
	
	cout << "	▀▄▀▄▀▄ SEARCH ▄▀▄▀▄▀" << "\n";
	cout << endl;
	phonebook.print_all();
	while (true)
	{
		user_input = get_input("🖎 Select an index to display (EXIT to return)--►");
		if (user_input.empty())
			return (0);
		if (user_input == "EXIT")
			return (1);
		if (string_to_int(user_input, converted_input))
		{
			if (converted_input > phonebook.get_count() || converted_input < 1)
			{
				cout << "-Index out of range-\n";
				continue;
			}
			else
			{
				phonebook.print_a_contact(static_cast<size_t> (converted_input-1));
				continue;
			}
		}
		else
		{
			cout << "!-Not a valid input-!\n";
			continue;
		}		
	}
	return (0);	
}

int	main_menu_selection(string command, PhoneBook& phonebook)
{
	Contact new_contact;
	
	if (command.empty())
	{
		return (1);
	}
	else if (command == "ADD")
	{
		if (add_contact(new_contact) == 0)
		{
			phonebook.add_contact(new_contact);
		}
		return (0);		
	}
	else if (command == "SEARCH")
	{
		search_contact(phonebook);
		return (0);
	}
	else if (command == "EXIT")
	{
		return (1);
	}
	else
	{
		cout << "!-Invalid Command-!" << "\n";
		cout << endl;
		return (0);
	}
}
