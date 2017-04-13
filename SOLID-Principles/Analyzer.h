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
    Analyzer() : m_configuration() {}

    virtual ResultSet run(std::istream &in) = 0;

    virtual void configure(Configuration const &config) = 0;

    virtual void configure() = 0;

protected:
    Configuration m_configuration;
};


#endif //SOLID_PRINCIPLES_ANALYSER_H
