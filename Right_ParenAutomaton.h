#ifndef CS236_RIGHT_PARENAUTOMATON_H
#define CS236_RIGHT_PARENAUTOMATON_H

#include "Automaton.h"

class Right_ParenAutomaton : public Automaton {
public:
    Right_ParenAutomaton() : Automaton(TokenType::RIGHT_PAREN) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //CS236_RIGHT_PARENAUTOMATON_H
