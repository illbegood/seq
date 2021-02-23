#include "rule.hpp"
#include "fact.hpp"

Rule::~Rule() 
{
    if (ant) delete ant;
}
