#ifndef B5834ECB_4D62_42EE_BB81_25B248E8E264
#define B5834ECB_4D62_42EE_BB81_25B248E8E264

#include "opnode.hpp"

struct OrNode : public OpNode{
    bool _solve(Solver& s);
    OrNode() {}
};

#endif /* B5834ECB_4D62_42EE_BB81_25B248E8E264 */
