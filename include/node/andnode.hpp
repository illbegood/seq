#ifndef C134091E_4350_446B_94F2_AC49A5843E7C
#define C134091E_4350_446B_94F2_AC49A5843E7C

#include "opnode.hpp"

struct AndNode : public OpNode{

    bool _solve(Solver& s);
    std::set<Node *>::const_iterator i;
};

#endif /* C134091E_4350_446B_94F2_AC49A5843E7C */
