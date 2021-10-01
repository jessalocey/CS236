#ifndef CS236_DATALOGPROGRAM_H
#define CS236_DATALOGPROGRAM_H

#include "Rule.h"

class DatalogProgram {
private:
    std::vector<Predicate> Schemes;
    std::vector<Predicate> Facts;
    std::vector<Rule> Rules;
    std::vector<Predicate> Queries;

public:
    DatalogProgram() {}
    ~DatalogProgram() {}

    std::string toString();
};


#endif //CS236_DATALOGPROGRAM_H


/*
 * Domain: only strings in FACTS
 *
 */