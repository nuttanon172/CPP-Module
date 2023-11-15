#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contact[8];
		int		total;
		int		index;
	
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void		setPhone(void);
		void		printContact(void);
		void		printHeader(void);
		void		printIndex(int i);
		void		addContact(void);
		void		getInput(std::string msg, std::string *str);
		int			getIndex(void);
		int			getTotal(void);
		std::string	strTruncate(std::string str);
};

#endif
