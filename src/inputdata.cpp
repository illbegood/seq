#include "inputdata.hpp"

void InputData::addFact(const Fact& fact) 
{
    facts.insert(fact);
}

void InputData::addRule(Rule* rule) 
{
    rules.push(rule);
}
