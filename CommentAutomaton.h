#ifndef CS236_COMMENTAUTOMATON_H
#define CS236_COMMENTAUTOMATON_H

#include "Automaton.h"

class CommentAutomaton : public Automaton {
private:
    void S1(const std::string& input);
    void S2(const std::string& input);
    void S3(const std::string& input);
    void S4(const std::string& input);

public:
    CommentAutomaton() : Automaton(TokenType::COMMENT) {}  // Call the base constructor

    void S0(const std::string& input);

};


#endif //CS236_COMMENTAUTOMATON_H
