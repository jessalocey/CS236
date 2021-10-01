#include "UndefinedAutomaton.h"

void UndefinedAutomaton::S0(const std::string& input) {
    if ((input[index] == '#') && ((input[index+1]) == '|')) { //block comment
        inputRead++;
        inputRead++;
        index++;
        index++;
        S1(input);
    }
    else if (input[index] == '\'') { //string
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

//BLOCK COMMENT
void UndefinedAutomaton::S1(const std::string& input) { //finding undefined block comments, found #|
    if (index == input.size()) { //reached EOF, comment not closed
        //inputRead stays same -- not zero, index stays same
    }
    else if (input[index] == '|') { //found bar, move to S2() to look for #
        inputRead++;
        index++;
        S2(input);
    }
    else { //didn't find bar or EOF, stay here
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S1(input);
    }
}

void UndefinedAutomaton::S2(const std::string& input) {
    if (index == input.size()) { //reached EOF, comment not closed
        //inputRead stays same -- not zero, index stays same
    }
    else if (input[index] == '|') { //multiple bars in a row, stay in this state
        inputRead++;
        index++;
        S2(input);
    }
    else if (input[index] == '#') { //block comment complete
        inputRead = 0; //commentA will get this, undefined returns 0
    }
    else { //anything else -- go back to S1 and wait for bar
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S1(input);
    }
}

//STRING
void UndefinedAutomaton::S3(const std::string& input) { //finding undefined strings, found '
    if (index == input.size()) { //started string, didn't complete
        //inputRead stays same -- not zero, index stays same ???????
    }
    else if (input[index] == '\'') { //another ' move on to next state
        inputRead++;
        index++;
        S4(input);
    }
    else { //anything but ' so we stay here
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S3(input);
    }
}

void UndefinedAutomaton::S4(const std::string& input) {
    if (input[index] == '\'') { //two ' in a row go back to S3
        inputRead++;
        index++;
        S3(input);
    }
    else { //complete string, stringA will handle this
        inputRead = 0;
    }
}
