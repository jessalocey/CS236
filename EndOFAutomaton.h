#ifndef CS236_ENDOFAUTOMATON_H
#define CS236_ENDOFAUTOMATON_H

#include "Automaton.h"

class EndOFAutomaton : public Automaton {
public:
    EndOFAutomaton() : Automaton(TokenType::EndOF) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //CS236_ENDOFAUTOMATON_H
