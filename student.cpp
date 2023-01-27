// Student CPP file

// Imports
#include <iostream>
#include <cstring>
#include <iomanip>
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
  cout << firstName << " " << lastName << ", " << id << ", " << fixed << setprecision(2) << gpa << endl;
}

void Student::setID(int myID) {
  id = myID;
}

void Student::setGPA(float myGPA) {
  gpa = myGPA;
}

int Student::getID() {
  return id;
}

float Student::getGPA() {
  return gpa;
}

char* Student::getFirstName() {
  return firstName;
}

char* Student::getLastName() {
  return lastName;
}
