#pragma once
#pragma once
#include "student.h"
using namespace std;

class Roster {
private:
	// Left empty

public:
	// This is the constructor
	Roster();

	// This is the destructor
	~Roster();

	// Pointers started
	Student* classRosterArray[5];

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string removestudentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degree_to_print);
};