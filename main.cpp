// Tanner Kvarfordt
// A02052217

#include <cstdlib>
#include <iostream>
#include "Comparer.h"

//TODO add documentation, name, and A number to every file
int main(int argv, char *argc[]) {
    // Declare (and create) a comparer object
    Comparer comparer;
    //comparer.load(argv, argc);

    // Have the comparer load all the input files and then do the comparison,
    // which creates the output file
    if (comparer.load(argv, argc) == 0) comparer.compare();
    return EXIT_SUCCESS;
}
