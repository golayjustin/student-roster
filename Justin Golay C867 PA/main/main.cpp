#include "roster.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	int i = 0;
	string separatedStudentData[5];

	//Step A
	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Justin,Golay,jgolay@wgu.edu,29,20,22,60,SOFTWARE" };

	//Step F1
	cout << "C867: Scripting and Programming - Applications" << endl << "Programming Language: C++"
		<< endl << "Student ID: #010176782" << endl << "Justin Golay" << endl << endl;

	//Step F2		
	Roster classRoster;
	
	for (i = 0; i < 5; ++i) {
		classRoster.parse(studentData[i]);
	}
	
	cout << "Displaying all students:" << endl;
	classRoster.printAll();
	cout << endl;

	cout << "Displaying invalid emails" << endl << endl;
	classRoster.printInvalidEmails(); 
	cout << endl;

	
	for (int i = 0; i < 5; ++i) {
		string studentId = classRoster.getStudent(i)->GetStudentId();
		classRoster.printAverageDaysInCourse(studentId);
	} 
	cout << endl;

	cout << "Showing students in degree program: SOFTWARE" << endl;
	classRoster.printByDegreeProgram(SOFTWARE); 
	cout << endl;

	classRoster.remove("A3");

	cout << "Removing A3" << endl;
	classRoster.printAll(); 
	cout << endl;
	
	cout << "Removing A3 again" << endl;
	classRoster.remove("A3"); 



	
	return 0;
}
