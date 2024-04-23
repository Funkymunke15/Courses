/*
    Arita, Davis

    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses
*/

#include "CourseList.h"

//Definition function insertInOrder
//Assume there are no duplicates.

void CourseList::insertInOrder(Node* newCourse)
{
    if (this->first == nullptr)
    {
        this->first = newCourse;
        this->last = newCourse;
    }
    else if (this->first->getCourse().getCourseNumber() >
        newCourse->getCourse().getCourseNumber())
    {
        newCourse->setNext(this->first);
        this->first = newCourse;
    }
    else if (newCourse->getCourse().getCourseNumber() >
        this->last->getCourse().getCourseNumber())
    {
        this->last->setNext(newCourse);
        this->last = newCourse;
	}
    else
    {
        Node* current = this->first;
        
		while (current->getNext() != 
            nullptr && 
            current->getNext()->getCourse().getCourseNumber()
            < newCourse->getCourse().getCourseNumber())
		{
			current = current->getNext();
		}
		newCourse->setNext(current->getNext());
		current->setNext(newCourse);
    }
    ++this->count;
}

