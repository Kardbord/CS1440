//
// Created by Tanner on 4/10/2017.
//

#include "ConfigurationTester.h"
#include "../Configuration.h"

void ConfigurationTester::testAddParameter(std::ostream &out) {
    out << "ConfigurationTester::testAddParameter" << std::endl;

    Configuration configuration;
    char k = 'a';

    for (int i = 0; i < 26; ++i, ++k) {
        std::string key = std::string(1, k);
        if (!configuration.addParameter(key, key)) {
            out << "Failure in configuration.addParameter(" << key << ", " << key << "), should have returned true."
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

void ConfigurationTester::testGetters(std::ostream &out) {
    out << "ConfigurationTester::testGetters" << std::endl;

    Configuration configuration = setUp(out);
}

Configuration ConfigurationTester::setUp(std::ostream &out) {
    Configuration configuration;
    char k = 'a';

    for (int i = 0; i < 26; ++i, ++k) {
        std::string key = std::string(1, k);
        if (!configuration.addParameter(key, key)) {
            out << "Failure in ConfigurationTester::setUp" << std::endl;
        }
    }
    return configuration;
}
