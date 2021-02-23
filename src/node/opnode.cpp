#include "node/opnode.hpp"

void OpNode::add(Node* node) 
{
    children.insert(node);
}

OpNode::~OpNode() 
{
    for (auto node : children) delete node;
}
