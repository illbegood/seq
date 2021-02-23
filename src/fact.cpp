#include "fact.hpp"

bool Fact::operator==(const Fact & other) const
{
    return value == other.value;    
}

bool Fact::operator!=(const Fact & other) const
{
    return value != other.value; 
}

const std::string& Fact::getValue() const
{
    return value;
}