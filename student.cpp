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
