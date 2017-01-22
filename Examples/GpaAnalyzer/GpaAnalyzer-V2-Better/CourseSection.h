//
// Created by Stephen Clyde on 1/10/17.
//

#ifndef GPAANALYZER_COURSESECTION_H
#define GPAANALYZER_COURSESECTION_H

#include <string>

#define MAX_STUDENTS 100

class Registration;

class CourseSection {
private:
    int _id;
    int _credits;
    std::string _name;
    float _gpa;
    Registration* _registrations[MAX_STUDENTS];
    int _registrationCount = 0;

public:
    CourseSection(int id, int credits, std::string& name);
    int getId();
    int getCredits();
    std::string getName();

    void addRegistration(Registration *registration);
    float getGpa();

private:
    void computeGpa();
    float ConvertLetterGradeToScore(std::string letterGrade);
};

#endif //GPAANALYZER_COURSESECTION_H
