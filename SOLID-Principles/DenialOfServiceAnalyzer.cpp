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
    // the [] operator on a map (and its subclasses) inserts the new std::pair element if it does not already exist
    // using the value's default constructor, see http://www.cplusplus.com/reference/map/map/operator[]/
    m_configuration["Timeframe"] = "";
    m_configuration["Likely Attack Message Count"] = "";
    m_configuration["Possible Attack Message Count"] = "";
}

ResultSet DenialOfServiceAnalyzer::run(std::istream &fin) {

    std::map<std::string, std::map<std::string, unsigned long>> addressToSummary;

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

    // Attack detection phase
    ResultSet results;
    unsigned long long likelyThreshold;
    unsigned long long possibleThreshold;

    try {
        // the [] operator on a map (and its subclasses) inserts the new std::pair element if it does not already exist
        // using the value's default constructor, see http://www.cplusplus.com/reference/map/map/operator[]/
        results["Likely Attackers"];
        results["Possible Attackers"];
        results["Attack Periods"];
        results["Timeframe"] = std::vector<std::string>(1, m_configuration.getParamAsString("Timeframe"));
        likelyThreshold = m_configuration.getParamAsInt("Likely Attack Message Count");
        possibleThreshold = m_configuration.getParamAsInt("Possible Attack Message Count");
    } catch (std::exception) {
        throw std::out_of_range(
                "Failure in DenialOfServiceAnalyzer::run when accessing configuration parameters during attack detection phase");
    }

    // For every address...
    for (auto &&addressSummaryPair : addressToSummary) {
        // For every timestamp that address did something...
        for (auto &&timeStampCountPair : addressSummaryPair.second) {
            unsigned long long startTime = std::stoull(timeStampCountPair.first);
            unsigned int count = timeStampCountPair.second;

        }
    }


    return ResultSet();
}
