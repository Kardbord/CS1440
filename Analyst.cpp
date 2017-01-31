//
// Created by Tanner Kvarfordt on 1/21/2017.
// A02052217
//

#include "Analyst.h"

// Initializes data members based on the input file provided in the cmd arguments
void Analyst::load(std::ifstream & fin) {
    std::getline(fin, _name);
    std::getline(fin, _initials);

    history.load(fin);
}
