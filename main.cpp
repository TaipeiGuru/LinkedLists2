#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

/*void printStudent(Node* headStudent);
void addStudent(Node* headStudent);
void deleteStudent(Node* headStudent); 
void findAvg(Node* headStudent); */

int main() {
  Node* head;
  char input[10];
  bool active = true;
  cout << "Welcome to Student List: Linked List Edition." << endl; 
  while(active == true) {
    cout << "Your options are \"ADD,\" \"DELETE,\" \"PRINT,\" \"AVERAGE,\" and \"QUIT.\"" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(10000, '\n');
    if(strcmp(input, "ADD") == 0){
      addStudent(head);
    } else if(strcmp(input, "DELETE") == 0){
      deleteStudent(head);      
    } else if(strcmp(input, "PRINT") == 0){
      printStudent(head);
    } else if(strcmp(input, "AVERAGE") == 0){
      findAvg(head);
    } else if(strcmp(input, "QUIT") == 0){
      active = false;
    } else {
      cout << "Invalid input." << endl;
    }
  }
  
  return 0;
}

Node* addStudent(Node* headStudent) {
  char input[20];
 
  Student* newStudent = new Student();
  cout << "Enter the student's first name:" << endl; 
  cin >> input;
  strcpy(newStudent->firstName, input);
  cout << "Enter the student's last name:" << endl; 
  cin >> input;
  strcpy(newStudent->lastName, input);
  cout << "Enter the student's ID:" << endl;
  cin >> newStudent->id;
  cout << "Enter the student's GPA:" << endl;
  cin >> newStudent->gpa;
  
  Node* newNode = new Node(newStudent);

  while(head->getNext() != NULL) {
    head = head->getNext(); 
  }
}
