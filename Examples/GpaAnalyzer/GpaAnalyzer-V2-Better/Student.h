//
// Created by Stephen Clyde on 1/10/17.
//

#ifndef GPAANALYZER_STUDENT_H
#define GPAANALYZER_STUDENT_H

#include <string>

#define MAX_SECTIONS 20

class Registration;

class Student {
private:
    std::string _aNumber;
    std::string _firstName;
    std::string _lastName;
    float _totalCredits = 0;
    float _gpa  = 0;
    Registration* _registrations[MAX_SECTIONS];
    int _registrationCount = 0;

public:
    Student(std::string& aNumber, std::string& firstName, std::string& lastName);
    std::string getANumber();
    std::string getFirstName();
    std::string getLastName();

    void addRegistration(Registration *registration);
    float getGpa();

private:
    void computeGpa();
    float ConvertLetterGradeToScore(std::string letterGrade);
};


#endif //GPAANALYZER_STUDENT_H
