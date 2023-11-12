#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
class Contact
{
	public:
		void		setValue(std::string f, std::string l, std::string n, std::string p, std::string d);
		std::string	getFirstN(void);
		std::string	getLastN(void);
		std::string	getNickN(void);
		std::string	getPhoneN(void);
		std::string	getDarks(void);
	private:
		std::string	firstname;
		std::string	lastname;
		std::string	nickname;
		std::string	phone_number;
		std::string	dark_secret;
};

#endif