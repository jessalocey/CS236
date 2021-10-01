#include "EndOFAutomaton.h"

void EndOFAutomaton::S0(const std::string &input) {
    if (input.empty()) { //string is empty == EndOF
        inputRead = 0; // this is 1 or 0?
    }
    else {
        Serr();
    }
}
