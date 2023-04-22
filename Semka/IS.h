#pragma once
#include <vector>
#include "Kraj.h"
#include "Okres.h"
#include "libds/amt/explicit_hierarchy.h"
#include <libds/amt/hierarchy.h>

class IS
{
private: 
	std::vector<UzemnaJednotka*>* jednotky_;
	std::vector<UzemnaJednotka*>* okresy_;
	std::vector<UzemnaJednotka*>* obce_;
	ds::amt::MultiWayExplicitHierarchy<UzemnaJednotka*>* hierarchia_;
	
	int kraj_;
	int okres_;
	int ba_;
	int tt_;
	int nr_;
	int tn_;
	int za_;
	int bb_;
	int ps_;
	int ke_;
	int o_;
	int obec_;
public:
	IS() {
		jednotky_ = new std::vector<UzemnaJednotka*>();
		okresy_ = new std::vector<UzemnaJednotka*>();
		obce_ = new std::vector<UzemnaJednotka*>();
		hierarchia_ = new ds::amt::MultiWayExplicitHierarchy<UzemnaJednotka*>();
		
		/*kraj_ = 0;
		okres_ = 0;
		ba_ = 0;
		tt_ = 0;
		nr_ = 0;
		tn_ = 0;
		za_ = 0;
		bb_ = 0;
		ps_ = 0;
		ke_ = 0;
		o_ = 0;
		obec_ = 0;*/
	}


	void nacitajJednotky();
	void nacitajUzly();
	void startWith(int level, std::string& start);
	void contains(int level, std::string& contains);
	void hasType();
	void iterator();

	//void vectorPP(Kraj jednotka) { jednotky_->push_back(jednotka); }

	~IS()
	{
		hierarchia_->processPostOrder(hierarchia_->accessRoot(), [&](ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* uj) {
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
		jednotky_->clear();

		delete hierarchia_;
		//std::cout << obce_->at(0)->getOfficialTitle() << std::endl;
		delete obce_;
		delete okresy_;
		delete jednotky_;
	}
private :
	void vlozKraj(int index);
	void vlozOkres(int i);
	void vlozObec(int i);
};

