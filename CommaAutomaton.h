#ifndef CS236_COMMAAUTOMATON_H
#define CS236_COMMAAUTOMATON_H

#include "Automaton.h"

class CommaAutomaton : public Automaton {
public:
    CommaAutomaton() : Automaton(TokenType::COMMA) {}  // Call the base constructor
    void S0(const std::string& input);
};


#endif //CS236_COMMAAUTOMATON_H
