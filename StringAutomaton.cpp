#include "StringAutomaton.h"
#include <iostream>

void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') { //starts with '
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    if (index == input.size()) { //started string, didn't complete //size is unsigned
        //undefinedA will catch this
        inputRead = 0;
    }
    else if (input[index] == '\'') { //another ' move to next state
        inputRead++;
        index++;
        S2(input);
    }
    else { //anything but ' we stay here
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S1(input);
    }
}

void StringAutomaton::S2(const std::string& input) {
    if (input[index] == '\'') { //two ' in a row go back to S1
        inputRead++;
        index++;
        S1(input);
    }
    else {
        //complete string
    }
}