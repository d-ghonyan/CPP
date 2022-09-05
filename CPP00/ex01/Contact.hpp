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
public:
	int			get_index();
	std::string	get_fname();
	std::string	get_lname();
	std::string	get_nname();
	std::string	get_secret();
	std::string	get_number();
	void		set_index(int val);
	void		set_fname(std::string val);
	void		set_lname(std::string val);
	void		set_nname(std::string val);
	void		set_secret(std::string val);
	void		set_number(std::string val);
};