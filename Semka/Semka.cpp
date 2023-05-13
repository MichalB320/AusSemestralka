#include <iostream>
#include "IS.h"
#include "libds/heap_monitor.h"
#include <Windows.h>
#include "Citac.h"

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
    is->run();
    //is->iter();
    delete is;
   
    return 0;
}
