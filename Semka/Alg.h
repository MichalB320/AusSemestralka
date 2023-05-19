#pragma once
#include <algorithm>
#include "IS.h"

template <typename Structure, typename MemoryBlock>
class Alg
{
private:

public:
    Alg() {}

    //template <typename Structure, typename MemoryBlock>
    void processData(Structure structs, std::function<void(MemoryBlock*)> operation) {
        int index = 0;
        for (auto zaciatok = structs->begin(); zaciatok != structs->end(); zaciatok.operator++())
        {
            operation(structs->access(index));
            index++;
        }
    }
};

