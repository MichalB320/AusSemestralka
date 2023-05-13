#include "IS.h"
#include <fstream>
#include "Slovensko.h"
#include "Alg.h"

IS::IS()
{
	kraje_ = new ds::amt::ImplicitSequence<UzemnaJednotka*>();
	okresy_ = new ds::amt::ImplicitSequence<UzemnaJednotka*>();
	obce_ = new ds::amt::ImplicitSequence<UzemnaJednotka*>();

	tabulkaKrajov_ = new ds::adt::SortedSequenceTable<std::string, UzemnaJednotka*>();
	tabulkaOkresov_ = new ds::adt::SortedSequenceTable<std::string, UzemnaJednotka*>();
	tabulkaObci_ = new ds::adt::SortedSequenceTable<std::string, UzemnaJednotka*>();

	hierarchia_ = new ds::amt::MultiWayExplicitHierarchy<UzemnaJednotka*>();

	tabulkaNarodnosti_ = new ds::adt::SortedSequenceTable<std::string, Narodnost*>();

	Citac citac;
	citac.nacitaj(kraje_, okresy_, obce_, tabulkaKrajov_, tabulkaOkresov_, tabulkaObci_);
	citac.nacitajNarodnosti(tabulkaNarodnosti_);
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

	//int krajIndex = 0;
	//for (auto kraj = jednotky_->begin(); kraj != jednotky_->end(); kraj++)
	//{
	//	hierarchia_->emplaceSon(*hierarchia_->accessRoot(), krajIndex).data_ = jednotky_->at(krajIndex);
	//	krajIndex++;
	//}

	//krajIndex = 0;
	//int okresIndex = 0;
	//int okresV = 0;
	//for (auto okres = okresy_->begin(); okres != okresy_->end(); okres++)
	//{
	//	auto kraj = hierarchia_->accessSon(*hierarchia_->accessRoot(), krajIndex);
	//	
	//	if (okresy_->at(okresV)->getNote() != "" && kraj->data_->getNote().substr(8, 2) == okresy_->at(okresV)->getCode().substr(3, 2))
	//	{
	//		hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), krajIndex), okresIndex).data_ = okresy_->at(okresV);
	//		//std::cout << "\t" << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), krajIndex), okresIndex)->data_->getOfficialTitle() << std::endl;

	//		okresIndex++;
	//		okresV++;
	//	}
	//	else if (okresy_->at(okresV)->getNote() == "" && kraj->data_->getNote() == "ZZ-9-*****")
	//	{
	//		hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3).data_ = okresy_->at(okresV);
	//		std::cout << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3)->data_->getCode() << std::endl;

	//		okresIndex++;
	//		okresV++;
	//	}
	//	else
	//	{
	//		okresIndex = 0;
	//		krajIndex++;
	//	}
	//}

	//krajIndex = 0;
	//okresIndex = 0;
	//int obecIndex = 0;
	//okresV = 0;
	//int obecV = 0;
	//for (auto obec = obce_->begin(); obec != obce_->end(); obec++)
	//{


	//	if (obce_->at(obecV)->getCode() != "" && okresy_->at(okresV)->getCode().substr(5, 1) == obce_->at(obecV)->getCode().substr(5, 1))
	//	{
	//		hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), krajIndex), okresIndex), obecIndex).data_ = std::move(obce_->at(obecV));
	//		std::cout << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), krajIndex), okresIndex), obecIndex)->data_->getOfficialTitle() << std::endl;

	//		obecIndex++;
	//		obecV++;
	//	}
	//	else
	//	{
	//		okresIndex++;
	//		okresV++;
	//		obecIndex = 0;

	//		if (jednotky_->at(krajIndex)->getNote().substr(8, 2) != okresy_->at(okresV)->getCode().substr(3, 2)) //(hierarchia_->accessSon(*hierarchia_->accessRoot(), krajIndex) == nullptr)
	//		{
	//			krajIndex++;
	//			okresIndex = 0;
	//			obecIndex = 0;
	//		}
	//		/*else if (jednotky_->at(krajIndex)->getNote() == "ZZ-9-*****")
	//		{
	//			krajIndex++;
	//			okresIndex = 0;
	//			obecIndex = 0;
	//		}*/
	//	}
	//}

	auto krajTab = tabulkaKrajov_->begin();

	hierarchia_->emplaceRoot().data_ = new Slovensko();
	//std::cout << obce_->access(0)->data_->getCode();
	for (auto kraj = kraje_->begin(); kraj != kraje_->end(); kraj++) //auto kraj : *kraje_
	{
		hierarchia_->emplaceSon(*hierarchia_->accessRoot(), index).data_ = kraje_->access(index)->data_;
		
		//hierarchia_->emplaceSon(*hierarchia_->accessRoot(), index).data_ = kraj;
		//std::cout << hierarchia_->accessSon(*hierarchia_->accessRoot(), index)->data_->getOfficialTitle() << std::endl;

		for (auto okres = curPos; okres != okresy_->end(); okres++)
		{
			if (okresy_->access(index2)->data_->getNote() != "" && kraje_->access(index)->data_->getNote().substr(8, 2) /*kraj->getNote().substr(8, 2)*/ == okresy_->access(index2)->data_->getCode().substr(3, 2))
			{
				hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3).data_ = okresy_->access(index2)->data_;
				//std::cout << "\t" << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3)->data_->getOfficialTitle() << std::endl;

				for (auto obec = curObec; obec != obce_->end(); obec++)
				{
					if (obce_->access(indexObce1)->data_->getCode() != "" && okresy_->access(index2)->data_->getCode().substr(5, 1) == obce_->access(indexObce1)->data_->getCode().substr(5, 1))
					{
						hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3), indexObce2).data_ = std::move(obce_->access(indexObce1)->data_); //obce_->at(indexObce1);
						//std::cout << "\t\t" << obce_->at(indexObce1)->getOfficialTitle() << std::endl;
						//hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3), indexObce2).data_ = obce_->at(indexObce1);

						indexObce1++;
						indexObce2++;
						curObec++;
					}
					//else if (obce_->at(indexObce1)->getCode().length() == 6)
					//{
					//	hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3), indexObce2).data_ = std::move(obce_->at(indexObce1)); //obce_->at(indexObce1);

					//	indexObce1++;
					//	indexObce2++;
					//	curObec++;
					//}
					//else if (obce_->at(indexObce1)->getCode() == "SKZZZZZZZZZZ")
					//{
					//	hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3), indexObce2).data_ = std::move(obce_->at(indexObce1)); //obce_->at(indexObce1);

					//	indexObce1++;
					//	indexObce2++;
					//	curObec++;
					//}
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
				//std::cout << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3)->data_->getCode() << std::endl;

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

	//for (auto kraj : *jednotky_)
	//{
	//	hierarchia_->emplaceSon(*hierarchia_->accessRoot(), index).data_ = jednotky_->at(index);
	//	//std::cout << hierarchia_->accessSon(*hierarchia_->accessRoot(), index)->data_->getOfficialTitle() << std::endl;

	//	for (auto okres = curPos; okres != okresy_->end(); okres++)
	//	{
	//		if (okresy_->at(index2)->getNote() != "" && kraj->getNote().substr(8, 2) == okresy_->at(index2)->getCode().substr(3, 2))
	//		{
	//			hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3).data_ = okresy_->at(index2);
	//			//std::cout << "\t" << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3)->data_->getOfficialTitle() << std::endl;
	//			
	//			for (auto obec = curObec; obec != obce_->end(); obec++)
	//			{
	//				if (obce_->at(indexObce1)->getCode() != "" && okresy_->at(index2)->getCode().substr(5, 1) == obce_->at(indexObce1)->getCode().substr(5 ,1))
	//				{
	//					hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3), indexObce2).data_ = std::move(obce_->at(indexObce1)); //obce_->at(indexObce1);
	//					//std::cout << "\t\t" << obce_->at(indexObce1)->getOfficialTitle() << std::endl;
	//					//hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3), indexObce2).data_ = obce_->at(indexObce1);

	//					indexObce1++;
	//					indexObce2++;
	//					curObec++;
	//				}
	//				//else if (obce_->at(indexObce1)->getCode().length() == 6)
	//				//{
	//				//	hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3), indexObce2).data_ = std::move(obce_->at(indexObce1)); //obce_->at(indexObce1);

	//				//	indexObce1++;
	//				//	indexObce2++;
	//				//	curObec++;
	//				//}
	//				//else if (obce_->at(indexObce1)->getCode() == "SKZZZZZZZZZZ")
	//				//{
	//				//	hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3), indexObce2).data_ = std::move(obce_->at(indexObce1)); //obce_->at(indexObce1);

	//				//	indexObce1++;
	//				//	indexObce2++;
	//				//	curObec++;
	//				//}
	//				else
	//					break;
	//			}
	//			//indexObce1 = 0;
	//			indexObce2 = 0;

	//			curPos++;
	//			index2++;
	//			index3++;
	//		}
	//		else if (okresy_->at(index2)->getNote() == "" && kraj->getNote() == "ZZ-9-*****")
	//		{
	//			hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3).data_ = okresy_->at(index2);
	//			std::cout << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3)->data_->getCode() << std::endl;

	//			indexObce2 = 0;

	//			curPos++;
	//			index2++;
	//			index3++;
	//		}
	//		else
	//			break;
	//	}
	//	index3 = 0;
	//	index++;
	//}
	//hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 8), 0), 0).data_ = obce_->at(2928);
	//hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 8), 1), 0).data_ = obce_->at(2929);
}

void IS::startWith(int level, std::string& start)
{
	hierarchia_->processPreOrder(hierarchia_->accessRoot(), [&](const ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* uj) {
		if (uj->data_->getOfficialTitle().compare(0, start.length(), start) == 0)
			std::cout << uj->data_->getOfficialTitle() << std::endl;
	});
}

void IS::contains(int level, std::string& contains)
{
	hierarchia_->processPreOrder(hierarchia_->accessRoot(), [&](const ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* uj) {
		if (uj->data_->getOfficialTitle().find(contains) != std::string::npos)
			std::cout << uj->data_->getOfficialTitle() << std::endl;
	});
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
		else if (in == "tabContains")
			tabContains(curNode);
		else if (in == "start")
			startWith(curNode);
		else if (in == "tabStart")
			tabStart(curNode);
		else if (in == "tab")
			tab();
		else if (in == "info")
			info(curNode);
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
		std::cout << "\t1. prvá úroveò\n\t2. druhá úroveò\n\t3. tretia úroveò\n\t4. štvrtá úroveò\n\t5. koniec" << std::endl;
		int uroven;
		std::cin >> uroven;
		switch (uroven)
		{
		case 1:
			proc();
			break;
		case 2:
			iter();
			break;
		case 3:
			tab();
			break;
		case 4:
			break;
		case 5:
			running = false;
			break;
		default:
			break;
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
	/*int i = 0;
	for (auto start = uj->begin(); start != uj->end(); start++)
	{
		if (uj->access(i)->data_->getOfficialTitle().find(vstup) != std::string::npos)
			std::cout << uj->access(i)->data_->getOfficialTitle() << std::endl;
		i++;
	}*/

	Alg spracovac;
	spracovac.processData<ds::amt::ImplicitSequence<UzemnaJednotka*>*, ds::amt::MemoryBlock<UzemnaJednotka*>>(uj, [&](ds::amt::MemoryBlock<UzemnaJednotka*>* uj) {
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
	/*int i = 0;
	for (auto start = uj->begin(); start != uj->end(); start++)
	{
		if (uj->access(i)->data_->getOfficialTitle().compare(0, vstup.length(), vstup) == 0)
			std::cout << uj->access(i)->data_->getOfficialTitle() << std::endl;
		i++;
	}*/

	Alg spracovac;
	spracovac.processData<ds::amt::ImplicitSequence<UzemnaJednotka*>*, ds::amt::MemoryBlock<UzemnaJednotka*>>(uj, [&](ds::amt::MemoryBlock<UzemnaJednotka*>* uj) {
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

void IS::tabStart(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode)
{
	system("cls");
	std::cout << "\t\tPREH¼ADÁVANIE V TABU¼KÁCH" << std::endl;
	std::cout << "\nContains: ";
	std::string vstup;
	std::cin >> vstup;

	if (tabulkaObci_->contains(vstup))
	{
		
	}
	
}

void IS::tabContains(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode)
{

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
		std::string in;
		std::cout << "> ";
		std::cin.ignore();
		std::getline(std::cin, in);
		switch (stoi(vyber))
		{
		case 1:
		{
			if (in == "contains")
				contains(kraje_);
			else if (in == "start")
				startWith(kraje_);
			else if (in == "exit")
				running = false;
			else
				std::cout << "Nesprávny vstup" << std::endl;
			break;
		}
		case 2:
		{
			if (in == "contains")
				contains(okresy_);
			else if (in == "start")
				startWith(okresy_);
			else if (in == "exit")
				running = false;
			else
				std::cout << "Nesprávny vstup" << std::endl;
			break;
		}
		case 3:
		{
			if (in == "contains")
				contains(obce_);
			else if (in == "start")
				startWith(obce_);
			else if (in == "exit")
				running = false;
			else
				std::cout << "Nesprávny vstup" << std::endl;
			break;
		}
		default:
			std::cout << "Nespravny vyber." << std::endl;
			break;
		}
	}
}

void IS::info(ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* curNode)
{
	if (tabulkaNarodnosti_->contains(curNode->data_->getCode()))
	{

		tabulkaNarodnosti_->find(curNode->data_->getCode())->vypis();

	}
	if (curNode->data_->getCode().length() == 1)
	{
		std::string cod = curNode->data_->getNote().substr(5, 10);
		tabulkaNarodnosti_->find(curNode->data_->getNote().substr(5, 10))->vypis();
	}
}

void IS::tab()
{
	system("cls");
	std::cout << "\t\tPREH¼ADÁVANIE V TABU¼KÁCH" << std::endl;
	std::cout << "\n\t1. Kraj\n\t2. Okres\n\t3. Obec" << std::endl;
	std::string vyber;
	std::cout << "\nUzemna jednotka: ";
	std::cin >> vyber;
	std::string nazov;
	std::cout << "Názov: ";
	std::cin.ignore();
	std::getline(std::cin, nazov);
	switch (stoi(vyber))
	{
	case 1:
	{
		if (tabulkaKrajov_->contains(nazov))
		{
			UzemnaJednotka* kraj = tabulkaKrajov_->find(nazov);
			std::cout << kraj->getShortTitle() << " - " << kraj->getNote() << std::endl;
		}
		else
			std::cout << "taky kraj neexistuje" << std::endl;
		break;
	}
	case 2:
	{
		if (tabulkaOkresov_->contains(nazov))
		{
			UzemnaJednotka* okres = tabulkaOkresov_->find(nazov);
			std::cout << okres->getShortTitle() << " - " << okres->getCode() << std::endl;
		}
		else
			std::cout << "taky okres neexistuje" << std::endl;
		break;
	}
	case 3:
	{
		if (tabulkaObci_->contains(nazov))
		{
			UzemnaJednotka* obec = tabulkaObci_->find(nazov);
			std::cout << obec->getShortTitle() << " - " << obec->getCode() << std::endl;
		}
		else
			std::cout << "taka obec neexistuje" << std::endl;
		break;
	}
	default:
		std::cout << "Nespravny vyber." << std::endl;
		break;
	}
	
}
