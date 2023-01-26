#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

void addStudent(Node* &headNode, Student* newStudent);
// void findAvg(Node* headNode); 
void printStudent(Node* headStudent);
// void deleteStudent(Node* headStudent); 

int main() {
  Node* head;
  char input[20];
  int myID;
  float myGPA;
  bool active = true;
  cout << "Welcome to Student List: Linked List Edition." << endl; 
  while(active == true) {
    cout << "Your options are \"ADD,\" \"DELETE,\" \"PRINT,\" \"AVERAGE,\" and \"QUIT.\"" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(10000, '\n');
    if(strcmp(input, "ADD") == 0){
      Student* newStudent = new Student();
      cout << "Enter the student's first name:" << endl; 
      cin >> newStudent->getFirstName();
      cout << "Enter the student's last name:" << endl; 
      cin >> newStudent->getLastName();
      cout << "Enter the student's ID:" << endl;
      cin >> myID;
      newStudent->setID(myID);
      cout << "Enter the student's GPA:" << endl;
      cin >> myGPA;
      newStudent->setGPA(myGPA);
      addStudent(head, newStudent);
    } else if(strcmp(input, "DELETE") == 0){
      if(head == NULL) {
        cout << "No students in list." << endl; 
      } else { 
        // deleteStudent(head);
      }      
    } else if(strcmp(input, "PRINT") == 0){
      if(head == NULL) {
        cout << "No students in list." << endl; 
      } else { 
        printStudent(head);
      }
    } else if(strcmp(input, "AVERAGE") == 0){
      if(head == NULL) {
        cout << "No students in list." << endl; 
      } else { 
        // findAvg(head);
      }
    } else if(strcmp(input, "QUIT") == 0){
      active = false;
    } else {
      cout << "Invalid input." << endl;
    }
  }
  
  return 0;
}

void addStudent(Node* &headNode, Student* newStudent) {
  if(headNode/*->getStudent()*/ == NULL) {
    headNode = new Node(newStudent);
    headNode->setNext(NULL);
  } else if(headNode->getStudent()->getGPA() > newStudent->getGPA()) {
    Node* tempNode = headNode;
    headNode = new Node(newStudent);
    headNode->setNext(tempNode);
  } else if(headNode->getNext() == NULL) {
    headNode->setNext(new Node(newStudent));
    headNode->getNext()->setNext(NULL);
  } else if(newStudent->getID() < headNode->getNext()->getStudent()->getID()) {
    Node* tempNode2 = new Node(newStudent);
    tempNode2->setNext(headNode->getNext()->getNext());
    headNode->setNext(tempNode2);
  } else {
    addStudent(headNode, newStudent);  
  }
}

void printStudent(Node* headNode) {
  while(headNode != NULL) {
    headNode->getStudent()->printStudent();
    printStudent(headNode->getNext());
  }
}

/*void findAvg(Node* headNode) {
  int counter = 0;
  double avg = 0;
  avg += headNode->getStudent->gpa;
  counter++;
  if(headNode->getNext() != NULL) {
    findAvg(headNode->next); 
  }
  cout << avg/counter << endl;
  }*/
