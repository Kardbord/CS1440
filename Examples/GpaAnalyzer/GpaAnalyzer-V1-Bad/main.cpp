#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#define MAX_STUDENTS 100
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
};

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
};

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

float ConvertLetterGradeToScore(std::string letterGrade)
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