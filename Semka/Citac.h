#pragma once
#include "libds/amt/implicit_sequence.h"
#include "UzemnaJednotka.h"

class Citac
{
private:
public:
	Citac() {}
	void nacitaj(ds::amt::ImplicitSequence<UzemnaJednotka*>* paKraje, ds::amt::ImplicitSequence<UzemnaJednotka*>* paOkresy, ds::amt::ImplicitSequence<UzemnaJednotka*>* paObce);
	~Citac() {}
};

