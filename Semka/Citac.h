#pragma once
#include "libds/amt/implicit_sequence.h"
#include "libds/adt/table.h"
#include "UzemnaJednotka.h"

class Citac
{
private:
public:
	Citac() {}
	void nacitaj(ds::amt::ImplicitSequence<UzemnaJednotka*>* paKraje, ds::amt::ImplicitSequence<UzemnaJednotka*>* paOkresy, ds::amt::ImplicitSequence<UzemnaJednotka*>* paObce, ds::adt::SortedSequenceTable<std::string, UzemnaJednotka*>* paTabulkaKrajov, ds::adt::SortedSequenceTable<std::string, UzemnaJednotka*>* paTabulkaOkresov, ds::adt::SortedSequenceTable<std::string, UzemnaJednotka*>* paTabulkaObci);
	~Citac() {}
};

