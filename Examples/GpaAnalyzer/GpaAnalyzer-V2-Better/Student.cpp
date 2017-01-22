//
// Created by Stephen Clyde on 1/10/17.
//

#include <iostream>
#include "Student.h"
#include "CourseSection.h"
#include "Registration.h"

Student::Student(std::string& aNumber, std::string& firstName, std::string& lastName) :
        _aNumber(aNumber),
        _firstName(firstName),
        _lastName(lastName),
        _gpa(0) {}

std::string Student::getANumber()
{
    return _aNumber;
}

std::string Student::getFirstName()
{
    return _firstName;
}

std::string Student::getLastName()
{
    return _lastName;
}

void Student::addRegistration(Registration *registration)
{
    if (_registrationCount>=MAX_SECTIONS)
    {
        std::cout << "Too many _registrations for a student " << _aNumber << std::endl;
        return;
    }

    _registrations[_registrationCount++] = registration;
    computeGpa();
}

void Student::computeGpa()
{
    _gpa = 0;
    _totalCredits = 0;

    float points = 0;
    for (int i = 0; i < _registrationCount; i++)
    {
        float rawScore = ConvertLetterGradeToScore(_registrations[i]->getLetterGrade());
        float credits = _registrations[i]->getCourseSection()->getCredits();
        float weightedScore = rawScore*credits;
        points += weightedScore;
        _totalCredits += credits;
    }

    if (_totalCredits>0)
        _gpa = points / _totalCredits;
}

float Student::getGpa()
{
    return _gpa;
}

float Student::ConvertLetterGradeToScore(std::string letterGrade)
{
    float result = 0;

    if (letterGrade=="A") result = 4.0;
    else if (letterGrade=="A-") result = 3.67;
    else if (letterGrade=="B+") result = 3.33;
    else if (letterGrade=="B") result = 3.00;
    else if (letterGrade=="B-") result = 2.67;
    else if (letterGrade=="C+") result = 2.33;
    else if (letterGrade=="C") result = 2.00;
    else if (letterGrade=="C-") result = 1.67;
    else if (letterGrade=="D+") result = 1.33;
    else if (letterGrade=="D") result = 1.00;
    else if (letterGrade=="D-") result = 0.67;

    return result;
}
