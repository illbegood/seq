#ifndef B2299725_738C_4090_8D68_501E644CD899
#define B2299725_738C_4090_8D68_501E644CD899

#include <queue>
#include <unordered_set>

#include "fact.hpp"

struct Rule;

class InputData{

    friend class Parser;
    friend class Solver;

public:
    InputData() {}

private:

    std::unordered_set<Fact, Fact::hash> facts;
    std::queue<Rule*> rules;

    void addFact(const Fact& fact);

    void addRule(Rule* rules);

};

#endif /* B2299725_738C_4090_8D68_501E644CD899 */
