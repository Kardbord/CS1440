//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_RESULTSET_H
#define SOLID_PRINCIPLES_RESULTSET_H

#include <map>
#include <ostream>
#include <string>
#include <vector>

class ResultSet : public std::map<std::string, std::vector<std::string>> {
public:
    // TODO: make sure I properly inherit constructors...

    virtual void print(std::ostream &out);
};


#endif //SOLID_PRINCIPLES_RESULTSET_H
