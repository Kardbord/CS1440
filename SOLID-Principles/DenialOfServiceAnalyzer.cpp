//
// Created by Tanner on 4/10/2017.
//

#include "DenialOfServiceAnalyzer.h"

DenialOfServiceAnalyzer::DenialOfServiceAnalyzer(std::string const &timeframe,
                                                 std::string const &likely_attack_message_count,
                                                 std::string const &possible_attack_message_count) : Analyzer() {
    configure();
    m_configuration["Timeframe"] = timeframe;
    m_configuration["Likely Attack Message Count"] = likely_attack_message_count;
    m_configuration["Possible Attack Message Count"] = possible_attack_message_count;
}

void DenialOfServiceAnalyzer::configure() {
    m_configuration["Timeframe"] = "";
    m_configuration["Likely Attack Message Count"] = "";
    m_configuration["Possible Attack Message Count"] = "";
}
