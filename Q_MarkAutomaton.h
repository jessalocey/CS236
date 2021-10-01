#ifndef CS236_Q_MARKAUTOMATON_H
#define CS236_Q_MARKAUTOMATON_H

#include "Automaton.h"

class Q_MarkAutomaton : public Automaton {
public:
    Q_MarkAutomaton() : Automaton(TokenType::Q_MARK) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //CS236_Q_MARKAUTOMATON_H
