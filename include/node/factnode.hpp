#ifndef A0C20838_72BB_4B9D_9BFA_C2E9538AA478
#define A0C20838_72BB_4B9D_9BFA_C2E9538AA478

#include "node.hpp"
#include "fact.hpp"

struct Fact;

struct FactNode : public Node {
    const Fact fact;
public:
    FactNode(const Fact& f);

    bool _solve(Solver& s);
};

#endif /* A0C20838_72BB_4B9D_9BFA_C2E9538AA478 */