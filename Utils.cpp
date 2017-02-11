//
// Base code created by Stephen Clyde on 1/16/17.
// Modified by Tanner Kvarfordt on 1/31/17
//

#include <sstream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "Utils.h"

// This function was added by Tanner Kvarfordt on 1/31/17
// Given a double, returns a string of that double with the given precision
std::string formatDouble(double num, int const &precision, bool const &penniesToDollars) {

    if (precision < 0) return std::to_string(num);

    int multiplier = 1;
    for (int i = 0; i < precision; ++i) {
        multiplier *= 10;
    }

    if (penniesToDollars) num /= 100;
    double formattedNum = std::floor(num * multiplier) / multiplier;
    std::string numString = std::to_string(formattedNum);

    int digitsLeftofDec = 1;
    for (int i = 10; i < std::abs(num); i *= 10) {
        ++digitsLeftofDec;
    }

    int cutOffDigit = digitsLeftofDec + precision + 1;

    // we need an additional cutOffDigit if our output is a whole number
    if (std::floor(formattedNum) == formattedNum) ++cutOffDigit;

    if (num > 0) {
        numString.erase((unsigned long long int) cutOffDigit, (unsigned long long int) (cutOffDigit + 1));
    } else { numString.erase((unsigned long long int) cutOffDigit + 1, (unsigned long long int) (cutOffDigit + 2)); }

    return numString;
}

bool split(const std::string &s, char delimiter, std::string elements[], int expectedNumberOfElements) {
    std::stringstream ss;
    ss.str(s);
    std::string item;

    int i = 0;
    while (std::getline(ss, item, delimiter) && i < expectedNumberOfElements) {
        elements[i++] = item;
    }
    return (i == expectedNumberOfElements);
}

std::string getTrimmedLine(std::ifstream &inputStream) {
    std::string line = "";
    if (inputStream.is_open() && !inputStream.eof()) {
        std::getline(inputStream, line);
        line = trim(line);
    }
    return line;
}

//  Note: trim, ltrim, and rtrim were adapted from
//  http://stackoverflow.com/questions/25829143/c-trim-whitespace-from-a-string

// Removes leading and trailing whitespace, include space, tabs, newlines, and returns
std::string trim(const std::string &str) {
    return ltrim(rtrim(str));
}

// Removes leading whitespace, include space, tabs, newlines, and returns
std::string ltrim(const std::string &inputStr) {
    std::string str = inputStr;
    auto it2 = std::find_if(str.begin(), str.end(), IsNotWhiteSpace);
    str.erase(str.begin(), it2);
    return str;
}

// Removes trailing whitespace, include space, tabs, newlines, and returns
std::string rtrim(const std::string &inputStr) {
    std::string str = inputStr;
    auto it1 = std::find_if(str.rbegin(), str.rend(), IsNotWhiteSpace);
    str.erase(it1.base(), str.end());
    return str;
}

// Function to check if a character is a not a whitespace character, namely
//      space (0x20, ' ')
//      form feed (0x0c, '\f')
//      line feed (0x0a, '\n')
//      carriage return (0x0d, '\r')
//      horizontal tab (0x09, '\t')
//      vertical tab (0x0b, '\v')
bool IsNotWhiteSpace(char ch) {
    return !std::isspace<char>(ch, std::locale::classic());
}

std::string centerString(const std::string &str, int width) {
    std::string tmp = str;
    int strLength = (int) tmp.length();
    if (strLength > width)
        tmp.erase((unsigned long long int) width, (unsigned long long int) (strLength - width));
    else if (strLength < width) {
        int paddingLeft = (width - strLength) / 2;
        int paddingRight = width - strLength - paddingLeft;
        tmp.insert(0, (unsigned long long int) paddingLeft, ' ');
        tmp.append((unsigned long long int) paddingRight, ' ');
    }

    return tmp;
}