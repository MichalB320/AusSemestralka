#include <iostream>
#include "Hierar.h"
#include "Slovensko.h"
#include <vector>
#include "Kraj.h"
#include "libds/adt/tree.h"
#include "Okres.h"
#include "IS.h"
#include "libds/heap_monitor.h"
#include <Windows.h>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
    SetConsoleOutputCP(1250);
    SetConsoleCP(1250);

    std::cout << "Hello World!\n";

    initHeapMonitor();

    IS* is = new IS();
    is->nacitajJednotky();
    //is->nacitajUzly();
    
    int vyber;
    std::cout << "kraje = 0" << std::endl;
    std::cout << "okresy = 1" << std::endl;
    std::cout << "obce = 2" << std::endl;
    std::cout << "uzemna jednota: ";
    std::cin >> vyber;
    
    std::string vstup;
    std::cout << "startStrWith: ";
    std::cin >> vstup;
    is->startWith(vyber, vstup);
    std::cout << "" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "contains: " << std::endl;
    is->contains(vyber, vstup);
    

    /*
    std::cout << "" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "" << std::endl;
    is->hasType();
    */

    is->iterator();

    delete is;
   
    //ds::adt::MultiwayTree strom = ds::adt::MultiwayTree<std::string>();
    
    //Slovensko svk;
    //strom.insertRoot().data_ = svk;

    //std::cout << strom.accessRoot()->data_.getOfficialTitle() << std::endl;


    
    //std::vector<std::string> vector_;

/*
    ds::amt::MultiWayExplicitHierarchy hierarchia_ = ds::amt::MultiWayExplicitHierarchy<UzemnaJednotka*>();
    
    Slovensko* svk = new Slovensko();
    //svk = new Slovensko();
    hierarchia_.emplaceRoot().data_ = svk;

    std::cout << "koren: " << hierarchia_.accessRoot()->data_->getOfficial() << std::endl;

    Kraj* krajTN = new Kraj("krajTN");
    Kraj* KrajZA = new Kraj("krajZA");
    hierarchia_.emplaceSon(*hierarchia_.accessRoot(), 0).data_ = krajTN;
    hierarchia_.emplaceSon(*hierarchia_.accessRoot(), 1).data_ = KrajZA;

    std::cout << "syn: " << hierarchia_.accessSon(*hierarchia_.accessRoot(), 0)->data_->getOfficial() << std::endl;
    std::cout << "syn: " << hierarchia_.accessSon(*hierarchia_.accessRoot(), 1)->data_->getOfficial() << std::endl;

    Okres* okresBN = new Okres("okresBN");
    Okres* okresMT = new Okres("okresMT");
    //Kraj krajTren = hierarchia_.accessSon(*hierarchia_.accessRoot(), 0)->data_;
    hierarchia_.emplaceSon(*hierarchia_.accessSon(*hierarchia_.accessRoot(), 0), 0).data_ = okresBN;
    hierarchia_.emplaceSon(*hierarchia_.accessSon(*hierarchia_.accessRoot(), 1), 0).data_ = okresMT;

    std::cout << "okres: " << hierarchia_.accessSon(*hierarchia_.accessSon(*hierarchia_.accessRoot(), 0), 0)->data_->getOfficial() << std::endl;
    std::cout << "okres: " << hierarchia_.accessSon(*hierarchia_.accessSon(*hierarchia_.accessRoot(), 1), 0)->data_->getOfficial();
    //Kraj* kraj
    //kraj = new Kraj("TN");

    //hierarchia_.emplaceSon(*hierarchia_.accessRoot(), 0).data_ = kraj;

    //std::cout << " " << hierarchia_.accessRoot()->data_->getOfficialTitle();
    //hierarchia_.emplaceRoot().data_ = &svk;
    //for (int i = 0; i < 8; i++) //kraje
    //{
    //    std::stringstream ss;
    //    ss << "kraj " << i << " ";
    //    Kraj kraj(ss.str());

        //hierarchia_.emplaceSon(*hierarchia_.accessRoot(), i).data_ = kraj; //ss.str();
    //}

    //hierarchia_.emplaceSon(*hierarchia_.accessSon(*hierarchia_.accessRoot(), 0), 0).data_ = "okres 00";
    //hierarchia_.emplaceSon(*hierarchia_.accessSon(*hierarchia_.accessRoot(), 3), 0).data_ = "okres 30";

    //std::cout << hierarchia_.accessRoot()->data_ << std::endl;
    //std::cout << hierarchia_.accessSon(*hierarchia_.accessRoot(), 3)->data_ << std::endl;
    //std::cout << hierarchia_.accessSon(*hierarchia_.accessSon(*hierarchia_.accessRoot(), 3), 0)->data_;

   
*/
    return 0;
}

