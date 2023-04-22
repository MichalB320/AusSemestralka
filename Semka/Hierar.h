#pragma once
#include <libds/amt/explicit_hierarchy.h>
#include "UzemnaJednotka.h"

class Hierar
{
private:
	ds::amt::MultiWayExplicitHierarchy<UzemnaJednotka>* hierarchia_;
public:
	Hierar();

	void napisRoot();

	~Hierar();
};

