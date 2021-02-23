#include "node/ornode.hpp"

bool OrNode:: _solve(Solver& s){
    if (!failTrace.empty()){
        auto node = failTrace.front();
        auto i = children.find(node);
        return (*i)->solve(s);
    }
    for (auto i = children.begin(); i != children.end(); ++i)
        if ((*i)->solve(s)) return true;
    return false;
}