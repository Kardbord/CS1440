#include <iostream>
#include <fstream>
#include <locale>
#include <sstream>
#include "Dictionary.h"

std::stringstream toUpper(std::string const &s);

std::string prompt(bool &cont);

// TODO: write UML
// TODO: write an example in main
int main() {

    // A non-comprehensive list of nations in the world
    Dictionary<std::string, std::string> nations(150);

    std::ifstream fin("./countrynames.txt");
    if (!fin) {
        std::cerr << "Could not open input file" << std::endl;
        return EXIT_FAILURE;
    }

    std::string nation = "";
    std::string about = "info about country goes here"; // Pretend we have info...

    while (!fin.eof()) {
        std::getline(fin, nation);
        nations.addKeyValue(toUpper(nation).str(), about);
    }

    bool cont = true;
    while (cont) {
        std::string input = prompt(cont);
        if (cont) {
            try {
                std::string def = nations.getByKey(input).getValue();
                std::cout << input << ": " << def << std::endl;
            } catch (std::exception e) {
                std::cout << "Sorry, could not find that nation." << std::endl << std::endl;
            }
        }
    }

    return EXIT_SUCCESS;
}

std::stringstream toUpper(std::string const &s) {
    std::stringstream ss;

    std::locale loc;
    for (std::string::size_type i = 0; i < s.length(); ++i) {
        ss << std::toupper(s[i], loc);
    }
    return ss;
}

std::string prompt(bool &cont) {
    std::string input = "";
    std::cout << "What would you like to do?\n"
              << "\t-  (S)earch for a nation\n"
              << "\t-  (E)xit" << std::endl;

    std::cin >> input;
    std::cin.ignore();

    if (input == "S" || input == "s" || input == "Search") {
        std::string word;
        std::cout << "Enter a nation to search for (enter to return to menu):";
        std::getline(std::cin, word);

        if (word != "") {
            return toUpper(word).str();
        } else {
            std::cout << std::endl << std::endl;
            return toUpper(prompt(cont)).str();
        }
    } else if (input == "E" || input == "e" || input == "Exit") {
        cont = false;
        return "";
    } else {
        std::cout << "Invalid input, try again!" << std::endl;
        return toUpper(prompt(cont)).str();
    }
}