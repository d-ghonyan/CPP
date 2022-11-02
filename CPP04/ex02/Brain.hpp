#pragma once

#include <iostream>

class Brain
{
private:
	size_t size;
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain &other);
	void insert(std::string idea);
	std::string getIdea(size_t index);
	Brain &operator=(const Brain &other);
	~Brain();
};
