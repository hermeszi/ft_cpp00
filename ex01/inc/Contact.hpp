/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myuen <myuen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:53:29 by myuen             #+#    #+#             */
/*   Updated: 2025/05/12 19:01:32 by myuen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

using std::string;

class Contact
{
private:
    string  first_name;
    string  last_name; 
    string  nickname;
    string  number;
    string  darkest_secret;
public:
    Contact(void);
    ~Contact();
    int set_first_name(string user_input);
    int set_last_name(string user_input);
    int set_nickname(string user_input);
    int set_number(string user_input);
    int set_darkest_secret(string user_input);
    string get_first_name(void);
    string get_last_name(void);
    string get_nickname(void);
    string get_number(void);
    string get_darkest_secret(void);

};