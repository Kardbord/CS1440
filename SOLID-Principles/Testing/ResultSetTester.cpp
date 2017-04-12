//
// Created by Tanner on 4/10/2017.
//

#include <fstream>
#include "ResultSetTester.h"


void ResultSetTester::testConstructorInheritance(std::ostream &out) const {
    out << "ResultSetTester::testConstructorInheritance" << std::endl;

    std::vector<std::string> container;
    char filler = 'a';
    for (int i = 0; i < 26; ++i, ++filler) {
        container.push_back(std::string(1, filler));
    }

    std::vector<std::string> container1;
    for (int i = 0; i < 26; ++i, ++filler) {
        container1.push_back(std::string(1, filler));
    }

    std::vector<std::string> container2;
    for (int i = 0; i < 26; ++i, ++filler) {
        container2.push_back(std::string(1, filler));
    }

    ResultSet first;

    first["a"] = container;
    first["b"] = container1;
    first["c"] = container2;

    if (first.size() != 3) {
        out << "Failure! first.getSize() should be 3" << std::endl;
        return;
    }

    ResultSet second(first);

    if (second.size() != 3) {
        out << "Failure! second.getSize() should be 3" << std::endl;
        return;
    }

    if (first.at("a") != second.at("a")) {
        out << "Failure! first.at(\"a\") != second.at(\"a\") should be false" << std::endl;
    }
    if (first.at("b") != second.at("b")) {
        out << "Failure! first.at(\"b\") != second.at(\"b\") should be false" << std::endl;
    }
    if (first.at("c") != second.at("c")) {
        out << "Failure! first.at(\"c\") != second.at(\"c\") should be false" << std::endl;
    }

}

void ResultSetTester::testPrint(std::ostream &out) const {
    out << "ResultSetTester::testPrint -- see printTest.txt" << std::endl;

    std::vector<std::string> container;
    char filler = 'a';
    for (int i = 0; i < 26; ++i, ++filler) {
        container.push_back(std::string(1, filler));
    }

    std::vector<std::string> container1;
    for (int i = 0; i < 26; ++i, ++filler) {
        container1.push_back(std::string(1, filler));
    }

    std::vector<std::string> container2;
    for (int i = 0; i < 26; ++i, ++filler) {
        container2.push_back(std::string(1, filler));
    }

    ResultSet resultSet;

    resultSet["a"] = container;
    resultSet["b"] = container1;
    resultSet["c"] = container2;

    std::ofstream fout("printTest.txt");
    if (!fout) {
        out << "Failure in creating output file in testPrint" << std::endl;
        return;
    }

    resultSet.print(fout);
    fout.close();
}
