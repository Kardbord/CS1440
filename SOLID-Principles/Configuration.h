//
// Created by Tanner on 4/10/2017.
//

#ifndef SOLID_PRINCIPLES_CONFIGURATION_H
#define SOLID_PRINCIPLES_CONFIGURATION_H

#include <string>
#include <map>

// TODO: test me
class Configuration : public std::map<std::string, std::string> {
public:

    bool addPair(std::string const &key, std::string const &param);

    std::string getParamAsString(std::string const &key) const;

    double getParamAsDouble(std::string const &key) const;

    unsigned long long getParamAsInt(std::string const &key) const;
};


#endif //SOLID_PRINCIPLES_CONFIGURATION_H
