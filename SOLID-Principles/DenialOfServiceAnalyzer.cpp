//
// Created by Tanner on 4/10/2017.
//

#include "DenialOfServiceAnalyzer.h"

DenialOfServiceAnalyzer::DenialOfServiceAnalyzer(std::string const &timeframe,
                                                 std::string const &likely_attack_message_threshold,
                                                 std::string const &possible_attack_message_threshold) : Analyzer() {
    if (std::stoull(likely_attack_message_threshold) < std::stoull(possible_attack_message_threshold)) {
        throw std::logic_error(
                "Failure in constructing DOSAnalyzer: likely_attack_threshold should be greater than possible_attack_threshold");
    }

    configure();
    m_configuration["Timeframe"] = timeframe;
    m_configuration["Likely Attack Message Threshold"] = likely_attack_message_threshold;
    m_configuration["Possible Attack Message Threshold"] = possible_attack_message_threshold;
}

void DenialOfServiceAnalyzer::configure() {
    // the [] operator on a map (and its subclasses) inserts the new std::pair element if it does not already exist
    // using the value's default constructor, see http://www.cplusplus.com/reference/map/map/operator[]/
    m_configuration["Timeframe"] = "";
    m_configuration["Likely Attack Message Threshold"] = "";
    m_configuration["Possible Attack Message Threshold"] = "";
}

ResultSet DenialOfServiceAnalyzer::run(std::istream &fin) {

    std::map<std::string, std::map<std::string, unsigned long>> addressToSummary;

    std::map<std::string, unsigned long> addressToMinTimestamp;
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
                if (addressToMinTimestamp[srcAddress] > std::stoul(timestamp)) {
                    addressToMinTimestamp[srcAddress] = std::stoul(timestamp);
                }
            } else {
                addressToSummary[srcAddress][timestamp] = 1;
                addressToMinTimestamp[srcAddress] = std::stoul(timestamp);
            }

        }
    }

    // Attack detection phase
    ResultSet results;
    // the [] operator on a map (and its subclasses) inserts the new std::pair element if it does not already exist
    // using the value's default constructor, see http://www.cplusplus.com/reference/map/map/operator[]/
    results["Likely Attackers"];
    results["Possible Attackers"];
    results["Attack Periods"];
    results["Timeframe"] = std::vector<std::string>(1, m_configuration.getParamAsString("Timeframe"));

    unsigned long long likelyThreshold;
    unsigned long long possibleThreshold;

    try {
        likelyThreshold = m_configuration.getParamAsInt("Likely Attack Message Count");
        possibleThreshold = m_configuration.getParamAsInt("Possible Attack Message Count");
    } catch (std::exception) {
        throw std::out_of_range(
                "Failure in DenialOfServiceAnalyzer::run when accessing configuration parameters during attack detection phase");
    }

    // For every address...
    for (auto &&addressSummaryPair : addressToSummary) {
        // For every timestamp at which that address did something...
        unsigned long long startTime;
        try {
            startTime = addressToMinTimestamp.at(addressSummaryPair.first);
        } catch (std::exception) {
            throw std::out_of_range("Failure in DOSAnalyzer::run when accessing addressToMinTimeStamp");
        }
        unsigned int count = 0;
        for (auto &&timeStampCountPair : addressSummaryPair.second) {
            if (std::stoul(timeStampCountPair.first) < startTime + m_configuration.getParamAsDouble("Timeframe")) {
                count += timeStampCountPair.second;
            }
        }

        if (count >= likelyThreshold) {
            results.at("Likely Attackers").push_back(addressSummaryPair.first);
            results.at("Attack Periods").push_back(
                    addressSummaryPair.first + ": " + std::to_string(startTime) + " to " + std::to_string(
                            startTime + m_configuration.getParamAsDouble("Timeframe")));
        } else if (count >= possibleThreshold) {
            results.at("Possible Attackers").push_back(addressSummaryPair.first);
            results.at("Attack Periods").push_back(
                    addressSummaryPair.first + ": " + std::to_string(startTime) + " to " + std::to_string(
                            startTime + m_configuration.getParamAsDouble("Timeframe")));
        }
    }


    return results;
}
