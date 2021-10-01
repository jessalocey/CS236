#ifndef CS236_MULTIPLYAUTOMATON_H
#define CS236_MULTIPLYAUTOMATON_H

#include "Automaton.h"

class MultiplyAutomaton : public Automaton {
public:
    MultiplyAutomaton() : Automaton(TokenType::MULTIPLY) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //CS236_MULTIPLYAUTOMATON_H
