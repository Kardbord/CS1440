//
// Created by Tanner on 4/10/2017.
//

#include "Configuration.h"

std::string Configuration::getParameter(std::string const &key) const {
    try {
        return m_configParameters.at(key);
    } catch (std::out_of_range e) {
        // Throw my own exception with my own message for greater clarity as to where things went wrong
        throw std::out_of_range("Invalid key in Configuration::getParameter(string)");
    }
}
