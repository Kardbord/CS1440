//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_CONFIGURATION_H
#define SOLID_PRINCIPLES_CONFIGURATION_H

#include <string>
#include <map>

class Configuration {
public:
    Configuration() : m_configParameters() {}

    // TODO: implement these
    bool addParameter();

    bool removeParemeter();

    std::string getParamAsString(std::string const &key) const;

    double getParamAsDouble(std::string const &key) const;

    unsigned long getParamAsInt(std::string const &key) const;

private:
    std::map<std::string, std::string> m_configParameters;
};


#endif //SOLID_PRINCIPLES_CONFIGURATION_H
