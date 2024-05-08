#include <iostream>
#include <string>
using namespace std;
#include "roster.h"
#include <cstring>

//Parse Function
void Roster::parse(string studentData) {
	//set studentId
	size_t rhs = studentData.find(",");
	string studentId = studentData.substr(0, rhs);

	//set firstName
	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	//set lastName
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	//set email
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	//set age
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	//set daysInCourse1
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

	//set daysInCourse2
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

	//set daysInCourse3
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs)); 

	//set degree
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string strDegreeProgram = studentData.substr(lhs, rhs - lhs);

	DegreeProgram degreeProgram = DegreeProgram::NETWORK;
	if (strDegreeProgram == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (strDegreeProgram == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (strDegreeProgram == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}

	add(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

//E3 functions
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	
	int numDaysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[lastIndex++] = new Student(studentID, firstName, lastName, emailAddress,
		age, numDaysInCourse, degreeProgram);
}

void Roster::remove(string studentID) {
	bool studentIdFound = false;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) { //this line to screens for null pointers before loop
			if (studentID == classRosterArray[i]->GetStudentId()) {
				classRosterArray[i] = nullptr;
				studentIdFound = true;
			}
		}
	}
	if (studentIdFound == false) {
		cout << "The student with the ID " << studentID << " was not found." << endl;
	}
}

void Roster::printAll() { 
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->Print();
		}
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	int strCompareResult;
	int totalDaysInAllCourses = 0;
	int averageDaysInCourses;
	string idFromRoster;

	for (int i = 0; i < 5; ++i) {
		idFromRoster = classRosterArray[i]->GetStudentId(); 
		strCompareResult = idFromRoster.compare(studentID); 
		if (strCompareResult == 0) {						
			for (int j = 0; j < 3; ++j) {						
				totalDaysInAllCourses += classRosterArray[i]->GetNumDaysToCompleteCourse()[j];
			}
			averageDaysInCourses = totalDaysInAllCourses / 3;
			cout << "Student ID: " << idFromRoster << ", average days in course is: " << averageDaysInCourses << endl;
		}
	}
}

void Roster::printInvalidEmails() {		// search for @, ., and no spaces. 
	string emailBeingChecked;
	for (int i = 0; i < 5; ++i) {
		emailBeingChecked = classRosterArray[i]->GetEmailAddress();
		if ((emailBeingChecked.find('@') == std::string::npos) || (emailBeingChecked.find('.') == std::string::npos) ||
			(emailBeingChecked.find(' ') != std::string::npos)) {
			cout << emailBeingChecked << endl;
		}
	}
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	DegreeProgram degreeProgramToCheck;
	for (int i = 0; i < 5; ++i) {
		degreeProgramToCheck = classRosterArray[i]->GetDegreeProgram();
		if (degreeProgram == degreeProgramToCheck) {
			classRosterArray[i]->Print();
		}
	}
}	

Student* Roster::getStudent(int classRosterIndex) {
	return classRosterArray[classRosterIndex];
}

//Destructor
Roster::~Roster() {
	cout << endl << "Destructor called" << endl;
	for (int i = 0; i < 5; ++i) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
