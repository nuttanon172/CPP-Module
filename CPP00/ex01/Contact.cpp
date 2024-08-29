#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void Contact::setValue(std::string f, std::string l, std::string n, std::string p, std::string d)
{
	firstname = f;
	lastname = l;
	nickname = n;
	phone_number = p;
	dark_secret = d;
}

std::string Contact::getFirstN(void)
{
	return (firstname);
}

std::string Contact::getLastN(void)
{
	return (lastname);
}

std::string Contact::getNickN(void)
{
	return (nickname);
}

std::string Contact::getPhoneN(void)
{
	return (phone_number);
}

std::string Contact::getDarks(void)
{
	return (dark_secret);
}
