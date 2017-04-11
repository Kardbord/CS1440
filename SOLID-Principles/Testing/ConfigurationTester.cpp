//
// Created by Tanner on 4/10/2017.
//

#include "ConfigurationTester.h"

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

    try {
        // The values are the same as the key for this Configuration
        if (configuration.getParamAsString("a") != "a") {
            out << "Failure in testGetters, getAsString(\"a\") != \"a\" should be false" << std::endl;
            return;
        }

        // The values are the same as the key for this Configuration
        if (configuration.getParamAsString("n") == "a") {
            out << "Failure in testGetters, getAsString(\"n\") == \"a\" should be false" << std::endl;
            return;
        }

        // The values are the same as the key for this Configuration
        if (configuration.getParamAsString("g") != "g") {
            out << "Failure in testGetters, getAsString(\"g\") != \"g\" should be false" << std::endl;
            return;
        }

        // The values are the same as the key for this Configuration
        if (configuration.getParamAsString("g") == "2") {
            out << "Failure in testGetters, getAsString(\"g\") == \"2\" should be false" << std::endl;
            return;
        }

        try {
            configuration.getParamAsString("1");
            out << "Failure! configuration.getParamAsString(\"1\") should have thrown std::out_of_range" << std::endl;
            return;
        } catch (std::exception e) {
            // do nothing, this is correct
        }

        try {
            configuration.getParamAsString("!");
            out << "Failure! configuration.getParamAsString(\"!\") should have thrown std::out_of_range" << std::endl;
            return;
        } catch (std::exception e) {
            // do nothing, this is correct
        }

        try {
            configuration.getParamAsString("$^");
            out << "Failure! configuration.getParamAsString(\"1\") should have thrown std::out_of_range" << std::endl;
            return;
        } catch (std::exception e) {
            // do nothing, this is correct
        }

        try {
            configuration.getParamAsString("asdf");
            out << "Failure! configuration.getParamAsString(\"1\") should have thrown std::out_of_range" << std::endl;
            return;
        } catch (std::exception e) {
            // do nothing, this is correct
        }

    } catch (std::exception e) {
        out << "Failure in testGetters while testing getParamAsString:" << std::endl;
        out << "\t" << e.what() << std::endl;
        return;
    }
}

Configuration ConfigurationTester::setUp(std::ostream &out) {
    Configuration configuration;
    char k = 'a';

    for (int i = 0; i < 26; ++i, ++k) {
        std::string key = std::string(1, k);
        if (!configuration.addParameter(key, key)) {
            out << "Failure in ConfigurationTester::setUp" << std::endl;
            exit(1);
        }
    }
    return configuration;
}
