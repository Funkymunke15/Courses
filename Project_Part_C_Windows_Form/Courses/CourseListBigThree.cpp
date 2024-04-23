/*
	Arita, Davis

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#include "CourseList.h"
#include <iostream>
//copy constructor
CourseList::CourseList(const CourseList& otherList)
{
	if (otherList.count == 0)
	{
		this->first = nullptr;
		this->last = first;
		this->count = 0;
	}
	else
	{
		Node* otherListCurrent = otherList.first;
		this->first = new Node(otherListCurrent->getCourse(), nullptr);

		Node* current = this->first;
		while (otherListCurrent->getNext() != nullptr)
		{
			otherListCurrent = otherListCurrent->getNext();
			current->setNext(new  Node(otherListCurrent->getCourse(), nullptr));
			current = current->getNext();
		}
		this->last = current;
	}
	this->count = otherList.count;
}


//Definition overloaded assignment operator
CourseList& CourseList::operator=(const CourseList& otherList)
{
	if (&otherList == this)
	{
		std::cerr << "Attempted assignment to itself." << std::endl;
	}
	else if (otherList.count == 0 && this->count != 0)
	{
		this->clearList();
	}
	else if (this->count == 0 && otherList.count != 0)
	{
		this->copyCallingObjIsEmpty(otherList);
	}
	else if (this->count == otherList.count)
	{
		this->copyObjectsSameLength(otherList);
	}
	else if (this->count < otherList.count)
	{
		this->copyCallingObjShorter(otherList);
	}
	else if (this->count > otherList.count)
	{
		this->copyCallingObjLonger(otherList);
	}
	else if (this->count == 0)
	{
		this->clearList();
	}
	return *this;
}
//Definition function copyCallingObjectIsEmpty
void CourseList::copyCallingObjIsEmpty(const CourseList& otherList)
{
	Node* current = otherList.first;
	while (current != nullptr)
	{
		this->insertInOrder(current);
		this->last = current;
		this->count++;
	}
}

//Definition function copyObjectsSameLength
void CourseList::copyObjectsSameLength(const CourseList& otherList)
{
	Node* current = this->first;
	Node* otherListCurrent = otherList.first;
	while (current != nullptr)
	{
		current->setCourse(otherListCurrent->getCourse());
		otherListCurrent = otherListCurrent->getNext();
		current = current->getNext();
	}
}

//Definition function copyCallingObjLonger
void CourseList::copyCallingObjLonger(const CourseList& otherList)
{
	Node* otherListCurrent = otherList.first;
	Node* current = this->first;
	current->setCourse(otherListCurrent->getCourse());

	while (otherListCurrent->getNext() != nullptr)
	{
		current->getNext()->setCourse(otherListCurrent->getNext()->getCourse());

		otherListCurrent = otherListCurrent->getNext();
		current = current->getNext();
	}
	this->last = current;
	this->count = otherList.count;
	delete current->getNext();
	current->setNext(nullptr);
}


//Definition function copyCallingObjShorter
void CourseList::copyCallingObjShorter(const CourseList& otherList)
{
	Node* otherListCurrent = otherList.first;
	Node* current = this->first;

	while (otherListCurrent != nullptr)
	{
		if (current == nullptr)
		{
			addCourse(otherListCurrent->getCourse());
		}
		else
		{
			current->setCourse(otherListCurrent->getCourse());
			current = current->getNext();
		}
		otherListCurrent = otherListCurrent->getNext();
	}
	this->count = otherList.count;
}

//Destructor
CourseList::~CourseList()
{
	if (this->first != nullptr)
	{
		this->clearList();
	}

}