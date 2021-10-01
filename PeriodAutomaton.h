#ifndef CS236_PERIODAUTOMATON_H
#define CS236_PERIODAUTOMATON_H

#include "Automaton.h"

class PeriodAutomaton : public Automaton {
public:
    PeriodAutomaton() : Automaton(TokenType::PERIOD) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //CS236_PERIODAUTOMATON_H
