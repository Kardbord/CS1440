//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_PORTSCANANALYSER_H
#define SOLID_PRINCIPLES_PORTSCANANALYSER_H


#include "Analyzer.h"
#include <stdexcept>

class PortScanAnalyzer : public Analyzer {
public:
    PortScanAnalyzer(std::string const &likely_attack_port_threshold, std::string const &possible_attack_port_threshold);

    ResultSet run(std::istream &fin);

    virtual Configuration getConfiguration() const { return m_configuration; }

protected:
    void configure();
};


#endif //SOLID_PRINCIPLES_PORTSCANANALYSER_H
