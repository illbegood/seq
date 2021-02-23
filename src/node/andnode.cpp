#include "node/andnode.hpp"

bool AndNode::_solve(Solver& s){
    if (failTrace.empty()) i = children.begin();
    for (; i != children.end(); ++i)
        if (!(*i)->solve(s)) return false;
    return true;
}