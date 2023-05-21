#pragma once
#include <string>
#include <iostream>

class Narodnost
{
private:
	std::string narodnosti[21];
	int pocet;
public:
	Narodnost() {
		for (int i = 0; i < 21; i++)
			narodnosti[i] = " ";
	}

	void load(std::string fs[]);
	void vypis(std::string filter);

	~Narodnost() {
		for (int i = 0; i < 21; i++)
			narodnosti[i] = " ";
		//delete narodnosti;
	}
};
