#include "ExactMatcher.h"

void ExactMatcher::S0(const std::string& input) {
    if (input[index] == '*') { //MULTIPLY
        inputRead = 1;
    }
    else if (input[index] == '+') { //ADD
        inputRead = 1;
    }
    else if (input[index] == 'S') { //SCHEMES
        std::string schemes = "Schemes";
        std::string toCheck;
        for (unsigned int i = 0; i < 7; i++) {
            toCheck += input[i];
        }
        if (schemes == toCheck) {
            inputRead = 7;
        }
    }
    else if (input[index] == 'F') { //FACTS
        std::string facts = "Facts";
        std::string toCheck;
        for (unsigned int i = 0; i < 5; i++) {
            toCheck += input[i];
        }
        if (facts == toCheck) {
            inputRead = 5;
        }
    }
    else if (input[index] == 'R') { //RULES
        std::string rules = "Rules";
        std::string toCheck;
        for (unsigned int i = 0; i < 5; i++) {
            toCheck += input[i];
        }
        if (rules == toCheck) {
            inputRead = 5;
        }
    }
    else if (input[index] == 'Q') { //QUERIES
        std::string queries = "Queries";
        std::string toCheck;
        for (unsigned int i = 0; i < 7; i++) {
            toCheck += input[i];
        }
        if (queries == toCheck) {
            inputRead = 7;
        }
    }
    else {
        Serr();
    }
}

