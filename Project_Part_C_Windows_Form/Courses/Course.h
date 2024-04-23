/*
    Arita, Davis

    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses
*/

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <set>

class Course
{
public:
    //Constructors
    Course() : courseNumber(0), courseName("N/A"), courseUnits(0) {}
    Course(int courseNum, const std::string& Name, int unitNum,
        const std::set<int>& prereq); 

    // accessor functions
    const std::string& getCourseName() const;
    int getCourseNumber() const;
    int getCourseUnits() const;
    const std::set<int>& getCoursePrereqs() const;
    const Course& getCourse() const;
    static std::string getPrefix();

    // mutator functions
    void setCourseName(const std::string& newName);
    void setCourseNumber(int newNum);
    void setCourseUnits(int newUnits);
    void setPrereqs(const int pre[], int numofPrereqs);

    //Destructor
    ~Course() {}

private:
    int courseNumber;
    std::string courseName;
    int courseUnits;
    std::set<int> prereqs;
    static const std::string PREFIX;
};

#endif#
