//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_RESULTSET_H
#define SOLID_PRINCIPLES_RESULTSET_H

#include <map>
#include <ostream>
#include <string>
#include <vector>

// TODO: decide if I want/need a getter and/or a method for adding individual results
class ResultSet {
public:
    // TODO: remove this constructor if I don't write a method to add individual results
    ResultSet() : m_results() {}

    ResultSet(std::map<std::string, std::vector<std::string>> const &map);

    void print(std::ostream &out) const;

    std::vector<std::string> getResults(std::string const &key) const;

private:
    std::map<std::string, std::vector<std::string>> m_results;
};


#endif //SOLID_PRINCIPLES_RESULTSET_H
