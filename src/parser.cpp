#include <fstream>
#include <cctype>

#include "parser.hpp"
#include "fact.hpp"
#include "rule.hpp"
#include "node/ornode.hpp"
#include "node/andnode.hpp"
#include "node/factnode.hpp"
#include "parserexception.hpp"

InputData& Parser::parse(char *fname) 
{
    this->fname = fname;
    line_i = 0;
    i = 0;
    std::ifstream file(fname);
    if (!file) throw exception("Cannot open file");
    if (std::getline(file, line).fail()) throw exception("Fact sequence expected");
    parseLine(FACT);
    if (std::getline(file, line).fail()) throw exception("Rule sequence expected");
    parseLine(RULE);
    return data;
}

void Parser::parseLine(Mode mode) 
{
    insideQuot = false;
    comma = false;
    i = 0;
    len = line.length();
    while (i < len){
        parseQuot();
        if (i >= len) break;
        if (insideQuot) modeSwitch(mode);
        else { 
            parseChar(',');
            comma = true;
            parseSpace(); 
        }
    }
    if (insideQuot) throw exception("Closing `\"` expected");
    if (comma) throw exception("Unnecessary comma(`,`)");
    line_i++;
}

void Parser::modeSwitch(Mode mode) 
{
    switch (mode){
        case FACT:
            data.addFact(parseFact());
            break;
        case RULE:
            data.addRule(parseRule());
            break;
    }
}

void Parser::parseQuot(){
    parseChar('"');
    insideQuot = !insideQuot;
    comma = false;
}

const Fact Parser::parseFact()
{
    std::string::size_type begin = i;
    for ( ;i < len && isIdChar(line[i]); i++);
    if (i == begin) throw exception("Fact identifier expected");
    return Fact(line.substr(begin, i - begin));
}

void Parser::parseSpace() 
{
    for ( ;i < len && std::isspace(line[i]); i++);
}


Rule* Parser::parseRule() 
{
    auto ant = parseOrNode();
    parseSpace();
    parseChar('-');
    parseChar('>');
    parseSpace();
    return new Rule(ant, parseFact());
}

OrNode* Parser::parseOrNode() 
{
    auto node = new OrNode;
    node->add(parseAndNode());
    while (i < len && line[i] == '|'){
        parseChar('|');
        node->add(parseAndNode());
    }
    return node;
}

AndNode* Parser::parseAndNode() 
{
    auto node = new AndNode;
    auto factnode = parseFactNode();
    node->add(factnode);
    while (i < len && line[i] == ','){
        parseChar(',');
        factnode = parseFactNode();
        node->add(factnode);
    }
    return node;
}

FactNode* Parser::parseFactNode() 
{
    return new FactNode(parseFact());
}

void Parser::parseChar(char c) 
{
    if (line[i] != c){
        charError[1] = c;
        throw exception(charError.c_str());
    }
    i++;
}

bool Parser::isIdChar(char c) const
{
    return isupper(c) || c == '_';
}

ParserException Parser::exception(const char* msg) 
{
    return ParserException(fname, line_i + 1, i + 1, msg);
}
