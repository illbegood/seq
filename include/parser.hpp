#ifndef CD58A358_7B57_44AC_92C9_B48E784CD0B9
#define CD58A358_7B57_44AC_92C9_B48E784CD0B9

#include <string>

#include "inputdata.hpp"

struct OrNode;
struct AndNode;
struct FactNode;
struct ParserException;

class Parser{
public:
    Parser(){}
    InputData& parse(char *fname);
private:
    enum Mode{FACT, RULE};
    Mode mode;
    InputData data;

    bool insideQuot;
    bool comma;

    std::string line;
    unsigned line_i;
    std::string::size_type i;
    std::string::size_type len;
    std::string charError = "`c` expected";
    const char* fname;

    void parseQuot();

    void parseLine(Mode mode);

    void modeSwitch(Mode mode);

    const Fact parseFact();

    void parseSpace();

    Rule* parseRule();

    OrNode* parseOrNode();

    AndNode* parseAndNode();

    FactNode* parseFactNode();

    void parseChar(char c);

    bool isIdChar(char c) const;

    ParserException exception(const char* msg);
};

#endif /* CD58A358_7B57_44AC_92C9_B48E784CD0B9 */
