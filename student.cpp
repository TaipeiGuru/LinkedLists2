#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

// Constructor.
Student::Student() {
}

// Destructor.
Student::~Student() {
}

// Printing the student name.
void Student::printStudent() {
  cout << firstName << " " << lastName << ", " << id << ", " << gpa << endl;
}
