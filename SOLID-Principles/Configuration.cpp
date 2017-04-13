//
// Created by Tanner on 4/10/2017.
//

#include <stdexcept>
#include "Configuration.h"

std::string Configuration::getParamAsString(std::string const &key) const {
    try {
        return this->at(key);
    } catch (std::out_of_range e) {
        // Throw my own exception with my own message for greater clarity as to where things went wrong
        throw std::out_of_range("Invalid key in Configuration::getParamAsString()");
    }
}

double Configuration::getParamAsDouble(std::string const &key) const {
    return std::stod(this->at(key));
}

unsigned long long Configuration::getParamAsInt(std::string const &key) const {
    return std::stoull(this->at(key));
}

void Configuration::addPair(std::string const &key, std::string const &param) {
    this->insert(std::pair<std::string, std::string>(key, param));
}
