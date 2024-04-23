/*
    Arita, Davis

    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses
*/

#include "Course.h"

#include <iostream>
#include <iomanip>
using namespace std;

const string Course::PREFIX = "CS A";

//Definition overloaded constructor
Course::Course(int courseNum, const std::string& Name, int unitNum,
    const std::set<int>& prereq) 
{
    this->courseNumber = courseNum;
    this->courseName = Name;
    this->courseUnits = unitNum;
    this->prereqs = prereq;
}

//Definition function getCourseName
const string& Course::getCourseName() const
{
    return this->courseName;
}

//Definition function getCourseNumber
int Course::getCourseNumber() const
{
    return this->courseNumber;
}

//Definition function getCourseUnits
int Course::getCourseUnits() const
{
    return this->courseUnits;
}

//Definition function getPrereqs
const std::set<int>& Course::getCoursePrereqs() const
{
    return this->prereqs;
}

//Definition function getCourse
const Course& Course::getCourse() const
{
    return *this;
}

//Definition function getPrefix
string Course::getPrefix()
{
    return PREFIX;
}

//Definition function setCourseName
void Course::setCourseName(const string& newName)
{
    this->courseName = newName;
}

//Definition funtion setCourseNumber
void Course::setCourseNumber(int newNum)
{
    this->courseNumber = newNum;
}

//Definition function setCourseUnits
void Course::setCourseUnits(int newUnits)
{
    this->courseUnits = newUnits;
}

//Definition function setPrereqs
void Course::setPrereqs(const int listOfPrereqs[], int numOfPrereqs)
{
    this->prereqs.clear();
    for (int i = 0; i < numOfPrereqs; ++i)
    {
        this->prereqs.insert(listOfPrereqs[i]);
    }
}

