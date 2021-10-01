#ifndef CS236_PARSER_H
#define CS236_PARSER_H

#include "Token.h"
#include "DatalogProgram.h"
#include <vector>

class Parser {
private:
    std::vector<Token*> allTokens;
    Token* currentToken;
    TokenType type;
    DatalogProgram datalogProgram;
    int index;


public:
    Parser(std::vector<Token*> tokens);
    ~Parser() {}


    DatalogProgram Parse();
    void increment();
    void parseDatalogProgram();
    std::string match(); //return string
    void parseScheme();
    void parseSchemeList();
    void parseFact();
    void parseFactList();
    void parseRule();
    void parseRuleList(); //return Rule
    void parseQuery();
    void parseQueryList();
    void parseHeadPredicate();
    void parsePredicate();
    void parsePredicateList();
    void parseParameterList();
    void parseStringList();
    void parseIdList();
    void parseParameter();
    std::string toString();


};


#endif //CS236_PARSER_H



/*
need individual functions for everything on left below

datalogProgram  ->  SCHEMES COLON scheme schemeList FACTS COLON factList RULES
                    COLON ruleList QUERIES COLON query queryList EOF

schemeList	->	scheme schemeList | lambda
factList	->	fact factList | lambda
ruleList	->	rule ruleList | lambda
queryList	->	query queryList | lambda

scheme   	-> 	ID LEFT_PAREN ID idList RIGHT_PAREN
fact    	->	ID LEFT_PAREN STRING stringList RIGHT_PAREN PERIOD
rule    	->	headPredicate COLON_DASH predicate predicateList PERIOD
query	    ->  predicate Q_MARK

headPredicate	->	ID LEFT_PAREN ID idList RIGHT_PAREN
predicate	->	ID LEFT_PAREN parameter parameterList RIGHT_PAREN

predicateList	->	COMMA predicate predicateList | lambda
parameterList	-> 	COMMA parameter parameterList | lambda
stringList	-> 	COMMA STRING stringList | lambda
idList  	-> 	COMMA ID idList | lambda
parameter	->	STRING | ID



 */