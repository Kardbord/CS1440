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

// TODO: test me
std::vector<std::string> ResultSet::getResults(std::string const &key) const {
    try {
        return m_results.at(key);
    } catch (std::out_of_range e) {
        // Throw my own exception for greater clarity
        throw std::out_of_range("Invalid key queried in ResultSet::getResults -- queried: " + key);
    }
}
