// Tanner Kvarfordt
// A02052217

#include <cstdlib>
#include <iostream>
#include "Comparer.h"

//TODO add documentation, name, and A number to every file
int main(int argv, char *argc[]) {
    // Declare (and create) a comparer object
    Comparer comparer;
    comparer.load(argv, argc);

    for (auto &&a : comparer.getAnalysts()) {
        std::cout << a.getName() << std::endl;
        for (auto &&h :  a.getSimulations()) {
            std::cout << "Stock Performance: " << std::endl;
            for (auto &&s : comparer.getSymbols()) {
                std::cout << s << std::endl;
                try {
                    std::cout << h.computeStockPerformance(s) << std::endl;
                } catch (const char *msg) { std::cout << msg << std::endl; }
            }
        }
        std::cout << "---------------------------" << std::endl;
    }

    // Have the comparer load all the input files and then do the comparison,
    // which creates the output file
    //if (comparer.load(argv, argc) == 0) comparer.compare();
    return EXIT_SUCCESS;
}
