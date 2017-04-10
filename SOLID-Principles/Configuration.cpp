//
// Created by Tanner on 4/10/2017.
//

#include <stdexcept>
#include "Configuration.h"

std::string Configuration::getParamAsString(std::string const &key) const {
    try {
        return m_configParameters.at(key);
    } catch (std::out_of_range e) {
        // Throw my own exception with my own message for greater clarity as to where things went wrong
        throw std::out_of_range("Invalid key in Configuration::getParamAsString()");
    }
}

double Configuration::getParamAsDouble(std::string const &key) const {
    try {
        return std::stod(m_configParameters.at(key));
    } catch (std::exception e) {
        // Throw my own exception with my own message for greater clarity as to where things went wrong
        throw std::out_of_range("Invalid key or no valid conversion in Configuration::getParamAsDouble()");
    }
}

unsigned long long Configuration::getParamAsInt(std::string const &key) const {
    try {
        return std::stoull(m_configParameters.at(key));
    } catch (std::exception e) {
        // Throw my own exception with my own message for greater clarity as to where things went wrong
        throw std::out_of_range("Invalid key or no valid conversion in Configuration::getParamAsInt()");
    }
}

bool Configuration::addParameter(std::string const &key, std::string const &value) {
    return m_configParameters.insert(std::pair<std::string, std::string>(key, value)).second;
}

bool Configuration::removeParemeter(std::string const &key) {
    unsigned int numRemoved = (int) m_configParameters.erase(key);
    return numRemoved == 1;
}
