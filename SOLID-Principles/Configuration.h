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

    /**
     * @param key for the std::pair
     * @param value for the std::pair
     * @return true if the new pair was added, false if the key already existed
     */
    bool addParameter(std::string const &key, std::string const &value);

    // TODO: implement
    bool removeParemeter(std::string const &key);

    std::string getParamAsString(std::string const &key) const;

    double getParamAsDouble(std::string const &key) const;

    unsigned long long getParamAsInt(std::string const &key) const;

private:
    std::map<std::string, std::string> m_configParameters;
};


#endif //SOLID_PRINCIPLES_CONFIGURATION_H
