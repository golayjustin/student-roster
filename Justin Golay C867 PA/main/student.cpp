#include "student.h"
#include <string>
#include <iostream>
using namespace std;

//Constructors with default assignments
Student::Student() {
	this->studentId = "NoID";
	this->firstName = "NoFName";
	this->lastName = "NoLName";
	this->emailAddress = "NoEmail";
	this->age = -1; 
	for (int i = 0; i < 3; ++i) {
		this->numDaysToCompleteCourse[i] = 0;
	}
	this->degreeProgram = DegreeProgram::NETWORK;
}
Student::Student(string studentId = "NoID", string firstName = "NoFName", string lastName = "NoLName",
	string emailAddress = "NoEmail", int age = -1, int numDaysToCompleteCourse[3] = {nullptr}, 
	DegreeProgram degreeProgram = DegreeProgram::NETWORK) {
	
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < 3; ++i) {
		this->numDaysToCompleteCourse[i] = numDaysToCompleteCourse[i];
	}
	this->degreeProgram = degreeProgram;
}

//Accessor functions
string Student::GetStudentId() const {
	return this->studentId;
}
string Student::GetFirstName() const {
	return this->firstName;
}
string Student::GetLastName() const {
	return this->lastName;
}
string Student::GetEmailAddress() const {
	return this->emailAddress;
}
int Student::GetAge() const {
	return this->age;
}
int* Student::GetNumDaysToCompleteCourse() { 
	return this->numDaysToCompleteCourse;
}
DegreeProgram Student::GetDegreeProgram() const {
	return this->degreeProgram;
}

//Mutator functions
void Student::SetStudentId(string studentId) {
	this->studentId = studentId;
}
void Student::SetFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::SetLastName(string lastName) {
	this->lastName = lastName;
}
void Student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::SetAge(int age) {
	this->age = age;
}

void Student::SetNumDaysToCompleteCourse(int numDaysInCourse[]) { 
	for (int i = 0; i < 3; ++i) {
		this->numDaysToCompleteCourse[i] = numDaysInCourse[i];
	}
}
void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

void Student::Print() {	
	cout << this->studentId << "\t";
	cout << "First Name: " << this->firstName << "\t";
	cout << "Last Name: " << this->lastName << "\t";
	cout << "Age: " << this->age << "\t";
	cout << "daysInCourse: {";
	cout << this->numDaysToCompleteCourse[0] << ",";
	cout << this->numDaysToCompleteCourse[1] << ",";
	cout << this->numDaysToCompleteCourse[2];
	cout << "}" << "\t";
	cout << "Degree Program: " << degreeProgramStrings[(int)this->degreeProgram];
	cout << endl;
}