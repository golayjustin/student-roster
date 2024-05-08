#pragma once
using namespace std;
#include <string>
#include "degree.h"

//Step D1 and D2 - set variables and functions
class Student {
	private:
		string studentId; 
		string firstName;
		string lastName;
		string emailAddress;
		int age = 0;
		int numDaysToCompleteCourse[3];
		DegreeProgram degreeProgram;
	public:
		//Constructors
		Student();
		Student(string studentId, string firstName, string lastName, string emailAddress, 
			int age, int numDaysToCompleteCourse[], DegreeProgram degreeProgram);

		//Accessor functions
		string GetStudentId() const; 
		string GetFirstName() const;
		string GetLastName() const;
		string GetEmailAddress() const;
		int GetAge() const;
		int* GetNumDaysToCompleteCourse();
		DegreeProgram GetDegreeProgram() const;
		
		//Mutator functions
		void SetStudentId(string studentId);
		void SetFirstName(string firstName);
		void SetLastName(string lastName);
		void SetEmailAddress(string emailAddress);
		void SetAge(int age);
		void SetNumDaysToCompleteCourse(int numDaysInCourse[]);
		void SetDegreeProgram(DegreeProgram degreeProgram);

		//Print function
		void Print();
};
