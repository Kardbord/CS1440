//
// Created by Tanner on 4/10/2017.
//

#include "ConfigurationTester.h"
#include "../Configuration.h"

void ConfigurationTester::testAddParameter(std::ostream &out) {
    out << "ConfigurationTester::testAddParameter" << std::endl;

    Configuration configuration;
    char k = 'a';
    char v = 'z';

    for (int i = 0; i < 20; ++i, ++k, --v) {
        std::string key = std::to_string(k);
        std::string val = std::to_string(v);
        if (!configuration.addParameter(key, val)) {
            out << "Failure in configuration.addParameter(" << key << ", " << val << "), should have returned true."
                << std::endl;
            return;
        }
    }
    
    if (configuration.addParameter("a", "u")) {
        out << "Failure in configuration.addParameter(\"a\", \"u\"), should have returned false." << std::endl;
        return;
    }

    if (configuration.addParameter("a", "z")) {
        out << "Failure in configuration.addParameter(\"a\", \"z\"), should have returned false." << std::endl;
        return;
    }

    if (configuration.addParameter("g", "asdf")) {
        out << "Failure in configuration.addParameter(\"a\", \"asdf\"), should have returned false." << std::endl;
        return;
    }

    if (!configuration.addParameter("asdf", "z")) {
        out << "Failure in configuration.addParameter(\"asdf\", \"z\"), should have returned true." << std::endl;
        return;
    }

    if (!configuration.addParameter("!#$%!", "z")) {
        out << "Failure in configuration.addParameter(\"!#$%!\", \"z\"), should have returned true." << std::endl;
        return;
    }
}
