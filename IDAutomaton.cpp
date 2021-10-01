#include "IDAutomaton.h"

void IDAutomaton::S0(const std::string& input) {
    if (std::isalpha(input[index])) { //check to see if first char is alpha
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void IDAutomaton::S1(const std::string& input) {
    if (std::isalnum(input[index])) { //see if it's alpha/num
        inputRead++;
        index++;
        S1(input);
    } //not alpha/num, move on
}