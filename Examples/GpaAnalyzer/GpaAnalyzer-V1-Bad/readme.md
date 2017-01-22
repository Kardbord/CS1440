# Grade Analyzer
This is a simple program that read in student, class (i.e., course section), and registration (i.e., transcript) data and then computes:
 1. Each students GPA
 2. Each class's average grade (one a 4.0 scale)

## Version 1
Initial version, not very high quality

## Open Problems
 * The main.cpp contains too much stuff that is not directly related to each other -- It lack cohesion
 * The Student, Registration, and CourseSection are localized into their own files and are therefore not reusable
 * The identifiers for private data members don't follow common C++ style guidelines
 * split is a re-usable piece of code, but is in a reusable place
 * The management of the student list is awkward and introduces some hidden dependencies
 * The management of the courseSection list is awkward and introduces some hidden dependencies
 * Poor UI
 * Redundancy in the logic of main()
 * Hard-coded implementation of ConvertLetterGrad (not extensible or flexible)
 * Hard-coded names for the data files
 * The CourseSection and Registration class and variable could have been identifiers.
 * Class data members, methods, and private variables are not as tightly constrained as they should be
 * There is some parameter passing that is not as effecient as it could be.
 
 