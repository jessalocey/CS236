#ifndef CS236_PREDICATE_H
#define CS236_PREDICATE_H

#include "Parameter.h"

class Predicate {
private:
    std::string id;
    std::vector<Parameter> parameters;

public:
    std::string toString();

};


#endif //CS236_PREDICATE_H

/*
 * used to represent a
 * Scheme, Fact, or Query
 *
 */