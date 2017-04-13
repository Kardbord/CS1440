//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_DENIALOFSERVICEANALYSER_H
#define SOLID_PRINCIPLES_DENIALOFSERVICEANALYSER_H

#include "Analyzer.h"
#include <stdexcept>

class DenialOfServiceAnalyzer : public Analyzer {
public:
    DenialOfServiceAnalyzer(std::string const &timeframe, std::string const &likely_attack_message_count,
                            std::string const &possible_attack_message_count);

    // TODO: implement me
    ResultSet run(std::istream &in) {}

    // TODO: decide whether or not to replace this with a getConfiguration() return m_configuration;
    virtual std::pair<std::string, std::string> getConfigPair(std::string const &key) const;

    virtual std::vector<std::string> getConfigKeys() const { return m_configKeys; }

protected:
    void configure();

    std::vector<std::string> m_configKeys;
};


#endif //SOLID_PRINCIPLES_DENIALOFSERVICEANALYSER_H
