#pragma once
#include <vector>
#include "Kraj.h"
#include "Okres.h"
#include "libds/amt/explicit_hierarchy.h"
#include "Citac.h"
#include <libds/amt/hierarchy.h>

class IS
{
private: 
	ds::amt::ImplicitSequence<UzemnaJednotka*>* kraje_;
	ds::amt::ImplicitSequence<UzemnaJednotka*>* okresy_;
	ds::amt::ImplicitSequence<UzemnaJednotka*>* obce_;
	ds::amt::MultiWayExplicitHierarchy<UzemnaJednotka*>* hierarchia_;
public:
	IS() 
	{
		kraje_ = new ds::amt::ImplicitSequence<UzemnaJednotka*>();
		okresy_ = new ds::amt::ImplicitSequence<UzemnaJednotka*>();
		obce_ = new ds::amt::ImplicitSequence<UzemnaJednotka*>();
		hierarchia_ = new ds::amt::MultiWayExplicitHierarchy<UzemnaJednotka*>();

		Citac citac;
		citac.nacitaj(kraje_, okresy_, obce_);
	}


	void nacitajJednotky();
	void nacitajUzly();
	void startWith(int level, std::string& start);
	void contains(int level, std::string& contains);
	void hasType();
	void iterator();
	void iter();

	//void vectorPP(Kraj jednotka) { jednotky_->push_back(jednotka); }

	~IS()
	{
		hierarchia_->processPostOrder(hierarchia_->accessRoot(), [&](ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* uj) {
			//std::cout << uj->data_->getOfficialTitle() << std::endl;
			delete uj->data_;
		});
		
		/*for (auto obec = obce_->begin(); obec != obce_->end(); obec++)
			delete* obec;

		for (auto okres = okresy_->begin(); okres != okresy_->end(); okres++)
			delete* okres;

		for (auto kraj = jednotky_->begin(); kraj != jednotky_->end(); kraj++)
			delete* kraj;*/

		obce_->clear();
		okresy_->clear();
		//jednotky_->clear();

		delete hierarchia_;
		//std::cout << obce_->at(0)->getOfficialTitle() << std::endl;
		delete obce_;
		delete okresy_;
		//delete jednotky_;
	}
private :
	void vlozKraj(int index);
	void vlozOkres(int i);
	void vlozObec(int i);
};

