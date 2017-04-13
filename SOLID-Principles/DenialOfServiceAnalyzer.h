//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_DENIALOFSERVICEANALYSER_H
#define SOLID_PRINCIPLES_DENIALOFSERVICEANALYSER_H

#include "Analyzer.h"

class DenialOfServiceAnalyzer : public Analyzer {
public:
    DenialOfServiceAnalyzer(std::string const &timeframe, std::string const &likely_attack_message_count,
                            std::string const &possible_attack_message_count);

    ResultSet run(std::istream &in);

protected:
    void configure();
};


#endif //SOLID_PRINCIPLES_DENIALOFSERVICEANALYSER_H
