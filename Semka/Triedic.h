#pragma once
#include "libds/amt/implicit_sequence.h"
#include "UzemnaJednotka.h"

class Triedic
{
private:

public:
	void pripravData(ds::amt::ImplicitSequence<UzemnaJednotka*>* uj, ds::amt::ImplicitSequence<std::string>& pomocna, std::function<void()> operation)
	{
		int i = 0;
		for (auto zaciatok = uj->begin(); zaciatok != uj->end(); zaciatok++)
		{
			pomocna.insertLast().data_ = uj->access(i)->data_->getOfficialTitle();
			i++;
		}

		operation();

		for (auto element : pomocna)
		{
			std::cout << "\t" << element << " : " << countVowels(element) << std::endl;
		}
	}

private:
	int countVowels(const std::string& str)
	{
		int pocet = 0;
		std::string samohlasky = "aáäeéiíyýoóuúôAÁEÉIÍYÝOÓUÚ";
		for (char pismeno : str)
		{
			if (samohlasky.find(pismeno) != std::string::npos)
				pocet++;
		}
		return pocet;
	}
};

