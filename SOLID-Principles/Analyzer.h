//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_ANALYSER_H
#define SOLID_PRINCIPLES_ANALYSER_H


#include <iosfwd>
#include "ResultSet.h"
#include "Configuration.h"

class Analyzer {
public:

    virtual ResultSet run(std::istream &in) = 0;

protected:
    Analyzer() : m_configuration() {}

    virtual void configure() = 0;

    Configuration m_configuration;
};


#endif //SOLID_PRINCIPLES_ANALYSER_H
