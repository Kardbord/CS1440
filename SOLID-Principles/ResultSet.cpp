//
// Created by Tanner on 4/10/2017.
//

#include "ResultSet.h"

void ResultSet::print(std::ostream &out) {
    for (auto &&pair : *this) {
        out << pair.first << std::endl;
        for (auto &&result : pair.second) {
            out << "    " << result << std::endl;
        }
    }
}
