#ifndef AACE8672_1B83_4678_BBC4_B46E485CFF22
#define AACE8672_1B83_4678_BBC4_B46E485CFF22

#include <unordered_map>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_set>
#include <iterator>

#include "inputdata.hpp"
#include "fact.hpp"

struct Rule;
struct Node;

class Solver{
    friend struct FactNode;
private:
    std::unordered_map<Fact, std::vector<std::pair<Rule*, std::deque<Node *>>>, Fact::hash> unknown;
    const std::unordered_set<Fact, Fact::hash>& known;
    std::unordered_set<Fact, Fact::hash> new_known;
    std::queue<Rule*>& rules;
    Rule* rule;

public:
    Solver(InputData& data) : known(data.facts), rules(data.rules) {}

    std::unordered_set<Fact, Fact::hash>& calc();
private:
    void solve();

    void addKnown(const Fact& fact);

    bool isKnown(const Fact& fact) const;

    void addUnknown(const Fact& fact);

};

#endif /* AACE8672_1B83_4678_BBC4_B46E485CFF22 */
