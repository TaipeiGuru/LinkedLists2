#include <iostream>
#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student {
 public:
  // Constructor.
  Student();
  // Destructor.
  ~Student();
  // Printing the name.
  void printStudent();
 private:
  // Student details.
  char firstName[20];
  char lastName[20];
  int id;
  float GPA;
};

#endif
