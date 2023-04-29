#include <fstream>
#include "Citac.h"
#include "Kraj.h"
#include "Okres.h"
#include "Obec.h"

void Citac::nacitaj(ds::amt::ImplicitSequence<UzemnaJednotka*>* paKraje, ds::amt::ImplicitSequence<UzemnaJednotka*>* paOkresy, ds::amt::ImplicitSequence<UzemnaJednotka*>* paObce)
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
					paKraje->insertLast().data_ = new Kraj(sortNumber, code, officialTitle, mediumTitle, shortTitle, note);
					break;
				case 1:
					paOkresy->insertLast().data_ = new Okres(sortNumber, code, officialTitle, mediumTitle, shortTitle, note);
					break;
				case 2:
					paObce->insertLast().data_ = new Obec(&sortNumber, &code,& officialTitle, &mediumTitle, &shortTitle, &note);
					break;
				default:
					std::cout << "chyba pri nacitavani zo suboru:" << std::endl;
					break;
				}
			}
		}
		citac.close();
	}
}
