//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_ANALYSER_H
#define SOLID_PRINCIPLES_ANALYSER_H


#include <iosfwd>
#include "ResultSet.h"

class Analyzer {
public:
    virtual ResultSet run(std::istream & in) = 0;
};


#endif //SOLID_PRINCIPLES_ANALYSER_H
