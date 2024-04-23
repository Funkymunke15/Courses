/*
	Arita, Davis

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#include "CourseList.h"

#include <iostream>
using namespace std;

//Definition function addCourse
void CourseList::addCourse(const Course& newCourse)
{
	this->insertInOrder(new Node(newCourse, nullptr));
}

//Definition function addCourse
void CourseList::addCourse(int courseNum, const std::string& courseName,
	int courseUnits, const std::set<int>& prereqs)
{
	this->insertInOrder(new Node(Course(courseNum,
		courseName, courseUnits, prereqs), nullptr));
}

//Definition function getPrefix
string CourseList::getPrefix() const
{
	return Course::getPrefix();
}

//Definition function getNumberOfCourses
int CourseList::getNumberOfCourses() const
{
	return this->count;
}

//Definition function isEmpty
bool CourseList::isEmpty() const
{
	return this->count == 0;
}

//Definition function searchCourse(coursenumber)
//assume list is non-empty
bool CourseList::searchCourse(int courseNum)
{
	return this->getCourseLocation(courseNum) != nullptr;
}

//Definition functino searchCourse(courseNumber, courseName)
//Assume list is non-empty
bool CourseList::searchCourse(int courseNumber, 
	std::string& courseName) const
{
	Node* location = this->getCourseLocation(courseNumber);
	if (location != nullptr)
	{
		courseName = location->getCourse().getCourseName();
		return true;
	}
	else
	{
		courseName = "Not Found";
		return false;
	}
}
//Definitino function searchCourse(courseNumber, course)
//Assume list is non-empty
bool CourseList::searchCourse(int courseNumber, Course& courseKey) const
{
	Node* location = this->getCourseLocation(courseNumber);
	if (location != nullptr)
	{
		courseKey = location->getCourse().getCourse();
		return true;
	}
	else
		return false;
}

//Definition delete course
//Assume is is non-empty
//Assume course is in the list.
void CourseList::deleteCourse(int courseNum)
{
	if (this->first->getCourse().getCourseNumber() == courseNum)
	{
		Node* temp = this->first;
		this->first = this->first->getNext();
		delete temp;
		temp = nullptr;
	}
	else
	{
		Node* current = this->first->getNext();
		Node* prev = this->first;
		while (current != nullptr)
		{
			if (current->getCourse().getCourseNumber() == courseNum)
			{
				prev->setNext(current->getNext());
				delete current;
				current = nullptr;
			}
			else
			{
				prev = current;
				current = current->getNext();
			}
		}
	}
	--this->count;
}

//Definition retrieveAllCourses
//Assume list is non-empty.
void CourseList::retrieveAllCourses(std::string& courses) const
{
	courses = "";
	Node* current = this->first;
	while (current != nullptr)
	{
		
		courses += current->getCourse().getPrefix() +
			to_string(current->getCourse().getCourseNumber())
			+ " - " + current->getCourse().getCourseName() + "\n";
		current = current->getNext();
	}	
}

//Definition clearList
void CourseList::clearList()
{
	Node* head = this->first;
	Node* temp = head;
	while (head != nullptr)
	{
		temp = head->getNext();
		delete head;
		head = temp;
	}
	this->first = nullptr;
	this->last = nullptr;
	this->count = 0;
}

//Definition fuunction getCourseLocation
Node* CourseList::getCourseLocation(int courseNum) const
{
	if (this->first->getCourse().getCourseNumber() == courseNum)
	{
		return this->first;
	}
	else if (this->last->getCourse().getCourseNumber() == courseNum)
	{
		return this->last;
	}
	else
	{
		Node* current = this->first->getNext();
		while (current != nullptr)
		{
			if (current->getCourse().getCourseNumber() == courseNum)
			{
				return current;
			}
			else
			{
				current = current->getNext();
			}
		}
	}
	return nullptr;
}