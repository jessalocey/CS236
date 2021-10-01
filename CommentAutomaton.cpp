#include "CommentAutomaton.h"
#include "UndefinedAutomaton.h"

void CommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') { //is a comment
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void CommentAutomaton::S1(const std::string& input) {
    if (input[index] == '|') { //block comment
        inputRead++;
        index++;
        S2(input);
    }
    else { //line comment
        inputRead++;
        index++;
        S4(input);
    }
}

//BLOCK COMMENT
void CommentAutomaton::S2(const std::string& input) {
    if (index == input.size()) { //EOF -- invalid
        //undefinedA will handle this
        inputRead = 0;
    }
    else if (input[index] != '|') { //isn't a bar, continue comment
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
    else { //is a bar, move to next state
        inputRead++;
        index++;
        S3(input);
    }
}

void CommentAutomaton::S3(const std::string& input) {
    if (index == input.size()) { //EOF -- invalid
        //undefinedA will handle this
        inputRead = 0;
    }
    else if (input[index] == '|') { //multiple bars in a row, stay in this state
        inputRead++;
        index++;
        S3(input);
    }
    else if (input[index] == '#') { //end of block comment
        inputRead++;
    }
    else { //anything else -- go back to S2 and wait for bar
        if (input[index] == '\n') {
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
}

//LINE COMMENT
void CommentAutomaton::S4(const std::string& input) {
    if (index == input.size()) { //EOF -- line comment complete
        //I think do nothing
        //EOF Automaton created elsewhere
    }
    else if (input[index] == '\n') {
        //line comment complete
    }
    else { //continue line comment
        inputRead++;
        index++;
        S4(input);
    }
}
