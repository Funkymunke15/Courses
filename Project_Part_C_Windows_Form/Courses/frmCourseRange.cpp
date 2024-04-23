/*
	Arita, Davis

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#include "frmCourseRange.h"
#include "CourseList.h"
#include "Course.h"

	//load
System::Void Courses::frmCourseRange::txtCourseRange_Load(System::Object^ sender, System::EventArgs^ e)
{
	this->txtMinCourseInput->Text = "";
	this->txtMaxCourseRange->Text = "";
}

System::Void Courses::frmCourseRange::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	txtMinCourseInput->Clear();
	txtMaxCourseRange->Clear();
}

	//exit button
System::Void Courses::frmCourseRange::btnExit_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
	
}

	//search button
System::Void Courses::frmCourseRange::btnRangeSearch_Click(System::Object^ sender, System::EventArgs^ e)
{
	if(IsPresent(txtMinCourseInput, "Minimum Course Number")&&
		IsInt32(txtMinCourseInput, "Minimum Course Number")&&
		IsWithinRange(txtMinCourseInput, "Minimum Course Number", 100, 300))
	{
		int rangeMin = Convert::ToInt32(txtMinCourseInput->Text);

		if (IsPresent(txtMaxCourseRange, "Maximum Course Number") &&
			IsInt32(txtMaxCourseRange, "Maximum Course Number") &&
			IsWithinRange(txtMaxCourseRange, "Maximum Course Number", 100, 300))
		{
			int rangeMax = Convert::ToInt32(txtMaxCourseRange->Text);

			if (rangeMax < rangeMin)
			{
				int tempNum = rangeMax;
				rangeMax = rangeMin;
				rangeMin = tempNum;
			}

			CourseList inRange;
								
			for (int i = rangeMin; i < (rangeMax + 1); i++)
			{
				Course temp;
				if (courseList->searchCourse(i, temp))
				{
					inRange.addCourse(temp);
				}
			}
			if (inRange.getNumberOfCourses() == 0)
			{
				MessageBox::Show("No courses exist within the range entered.\nPlease try again.", "Error");
			}
			else
			{
				std::string input;
				inRange.retrieveAllCourses(input);
				String^ str = gcnew String(input.c_str());

				MessageBox::Show(str, "Courses within range");
			}			
		}
	}
}


