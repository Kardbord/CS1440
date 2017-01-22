#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Student.h"
#include "CourseSection.h"
#include "Registration.h"

bool split(const std::string& s, char delimiter, std::string elements[], int expectedNumberOfElements)
{
    std::stringstream ss;
    ss.str(s);
    std::string item;

    int i=0;
    while (std::getline(ss, item, delimiter) && i<expectedNumberOfElements)
    {
        elements[i++] = item;
    }
    return (i==expectedNumberOfElements);
}

Student* students[MAX_STUDENTS];
int studentCount = 0;

Student* findStudent(std::string& aNumber)
{
    Student* student = nullptr;
    for (int i = 0; i < studentCount && student == nullptr; i++)
        if (students[i]->getANumber() == aNumber)
            student = students[i];
    return student;
}

CourseSection* courseSections[MAX_SECTIONS];
int courseSectionCount = 0;

CourseSection* findCourseSection(int id)
{
    CourseSection* courseSection = nullptr;
    for (int i = 0; i < courseSectionCount && courseSection == nullptr; i++)
        if (courseSections[i]->getId() == id)
            courseSection = courseSections[i];
    return courseSection;
}

int main() {

    std::string line;

    // Load student data
    std::ifstream studentInput("Students.csv");
    while (studentInput.is_open() && !studentInput.eof())
    {
        std::getline(studentInput, line);
        std::string fields[3];
        if (split(line, ',', fields, 3))
        {
            students[studentCount++] = new Student(fields[0], fields[1], fields[2]);
        }
    }
    studentInput.close();

    // Load course section data
    std::ifstream sectionInput("CourseSections.csv");
    while (sectionInput.is_open() && !sectionInput.eof())
    {
        std::getline(sectionInput, line);
        std::string fields[3];
        if (split(line, ',', fields, 3))
        {
            int id = std::stoi(fields[0]);
            int credits = std::stoi(fields[1]);
            courseSections[courseSectionCount++] = new CourseSection(id, credits, fields[2]);
        }
    }
    sectionInput.close();

    // Load Registration data
    std::ifstream registrationInput("Registrations.csv");
    while (registrationInput.is_open() && !registrationInput.eof())
    {
        std::getline(registrationInput, line);
        std::string fields[3];
        if (split(line, ',', fields, 3))
        {
            Student* student = findStudent(fields[0]);

            int id = std::stoi(fields[1]);
            CourseSection* courseSection = findCourseSection(id);

            if (student!= nullptr && courseSection!= nullptr)
            {
                Registration* registration = new Registration(student, courseSection, fields[2]);
                student->addRegistration(registration);
                courseSection->addRegistration(registration);
            }
        }
    }
    registrationInput.close();


    // Display Students and GPA's;
    std::cout << "Students" << std::endl;
    std::cout << "========" << std::endl;
    for (int i = 0; i < studentCount; i++)
    {
        std::cout << students[i]->getFirstName() << " " << students[i]->getLastName() << ": " << students[i]->getGpa() << std::endl;
    }
    std::cout << std::endl;

    // Display Course and GPA's
    std::cout << "Course" << std::endl;
    std::cout << "========" << std::endl;
    for (int i = 0; i < courseSectionCount; i++)
    {
        std::cout << courseSections[i]->getName() << ": " << courseSections[i]->getGpa() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}