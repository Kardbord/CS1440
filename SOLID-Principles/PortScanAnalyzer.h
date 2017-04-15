//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_PORTSCANANALYSER_H
#define SOLID_PRINCIPLES_PORTSCANANALYSER_H


#include "Analyzer.h"

class PortScanAnalyser : public Analyzer {
public:
    PortScanAnalyser(std::string const &likely_attack_port_count, std::string const &possible_attack_port_count);

    // TODO: implement me
    ResultSet run(std::istream &fin) {}

    virtual Configuration getConfiguration() const { return m_configuration; }

protected:
    void configure();
};


#endif //SOLID_PRINCIPLES_PORTSCANANALYSER_H
