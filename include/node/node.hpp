#ifndef B023A76E_0644_472F_A7A7_D7516CEC2CF6
#define B023A76E_0644_472F_A7A7_D7516CEC2CF6

#include <deque>

class Solver;

struct Node{
    std::deque<Node *> trace;
    std::deque<Node *> failTrace;
    bool solve(Solver& s);
    virtual bool _solve(Solver& s) = 0;
    virtual ~Node() {}
};


#endif /* B023A76E_0644_472F_A7A7_D7516CEC2CF6 */
