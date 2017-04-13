//
// Created by Tanner on 4/10/2017.
//

#include "DenialOfServiceAnalyzer.h"

DenialOfServiceAnalyzer::DenialOfServiceAnalyzer() : Analyzer() {
    configure();
}

void DenialOfServiceAnalyzer::configure() {
    m_configuration["Timeframe"] = "";
    m_configuration["Likely Attack Message Count"] = "";
    m_configuration["Possible Attack Message Count"] = "";
}

// TODO: test me
void DenialOfServiceAnalyzer::configure(Configuration const &config) {
    for (auto &&pair : config){
        m_configuration[pair.first] = pair.second;
    }
}
