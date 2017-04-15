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

ResultSet DenialOfServiceAnalyzer::run(std::istream &fin) {

    std::map<std::string, std::map<std::string, unsigned long long>> addressToSummary;

    // Data loading phase
    {
        std::string timestamp;
        std::string srcAddress;
        std::string srcPort;
        std::string destPort;

        while (!fin.eof()) {
            std::getline(fin, timestamp, ',');
            std::getline(fin, srcAddress, ',');
            std::getline(fin, srcPort, ',');
            std::getline(fin, destPort);

            if (addressToSummary[srcAddress].count(timestamp) > 0) {
                ++addressToSummary[srcAddress][timestamp];
            } else {
                addressToSummary[srcAddress][timestamp] = 1;
            }

        }
    }

    return ResultSet();
}
