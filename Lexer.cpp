#include "Lexer.h"
#include "CommaAutomaton.h"
#include "PeriodAutomaton.h"
#include "Q_MarkAutomaton.h"
#include "Left_ParenAutomaton.h"
#include "Right_ParenAutomaton.h"
#include "ColonAutomaton.h"
#include "ColonDashAutomaton.h"
#include "MultiplyAutomaton.h"
#include "AddAutomaton.h"
#include "SchemesAutomaton.h"
#include "FactsAutomaton.h"
#include "RulesAutomaton.h"
#include "QueriesAutomaton.h"
#include "IDAutomaton.h"
#include "StringAutomaton.h"
#include "CommentAutomaton.h"
#include "UndefinedAutomaton.h"
#include "EndOFAutomaton.h"

Lexer::Lexer() {
    CreateAutomata();
}

Lexer::~Lexer() {
    for (unsigned int i = 0; i < automata.size(); i++) { //delete automata
        delete automata[i];
    }
    for (unsigned int i = 0; i < tokens.size(); i++) { //delete tokens
        delete tokens[i];
    }
}

void Lexer::CreateAutomata() {
    automata.push_back(new CommaAutomaton());
    automata.push_back(new PeriodAutomaton());
    automata.push_back(new Q_MarkAutomaton());
    automata.push_back(new Left_ParenAutomaton());
    automata.push_back(new Right_ParenAutomaton());
    automata.push_back(new ColonAutomaton());
    automata.push_back(new ColonDashAutomaton());
    automata.push_back(new MultiplyAutomaton());
    automata.push_back(new AddAutomaton());
    automata.push_back(new SchemesAutomaton());
    automata.push_back(new FactsAutomaton());
    automata.push_back(new RulesAutomaton());
    automata.push_back(new QueriesAutomaton());
    automata.push_back(new IDAutomaton());
    automata.push_back(new StringAutomaton());
    automata.push_back(new CommentAutomaton());
    automata.push_back(new UndefinedAutomaton());
    automata.push_back(new EndOFAutomaton());
}

void Lexer::Run(std::string& input) {
    lineNumber = 1;

    // While there are more characters to tokenize
    while (input.size() > 0) { //while (input.size() > 0) && input[(input.size()-1)] /*last element*/  !isspace
        maxRead = 0;
        maxAutomaton = automata[0];
        bool flag = false;

        while (isspace(input[0])) {
            if (input[0] == '\n') { //new line
                lineNumber++;
            }
            if (input.size() == 1) { //one isspace left in input -- clear it
                input = "";
                flag = true;
                //exit this while loop and bigger while loop -- straight to EOF token
            }
            else {
                input = input.substr(1, input.size());
            }
        }
        if (flag) {
            break; //to EOF token
        }
    // Here is the "Parallel" part of the algorithm
    // Each automaton runs with the same input
        for (unsigned int i = 0; i < automata.size(); i++) {
            inputRead = automata[i]->Start(input); //[i] in automata == comma->start(), will return !=0 if matches
            if (inputRead > maxRead) {
                maxRead = inputRead;
                maxAutomaton = automata[i]; //maxA set to whatever A had the max inputRead
            }
        }
        // Here is the "Max" part of the algorithm
        if (maxRead > 0) {
            Token* newToken = maxAutomaton->CreateToken(input.substr(0,maxRead), lineNumber);
            lineNumber += maxAutomaton->NewLinesRead();
            tokens.push_back(newToken);
        }
        // No automaton accepted input
        // Create single character undefined token
        else {
            maxRead = 1;
            Token* newToken = new Token(TokenType::UNDEFINED, input.substr(0,1), lineNumber); //create (with first character of input)
            tokens.push_back(newToken);
        }
        // Update `input` by removing characters read to create Token
        input = input.substr(maxRead, input.size() - 1); //remove maxRead characters from input beginning
    }
    //add end of file token
    Token* newToken = new Token(TokenType::EndOF, "", lineNumber);
    tokens.push_back(newToken);
}

std::string Lexer::toString() {
    std::string toReturn;
    for (unsigned int i = 0; i < tokens.size(); i++) {
        toReturn += tokens[i]->toString();
    }
    toReturn += "Total Tokens = " + std::to_string(tokens.size()) + "\n";
    return toReturn;
}

std::vector<Token*> Lexer::getTokenVector() {
    return tokens;
}

