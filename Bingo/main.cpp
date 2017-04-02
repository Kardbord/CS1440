#include <iostream>
#include <ctime>

#include "UserInterface.h"

// TODO: make sure all getters are const
int main() {

    // Initialize the random number generator
    unsigned int seed = (unsigned int) time(NULL);
    srand(seed);

    // Create a UI object and run it
    UserInterface ui;
    ui.run();
}