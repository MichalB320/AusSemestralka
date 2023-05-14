#include <fstream>
#include "Citac.h"
#include "Kraj.h"
#include "Okres.h"
#include "Obec.h"
#include "Narodnost.h"

void Citac::nacitaj(ds::amt::ImplicitSequence<UzemnaJednotka*>* paKraje, ds::amt::ImplicitSequence<UzemnaJednotka*>* paOkresy, ds::amt::ImplicitSequence<UzemnaJednotka*>* paObce, ds::adt::SortedSequenceTable<std::string, UzemnaJednotka*>* paTabulkaKrajov)
{
	std::string cesty[] = { "C:\\Users\\micha\\Downloads\\kraje_test.csv",
							"C:\\Users\\micha\\Downloads\\okresy_test.csv", 
							"C:\\Users\\micha\\Downloads\\obce_test.csv" };

	std::ifstream citac;

	for (size_t cesta = 0; cesta < std::size(cesty); cesta++)
	{
		citac.open(cesty[cesta]);

		if (citac.is_open())
		{
			//sortNumber;code;officialTitle;mediumTitle;shortTitle;note
			std::string sortNumber = " ";
			std::string code = u8" ";
			std::string officialTitle = u8" ";
			std::string mediumTitle = u8" ";
			std::string shortTitle = u8" ";
			std::string note = u8" ";

			std::string riadok;

			getline(citac, riadok);

			int index = 0;
			while (!citac.eof()) 
			{
				getline(citac, sortNumber, ';');
				getline(citac, code, ';');
				getline(citac, officialTitle, ';');
				getline(citac, mediumTitle, ';');
				getline(citac, shortTitle, ';');
				getline(citac, note);

				switch (cesta)
				{
				case 0:
				{
					Kraj* kraj = new Kraj(sortNumber, code, officialTitle, mediumTitle, shortTitle, note);
					paKraje->insertLast().data_ = kraj;//new Kraj(sortNumber, code, officialTitle, mediumTitle, shortTitle, note);
					paTabulkaKrajov->insert(officialTitle, kraj);
					break;
				}
				case 1:
				{
					Okres* okres = new Okres(sortNumber, code, officialTitle, mediumTitle, shortTitle, note);
					paOkresy->insertLast().data_ = okres;
					break;
				}
				case 2:
				{
					Obec* obec = new Obec(&sortNumber, &code, &officialTitle, &mediumTitle, &shortTitle, &note);
					paObce->insertLast().data_ = obec;
					break;
				}
				default:
					std::cout << "chyba pri nacitavani zo suboru:" << std::endl;
					break;
				}
				citac.peek();
			}
		}
		citac.close();
	}
}

void Citac::nacitajNarodnosti(ds::adt::SortedSequenceTable<std::string, Narodnost*>* paTabulkaNarodnosti)
{
	std::string cesta = "C:\\Users\\micha\\Downloads\\narodnosti22.csv";

	std::ifstream citac;

	citac.open(cesta);

	if (citac.is_open())
	{
		//code;officialTitle;Slovenská;Maïarská;Rómska;Rusínska;Ukrajinská;Èeská;Nemecká;Po¾ská;Chorvátska;Srbská;Ruská;Židovská;Moravská;Bulharská;Sliezska;Grécka;Rumunská;Rakúska;Vietnamská;Albánska;Iná a nezistená
		std::string code = " ";
		std::string officialTitle = u8" ";
		std::string* pole = new std::string[21];
		for (int i = 0; i < 21; i++)
			pole[i] = " ";

		std::string riadok;

		getline(citac, riadok);

		while (!citac.eof())
		{
			getline(citac, code, ';');
			getline(citac, officialTitle, ';');
			
			for (int i = 0; i < 21; i++)
			{
				if (i == 20)
					getline(citac, pole[i]);
				else
					getline(citac, pole[i], ';');
			}

			/*Narodnost* nar = new std::string[21];
			for (int i = 0; i < 21; i++)
				nar[]*/

			Narodnost* nar = new Narodnost();
			nar->load(pole);

			paTabulkaNarodnosti->insert(code, nar);

			citac.peek();
		}
		delete[] pole;
	}
	citac.close();
}
