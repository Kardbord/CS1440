//
// Created by Tanner on 4/10/2017.
//

#include "ResultSet.h"

// TODO: test me
void ResultSet::print(std::ostream &out) const {
    for (auto &&pair : m_results) {
        out << pair.first << ": " << std::endl;
        for (auto &&result : pair.second) {
            out << "    " << result << std::endl;
        }
    }
}

// TODO: test me
ResultSet::ResultSet(std::map<std::string, std::vector<std::string>> const &map) :m_results(map) {}
