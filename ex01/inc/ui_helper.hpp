/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_helper.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/05/15 16:55:50 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_HELPER_HPP
#define UI_HELPER_HPP

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include "Contact.hpp"
#include "PhoneBook.hpp"

bool		string_to_int_ok(const std::string& input, int& result);
void		show_main_menu(void);
std::string get_input(const std::string& prompt);
int			add_contact_ok(Contact& new_contact);
int			search_contact_ok(PhoneBook& phonebook);
int			main_menu_selection(std::string command, PhoneBook& phonebook);

#endif