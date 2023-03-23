#pragma once
#include "Degree.h"
using namespace std;

// Defining the student class
class Student {

private:
	string studentID, firstName, lastName, studentEmail;
	int studentAge;
	// Int array for the days to complete
	int daysToComplete[3];
	DegreeProgram degreeProgram;

public:
	// This is the constructor
	Student();
	// The destructor
	~Student();

	// Defining set methods for each class
	void set_studentID(string new_studentID);
	void set_firstName(string new_firstName);
	void set_lastName(string new_lastName);
	void set_studentEmail(string new_studentEmail);
	void set_studentAge(int new_studentAge);
	void set_degreeProgram(DegreeProgram newDegreeProgram);
	void set_daysToComplete(int* new_daysToComplete);

	// Using an ancessor (getters)
	string get_studentID();
	string get_firstName();
	string get_lastName();
	string get_studentEmail();
	int get_studentAge();
	DegreeProgram get_degreeProgram();
	int* get_daysToComplete();

	// Print method
	void print();

};