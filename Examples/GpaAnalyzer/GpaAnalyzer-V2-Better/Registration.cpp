//
// Created by Stephen Clyde on 1/10/17.
//

#include "Registration.h"

Registration::Registration(Student* student, CourseSection* courseSection, std::string letterGrade) :
        _student(student),
        _courseSection(courseSection),
        _letterGrade(letterGrade) {}

Student* Registration::getStudent()
{
    return _student;
}

CourseSection* Registration::getCourseSection()
{
    return _courseSection;
}

std::string Registration::getLetterGrade()
{
    return _letterGrade;
}
