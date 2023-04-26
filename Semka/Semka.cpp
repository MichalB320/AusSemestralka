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
    
    int vyber = 0;
    
    std::string vstup;
    std::cout << "startStrWith: ";
    std::cin >> vstup;
    is->startWith(vyber, vstup);
    std::cout << "" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "contains: " << std::endl;
    is->contains(vyber, vstup);
    

    /*
    std::cout << "" << std::endl;
    std::cout << "----------------------" << std::endl;
    std::cout << "" << std::endl;
    is->hasType();
    */

    //is->iterator();
    is->iter();

    delete is;
   
    return 0;
}

