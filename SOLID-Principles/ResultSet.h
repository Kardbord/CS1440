//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_RESULTSET_H
#define SOLID_PRINCIPLES_RESULTSET_H

#include <map>
#include <ostream>
#include <string>
#include <vector>

// TODO: this class is a map iwth a string as a key and a container as the value
class ResultSet {
public:
    ResultSet() : m_results() {}

    void print(std::ostream &out) const;

private:
    std::map<std::string, std::vector<std::string>> m_results;
};


#endif //SOLID_PRINCIPLES_RESULTSET_H
