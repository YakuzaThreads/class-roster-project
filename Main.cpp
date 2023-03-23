#include <iostream>
#include "Degree.h"
#include "Roster.h"
#include "Student.h"
using namespace std;

int main()
{
	cout << "Name: Rashad Hussain" << endl;
	cout << "Student ID: 010961737" << endl;
	cout << "C867 Performance Assessment" << endl;
	cout << endl;

	// This creates the roster class
	Roster classRoster;

	// This displays the roster list
	cout << "All Students: \n" << endl;
	classRoster.printAll();
	cout << endl;

	// Invalid email function to display all invalid emails
	cout << "Invalid Emails: \n" << endl;
	classRoster.printInvalidEmails();
	cout << endl;

	// Printing student number of days in three courses by student ID
	classRoster.printAverageDaysInCourse("A1");
	classRoster.printAverageDaysInCourse("A2");
	classRoster.printAverageDaysInCourse("A3");
	classRoster.printAverageDaysInCourse("A4");
	classRoster.printAverageDaysInCourse("A5");
	cout << endl;


	// Print students in the SOFTWARE degree program
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	// Remove Student ID A3 from the roster
	cout << "Removing A3" << endl;
	classRoster.remove("A3");

	// Print updated roster without A3
	classRoster.printAll();
	cout << endl;

	return(0);
	
}