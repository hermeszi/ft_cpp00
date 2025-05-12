/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/05/12 19:28:11 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact()
{
}

int Contact::set_first_name(string user_input)
{
	if (user_input.length() < 1)
	{
		cout << "first name cannot be empty" << endl;
		return (1);
	}
	else
	{
		first_name = user_input;
		return (0);
	}
}

int Contact::set_last_name(string user_input)
{
	if (user_input.length() < 1)
	{
		cout << "last name cannot be empty" << endl;
		return (1);
	}
	else
	{
		last_name = user_input;
		return (0);
	}
}
int Contact::set_nickname(string user_input)
{
	if (user_input.length() < 1)
	{
		cout << "nickname cannot be empty" << endl;
		return (1);
	}
	else
	{
		nickname = user_input;
		return (0);
	}
}
int Contact::set_number(string user_input)
{
	if (user_input.length() < 1)
	{
		cout << "number cannot be empty" << endl;
		return (1);
	}
	for (unsigned long c=0; c<user_input.length(); c++)
	{
		if (!std::isdigit(user_input[c]))
		{
			cout << "number must contain only digits" << endl;
			return (1);
		}
	} 
	number = user_input;
	return (0);
}
int Contact::set_darkest_secret(string user_input)
{
	if (user_input.length() < 1)
	{
		cout << "nickname cannot be empty" << endl;
		return (1);
	}
	else
	{
		darkest_secret = user_input;
		return (0);
	}
}

string Contact::get_first_name(void)
{
	return (first_name);
}
string Contact::get_last_name(void)
{
	return (last_name);
}
string Contact::get_nickname(void)
{
	return (nickname);
}
string Contact::get_number(void)
{
	return (number);
}
string Contact::get_darkest_secret(void)
{
	return (darkest_secret);
}