# Grade Analyzer
This is a simple program that read in student, class (i.e., course section), and registration (i.e., transcript) data and then computes:
 1. Each students GPA
 2. Each class's average grade (one a 4.0 scale)

## Version 1
Initial version, not very high quality

## Version 2
The functionality is the same as Version 1, but makes some improvements to the code.
 * Moved the declaration of the Student class to Student.h and the implementation to Student.cpp
 * Moved the declaration of the CourseSection class to CourseSection.h and the implementation to CourseSection.cpp
 * moved the declaration of the Registration class to Registration.h and the implementation moved to Registration.cpp
 * Added a prototype declaration for Registration to Student.h and CourseSection.h
 * Added prototypes declarations for Student and CourseSection to Registration.h
 * Added the ConvertLetterGradeToScore function to both the Student and CourseSection class. (Yes, this is not a great solution because it duplicates the code.  We'll solve this a better duplicate code problem later.)

## Some Remaining Problems
 * The identifiers for private data members don't follow common C++ style guidelines
 * split is a re-usable piece of code, but is in a reusable place
 * The ConvertLetterGrade functionality exists in two places
 * The management of the student list is awkward and introduces some hidden dependencies
 * The management of the courseSection list is awkward and introduces some hidden dependencies
 * Poor UI
 * Redundancy in the logic of main()
 * Hard-coded implementation of ConvertLetterGrad (not extensible or flexible)
 * Hard-coded names for the data files
 * The CourseSection and Registration class and variable could have been identifiers.
 * Class data members, methods, and private variables are not as tightly constrained as they should be
 * There is some parameter passing that is not as effecient as it could be.

 
 