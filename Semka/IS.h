#pragma once
#include "libds/amt/explicit_hierarchy.h"
#include "Citac.h"

class IS
{
private: 
	ds::amt::ImplicitSequence<UzemnaJednotka*>* kraje_;
	ds::amt::ImplicitSequence<UzemnaJednotka*>* okresy_;
	ds::amt::ImplicitSequence<UzemnaJednotka*>* obce_;
	ds::amt::MultiWayExplicitHierarchy<UzemnaJednotka*>* hierarchia_;
public:
	IS();

	void nacitajJednotky();
	void startWith(int level, std::string& start);
	void contains(int level, std::string& contains);
	void iter();

	~IS()
	{
		hierarchia_->processPostOrder(hierarchia_->accessRoot(), [&](ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* uj) {
			delete uj->data_;
		});

		obce_->clear();
		okresy_->clear();
		kraje_->clear();

		delete hierarchia_;
		delete obce_;
		delete okresy_;
		delete kraje_;
	}
private:
	void contains(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode);
	void startWith(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode);

	void dir(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode);
	void type(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode);
	ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* changeDirectory(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode);
};
