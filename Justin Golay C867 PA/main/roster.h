#pragma once
using namespace std;
#include <string>
#include "student.h"

class Roster {
	private:
		int lastIndex = 0;
		Student* classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};
	public:
		//Parse Function
		void parse(string studentData);

		//E3 functions
		void add(string studentID, string firstName, string lastName, string emailAddress, int age,
			int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
		void remove(string studentID);
		void printAll();
		void printAverageDaysInCourse(string studentID);
		void printInvalidEmails();
		void printByDegreeProgram(DegreeProgram degreeProgram);

		//Accessor functions
		Student* getStudent(int ClassRosterIndex);
		
		//Destructor
		~Roster();
};