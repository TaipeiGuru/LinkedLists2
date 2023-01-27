#include <iostream>
#include <cstring>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

void addStudent(Node* &headNode, Student* newStudent);
void findAvg(Node* headNode, int counter, double avg); 
void printStudent(Node* headNode);
void deleteStudent(Node* &headNode, int myID); 

int main() {
  Node* head = NULL;
  char input[20];
  int myID;
  float myGPA;
  int counter = 0;
  double avg = 0;
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
        cout << "What's the ID of the student you wish to delete?" << endl;
        cin >> myID;
        deleteStudent(head, myID);
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
        findAvg(head, counter, avg);
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
  if(headNode == NULL) {
    headNode = new Node(newStudent);
    cout << "Student added." << endl;
  } else if(headNode->getStudent()->getID() > newStudent->getID()) {
    Node* tempNode = headNode;
    headNode = new Node(newStudent);
    headNode->setNext(tempNode);
    cout << "Student added." << endl;
  } else if(headNode->getNext() == NULL) {
    Node* tempNode4 = new Node(newStudent);
    headNode->setNext(tempNode4);
    cout << "Student added." << endl;
  } else if(newStudent->getID() <= headNode->getNext()->getStudent()->getID() && newStudent->getID() >= headNode->getStudent()->getID()) {
    Node* tempNode2 = new Node(newStudent);
    tempNode2->setNext(headNode->getNext());
    headNode->setNext(tempNode2);
    cout << "Student added." << endl;
  } else {
    Node* tempNode3 = headNode->getNext();
    addStudent(tempNode3, newStudent);  
  }
}

void printStudent(Node* headNode) {
  if(headNode != NULL) {
    headNode->getStudent()->printStudent();
    printStudent(headNode->getNext());
  }
}

void findAvg(Node* headNode, int counter, double avg) {
  if(headNode != NULL) {
    avg += headNode->getStudent()->getGPA();
    counter++;
    findAvg(headNode->getNext(), counter, avg); 
  } else {
    cout << "Average GPA: " << fixed << setprecision(2) << avg/counter << endl;
  }
}

void deleteStudent(Node* &headNode, int myID) {
  if(headNode->getStudent()->getID() == myID && headNode->getNext() == NULL) {
    delete headNode;
    headNode = NULL;
    cout << "Student deleted." << endl;
  } else if(headNode->getNext()->getStudent()->getID() == myID && headNode->getNext()->getNext() != NULL) {
    Node* tempNode = headNode->getNext();
    headNode->setNext(headNode->getNext()->getNext());
    delete tempNode;
    cout << "Student deleted." << endl;
  } else if(headNode->getNext()->getStudent()->getID() == myID && headNode->getNext()->getNext() == NULL) {
    Node* tempNode2 = headNode->getNext();
    headNode->setNext(NULL);
    delete tempNode2;
    cout << "Student deleted." << endl;
  } else if (headNode->getStudent()->getID() == myID && headNode->getNext() != NULL) {
    Node* tempNode3 = headNode;
    headNode = headNode->getNext();
    delete tempNode3;
    cout << "Student deleted." << endl;
  } else {
    Node* tempNode4 = headNode->getNext();
    deleteStudent(tempNode4, myID);   
  }
}
