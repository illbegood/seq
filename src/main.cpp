#include <iostream>

#include "parser.hpp"
#include "inputdata.hpp"
#include "solver.hpp"
#include "fact.hpp"
#include "parserexception.hpp"

int main(int argc, char **argv){
    if (argc < 2){
        std::cerr << "Error: not enough arguments" << std::endl;
        return 1;
    }
    try{
        Parser parser;
        auto data = parser.parse(argv[1]);
        auto new_facts = Solver(data).calc();
        for (auto i = new_facts.begin(); i != new_facts.end(); ++i)
            std::cout << i->getValue() << ' ';
        std::cout << std::endl;
        return 0;
    }
    catch (const ParserException& e) {
        std::cerr << e.what() << std::endl;
        return 2;
    }
}
