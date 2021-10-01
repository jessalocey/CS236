#ifndef CS236_RULE_H
#define CS236_RULE_H

#include "Predicate.h"

class Rule {
private:
    //Predicate headPredicate;
    std::vector<Predicate> bodyPredicates;

public:
    std::string toString();
};


#endif //CS236_RULE_H

/*
 * used to represent a
 * Rule
 *
 */