#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include "Lexer.h"
#include "Parser.h"

int main(int argc, char** argv) {
    // check command line arguments
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " input_file" << std::endl;
        return 1;
    }

    // open file
    std::string fileName = argv[1];
    //ifstream input; //this line
    //input.open(fileName); //and this line same as line below
    std::ifstream input(fileName); //tries to open file //"input" = the file itself; "fileName" = just what it's called
    if (!input.is_open()) { //does it fail
        std::cout << "File " << fileName << " could not be found or opened." << std::endl;
        return 1;
    }
    //here we know the file is open

    std::stringstream ss;
    ss << input.rdbuf(); //read buffer -- get everything

    std::string fileContent = ss.str(); //changes ss into a string

    Lexer* lexer = new Lexer();
    lexer->Run(fileContent); //give filecontent to lexer, lexer gives it to each automaton child and they return 0 or !0

    //lexer gives all tokens to main to print
    std::cout << lexer->toString();
    /*end project 1 */



    /*project 2 */

    Parser parser(lexer->getTokenVector());

    try {
        parser.Parse(); //returns datalog program
        std::cout << "Success!\n" << parser.toString();
    }
    catch (Token* t) {
        std::cout << "Failure! \n  " << t->toString() << std::endl;
    }


    delete lexer;

    return 0;
}