//
// Created by Stephen Clyde on 1/10/17.
//

#ifndef GPAANALYZER_REGISTRATION_H
#define GPAANALYZER_REGISTRATION_H

#include <string>

class Student;
class CourseSection;

class Registration
{
private:
    Student* _student;
    CourseSection* _courseSection;
    std::string _letterGrade;

public:
    Registration(Student* student, CourseSection* courseSection, std::string letterGrade);
    Student* getStudent();
    CourseSection* getCourseSection();
    std::string getLetterGrade();
};

#endif //GPAANALYZER_REGISTRATION_H
