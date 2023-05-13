#include "Narodnost.h"

void Narodnost::load(std::string fs[])
{
	for (int i = 0; i < 21; i++)
		narodnosti[i] = fs[i];
}

void Narodnost::vypis()
{
	std::string nazvy[] = { "Slovenská", "Maïarská", "Rómska", "Rusínska", "Ukrajinská", "Èeská", "Nemecká", "Po¾ská", "Chorvátska", "Srbská", "Ruská", "Židovská", "Moravská", "Bulharská", "Sliezska", "Grécka", "Rumunská", "Rakúska", "Vietnamská", "Albánska", "Iná a nezistená" };
	for (int i = 0; i < 21; i++)
	{
		std::cout << nazvy[i] << ": " << narodnosti[i] << std::endl;
	}
}
