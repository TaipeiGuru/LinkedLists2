#include <iostream>
#include <cstring>
#include "node.h"
#include "student.h"

using namespace std;

/*void printStudent(Node* headStudent);
Student* addStudent();
void deleteStudent(Node* headStudent); 
void findAvg(Node* headStudent); */

int main() {
  char input[10];
  bool active = true;
  while(active == true) {
    cout << "Welcome to Student List: Linked List Edition. What can I do for you? Your options are \"ADD,\" \"DELETE,\" \"PRINT,\" \"AVERAGE,\" and \"QUIT.\"" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(10000, '\n');
    if(strcmp(input, "ADD") == 0){
      
    } else if(strcmp(input, "DELETE") == 0){
      
    } else if(strcmp(input, "PRINT") == 0){
      
    } else if(strcmp(input, "AVERAGE") == 0){
      
    } else if(strcmp(input, "QUIT") == 0){
      active = false;
    } else {
      cout << "Invalid input." << endl;
    }
  }
  
  return 0;
}
