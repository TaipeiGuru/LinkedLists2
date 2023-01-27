// Imports
#include <iostream>
#include <cstring>
#include <iomanip>
#include "node.h"
#include "student.h"

using namespace std;

// Prototypes
void addStudent(Node* &headNode, Student* newStudent);
void findAvg(Node* headNode, int counter, double avg); 
void printStudent(Node* headNode);
void deleteStudent(Node* &headNode, int myID); 

int main() {
  // Variable initialization
  Node* head = NULL;
  char input[20];
  int myID;
  float myGPA;
  int counter = 0;
  double avg = 0;
  bool active = true;
  cout << "Welcome to Student List: Linked List Edition." << endl; 
  
  // While loop to keep track of game running
  while(active == true) {
    cout << "Your options are \"ADD,\" \"DELETE,\" \"PRINT,\" \"AVERAGE,\" and \"QUIT.\"" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(10000, '\n');
    
    // If the user wants to add a student, names, ID, and GPA are collected and stored in a new Student. addStudent is then called.
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
      
      // If the head node is null, the deleteStudent function won't run. Otherwise, it asks for the ID and then calls the function.
    } else if(strcmp(input, "DELETE") == 0){
      if(head == NULL) {
        cout << "No students in list." << endl; 
      } else { 
        cout << "What's the ID of the student you wish to delete?" << endl;
        cin >> myID;
        deleteStudent(head, myID);
      }      
      
      // calls printStudent
    } else if(strcmp(input, "PRINT") == 0){
      if(head == NULL) {
        cout << "No students in list." << endl; 
      } else { 
        printStudent(head);
      }
      
      // calls findAvg
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
  // If the head node is null, a new head node is created using the new Student.
  if(headNode == NULL) {
    headNode = new Node(newStudent);
    cout << "Student added." << endl;
    // If the new Student's GPA is higher than the head Node, a new head node is created that links to the previous head node.
  } else if(headNode->getStudent()->getID() > newStudent->getID()) {
    Node* tempNode = headNode;
    headNode = new Node(newStudent);
    headNode->setNext(tempNode);
    cout << "Student added." << endl;
    // If the next node is null, a new node is created and the head node links to that new node
  } else if(headNode->getNext() == NULL) {
    Node* tempNode4 = new Node(newStudent);
    headNode->setNext(tempNode4);
    cout << "Student added." << endl;
    // If the student's GPA is between two nodes, a new node is created with that new Student. This node then links to the head node's next next node. 
    // Finally, the head node links to the new node. 
  } else if(newStudent->getID() <= headNode->getNext()->getStudent()->getID() && newStudent->getID() >= headNode->getStudent()->getID()) {
    Node* tempNode2 = new Node(newStudent);
    tempNode2->setNext(headNode->getNext());
    headNode->setNext(tempNode2);
    cout << "Student added." << endl;
    // If no conditions are met, the function is called again (recursive).
  } else {
    Node* tempNode3 = headNode->getNext();
    addStudent(tempNode3, newStudent);  
  }
}

void printStudent(Node* headNode) {
  // As long as the node isn't null, the node's student is printed and then the function is called again with the next node
  if(headNode != NULL) {
    headNode->getStudent()->printStudent();
    printStudent(headNode->getNext());
  }
}

/* Takes in a node, counter, and average. For each node, the GPA is added to avg and counter is incremented. Once all nodes have run out, the avg is divided
 * by counter and outputted */
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
  // If the ID matches and the next node is null, the node is deleted and set to null for safety.
  if(headNode->getStudent()->getID() == myID && headNode->getNext() == NULL) {
    delete headNode;
    headNode = NULL;
    cout << "Student deleted." << endl;
    /* If the ID of the next node's student matches and the next next node isn't null, a new node is set to head->next. Then, head is set to the next next 
     * and the new node is deleted. */
  } else if(headNode->getNext()->getStudent()->getID() == myID && headNode->getNext()->getNext() != NULL) {
    Node* tempNode = headNode->getNext();
    headNode->setNext(headNode->getNext()->getNext());
    delete tempNode;
    cout << "Student deleted." << endl;
    /* If the ID of the next node's student matches but the next next node is null, the 
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
