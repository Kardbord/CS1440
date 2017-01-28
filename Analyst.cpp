//
// Created by Tanner on 1/21/2017.
//

//TODO add documentation

#include "Analyst.h"

void Analyst::load(std::ifstream & fin) {
    std::getline(fin, _name);
    std::getline(fin, _initials);

    _simulations.push_back(History(fin));
}
