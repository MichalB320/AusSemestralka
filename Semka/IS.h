#pragma once
#include "libds/amt/explicit_hierarchy.h"
#include "libds/adt/table.h"
#include "Citac.h"
#include "Narodnost.h"

class IS
{
private: 
	ds::amt::ImplicitSequence<UzemnaJednotka*>* kraje_;
	ds::amt::ImplicitSequence<UzemnaJednotka*>* okresy_;
	ds::amt::ImplicitSequence<UzemnaJednotka*>* obce_;

	ds::adt::SortedSequenceTable<std::string, UzemnaJednotka*>* tabulkaKrajov_;
	ds::adt::SortedSequenceTable<std::string, UzemnaJednotka*>* tabulkaOkresov_;
	ds::adt::SortedSequenceTable<std::string, UzemnaJednotka*>* tabulkaObci_;

	//ds::adt::Treap<std::string, UzemnaJednotka*>* treap;
	ds::adt::SortedSequenceTable<std::string, Narodnost*>* tabulkaNarodnosti_;

	ds::amt::MultiWayExplicitHierarchy<UzemnaJednotka*>* hierarchia_;
public:
	IS();

	void nacitajJednotky();
	void startWith(int level, std::string& start);
	void contains(int level, std::string& contains);
	void iter();
	void run();

	~IS()
	{	
		std::string kody[] = {/*"SK0",*/ "SK010", "SK021", "SK022", "SK023", "SK031", "SK032", "SK041", "SK042"};

		hierarchia_->processPostOrder(hierarchia_->accessRoot(), [&](ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* uj) {
			if (tabulkaNarodnosti_->contains(uj->data_->getCode()))
				delete tabulkaNarodnosti_->find(uj->data_->getCode());
			delete uj->data_;
		});

		for (int i = 0; i < 8; i++)
			delete tabulkaNarodnosti_->find(kody[i]);

		obce_->clear();
		okresy_->clear();
		kraje_->clear();

		tabulkaKrajov_->clear();
		tabulkaOkresov_->clear();
		tabulkaObci_->clear();
		tabulkaNarodnosti_->clear();

		delete tabulkaNarodnosti_;
		delete tabulkaKrajov_;
		delete tabulkaOkresov_;
		delete tabulkaObci_;
		delete hierarchia_;
		delete obce_;
		delete okresy_;
		delete kraje_;
	}
private:
	void contains(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode);
	void contains(ds::amt::ImplicitSequence<UzemnaJednotka*>* uj);
	void startWith(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode);
	void startWith(ds::amt::ImplicitSequence<UzemnaJednotka*>* uj);

	void dir(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode);
	void type(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode);
	ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* changeDirectory(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode);
	
	void tabStart(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode);
	void tabContains(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode);
	
	void proc();
	void info(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode);
	void tab();
};
