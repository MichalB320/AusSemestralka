#include "Narodnost.h"

void Narodnost::load(std::string fs[])
{
	for (int i = 0; i < 21; i++)
		narodnosti[i] = fs[i];
}

void Narodnost::vypis(std::string filter)
{
	std::string nazvy[] = { "Slovensk�", "Ma�arsk�", "R�mska", "Rus�nska", "Ukrajinsk�", "�esk�", "Nemeck�", "Po�sk�", "Chorv�tska", "Srbsk�", "Rusk�", "�idovsk�", "Moravsk�", "Bulharsk�", "Sliezska", "Gr�cka", "Rumunsk�", "Rak�ska", "Vietnamsk�", "Alb�nska", "In� a nezisten�" };
	

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
}
