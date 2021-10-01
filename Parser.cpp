#include "Parser.h"

Parser::Parser(std::vector<Token*> tokens) {
    allTokens = tokens;
    index = 0;
    type = allTokens[0]->getTokenType();
}

DatalogProgram Parser::Parse() {
    parseDatalogProgram();
    return datalogProgram;
}

void Parser::increment() {
    index++;
    type = allTokens[index]->getTokenType();
}

void Parser::parseDatalogProgram() {
    if (match() == "SCHEMES") {} //SCHEMES
    else throw allTokens[index];
    increment();
    if (match() == "COLON") {} //COLON
    else throw allTokens[index];
    increment();
    parseScheme();
    parseSchemeList();
    if (match() == "FACTS") {} //FACTS
    else throw allTokens[index];
    increment();
    if (match() == "COLON") {} //COLON
    else throw allTokens[index];
    increment();
    parseFactList();
    if (match() == "RULES") {} //RULES
    else throw allTokens[index];
    increment();
    if (match() == "COLON") {} //COLON
    else throw allTokens[index];
    increment();
    parseRuleList();
    if (match() == "QUERIES") {} //QUERIES
    else throw allTokens[index];
    increment();
    if (match() == "COLON") {} //COLON
    else throw allTokens[index];
    increment();
    parseQuery();
    parseQueryList();
    if (match() == "EOF") {} //EOF
    else throw allTokens[index];
    //return datalog program
}

std::string Parser::match() { //SCHEMES, COLON, FACTS, RULES, QUERIES, EOF
    if (type == TokenType::COMMENT) {
        increment();
        return match();
    }
    else if (type == TokenType::COMMA) return "COMMA";
    else if (type == TokenType::PERIOD) return "PERIOD";
    else if (type == TokenType::Q_MARK) return "Q_MARK";
    else if (type == TokenType::LEFT_PAREN) return "LEFT_PAREN";
    else if (type == TokenType::RIGHT_PAREN) return "RIGHT_PAREN";
    else if (type == TokenType::COLON) return "COLON";
    else if (type == TokenType::COLON_DASH) return "COLON_DASH";
    else if (type == TokenType::SCHEMES) return "SCHEMES";
    else if (type == TokenType::FACTS) return "FACTS";
    else if (type == TokenType::RULES) return "RULES";
    else if (type == TokenType::QUERIES) return "QUERIES";
    else if (type == TokenType::ID) return "ID";
    else if (type == TokenType::STRING) return "STRING";
    else if (type == TokenType::EndOF) return "EOF";
    else throw allTokens[index];
}

void Parser::parseScheme() {
    if (match() == "ID") {} //ID
    else throw allTokens[index];
    increment();
    if (match() == "LEFT_PAREN") {} //LEFT_PAREN
    else throw allTokens[index];
    increment();
    if (match() == "ID") {} //ID
    else throw allTokens[index];
    increment();
    parseIdList();
    if (match() == "RIGHT_PAREN") {} //RIGHT_PAREN
    else throw allTokens[index];
    increment();

}

void Parser::parseSchemeList() {
    if (match() == "FACTS") {} //return
    else if (match() == "ID") {
        parseScheme();
        parseSchemeList();
    }
    else throw allTokens[index];
}

void Parser::parseFact() {
    if (match() == "ID") {} //ID
    else throw allTokens[index];
    increment();
    if (match() == "LEFT_PAREN") {} //LEFT_PAREN
    else throw allTokens[index];
    increment();
    if (match() == "STRING") {} //STRING
    else throw allTokens[index];
    increment();
    parseStringList();
    if (match() == "RIGHT_PAREN") {} //RIGHT_PAREN
    else throw allTokens[index];
    increment();
    if (match() == "PERIOD") {} //PERIOD
    else throw allTokens[index];
    increment();
}

void Parser::parseFactList() {
    if (match() == "RULES") {} //return
    else if (match() == "ID") {
        parseFact();
        parseFactList();
    }
    else throw allTokens[index];
}

void Parser::parseRule() {
    parseHeadPredicate();
    if (match() == "COLON_DASH") {} //COLON_DASH
    else throw allTokens[index];
    increment();
    parsePredicate();
    parsePredicateList();
    if (match() == "PERIOD") {} //PERIOD
    else throw allTokens[index];
    increment();
}

void Parser::parseRuleList() {
    if (match() == "QUERIES") {} //return
    else if (match() == "ID") {
        parseRule();
        parseRuleList();
    }
    else throw allTokens[index];
}

void Parser::parseQuery() {
    parsePredicate();
    if (match() == "Q_MARK") {} //Q_MARK
    else throw allTokens[index];
    increment();
}

void Parser::parseQueryList() {
    if (match() == "EOF") {} //return
    else if (match() == "ID") {
        parseQuery();
        parseQueryList();
    }
    else throw allTokens[index];
}

void Parser::parseHeadPredicate() {
    //match(); //ID //checked in parse R L
    increment();
    if (match() == "LEFT_PAREN") {} //LEFT_PAREN
    else throw allTokens[index];
    increment();
    if (match() == "ID") {} //ID
    else throw allTokens[index];
    increment();
    parseIdList();
    if (match() == "RIGHT_PAREN") {} //RIGHT_PAREN
    else throw allTokens[index];
    increment();
}

void Parser::parsePredicate() {
    //match(); //ID //checked in if statement in parse Q L
    increment();
    if (match() == "LEFT_PAREN") {} //LEFT_PAREN
    else throw allTokens[index];
    increment();
    parseParameter();
    parseParameterList();
    if (match() == "RIGHT_PAREN") {} //RIGHT_PAREN
    else throw allTokens[index];
    increment();
}

void Parser::parsePredicateList() {
    if (match() == "PERIOD") {} //return
    else if (match() == "COMMA") {
        //match(); //COMMA //checked in if statement
        increment();
        parsePredicate();
        parsePredicateList();
    }
    else throw allTokens[index];
}

void Parser::parseParameterList() {
    if (match() == "RIGHT_PAREN") {} //return
    else if (match() == "COMMA") {
        //match(); //COMMA //checked in if statement
        increment();
        parseParameter();
        parseParameterList();
    }
    else throw allTokens[index];
}

void Parser::parseStringList() {
    if (match() == "RIGHT_PAREN") {} //return
    else if (match() == "COMMA") {
        //match(); //COMMA //checked in if statement
        increment();
        if (match() == "STRING") {} //STRING
        else throw allTokens[index];
        increment();
        parseStringList();
    }
    else throw allTokens[index];
}

void Parser::parseIdList() {
    if (match() == "RIGHT_PAREN") {} //return
    else if (match() == "COMMA") {
        //match(); //COMMA //checked in if statement
        increment();
        if (match() == "ID") {} //ID
        else throw allTokens[index];
        increment();
        parseIdList();
    }
    else throw allTokens[index];
}

void Parser::parseParameter() {
    if ((match() == "STRING") || (match() == "ID")) {
        //match(); //string or ID //checked in if statement
        increment();
    }
    else throw allTokens[index];
}

std::string Parser::toString() {
    return datalogProgram.toString();
}
