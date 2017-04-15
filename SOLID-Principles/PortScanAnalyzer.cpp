//
// Created by Tanner on 4/10/2017.
//

#include "PortScanAnalyzer.h"

PortScanAnalyser::PortScanAnalyser(std::string const &likely_attack_port_count,
                                   std::string const &possible_attack_port_count) : Analyzer() {
    configure();
    m_configuration["Likely Attack Port Count"] = likely_attack_port_count;
    m_configuration["Possible Attack Port Count"] = possible_attack_port_count;
}

void PortScanAnalyser::configure() {
    // the [] operator on a map (and its subclasses) inserts the new std::pair element if it does not already exist
    // using the value's default constructor, see http://www.cplusplus.com/reference/map/map/operator[]/
    m_configuration["Likely Attack Port Count"] = "";
    m_configuration["Possible Attack Port Count"] = "";
}
