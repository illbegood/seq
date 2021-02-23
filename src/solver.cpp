#ifndef F8DE622A_87FF_4E20_9E1A_5FE871909FF2
#define F8DE622A_87FF_4E20_9E1A_5FE871909FF2

#include "solver.hpp"
#include "rule.hpp"

std::unordered_set<Fact, Fact::hash>& Solver::calc(){
    while(!rules.empty()){
        rule = rules.front();
        rules.pop();
        solve();
    }
    return new_known;
}

void Solver::solve(){
    if (rule->ant->solve(*this)) 
        if (!isKnown(rule->suc)) 
            addKnown(rule->suc);
}

void Solver::addKnown(const Fact& fact) 
{
    new_known.insert(fact);
    std::vector<std::pair<Rule*, std::deque<Node *>>>& pending = unknown[fact];
    for (auto i = pending.begin(); i != pending.end(); ++i){
        Rule *r = i->first;
        r->failTrace = i->second;
        rules.push(r);
    }
    pending.clear();
}

bool Solver::isKnown(const Fact& fact) const 
{
    return known.find(fact) != known.end() || 
        new_known.find(fact) != new_known.end();
}

void Solver::addUnknown(const Fact& fact) 
{
    unknown[fact].push_back(std::pair<Rule *, std::deque<Node *>>(rule, rule->ant->trace));
}

#endif /* F8DE622A_87FF_4E20_9E1A_5FE871909FF2 */


