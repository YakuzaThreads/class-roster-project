#include <iostream>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

// Constructor for the student class
Student::Student() {
	// Initializing the variables
	studentID = "";
	firstName = "";
	lastName = "";
	studentEmail = "";

	// Initializing array of integers for number of days it took to complete courses
	for (int i = 0; i < 3; i++) {
		daysToComplete[i] = i;
	}

	// Setting age variable to zero
	studentAge = 0;

	// Degree program
	degreeProgram = NONE;
}

// Student destructor
Student::~Student() {
	cout << "The student destructor finished running." << endl;
}

// Mutators (setters)
void Student::set_studentID(string new_studentID) { this->studentID = new_studentID; }
void Student::set_firstName(string new_firstName) { this->firstName = new_firstName; }
void Student::set_lastName(string new_lastName) { this->lastName = new_lastName; }
void Student::set_studentEmail(string new_studentEmail) { this->studentEmail = new_studentEmail; }
void Student::set_studentAge(int new_studentAge) { this->studentAge = new_studentAge; }
void Student::set_degreeProgram(DegreeProgram new_degreeProgram) { this->degreeProgram = new_degreeProgram; }

// Mutator (setter) for the daysToComplete
void Student::set_daysToComplete(int* new_day_to_complete) {
	for (int k = 0; k < 3; k++) {
		this->daysToComplete[k] = new_day_to_complete[k];
	}
}

// Ancessors (getters)
string Student::get_studentID() { return this->studentID; }
string Student::get_firstName() { return this->firstName; }
string Student::get_lastName() { return this->lastName; }
string Student::get_studentEmail() { return this->studentEmail; }
int Student::get_studentAge() { return this->studentAge; }
DegreeProgram Student::get_degreeProgram() { return this->degreeProgram; }
int* Student::get_daysToComplete() { return this->daysToComplete; }

void Student::print() {
	cout << this->studentID << "\t" << flush;
	cout << this->firstName << "\t" << flush;
	cout << this->lastName << "\t" << flush;
	cout << this->studentAge << "\t" << flush;

	// Prints daysToComplete
	cout << "{" << this->daysToComplete[0] << ", " << this->daysToComplete[1] << ", " << this->daysToComplete[2] << "}" << " \t" << flush;

	// Dereferences enum
	string print_degree_array[] = { "SECURITY", "NETWORK", "SOFTWARE", "NONE" };
	cout << print_degree_array[this->degreeProgram] << "\t" << endl;
}