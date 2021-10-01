#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <iostream>

enum class TokenType {
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    COLON,
    COLON_DASH,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    STRING,
    COMMENT,
    UNDEFINED,
    EndOF
};

class Token
{
private:
    TokenType type;
    std::string description;
    unsigned int line;

public:
    Token(TokenType type, std::string description, int line);
    std::string toString();
    TokenType getTokenType();
};

#endif // TOKEN_H

