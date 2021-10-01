#ifndef CS236_EXACTMATCHER_H
#define CS236_EXACTMATCHER_H

#include "Automaton.h"

class ExactMatcher : public Automaton {
public:
    //this is for COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, MULTIPLY, ADD,
    // SCHEMES, FACTS, RULES, QUERIES, maybe: COLON, COLON_DASH
    ExactMatcher() : Automaton() {} //call base constructor -- don't want the one w/ TokenType because not always same

    void S0(const std::string& input);

};


#endif //CS236_EXACTMATCHER_H
