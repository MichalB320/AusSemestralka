#include "Narodnost.h"

void Narodnost::load(std::string fs[])
{
	for (int i = 0; i < 21; i++)
		narodnosti[i] = fs[i];
}

void Narodnost::vypis()
{
	std::string nazvy[] = { "Slovensk�", "Ma�arsk�", "R�mska", "Rus�nska", "Ukrajinsk�", "�esk�", "Nemeck�", "Po�sk�", "Chorv�tska", "Srbsk�", "Rusk�", "�idovsk�", "Moravsk�", "Bulharsk�", "Sliezska", "Gr�cka", "Rumunsk�", "Rak�ska", "Vietnamsk�", "Alb�nska", "In� a nezisten�" };
	for (int i = 0; i < 21; i++)
	{
		std::cout << nazvy[i] << ": " << narodnosti[i] << std::endl;
	}
}
