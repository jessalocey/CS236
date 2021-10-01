#include "Token.h"

Token::Token(TokenType type, std::string description, int line) {
    this->type = type;
    this->description = description;
    this->line = line;
}

std::string Token::toString() {
    std::string typeString;
    std::string stringToReturn;
    if (type == TokenType::COMMA) {
        typeString = "COMMA,";
    }
    else if (type == TokenType::PERIOD) {
        typeString = "PERIOD,";
    }
    else if (type == TokenType::Q_MARK) {
        typeString = "Q_MARK,";
    }
    else if (type == TokenType::LEFT_PAREN) {
        typeString = "LEFT_PAREN,";
    }
    else if (type == TokenType::RIGHT_PAREN) {
        typeString = "RIGHT_PAREN,";
    }
    else if (type == TokenType::COLON) {
        typeString = "COLON,";
    }
    else if (type == TokenType::COLON_DASH) {
        typeString = "COLON_DASH,";
    }
    else if (type == TokenType::MULTIPLY) {
        typeString = "MULTIPLY,";
    }
    else if (type == TokenType::ADD) {
        typeString = "ADD,";
    }
    else if (type == TokenType::SCHEMES) {
        typeString = "SCHEMES,";
    }
    else if (type == TokenType::FACTS) {
        typeString = "FACTS,";
    }
    else if (type == TokenType::RULES) {
        typeString = "RULES,";
    }
    else if (type == TokenType::QUERIES) {
        typeString = "QUERIES,";
    }
    else if (type == TokenType::ID) {
        typeString = "ID,";
    }
    else if (type == TokenType::STRING) {
        typeString = "STRING,";
    }
    else if (type == TokenType::COMMENT) {
        typeString = "COMMENT,";
    }
    else if (type == TokenType::UNDEFINED) {
        typeString = "UNDEFINED,";
    }
    else if (type == TokenType::EndOF) {
        typeString = "EOF,";
    }
    else {
        std::cout << "error: token type not found\n";
    }
    stringToReturn += "(" + typeString + "\"" + description + "\"," + std::to_string(line) + ")\n";

    return stringToReturn;
}

TokenType Token::getTokenType() {
    return type;
}
