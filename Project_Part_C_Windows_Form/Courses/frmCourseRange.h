/*
	Arita, Davis

	Fall 2022
	CS A250 - C++ 2
	Project: CS Courses
*/

#pragma once

#include "CourseList.h"

namespace Courses {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmCourseRange
	/// </summary>
	public ref class frmCourseRange : public System::Windows::Forms::Form
	{
	public:
		frmCourseRange(void)
		{
			InitializeComponent();
		}

		frmCourseRange(CourseList* list)
		{
			InitializeComponent();

			this->courseList = list;
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmCourseRange()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnRangeSearch;
	private: System::Windows::Forms::TextBox^ txtMinCourseInput;
	private: System::Windows::Forms::TextBox^ txtMaxCourseRange;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button1;



		CourseList* courseList;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnRangeSearch = (gcnew System::Windows::Forms::Button());
			this->txtMinCourseInput = (gcnew System::Windows::Forms::TextBox());
			this->txtMaxCourseRange = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnExit
			// 
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->btnExit->Location = System::Drawing::Point(256, 315);
			this->btnExit->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(124, 49);
			this->btnExit->TabIndex = 0;
			this->btnExit->Text = L"E&xit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &frmCourseRange::btnExit_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->label1->Location = System::Drawing::Point(40, 114);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(193, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Min Course Number:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->label2->Location = System::Drawing::Point(40, 189);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(199, 25);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Max Course Number:";
			// 
			// btnRangeSearch
			// 
			this->btnRangeSearch->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->btnRangeSearch->Location = System::Drawing::Point(40, 315);
			this->btnRangeSearch->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnRangeSearch->Name = L"btnRangeSearch";
			this->btnRangeSearch->Size = System::Drawing::Size(124, 49);
			this->btnRangeSearch->TabIndex = 3;
			this->btnRangeSearch->Text = L"&Search";
			this->btnRangeSearch->UseVisualStyleBackColor = true;
			this->btnRangeSearch->Click += gcnew System::EventHandler(this, &frmCourseRange::btnRangeSearch_Click);
			// 
			// txtMinCourseInput
			// 
			this->txtMinCourseInput->Location = System::Drawing::Point(242, 109);
			this->txtMinCourseInput->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtMinCourseInput->Name = L"txtMinCourseInput";
			this->txtMinCourseInput->Size = System::Drawing::Size(138, 26);
			this->txtMinCourseInput->TabIndex = 4;
			// 
			// txtMaxCourseRange
			// 
			this->txtMaxCourseRange->Location = System::Drawing::Point(243, 185);
			this->txtMaxCourseRange->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtMaxCourseRange->Name = L"txtMaxCourseRange";
			this->txtMaxCourseRange->Size = System::Drawing::Size(136, 26);
			this->txtMaxCourseRange->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(36, 14);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(372, 60);
			this->label3->TabIndex = 6;
			this->label3->Text = L"To search for courses within a certain range, \r\nplease enter a minimum course num"
				L"ber \r\nand a maximum course number between (100-300).";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F));
			this->button1->Location = System::Drawing::Point(256, 225);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 40);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Clear";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmCourseRange::button1_Click);
			// 
			// frmCourseRange
			// 
			this->AcceptButton = this->btnRangeSearch;
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(426, 402);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtMaxCourseRange);
			this->Controls->Add(this->txtMinCourseInput);
			this->Controls->Add(this->btnRangeSearch);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnExit);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"frmCourseRange";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Search Courses in Range";
			this->Load += gcnew System::EventHandler(this, &frmCourseRange::txtCourseRange_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btnRangeSearch_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void txtCourseRange_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);


	private: bool IsPresent(TextBox^ textBox, String^ name)
	{
		if (textBox->Text == "")
		{
			MessageBox::Show(name + " is a required field.", "Entry Error");
			textBox->Focus();
			return false;
		}
		return true;
	}

				// Validator: Text is integer
	private: bool IsInt32(TextBox^ textBox, String^ name)
	{
		try
		{
			Convert::ToInt32(textBox->Text);
			return true;
		}
		catch (FormatException^)
		{
			MessageBox::Show(name + " must be a valid integer.", "Entry Error");
			textBox->Focus();
			return false;
		}
	}

			// Validator: Text is within range
	private: bool IsWithinRange(TextBox^ textBox, String^ name,
		double min, double max)
	{
		double number = Convert::ToDouble(textBox->Text);
		if (number < min || number > max)
		{
			MessageBox::Show(name + " must be between " + min +
				" and " + max + ".", "Entry Error");
			textBox->Focus();
			return false;
		}
		return true;
	}

};
}
