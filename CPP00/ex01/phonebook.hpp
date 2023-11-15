#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	setPhone(void);
		void	printHeader(void);
		void	addContact(void);
		int		getIndex(void);
		int		getTotal(void);
	private:
		Contact	conTact[8];
		int		total;
		int		index;
};

#endif
