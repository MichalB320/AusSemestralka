#include "IS.h"
#include <fstream>
#include "Slovensko.h"
#include "Alg.h"
#include <chrono>
#include <thread>
#include "libds/adt/sorts.h"
#include "Triedic.h"

IS::IS()
{
	kraje_ = new ds::amt::ImplicitSequence<UzemnaJednotka*>();
	okresy_ = new ds::amt::ImplicitSequence<UzemnaJednotka*>();
	obce_ = new ds::amt::ImplicitSequence<UzemnaJednotka*>();

	tabulkaKrajov_ = new ds::adt::SortedSequenceTable<std::string, UzemnaJednotka*>();
	tabulkaOkresov_ = new ds::adt::SortedSequenceTable<std::string, std::vector<UzemnaJednotka*>*>();
	tabulkaObci_ = new ds::adt::SortedSequenceTable<std::string, std::vector<UzemnaJednotka*>*>();

	hierarchia_ = new ds::amt::MultiWayExplicitHierarchy<UzemnaJednotka*>();

	tabulkaNarodnosti_ = new ds::adt::SortedSequenceTable<std::string, Narodnost*>();

	Citac citac;
	citac.nacitaj(kraje_, okresy_, obce_, tabulkaKrajov_);
	citac.nacitajNarodnosti(tabulkaNarodnosti_);
	nacitajTabulky();
}

void IS::nacitajJednotky()
{
	int index = 0;
	int index2 = 0;
	int index3 = 0;
	int i = 0;
	auto curPos = okresy_->begin();
	auto curObec = obce_->begin();

	int indexObce1 = 0;
	int indexObce2 = 0;

	auto krajTab = tabulkaKrajov_->begin();

	hierarchia_->emplaceRoot().data_ = new Slovensko();
	for (auto kraj = kraje_->begin(); kraj != kraje_->end(); kraj++)
	{
		hierarchia_->emplaceSon(*hierarchia_->accessRoot(), index).data_ = kraje_->access(index)->data_;

		for (auto okres = curPos; okres != okresy_->end(); okres++)
		{
			if (okresy_->access(index2)->data_->getNote() != "" && kraje_->access(index)->data_->getNote().substr(8, 2) /*kraj->getNote().substr(8, 2)*/ == okresy_->access(index2)->data_->getCode().substr(3, 2))
			{
				hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3).data_ = okresy_->access(index2)->data_;
				for (auto obec = curObec; obec != obce_->end(); obec++)
				{
					if (obce_->access(indexObce1)->data_->getCode() != "" && okresy_->access(index2)->data_->getCode().substr(5, 1) == obce_->access(indexObce1)->data_->getCode().substr(5, 1))
					{
						hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3), indexObce2).data_ = std::move(obce_->access(indexObce1)->data_);
						indexObce1++;
						indexObce2++;
						curObec++;
					}
					else
						break;
				}
				//indexObce1 = 0;
				indexObce2 = 0;

				curPos++;
				index2++;
				index3++;
			}
			else if (okresy_->access(index2)->data_->getNote() == "" && kraje_->access(index)->data_->getNote() /*kraj->getNote()*/ == "ZZ-9-*****")
			{
				hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3).data_ = okresy_->access(index2)->data_;

				indexObce2 = 0;

				curPos++;
				index2++;
				index3++;
			}
			else
				break;
		}
		index3 = 0;
		index++;
	}
	hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 8), 0), 0).data_ = obce_->access(2928)->data_;
	hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 8), 1), 0).data_ = obce_->access(2929)->data_;
}

void IS::iter()
{
	system("cls");
	std::cout << "\t\tITERÁTOR HIERARCHIE ÚZEMNÝCH JEDNOTIEK" << std::endl;
	auto curNode = hierarchia_->accessRoot();
	std::string in;
	while (true)
	{
		if (hierarchia_->level(*curNode) == 0)
			std::cout << curNode->data_->getCode() << ">";
		else if (hierarchia_->level(*curNode) == 1)
			std::cout << hierarchia_->accessParent(*curNode)->data_->getCode() << "\\" << curNode->data_->getOfficialTitle() << ">";
		else if (hierarchia_->level(*curNode) == 2)
			std::cout << hierarchia_->accessRoot()->data_->getCode() << "\\" << hierarchia_->accessParent(*curNode)->data_->getOfficialTitle() << "\\" << curNode->data_->getMediumTitle() << ">";
		else if (hierarchia_->level(*curNode) == 3)
			std::cout << hierarchia_->accessRoot()->data_->getCode() << "\\" << hierarchia_->accessParent(*hierarchia_->accessParent(*curNode))->data_->getOfficialTitle() << "\\" << hierarchia_->accessParent(*curNode)->data_->getMediumTitle() << "\\" << curNode->data_->getOfficialTitle() << ">";

		std::cin >> in;

		if (in == "dir")
			dir(curNode);
		else if (in == "type")
			type(curNode);
		else if (in == "cd")
			curNode = changeDirectory(curNode);
		else if (in == "contains")
			contains(curNode);
		else if (in == "start")
			startWith(curNode);
		else if (in == "tab")
			tab();
		else if (in == "info")
			info(curNode);
		else if (in == "sort")
			sort();
		else if (in == "alpha")
			alpha(curNode);
		else if (in == "vowels")
			vowelsCount(curNode);
		else if (in == "exit")
			break;
		else
			std::cout << "Nesprávny vstup" << std::endl;
	}
}

void IS::run()
{
	bool running = true;
	while (running)
	{
		system("cls");
		std::cout << "\t1. prvá úroveò\n\t2. druhá úroveò\n\t3. tretia úroveò\n\t4. štvrtá úroveò\n\t5. koniec" << std::endl;
		std::string uroven;
		std::cin >> uroven;
		
		if (uroven == "1")
			proc();
		else if (uroven == "2")
			iter();
		else if (uroven == "3")
			tab();
		else if (uroven == "4")
			sort();
		else if (uroven == "5")
			running = false;
		else if (uroven == "exit")
			running = false;
		else
		{
			std::cout << "nesprávny vstup" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(600));
		}
	}
}

void IS::contains(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode)
{
	std::string vstup;
	std::cin >> vstup;
	hierarchia_->processPreOrder(curNode, [&](const ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* uj) {
		if (uj->data_->getOfficialTitle().find(vstup) != std::string::npos)
			std::cout << uj->data_->getOfficialTitle() << std::endl;
	});
}

void IS::contains(ds::amt::ImplicitSequence<UzemnaJednotka*>* uj)
{
	std::string vstup;
	std::cin >> vstup;
	Alg<ds::amt::ImplicitSequence<UzemnaJednotka*>*, ds::amt::MemoryBlock<UzemnaJednotka*>> spracovac;
	spracovac.processData(uj, [&](ds::amt::MemoryBlock<UzemnaJednotka*>* uj) {
		if (uj->data_->getOfficialTitle().find(vstup) != std::string::npos)
			std::cout << uj->data_->getOfficialTitle() << std::endl;
	});
}

void IS::startWith(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode)
{
	std::string vstup;
	std::cin >> vstup;
	hierarchia_->processPreOrder(curNode, [&](const ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* uj) {
		if (uj->data_->getOfficialTitle().compare(0, vstup.length(), vstup) == 0)
			std::cout << uj->data_->getOfficialTitle() << std::endl;
	});
}

void IS::startWith(ds::amt::ImplicitSequence<UzemnaJednotka*>* uj)
{
	std::string vstup;
	std::cin >> vstup;
	Alg<ds::amt::ImplicitSequence<UzemnaJednotka*>*, ds::amt::MemoryBlock<UzemnaJednotka*>> spracovac;
	spracovac.processData(uj, [&](ds::amt::MemoryBlock<UzemnaJednotka*>* uj) {
		if (uj->data_->getOfficialTitle().compare(0, vstup.length(), vstup) == 0)
			std::cout << uj->data_->getOfficialTitle() << std::endl;
	});
}

void IS::dir(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode)
{
	if (hierarchia_->level(*curNode) == 0)
	{
		int index = 0;
		for (auto kraj : *kraje_)
		{
			std::cout << "\t" << index << " " << kraj->getOfficialTitle() << std::endl;
			index++;
		}
	}
	else if (hierarchia_->level(*curNode) == 1)
	{
		int index = 0;
		hierarchia_->processLevelOrder(curNode, [&](ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* uj) {
			//std::cout << uj->data_->getOfficialTitle() << std::endl;
			if (hierarchia_->level(*uj) == 2)
			{
				std::cout << "\t" << index << " " << uj->data_->getOfficialTitle() << std::endl;
				index++;
			}
			});
	}
	else if (hierarchia_->level(*curNode) == 2)
	{
		int index = 0;
		hierarchia_->processLevelOrder(curNode, [&](ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* uj) {
			if (hierarchia_->level(*uj) == 3)
			{
				std::cout << "\t" << index << " " << uj->data_->getOfficialTitle() << std::endl;
				index++;
			}
			});
	}
	else if (hierarchia_->level(*curNode) == 3)
		std::cout << "\t" << curNode->data_->getOfficialTitle() << " = " << hierarchia_->isLeaf(*curNode) << "(is leaf)" << std::endl;
}

void IS::type(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode)
{
	switch (hierarchia_->level(*curNode))
	{
	case 0:
		std::cout << "\tštát" << std::endl;
		break;
	case 1:
		std::cout << "\tkraj" << std::endl;
		break;
	case 2:
		std::cout << "\tokres" << std::endl;
		break;
	case 3:
		std::cout << "\tobec" << std::endl;
		break;
	default:
		break;
	}
}

ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* IS::changeDirectory(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode)
{
	std::string vstup;
	std::cin >> vstup;
	if (vstup == ".." && !hierarchia_->isRoot(*curNode))
		return hierarchia_->accessParent(*curNode);
	else if (vstup == ".." && hierarchia_->isRoot(*curNode))
		return curNode;
	else if (vstup == "/")
		return hierarchia_->accessRoot();
	else 
		return hierarchia_->accessSon(*curNode, stoi(vstup));
}

void IS::proc()
{
	system("cls");
	std::cout << "\t\tSPRACOVANIE ÚDAJOVEJ ŠTRUKTÚRY" << std::endl;
	bool running = true;
	while (running)
	{
		std::cout << "\n\t1. Kraj\n\t2. Okres\n\t3. Obec" << std::endl;
		std::string vyber;
		std::cout << "\nUzemna jednotka: ";
		std::cin >> vyber;
		
		if (vyber == "1")
		{
			std::string in;
			std::cout << "> ";
			std::cin >> in;
			if (in == "contains")
				contains(kraje_);
			else if (in == "start")
				startWith(kraje_);
			else if (in == "exit")
				running = false;
			else
				std::cout << "Nesprávny vstup" << std::endl;
		}
		else if (vyber == "2")
		{
			std::string in;
			std::cout << "> ";
			std::cin >> in;
			if (in == "contains")
				contains(okresy_);
			else if (in == "start")
				startWith(okresy_);
			else if (in == "exit")
				running = false;
			else
				std::cout << "Nesprávny vstup" << std::endl;
		}
		else if (vyber == "3")
		{
			std::string in;
			std::cout << "> ";
			std::cin >> in;
			if (in == "contains")
				contains(obce_);
			else if (in == "start")
				startWith(obce_);
			else if (in == "exit")
				running = false;
			else
				std::cout << "Nesprávny vstup" << std::endl;
		}
		else if (vyber == "exit")
			break;
		else
			std::cout << "Nespravny vyber." << std::endl;
	}
}

void IS::info(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode)
{
	std::string vyber;
	std::cin >> vyber;
	if (tabulkaNarodnosti_->contains(curNode->data_->getCode()))
		tabulkaNarodnosti_->find(curNode->data_->getCode())->vypis(vyber);
	if (curNode->data_->getCode().length() == 1)
		tabulkaNarodnosti_->find(curNode->data_->getNote().substr(5, 10))->vypis(vyber);
}

void IS::tab()
{
	system("cls");
	std::cout << "\t\tPREH¼ADÁVANIE V TABU¼KÁCH" << std::endl;
	while (true)
	{
		std::cout << "\n\t1. Kraj\n\t2. Okres\n\t3. Obec" << std::endl;
		std::string vyber;
		std::cout << "\nUzemna jednotka: ";
		std::cin >> vyber;
		std::string nazov;
		std::cout << "Názov: ";
		std::cin.ignore();
		std::getline(std::cin, nazov);
		if (vyber == "1")
		{
			if (tabulkaKrajov_->contains(nazov))
			{
				UzemnaJednotka* kraj = tabulkaKrajov_->find(nazov);
				std::cout << kraj->getShortTitle() << " - " << kraj->getNote() << std::endl;
			}
			else
				std::cout << "taky kraj neexistuje" << std::endl;
		}
		else if (vyber == "2")
		{
			if (tabulkaOkresov_->contains(nazov))
			{
				int index = 0;
				for (auto zaciatok = tabulkaOkresov_->find(nazov)->begin(); zaciatok != tabulkaOkresov_->find(nazov)->end(); zaciatok++)
				{
					UzemnaJednotka* okres = tabulkaOkresov_->find(nazov)->at(index);
					std::cout << okres->getShortTitle() << " - " << okres->getCode() << " - " << okres->getNote() << std::endl;
					index++;
				}
			}
			else
				std::cout << "taky okres neexistuje" << std::endl;
		}
		else if (vyber == "3")
		{
			if (tabulkaObci_->contains(nazov))
			{
				int index = 0;
				for (auto zaciatok = tabulkaObci_->find(nazov)->begin(); zaciatok != tabulkaObci_->find(nazov)->end(); zaciatok++)
				{
					UzemnaJednotka* obec = tabulkaObci_->find(nazov)->at(index);
					std::cout << obec->getShortTitle() << " - " << obec->getCode() << " - " << obec->getNote() << std::endl;
					index++;
				}
			}
			else
				std::cout << "taka obec neexistuje" << std::endl;
		}
		else if (vyber == "exit")
			break;
		else
			std::cout << "Nespravny vyber." << std::endl;
	}
}

void IS::nacitajTabulky()
{
	int index = 0;
	for (auto zaciatok = okresy_->begin(); zaciatok != okresy_->end(); zaciatok++)
	{
		if (tabulkaOkresov_->contains(okresy_->access(index)->data_->getOfficialTitle()))
		{
			tabulkaOkresov_->find(okresy_->access(index)->data_->getOfficialTitle())->push_back(okresy_->access(index)->data_);
		}
		else
		{
			std::vector<UzemnaJednotka*>* Vokres = new std::vector<UzemnaJednotka*>();
			Vokres->push_back(okresy_->access(index)->data_);
			tabulkaOkresov_->insert(okresy_->access(index)->data_->getOfficialTitle(), Vokres);
		}
		index++;
	}

	index = 0;
	for (auto zaciatok = obce_->begin(); zaciatok != obce_->end(); zaciatok++)
	{
		if (tabulkaObci_->contains(obce_->access(index)->data_->getOfficialTitle()))
		{
			tabulkaObci_->find(obce_->access(index)->data_->getOfficialTitle())->push_back(obce_->access(index)->data_);
		}
		else
		{
			std::vector<UzemnaJednotka*>* Vobce = new std::vector<UzemnaJednotka*>();
			Vobce->push_back(obce_->access(index)->data_);
			tabulkaObci_->insert(obce_->access(index)->data_->getOfficialTitle(), Vobce);
		}
		index++;
	}
}

void IS::sort()
{
	system("cls");
	std::cout << "\t\tSORTOVANIE" << std::endl;
	bool running = true;
	while (running)
	{
		std::cout << "\n\t1. Kraj\n\t2. Okres\n\t3. Obec" << std::endl;
		std::string vyber;
		std::cout << "\nUzemna jednotka: ";
		std::cin >> vyber;

		if (vyber == "1")
		{
			std::string in;
			std::cout << "> ";
			std::cin >> in;
			if (in == "alpha")
				alpha(kraje_);
			else if (in == "vowelsCount")
				vowelsCount(kraje_);
			else if (in == "exit")
				running = false;
			else
				std::cout << "Nesprávny vstup" << std::endl;
		}
		else if (vyber == "2")
		{
			std::string in;
			std::cout << "> ";
			std::cin >> in;
			if (in == "alpha")
				alpha(okresy_);
			else if (in == "vowelsCount")
				vowelsCount(okresy_);
			else if (in == "exit")
				running = false;
			else
				std::cout << "Nesprávny vstup" << std::endl;
		}
		else if (vyber == "3")
		{
			std::string in;
			std::cout << "> ";
			std::cin >> in;
			if (in == "alpha")
				alpha(obce_);
			else if (in == "vowelsCount")
				vowelsCount(obce_);
			else if (in == "exit")
				running = false;
			else
				std::cout << "Nesprávny vstup" << std::endl;
		}
		else if (vyber == "exit")
			break;
		else
			std::cout << "Nespravny vyber." << std::endl;
	}
}

void IS::alpha(ds::amt::ImplicitSequence<UzemnaJednotka*>* uj)
{
	ds::amt::ImplicitSequence<std::string> pomocna;
	Triedic triedic;
	triedic.pripravData(uj, pomocna, [&]() {
		ds::adt::QuickSort<std::string> quickSort;
		
		quickSort.sort(pomocna, [&](const std::string& a, const std::string& b) -> bool {
			return a < b;
		});
	});
}

void IS::alpha(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode)
{
	ds::amt::ImplicitSequence<UzemnaJednotka*>* pomocnaZHierarchie = new ds::amt::ImplicitSequence<UzemnaJednotka*>();

	if (hierarchia_->level(*curNode) == 0)
		alpha(kraje_);
	else if (hierarchia_->level(*curNode) == 1)
	{
		hierarchia_->processLevelOrder(curNode, [&](ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* uj) {
			if (hierarchia_->level(*uj) == 2)
				pomocnaZHierarchie->insertLast().data_ = uj->data_;
		});
	}
	else if (hierarchia_->level(*curNode) == 2)
	{
		hierarchia_->processLevelOrder(curNode, [&](ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* uj) {
			if (hierarchia_->level(*uj) == 3)
				pomocnaZHierarchie->insertLast().data_ = uj->data_;
		});
	}
	else if (hierarchia_->level(*curNode) == 3)
		std::cout << "\t" << curNode->data_->getOfficialTitle() << " = " << hierarchia_->isLeaf(*curNode) << "(is leaf)" << std::endl;

	if (pomocnaZHierarchie->begin() != pomocnaZHierarchie->end())
		alpha(pomocnaZHierarchie);
	pomocnaZHierarchie->clear();
	delete pomocnaZHierarchie;
}

void IS::vowelsCount(ds::amt::ImplicitSequence<UzemnaJednotka*>* uj)
{
	ds::amt::ImplicitSequence<std::string> pomocna;
	Triedic triedic;
	triedic.pripravData(uj, pomocna, [&]() {

		ds::adt::QuickSort<std::string> quickSort;

		quickSort.sort(pomocna, [&](const std::string& a, const std::string& b) -> bool {
			int pocetA = countVowels(a);
			int pocetB = countVowels(b);
			return pocetA < pocetB;
		});
	});
}

void IS::vowelsCount(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode)
{
	ds::amt::ImplicitSequence<UzemnaJednotka*>* pomocnaZHierarchie = new ds::amt::ImplicitSequence<UzemnaJednotka*>();

	if (hierarchia_->level(*curNode) == 0)
		vowelsCount(kraje_);
	else if (hierarchia_->level(*curNode) == 1)
	{
		hierarchia_->processLevelOrder(curNode, [&](ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* uj) {
			if (hierarchia_->level(*uj) == 2)
				pomocnaZHierarchie->insertLast().data_ = uj->data_;
		});
	}
	else if (hierarchia_->level(*curNode) == 2)
	{
		hierarchia_->processLevelOrder(curNode, [&](ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* uj) {
			if (hierarchia_->level(*uj) == 3)
				pomocnaZHierarchie->insertLast().data_ = uj->data_;
		});
	}
	else if (hierarchia_->level(*curNode) == 3)
		std::cout << "\t" << curNode->data_->getOfficialTitle() << " = " << hierarchia_->isLeaf(*curNode) << "(is leaf)" << std::endl;

	if (pomocnaZHierarchie->begin() != pomocnaZHierarchie->end())
		vowelsCount(pomocnaZHierarchie);
	pomocnaZHierarchie->clear();
	delete pomocnaZHierarchie;
}

int IS::countVowels(const std::string& str)
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
