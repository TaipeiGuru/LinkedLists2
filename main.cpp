#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

void addStudent(Node* &headNode, Node* previousNode, Node* currentNode);
void findAvg(Node* headNode); 
/*void printStudent(Node* headStudent);
void deleteStudent(Node* headStudent); 
*/

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

Node* addStudent(Node* &headNode, Node* previousNode, Node* currentNode) {
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
  
  if(headNode->getStudent == NULL) {
    headNode->student = newStudent;
    headNode->setNext(NULL);
  } else {
    if(currentNode->gpa < headNode->getStudent->gpa) {
      Node* tempNode = headNode;
      headNode = new Node(newStudent);
      headNode->setNext(tempNode);
    } else if(currentNode == NULL) {
      previousNode->setNext(new Node(newStudent));
      previousNode->getNext()->setNext(NULL);
    } else if(newStudent->id < currentNode->getStudent->id) {
      Node* tempNode2 = new Node(newStudent);
      previousNode->setNext(tempNode2);
      tempNode2->setNext(currentNode);
    } else {
      addStudent(headNode, currentNode, currentNode->getNext());  
    }
  }
}

void findAvg(Node* headNode) {
  int counter = 0;
  double avg = 0;
  avg += headNode->getStudent->gpa;
  counter++;
  if(headNode->getNext() != NULL) {
    findAvg(headNode->next); 
  }
  cout << avg/counter << endl;
}
