//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_DENIALOFSERVICEANALYSER_H
#define SOLID_PRINCIPLES_DENIALOFSERVICEANALYSER_H

#include "Analyzer.h"
#include <stdexcept>

class DenialOfServiceAnalyzer : public Analyzer {
public:
    DenialOfServiceAnalyzer(std::string const &timeframe, std::string const &likely_attack_message_threshold,
                            std::string const &possible_attack_message_threshold);

    ResultSet run(std::istream &fin);

    virtual Configuration getConfiguration() const { return m_configuration; }

protected:
    void configure();
};



#endif //SOLID_PRINCIPLES_DENIALOFSERVICEANALYSER_H
