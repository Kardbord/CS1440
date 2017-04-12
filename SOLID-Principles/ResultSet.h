//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_RESULTSET_H
#define SOLID_PRINCIPLES_RESULTSET_H

#include <map>
#include <ostream>
#include <string>
#include <vector>

// TODO: decide if I want/need a getter
class ResultSet {
public:
    ResultSet() : m_results() {}

    ResultSet(std::vector<std::pair<std::string, std::vector<std::string>>> const &results);

    ResultSet(std::map<std::string, std::vector<std::string>> const &map);

    void print(std::ostream &out) const;

private:
    std::map<std::string, std::vector<std::string>> m_results;
};


#endif //SOLID_PRINCIPLES_RESULTSET_H
