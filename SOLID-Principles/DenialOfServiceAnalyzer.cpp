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
    m_configKeys.push_back("Timeframe");
    m_configKeys.push_back("Likely Attack Message Count");
    m_configKeys.push_back("Possible Attack Message Count");
    m_configuration["Timeframe"] = "";
    m_configuration["Likely Attack Message Count"] = "";
    m_configuration["Possible Attack Message Count"] = "";
}

std::pair<std::string, std::string> DenialOfServiceAnalyzer::getConfigPair(std::string const &key) const {
    auto pair = m_configuration.find(key);

    if (pair == m_configuration.end()) {
        throw std::out_of_range("Invalid key in DenialOfServiceAnalyzer::getConfigPair");
    }

    return *pair;
}
