/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/05/16 16:51:29 by myuen            ###   ########.fr       */
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
#include "inc/ui_helper.hpp"


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
	cout << "✴.·´¯`·.·★  🎀𝓜𝔂 𝓐𝔀𝓮𝓼𝓸𝓶𝓮 𝓟𝓱𝓸𝓷𝓮𝓑𝓸𝓸𝓴🎀  ★·.·`¯´·.✴" << "\n";
	while (in_menu)
	{
		show_main_menu();
		if (main_menu_selection(get_input("🖎 "), phonebook_1) != 0)
			in_menu = 0;		
	}
	cout << "	👋 Bye! 👋" << endl;
	return (0);
}