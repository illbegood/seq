#include "node/node.hpp"

bool Node::solve(Solver& s) 
{
    trace.push_back(this);
    if (!failTrace.empty()) failTrace.pop_front();
    bool b = _solve(s);
    trace.pop_back();
    return b;
}