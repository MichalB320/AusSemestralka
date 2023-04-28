#include "IS.h"
#include <fstream>
#include "Kraj.h"
#include "Slovensko.h"
#include "Obec.h"

void IS::nacitajJednotky()
{
	//hierarchia_->emplaceRoot().data_ = new Slovensko();
	//int jednotka = 0;

	//std::ifstream citac;

	//citac.open("C:\\Users\\micha\\Downloads\\kraje_test.csv");

	//if (citac.is_open())
	//{
	//	//sortNumber;code;officialTitle;mediumTitle;shortTitle;note
	//	std::string sortNumber = " ";
	//	std::string code = u8" ";
	//	std::string officialTitle = u8" ";
	//	std::string mediumTitle = u8" ";
	//	std::string shortTitle = u8" ";
	//	std::string note = u8" ";

	//	std::string riadok;

	//	getline(citac, riadok);

	//	while (!citac.eof())
	//	{
	//		getline(citac, sortNumber, ';');
	//		getline(citac, code, ';');
	//		getline(citac, officialTitle, ';');
	//		getline(citac, mediumTitle, ';');
	//		getline(citac, shortTitle, ';');
	//		getline(citac, note);

	//		//Kraj *kraj = new Kraj(sortNumber, code, officialTitle, mediumTitle, shortTitle, note);
	//		jednotky_->push_back(new Kraj(sortNumber, code, officialTitle, mediumTitle, shortTitle, note));
	//		//jednotky_->push_back(kraj);
	//	}
	//}
	//citac.close();
	//delete jednotky_->back();
	//jednotky_->pop_back();


	//citac.open("C:\\Users\\micha\\Downloads\\okresy_test.csv");

	//if (citac.is_open())
	//{
	//	//sortNumber;code;officialTitle;mediumTitle;shortTitle;note
	//	std::string sortNumber = u8" ";
	//	std::string code = u8" ";
	//	std::string officialTitle = u8" ";
	//	std::string mediumTitle = u8" ";
	//	std::string shortTitle = u8" ";
	//	std::string note = u8" ";

	//	std::string riadok;

	//	getline(citac, riadok);

	//	while (!citac.eof())
	//	{
	//		getline(citac, sortNumber, ';');
	//		getline(citac, code, ';');
	//		getline(citac, officialTitle, ';');
	//		getline(citac, mediumTitle, ';');
	//		getline(citac, shortTitle, ';');
	//		getline(citac, note);

	//		//Okres *okres = new Okres(sortNumber, code, officialTitle, mediumTitle, shortTitle, note);
	//		okresy_->push_back(new Okres(sortNumber, code, officialTitle, mediumTitle, shortTitle, note));
	//		//okresy_->push_back(okres);
	//		//jednotky_->push_back(okres);
	//	}
	//}
	//citac.close();
	//delete okresy_->back();
	//okresy_->pop_back();

	//citac.open("C:\\Users\\micha\\Downloads\\obce_test.csv");

	//if (citac.is_open())
	//{
	//	//sortNumber;code;officialTitle;mediumTitle;shortTitle;note
	//	std::string sortNumber = u8" ";
	//	std::string code = u8" ";
	//	std::string officialTitle = u8" ";
	//	std::string mediumTitle = u8" ";
	//	std::string shortTitle = u8" ";
	//	std::string note = u8" ";

	//	std::string riadok;

	//	getline(citac, riadok);

	//	while (!citac.eof())
	//	{
	//		getline(citac, sortNumber, ';');
	//		getline(citac, code, ';');
	//		getline(citac, officialTitle, ';');
	//		getline(citac, mediumTitle, ';');
	//		getline(citac, shortTitle, ';');
	//		getline(citac, note);

	//		//Obec* obec = new Obec(sortNumber, code, officialTitle, mediumTitle, shortTitle, note);
	//		obce_->push_back(new Obec(&sortNumber, &code, &officialTitle, &mediumTitle, &shortTitle, &note));
	//		//obce_->push_back(obec);
	//	}
	//}
	//citac.close();
	//delete obce_->back();
	//obce_->pop_back();

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

	hierarchia_->emplaceRoot().data_ = new Slovensko();
	std::cout << obce_->access(0)->data_->getCode();
	for (auto kraj : *kraje_)
	{
		hierarchia_->emplaceSon(*hierarchia_->accessRoot(), index).data_ = kraje_->access(index)->data_;
		//std::cout << hierarchia_->accessSon(*hierarchia_->accessRoot(), index)->data_->getOfficialTitle() << std::endl;

		for (auto okres = curPos; okres != okresy_->end(); okres++)
		{
			if (okresy_->access(index2)->data_->getNote() != "" && kraj->getNote().substr(8, 2) == okresy_->access(index2)->data_->getCode().substr(3, 2))
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
			else if (okresy_->access(index2)->data_->getNote() == "" && kraj->getNote() == "ZZ-9-*****")
			{
				hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3).data_ = okresy_->access(index2)->data_;
				std::cout << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), index), index3)->data_->getCode() << std::endl;

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

void IS::nacitajUzly()
{
	/*Slovensko* slovensko = new Slovensko();
	hierarchia_->emplaceRoot().data_ = slovensko;
	UzemnaJednotka* root = hierarchia_->accessRoot()->data_;

	for (int i = 0; i < jednotky_->size(); i++)
	{
		if (jednotky_->at(i)->codeLen() == 1)
			vlozKraj(i);

		if (jednotky_->at(i)->codeLen() == 6)
			vlozOkres(i);

		if (jednotky_->at(i)->codeLen() > 7)
			vlozObec(i);
	}*/
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

void IS::hasType()
{
	hierarchia_->processPreOrder(hierarchia_->accessRoot(), [&](const ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* jednotka){
		
	});
	
}

void IS::iterator()
{
	int vyber;
	std::string sp;
	auto currentNode = hierarchia_->accessRoot();;
	while (true)
	{
		std::cout << "current node: " << currentNode->data_->getOfficialTitle() <<  " \tHasType: ";
		if (currentNode->data_->getLevel() == -1)
		{
			std::cout << "štát" << std::endl;
		}
		else if (currentNode->data_->getLevel() == 0)
		{
			std::cout << "kraj" << std::endl;
		}
		else if (currentNode->data_->getLevel() == 1)
		{
			std::cout << "okres" << std::endl;
		}
		else if (currentNode->data_->getLevel() == 2)
		{
			std::cout << "obec" << std::endl;
		}

		std::cout << "S/P ";
		std::cin >> sp;
		

		if (sp == "S")
		{
			for (int i = 0; i < hierarchia_->degree(*currentNode); i++)
			{
				std::cout << "syn " << i << ": " << hierarchia_->accessSon(*currentNode, i)->data_->getOfficialTitle() << "\t\t\tHasType: ";
				if (hierarchia_->accessSon(*currentNode, 0)->data_->getLevel() == -1)
				{
					std::cout << "štát" << std::endl;
				}
				else if (hierarchia_->accessSon(*currentNode, 0)->data_->getLevel() == 0)
				{
					std::cout << "kraj" << std::endl;
				}
				else if (hierarchia_->accessSon(*currentNode, 0)->data_->getLevel() == 1)
				{
					std::cout << "okres" << std::endl;
				}
				else if (hierarchia_->accessSon(*currentNode, 0)->data_->getLevel() == 2)
				{
					std::cout << "obec" << std::endl;
				}
			}
			if (hierarchia_->level(*currentNode) < 3)
			{
				if (hierarchia_->level(*currentNode) == 2)
				{
					std::cout << "rodic: ";
					std::cin >> vyber;
					currentNode = hierarchia_->accessParent(*currentNode);
				}
				else
				{
					std::cout << "vyber syna: ";
					std::cin >> vyber;
					currentNode = hierarchia_->accessSon(*currentNode, vyber);
				}
			}
			else
			{
				break;
			}
		}
		else if (sp == "P")
		{
			std::cout << "rodic " << "0" << ": " << hierarchia_->accessParent(*currentNode)->data_->getOfficialTitle() << std::endl;
			if (hierarchia_->level(*currentNode) < 3)
			{
				currentNode = hierarchia_->accessParent(*currentNode);
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
}

void IS::iter()
{
	/*auto curNode = hierarchia_->begin();

	while (true)
	{
		std::cout << "Aktuálny uzol: " << curNode->data_->getOfficialTitle() << std::endl;
		hierarchia_->processLevelOrder(curNode, [&](ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* uj) {
			if (hierarchia_->level(*uj) == hierarchia_->level(*hierarchia_->accessSon(*curNode, 0)))
			{
				std::cout << "\t" << uj->data_->getOfficialTitle() << std::endl;
			}
			else
				curNode->data_ = uj->data_;
		});

		
		
	}*/
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
			{
				std::cout << curNode->data_->getOfficialTitle() << " = " << hierarchia_->isLeaf(*curNode) << "(is leaf)" << std::endl;
			}
		}
		else if (in == "..")
		{
			curNode = hierarchia_->accessParent(*curNode);
		}
		else if (in == "type")
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
			default:
				break;
			}
		}
		else if (in == "exit")
			break;
		else if (in == "cd")
		{
			std::string vstup;
			std::cin >> vstup;
			curNode = hierarchia_->accessSon(*curNode, stoi(vstup));
		}
		else if (in == "contains")
		{

		}
		else if (in == "start")
		{
			
		}
		else
			std::cout << "Nesprávny vstup" << std::endl;
			//curNode = hierarchia_->accessSon(*curNode, stoi(in));

	}

	/*auto zaciatok = hierarchia_->beginPre();

	hierarchia_->processPreOrder(hierarchia_->accessRoot(), [&](const ds::amt::MultiWayExplicitHierarchyBlock<UzemnaJednotka*>* uj) {
		if (hierarchia_->level(*uj) == 0)
			std::cout << uj->data_->getOfficialTitle() << std::endl;
		else if (hierarchia_->level(*uj) == 1)
			std::cout << "    |---->  " << uj->data_->getOfficialTitle() << std::endl;
		else if (hierarchia_->level(*uj) == 2)
			std::cout << "    |        |---->  " << uj->data_->getOfficialTitle() << std::endl;
		else if (hierarchia_->level(*uj) == 3)
			std::cout << "    |        |        |---->  " << uj->data_->getOfficialTitle() << std::endl;
		else
			std::cout << "    |--------|--------|----" << uj->data_->getOfficialTitle() << std::endl;
	});*/
}

void IS::vlozKraj(int index)
{
	/*hierarchia_->emplaceSon(*hierarchia_->accessRoot(), index).data_ = jednotky_->at(index);*/
}

void IS::vlozOkres(int i)
{
	//if (okresy_->at(i)->getNote() != "" && stoi(okresy_->at(i)->getNote()) > 100 && stoi(okresy_->at(i)->getNote()) < 200)
	//{
	//	hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 0), ba_).data_ = okresy_->at(i);
	//	//std::cout << "BA: " << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 0), ba_)->data_->getOfficialTitle() << std::endl;
	//	ba_++;
	//}
	//else if (okresy_->at(i)->getNote() != "" && stoi(okresy_->at(i)->getNote()) > 200 && stoi(okresy_->at(i)->getNote()) < 300)
	//{
	//	hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 1), tt_).data_ = okresy_->at(i);
	//	//std::cout << "TT: " << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 1), tt_)->data_->getOfficialTitle() << std::endl;
	//	tt_++;
	//}
	//else if (okresy_->at(i)->getNote() != "" && stoi(okresy_->at(i)->getNote()) > 300 && stoi(okresy_->at(i)->getNote()) < 400)
	//{
	//	hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 2), tn_).data_ = okresy_->at(i);
	//	//std::cout << "TN: " << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 2), tn_)->data_->getOfficialTitle() << std::endl;
	//	tn_++;
	//}
	//else if (okresy_->at(i)->getNote() != "" && stoi(okresy_->at(i)->getNote()) > 400 && stoi(okresy_->at(i)->getNote()) < 500)
	//{
	//	hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 3), nr_).data_ = okresy_->at(i);
	//	//std::cout << "NR: " << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 3), nr_)->data_->getOfficialTitle() << std::endl;
	//	nr_++;
	//}
	//else if (okresy_->at(i)->getNote() != "" && stoi(okresy_->at(i)->getNote()) > 500 && stoi(okresy_->at(i)->getNote()) < 600)
	//{
	//	hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 4), za_).data_ = okresy_->at(i);
	//	//std::cout << "ZA: " << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 4), za_)->data_->getOfficialTitle() << std::endl;
	//	za_++;
	//}
	//else if (okresy_->at(i)->getNote() != "" && stoi(okresy_->at(i)->getNote()) > 600 && stoi(okresy_->at(i)->getNote()) < 700)
	//{
	//	hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 5), bb_).data_ = okresy_->at(i);
	//	//std::cout << "BB: " << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 5), bb_)->data_->getOfficialTitle() << std::endl;
	//	bb_++;
	//} 
	//else if (okresy_->at(i)->getNote() != "" && stoi(okresy_->at(i)->getNote()) > 700 && stoi(okresy_->at(i)->getNote()) < 800)
	//{
	//	hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 6), ps_).data_ = okresy_->at(i);
	//	//std::cout << "PS: " << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 6), ps_)->data_->getOfficialTitle() << std::endl;
	//	ps_++;
	//}
	//else if (okresy_->at(i)->getNote() != "" && stoi(okresy_->at(i)->getNote()) > 800 && stoi(okresy_->at(i)->getNote()) < 900)
	//{
	//	hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 7), ke_).data_ = okresy_->at(i);
	//	//std::cout << "BA: " << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 7), ke_)->data_->getOfficialTitle() << std::endl;
	//	ke_++;
	//}
	//else if (okresy_->at(i)->getNote() == "")
	//{
	//	hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 8), o_).data_ = okresy_->at(i);
	//	//std::cout << "OT: " << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), 8), o_)->data_->getOfficialTitle() << std::endl;
	//	o_++;
	//}
}

void IS::vlozObec(int i)
{
	//for (int IKraj = 0; IKraj < 9; IKraj++)
	//{
	//	for (int IOkres = 0; IOkres < 81; IOkres++)
	//	{
	//		if (IKraj < hierarchia_->degree(*hierarchia_->accessRoot()) && IOkres < hierarchia_->degree(*hierarchia_->accessSon(*hierarchia_->accessRoot(), IKraj)))
	//		{
	//			UzemnaJednotka* okres = hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), IKraj), IOkres)->data_;
	//			if (okres->getCode() == jednotky_->at(i)->getCode().substr(0, 6))
	//			{
	//				//int stupenOk = hierarchia_->degree(*hierarchia_->accessSon(*hierarchia_->accessRoot(), IKraj));
	//				hierarchia_->emplaceSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), IKraj), IOkres), obec_).data_ = jednotky_->at(i);
	//				//std::cout << hierarchia_->isLeaf(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), IKraj), IOkres), obec_)) << std::endl;
	//				//std::cout << hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessSon(*hierarchia_->accessRoot(), IKraj), IOkres), obec_)->data_->getOfficialTitle() << std::endl;
	//				//std::cout << obec_ << std::endl;
	//				obec_++;
	//				
	//			}
	//		}
	//	}
	//	obec_ = 0;
	//}
}
