#ifndef CS236_UNDEFINEDAUTOMATON_H
#define CS236_UNDEFINEDAUTOMATON_H

#include "Automaton.h"

class UndefinedAutomaton : public Automaton { //for comments and strings -- single char will get caught elsewhere
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);

public:
    UndefinedAutomaton() : Automaton(TokenType::UNDEFINED) {}  // Call the base constructor

    void S0(const std::string& input);
};


#endif //CS236_UNDEFINEDAUTOMATON_H
