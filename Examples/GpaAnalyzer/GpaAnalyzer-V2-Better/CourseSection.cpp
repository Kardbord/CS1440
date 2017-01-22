//
// Created by Stephen Clyde on 1/10/17.
//

#include <iostream>
#include "CourseSection.h"
#include "Registration.h"

CourseSection::CourseSection(int id, int credits, std::string& name) : _id(id), _credits(credits), _name(name) {}

int CourseSection::getId()
{
    return _id;
}

int CourseSection::getCredits()
{
    return _credits;
}

std::string CourseSection::getName()
{
    return _name;
}

void CourseSection::addRegistration(Registration *registration)
{
    if (_registrationCount>=MAX_STUDENTS)
    {
        std::cout << "Too many students for course " << _id << std::endl;
        return;
    }

    _registrations[_registrationCount++] = registration;
    computeGpa();
}

void CourseSection::computeGpa()
{
    _gpa = 0;

    float points = 0;
    float count = 0;
    for (int i = 0; i < _registrationCount; i++)
    {
        float rawScore = ConvertLetterGradeToScore(_registrations[i]->getLetterGrade());
        points += rawScore;
        count += 1;
    }

    if (count>0)
        _gpa = points / count;
}

float CourseSection::getGpa()
{
    return _gpa;
}

float CourseSection::ConvertLetterGradeToScore(std::string letterGrade)
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
