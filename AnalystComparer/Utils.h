//
// Created by Stephen Clyde on 1/16/17.
//

#ifndef ANALYSTCOMPARER_UTILS_H
#define ANALYSTCOMPARER_UTILS_H

#include <string>
#include <fstream>

bool split(const std::string &s, char delimiter, std::string elements[], int expectedNumberOfElements);

std::string getTrimmedLine(std::ifstream &inputStream);

std::string trim(const std::string &str);

std::string ltrim(const std::string &str);

std::string rtrim(const std::string &str);

bool IsNotWhiteSpace(char ch);

std::string centerString(const std::string &str, int width);

std::string formatDouble(double num, int const &precision = 2, bool const &penniesToDollars = false);

#endif //ANALYSTCOMPARER_UTILS_H
