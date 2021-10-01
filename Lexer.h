#ifndef LEXER_H
#define LEXER_H
#include <vector>
#include "Automaton.h"
#include "Token.h"

class Lexer
{
private:
    std::vector<Automaton*> automata;
    std::vector<Token*> tokens;
    Automaton* maxAutomaton = NULL;
    unsigned int inputRead;
    unsigned int maxRead;
    unsigned int lineNumber;

    void CreateAutomata();

public:
    Lexer();
    ~Lexer();

    void Run(std::string& input);
    std::string toString();
    std::vector<Token*> getTokenVector();

};

#endif // LEXER_H

