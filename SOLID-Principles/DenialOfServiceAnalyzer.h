//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_DENIALOFSERVICEANALYSER_H
#define SOLID_PRINCIPLES_DENIALOFSERVICEANALYSER_H

#include "Analyzer.h"

class DenialOfServiceAnalyser : public Analyzer {
public:
    ResultSet run(std::istream &in);

    void configure(Configuration const &config);

    void configure();
};


#endif //SOLID_PRINCIPLES_DENIALOFSERVICEANALYSER_H
