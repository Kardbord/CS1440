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

    std::vector<Analyst> test = comparer.getAnalysts();

    for (auto &&e : test) {
        std::cout << e.getName() << ": " << e.getInitials() << std::endl;
        std::vector<History> histories = e.getSimulations();
        for (auto &&f : histories) {
            std::cout << "numRecords: " << f.getNumRecords() << std::endl
                      << "simDays: " << f.getSimDays() << std::endl
                      << "seed: " << f.getSeedMoney() << std::endl;
            std::vector<PurchaseSaleRecord> recs = f.getRecords();
            for (auto &&g : recs) {
                std::cout << g.getCompany() << std::endl;
            }
        }
        std::cout << "-----------------------------------" << std::endl;
    }

    // Have the comparer load all the input files and then do the comparison,
    // which creates the output file
    //if (comparer.load(argv, argc) == 0) comparer.compare();
    return EXIT_SUCCESS;
}
