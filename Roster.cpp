#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "roster.h"
#include "degree.h"
using namespace std;

const string studentData[] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Rashad,Hussain,rhuss26@wgu.edu,21,21,47,30,SOFTWARE"
};

// This is the string for dereferencing the enum
string degree_array[] = { "SECURITY", "NETWORK", "SOFTWARE", "NONE" };

// This determines the table size that will be used in loop increases
int table_size = sizeof(studentData) / sizeof(string);

// Constructor for roster object
Roster::Roster() {
	// The code inserts a new student into every element of the pointer array and adds the information from the studentData.
	for (int i = 0; i < table_size; i++) {
		classRosterArray[i] = new Student;

		// Temporary parsing variable
		string temp_student_id, temp_first_name, temp_last_name, temp_student_email, age_string, day0_string, day1_string, day2_string, degree_string;
		int temp_student_age, temp_day0, temp_day1, temp_day2;
		DegreeProgram temp_degree = NONE;

		int temp_day_to_complete[3];

		// A stringstream will store a single line from the studentData table
		stringstream input_stream;
		input_stream << studentData[i];

		char delimit = ',';

		// Will create a temp student object in order to parse string data
		Student* ptr_student;
		ptr_student = new Student;

		// Involves taking every item that is separated by the delimiter from the stringstream, then utilizing the setter method of the student object to set each item
		getline(input_stream, temp_student_id, delimit);
		ptr_student->set_studentID(temp_student_id);

		getline(input_stream, temp_first_name, delimit);
		ptr_student->set_firstName(temp_first_name);

		getline(input_stream, temp_last_name, delimit);
		ptr_student->set_lastName(temp_last_name);

		getline(input_stream, temp_student_email, delimit);
		ptr_student->set_studentEmail(temp_student_email);

		getline(input_stream, age_string, delimit);
		temp_student_age = stoi(age_string);
		ptr_student->set_studentAge(temp_student_age);

		// Gathers total number of days to complete all three classes
		getline(input_stream, day0_string, delimit);
		temp_day0 = stoi(day0_string);
		temp_day_to_complete[0] = stoi(day0_string);

		getline(input_stream, day1_string, delimit);
		temp_day1 = stoi(day1_string);
		temp_day_to_complete[1] = stoi(day1_string);

		getline(input_stream, day2_string, delimit);
		temp_day2 = stoi(day2_string);
		temp_day_to_complete[2] = stoi(day2_string);

		// Sets the number of days it takes to complete classes with a populated array
		ptr_student->set_daysToComplete(temp_day_to_complete);

		// Gathers string that corresponds with degree
		getline(input_stream, degree_string, delimit);

		//if-else statements that assign the matching degree program to the enum value
		if (degree_string == "SECURITY")
			temp_degree = SECURITY;
		else if (degree_string == "NETWORK")
			temp_degree = NETWORK;
		else if (degree_string == "SOFTWARE")
			temp_degree = SOFTWARE;
		else
			temp_degree = NONE;

		// Sets enum value for the degreeProgram for the pointer student
		ptr_student->set_degreeProgram(temp_degree);

		// Assigns the temporary student object to the correct index in the roster array
		classRosterArray[i] = ptr_student;
	}
}


// Destructor is responsible for releasing memory, also signals the completion of its execution
Roster::~Roster() { cout << "Roster Destructor has ran." << endl; }

// Loops through each item then triggers the print function defined in the student method for each of them.
void Roster::printAll() {
	for (int i = 0; i < table_size; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::remove(string remove_student_ID) {
	// Boolean flag is set to determine whether or not ID is found
	bool found_flag = false;

	for (int i = 0; i < table_size; i++) {
		if (classRosterArray[i]->get_studentID() == remove_student_ID) {
			found_flag = true; 
			// Found_flag gets set to true

			table_size = table_size - 1; 
			// Makes the table size smaller since we are getting rid of an item

			// Loop begins where ID is found
			for (int j = i; j < table_size; j++) {
				classRosterArray[j] = classRosterArray[j + 1];
			}
		}
	}
	// Prints out that ID wasn't found 
	if (found_flag == false) { cout << "The Student ID was not found" << endl; }
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	table_size++;
	// Increments table size
	int a = table_size - 1;

	int days_array[3]; 
	// Temporary array

	// Temporary object
	Student* add_student;
	add_student = new Student;


	// Setter for strings and age
	add_student->set_studentID(studentID);
	add_student->set_firstName(firstName);
	add_student->set_lastName(lastName);
	add_student->set_studentEmail(emailAddress);
	add_student->set_studentAge(age);

	// Fills the temporary array with the provided integers
	days_array[0] = daysInCourse1;
	days_array[1] = daysInCourse2;
	days_array[2] = daysInCourse3;

	// Assigns the values stored in the temporary array to the daysToComplete array by calling the appropriate setter method
	add_student->set_daysToComplete(days_array);

	// Sets the degreeProgram accordingly
	add_student->set_degreeProgram(degreeprogram);

	// Reassigns the position of the temp student in the array
	classRosterArray[a] = add_student;
}

void Roster::printInvalidEmails() {

	bool valid_email = true;
	bool valid_char = true;
	string email_search;
	size_t found; 
	// The pointer will reference the position where the character is located in the string, pointer will point to end if not found

	for (int i = 0; i < table_size; i++) {

		// For loop conditions
		valid_email = true;
		valid_char = true;

		// Object email to a string
		email_search = classRosterArray[i]->get_studentEmail();

		// Looks for @ symbol in the email address
		found = email_search.find("@");

		// Determines the email as invalid @ is in the wrong postion
		if (found > email_search.length()) { valid_email = false; }

		// If the @ symbol is found, this conditional statement verifies the validity of the next character
		if (found < email_search.length()) {
			found++;
			// Increments found by one
			valid_char = isalnum(email_search[found]);
		}

		if (valid_char == false) { valid_email = false; }
		// Email will be shown as invalid if the valid character isn't placed correctly

		// Looks for a period (.) within email string
		found = email_search.find(".");
		if (found > email_search.length()) { valid_email = false; }


		// Checks whether there are blank spaces or not
		found = email_search.find(" ");
		if (found < email_search.length()) { valid_email = false; }

		// Prints a list of invalid emails
		if (valid_email == false) {
			cout << email_search << "\t" << "- is invalid." << endl;

		}
	}
}

void Roster::printAverageDaysInCourse(string student_id) {

	for (int i = 0; i < table_size; i++) {

		int day0, day1, day2;
		// Declaring int
		double avg;
		string id = classRosterArray[i]->get_studentID(); 
		// Gets the studentID based from loop

		// Assigns values in student object to corresponding local int variable
		day0 = classRosterArray[i]->get_daysToComplete()[0];
		day1 = classRosterArray[i]->get_daysToComplete()[1];
		day2 = classRosterArray[i]->get_daysToComplete()[2];

		avg = (day0 + day1 + day2) / 3.0;

		if (id == student_id) {
			cout << "Student ID: " << id << ", average days in course is: - " << avg << endl;

		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degree_to_print) {

	cout << "Students In " << degree_array[degree_to_print] << " Degree Program:\n" << endl;

	int student_count = 0;
	DegreeProgram local_degree;

	for (int i = 0; i < table_size; i++) {

		// The function creates a variable within its own scope, assigns it the value of the degree program for student currently being checked
		local_degree = classRosterArray[i]->get_degreeProgram();

		// If the student matches then print
		if (local_degree == degree_to_print) {

			classRosterArray[i]->print();
			student_count++;
		}
	}
	// Shows an error if there are no valid students
	if (student_count == 0) { cout << "No valid students found" << endl; }
}