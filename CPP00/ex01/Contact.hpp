#pragma once
#include <string>

class Contact
{
private:
	int			index;
	std::string fname;
	std::string lname;
	std::string nname;
	std::string secret;
	std::string number;
	int			isNumber(std::string s);
public:
	int			get_index();
	std::string	get_fname();
	std::string	get_lname();
	std::string	get_nname();
	std::string	get_secret();
	std::string	get_number();
	void		set_index(int val);
	int			set_fname(std::string val);
	int			set_lname(std::string val);
	int			set_nname(std::string val);
	int			set_secret(std::string val);
	int			set_number(std::string val);
};
