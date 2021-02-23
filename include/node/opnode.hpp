#ifndef A1BDC406_E450_4F1B_9C19_00C292FEB10E
#define A1BDC406_E450_4F1B_9C19_00C292FEB10E

#include <set>

#include "node.hpp"

struct OpNode : public Node {

    OpNode() {}
    virtual ~OpNode();
    void add(Node* node);
protected:
    std::set<Node*> children;
};



#endif /* A1BDC406_E450_4F1B_9C19_00C292FEB10E */
