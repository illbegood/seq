#include "node/factnode.hpp"
#include "solver.hpp"

FactNode::FactNode(const Fact& f) : fact(f){}

bool FactNode::_solve(Solver& s) 
{
    if (s.isKnown(fact)) return true;
    s.addUnknown(fact);
    return false;
}
