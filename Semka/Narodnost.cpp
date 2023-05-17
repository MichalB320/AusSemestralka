#include "Narodnost.h"

void Narodnost::load(std::string fs[])
{
	for (int i = 0; i < 21; i++)
		narodnosti[i] = fs[i];
}

void Narodnost::vypis(std::string filter)
{
	std::string nazvy[] = { "Slovenská", "Maïarská", "Rómska", "Rusínska", "Ukrajinská", "Èeská", "Nemecká", "Po¾ská", "Chorvátska", "Srbská", "Ruská", "Židovská", "Moravská", "Bulharská", "Sliezska", "Grécka", "Rumunská", "Rakúska", "Vietnamská", "Albánska", "Iná a nezistená" };
	

	if (filter == "all")
	{
		for (int i = 0; i < 21; i++)
		{
			std::cout << nazvy[i] << ": " << narodnosti[i] << std::endl;
		}
	}
	else if (filter == "min")
	{
		int min = 99999999;
		int index = -1;
		for (int i = 0; i < 21; i++)
		{
			if (stoi(narodnosti[i]) < min)
			{
				min = stoi(narodnosti[i]);
				index = i;
			}
		}
		std::cout << nazvy[index] << ": " << min << std::endl;
	}
	else if (filter == "max")
	{
		std::string docasna = narodnosti[0];
		narodnosti[0] = "0";
		int max = 0;
		int index = -1;
		for (int i = 0; i < 21; i++)
		{
			if (stoi(narodnosti[i]) > max)
			{
				max = stoi(narodnosti[i]);
				index = i;
			}
		}
		std::cout << nazvy[index] << ": " << max << std::endl;
		narodnosti[0] = docasna;
	}
	else
	{
		int vstupInt = stoi(filter);
		if (vstupInt < 21)
		{
			std::string* hlbokaKopiaPola = new std::string[21];
			for (int i = 0; i < 21; i++)
			{
				hlbokaKopiaPola[i] = narodnosti[i];
			}

			int max = 0;
			int index;
			for (int j = 0; j < vstupInt; j++)
			{
				for (int i = 0; i < 21; i++)
				{
					if (stoi(hlbokaKopiaPola[i]) > max)
					{
						max = stoi(hlbokaKopiaPola[i]);
						index = i;
					}
				}
				hlbokaKopiaPola[index] = "0";
				max = 0;
			}
			for (int i = 0; i < 21; i++)
			{
				if (stoi(hlbokaKopiaPola[i]) > max)
				{
					max = stoi(hlbokaKopiaPola[i]);
					index = i;
				}
			}
			std::cout << "\t" << nazvy[index] << ": " << max << std::endl;
			delete[] hlbokaKopiaPola;
		}
		else
		{
			std::cout << "narodnosti je len 21" << std::endl;
		}
	}
}
