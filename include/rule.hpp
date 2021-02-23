#ifndef A847CB8E_F6AB_4923_BECA_626DDB80E61A
#define A847CB8E_F6AB_4923_BECA_626DDB80E61A

#include <deque>

#include "node/node.hpp"
#include "fact.hpp"

struct Rule{
    // antecedent
    Node* ant = nullptr;
    // succedent
    const Fact suc;
    std::deque<Node *> failTrace;
    Rule(Node* a, const Fact& s) : ant(a), suc(s) {}
    ~Rule();
};

#endif /* A847CB8E_F6AB_4923_BECA_626DDB80E61A */
