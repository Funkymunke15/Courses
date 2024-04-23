/*
	Arita, Davis

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"

#include <string>
#include <set>

class Node
{
public:
	Node() : course(), next(nullptr) {}
	Node(const Course& newCourse, Node* newNext)
		: course(newCourse), next(newNext) {}
	Course getCourse() const { return course; } 
	Node* getNext() const { return next; }
	void setCourse(const Course& newCourse) { course = newCourse; }
	void setNext(Node* newNext) { next = newNext; }
	~Node() {}

private:
	Course course;
	Node* next;
};

class CourseList
{
public:
	//Default construtor
	CourseList() : first(nullptr), last(nullptr), count(0) {}
	//Functions addCourse
	void addCourse(const Course& newCourse);
	void addCourse(int courseNum, const std::string& courseName, 
		int courseUnits, const std::set<int>& prereqs) ;
	
	//accessor functions
	std::string getPrefix() const;
	int getNumberOfCourses() const;

	//boolean functions
	bool isEmpty() const;
	bool searchCourse(int couresToSearchFor);
	bool searchCourse(int courseToSearchFor,
		std::string& courseName) const;
	bool searchCourse(int courseToSearchFor, 
		Course& courseKey) const;
	
	//Funtion deleteCourse
	void deleteCourse(int courseNum);
	
	//Function retrieveAllCourses
	void retrieveAllCourses(std::string& courses) const;

	//Function clearList
	void clearList();

	/********************* THE BIG THREE *********************/

	//copy Construcor
	CourseList(const CourseList& param);

	//Overloaded assingment operator
	CourseList& operator=(const CourseList& param);
	//destructor
	~CourseList();

private:
	//Function getCourseLocation
	Node* getCourseLocation(int courseNum) const;

	//Function addInOrder
	void insertInOrder(Node* nodeToAdd);
	
	//Helper functions for overloaded assignment operator
	void copyCallingObjIsEmpty(const CourseList& param);
	void copyObjectsSameLength(const CourseList& param);
	void copyCallingObjLonger(const CourseList& param);
	void copyCallingObjShorter(const CourseList& param);

	Node* first;
	Node* last;
	int count;
};

#endif
