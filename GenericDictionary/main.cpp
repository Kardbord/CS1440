#include <iostream>
#include <fstream>
#include "Dictionary.h"

// TODO: write UML
// TODO: write an example in main
int main() {

    // Dictionary object for an English dictionary
    // The key is the word, the value is the definition
    // except I'm too lazy to actually find a dictionary with definitions, and I'm sure not writing my own.
    // so just pretend that each one has a real definition.
    Dictionary<std::string, std::string> dictionary(130000);

    std::ifstream fin("./Dictionary.txt");
    if (!fin) {
        std::cerr << "Could not open input file" << std::endl;
    }

    std::string word;
    std::string definition = "definition goes here"; // Pretend we have real definitions...

    while (fin >> word) {
        dictionary.addKeyValue(word, definition);
    }

    return EXIT_SUCCESS;
}