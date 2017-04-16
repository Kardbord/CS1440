//
// Created by Tanner on 4/10/2017.
//

#include "PortScanAnalyzer.h"
#include <algorithm>

PortScanAnalyzer::PortScanAnalyzer(std::string const &likely_attack_port_threshold,
                                   std::string const &possible_attack_port_threshold) : Analyzer() {

    if (std::stoull(likely_attack_port_threshold) < std::stoull(possible_attack_port_threshold)) {
        throw std::logic_error(
                "Failure in constructing PortScanAnalyzer: likely_attack_threshold should be greater than possible_attack_threshold");
    }

    configure();
    m_configuration["Likely Attack Port Threshold"] = likely_attack_port_threshold;
    m_configuration["Possible Attack Port Threshold"] = possible_attack_port_threshold;
}

void PortScanAnalyzer::configure() {
    // the [] operator on a map (and its subclasses) inserts the new std::pair element if it does not already exist
    // using the value's default constructor, see http://www.cplusplus.com/reference/map/map/operator[]/
    m_configuration["Likely Attack Port Threshold"] = "";
    m_configuration["Possible Attack Port Threshold"] = "";
}

ResultSet PortScanAnalyzer::run(std::istream &fin) {

    std::map<std::string, std::vector<unsigned long>> addressToSummary;

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

            auto it = std::find(addressToSummary[srcAddress].begin(), addressToSummary[srcAddress].end(),
                                std::stoul(destPort));
            if (it == addressToSummary[srcAddress].end()) {
                addressToSummary[srcAddress].push_back(std::stoul(destPort));
            }
        }
    }

    // Attack detection phase
    ResultSet results;
    // the [] operator on a map (and its subclasses) inserts the new std::pair element if it does not already exist
    // using the value's default constructor, see http://www.cplusplus.com/reference/map/map/operator[]/
    results["Likely Attackers"];
    results["Possible Attackers"];
    results["Port Count"];
    unsigned long likelyThreshold;
    unsigned long possibleThreshold;
    try {
        likelyThreshold = std::stoul(m_configuration.at("Likely Attack Port Threshold"));
        possibleThreshold = std::stoul(m_configuration.at("Possible Attack Port Threshold"));
    } catch (std::exception e) {
        throw std::out_of_range(
                "Failure in PortScanAnalyzer::run when accessing configuration parameters during attack detection phase");
    }

    std::string src;
    unsigned long long uniqueAddresses = 0;
    for (auto &&addressSummaryPair : addressToSummary) {
        src = addressSummaryPair.first;
        uniqueAddresses = addressSummaryPair.second.size();

        if (uniqueAddresses >= likelyThreshold) {
            results["Likely Attackers"].push_back(src);
            results["Port Count"].push_back(src + ": " + std::to_string(uniqueAddresses));
        } else if (uniqueAddresses >= possibleThreshold) {
            results["Possible Attackers"].push_back(src);
            results["Port Count"].push_back(src + ": " + std::to_string(uniqueAddresses));
        }
    }

    return results;
}
