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

    // **************************getParamAsString()********************************************************************
    try {
        if (configuration.getParamAsString("a") != "0") {
            out << "Failure in testGetters, getAsString(\"a\") != \"0\" should be false" << std::endl;
            return;
        }

        if (configuration.getParamAsString("n") == "0") {
            out << "Failure in testGetters, getAsString(\"n\") == \"0\" should be false" << std::endl;
            return;
        }

        if (configuration.getParamAsString("g") != "6") {
            out << "Failure in testGetters, getAsString(\"6\") != \"6\" should be false" << std::endl;
            return;
        }

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
            out << "Failure! configuration.getParamAsString(\"$^\") should have thrown std::out_of_range" << std::endl;
            return;
        } catch (std::exception e) {
            // do nothing, this is correct
        }

        try {
            configuration.getParamAsString("asdf");
            out << "Failure! configuration.getParamAsString(\"asdf\") should have thrown std::out_of_range"
                << std::endl;
            return;
        } catch (std::exception e) {
            // do nothing, this is correct
        }

    } catch (std::exception e) {
        out << "Failure in testGetters while testing getParamAsString:" << std::endl;
        out << "\t" << e.what() << std::endl;
        return;
    }

    // **************************getParamAsInt()***********************************************************************
    try {
        configuration.addParameter("hat", "-20");

        if (configuration.getParamAsInt("hat") != -20) {
            out << "Failure! configuration.getParamAsInt(\"hat\") != -20) should be false" << std::endl;
        }

        if (configuration.getParamAsInt("a") != 0) {
            out << "Failure! configuration.getParamAsInt(\"a\") != 0) should be false" << std::endl;
        }

        if (configuration.getParamAsInt("q") != 16) {
            out << "Failure! configuration.getParamAsInt(\"q\") != 16) should be false" << std::endl;
        }

        if (configuration.getParamAsInt("q") == '1') {
            out << "Failure! configuration.getParamAsInt(\"q\") == 1) should be false" << std::endl;
        }

        if (configuration.getParamAsInt("q") == 30) {
            out << "Failure! configuration.getParamAsInt(\"q\") == 30) should be false" << std::endl;
        }

        if (configuration.getParamAsInt("q") == -16) {
            out << "Failure! configuration.getParamAsInt(\"q\") == -16) should be false" << std::endl;
        }

        if (configuration.getParamAsInt("q") == -12) {
            out << "Failure! configuration.getParamAsInt(\"q\") == -12) should be false" << std::endl;
        }

        if (configuration.getParamAsInt("q") == 2) {
            out << "Failure! configuration.getParamAsInt(\"q\") == 2) should be false" << std::endl;
        }

        try {
            configuration.getParamAsInt("1");
            out << "Failure! configuration.getParamAsInt(\"1\") should have thrown std::out_of_range" << std::endl;
            return;
        } catch (std::exception e) {
            // do nothing, this is correct
        }

        try {
            configuration.getParamAsInt("!");
            out << "Failure! configuration.getParamAsInt(\"!\") should have thrown std::out_of_range" << std::endl;
            return;
        } catch (std::exception e) {
            // do nothing, this is correct
        }

        try {
            configuration.getParamAsInt("$^");
            out << "Failure! configuration.getParamAsInt(\"$^\") should have thrown std::out_of_range" << std::endl;
            return;
        } catch (std::exception e) {
            // do nothing, this is correct
        }

        try {
            configuration.getParamAsInt("asdf");
            out << "Failure! configuration.getParamAsInt(\"asdf\") should have thrown std::out_of_range"
                << std::endl;
            return;
        } catch (std::exception e) {
            // do nothing, this is correct
        }

    } catch (std::exception e) {
        out << "Failure in testGetters while testing getParamAsInt:" << std::endl;
        out << "\t" << e.what() << std::endl;
        return;
    }

    // **************************getParamAsDouble()***********************************************************************
    try {
        configuration.addParameter("blah", "16.2");
        configuration.addParameter("yo", "-10.6");

        if (configuration.getParamAsDouble("blah") != 16.2) {
            out << "Failure! configuration.getParamAsDouble(\"blah\") != 16.2) should be false" << std::endl;
        }

        if (configuration.getParamAsDouble("yo") != -10.6) {
            out << "Failure! configuration.getParamAsDouble(\"blah\") != -10.6) should be false" << std::endl;
        }

        if (configuration.getParamAsDouble("a") != 0) {
            out << "Failure! configuration.getParamAsDouble(\"a\") != 0) should be false" << std::endl;
        }

        if (configuration.getParamAsDouble("q") != 16) {
            out << "Failure! configuration.getParamAsDouble(\"q\") != 16) should be false" << std::endl;
        }

        if (configuration.getParamAsDouble("q") == '1') {
            out << "Failure! configuration.getParamAsDouble(\"q\") == 1) should be false" << std::endl;
        }

        if (configuration.getParamAsDouble("q") == 30) {
            out << "Failure! configuration.getParamAsDouble(\"q\") == 30) should be false" << std::endl;
        }

        if (configuration.getParamAsDouble("q") == -16) {
            out << "Failure! configuration.getParamAsDouble(\"q\") == -16) should be false" << std::endl;
        }

        if (configuration.getParamAsDouble("q") == -12) {
            out << "Failure! configuration.getParamAsDouble(\"q\") == -12) should be false" << std::endl;
        }

        if (configuration.getParamAsDouble("q") == 2) {
            out << "Failure! configuration.getParamAsDouble(\"q\") == 2) should be false" << std::endl;
        }

        try {
            configuration.getParamAsDouble("1");
            out << "Failure! configuration.getParamAsDouble(\"1\") should have thrown std::out_of_range" << std::endl;
            return;
        } catch (std::exception e) {
            // do nothing, this is correct
        }

        try {
            configuration.getParamAsDouble("!");
            out << "Failure! configuration.getParamAsDouble(\"!\") should have thrown std::out_of_range" << std::endl;
            return;
        } catch (std::exception e) {
            // do nothing, this is correct
        }

        try {
            configuration.getParamAsDouble("$^");
            out << "Failure! configuration.getParamAsDouble(\"$^\") should have thrown std::out_of_range" << std::endl;
            return;
        } catch (std::exception e) {
            // do nothing, this is correct
        }

        try {
            configuration.getParamAsDouble("asdf");
            out << "Failure! configuration.getParamAsDouble(\"asdf\") should have thrown std::out_of_range"
                << std::endl;
            return;
        } catch (std::exception e) {
            // do nothing, this is correct
        }

    } catch (std::exception e) {
        out << "Failure in testGetters while testing getParamAsDouble:" << std::endl;
        out << "\t" << e.what() << std::endl;
        return;
    }
}

Configuration ConfigurationTester::setUp(std::ostream &out) {
    Configuration configuration;
    char k = 'a';

    for (int i = 0; i < 26; ++i, ++k) {
        std::string key = std::string(1, k);
        if (!configuration.addParameter(key, std::to_string(i))) {
            out << "Failure in ConfigurationTester::setUp" << std::endl;
            exit(1);
        }
    }
    return configuration;
}
