#include <iostream>
#include <cstring>

using namespace std;

void printStudent(Node* headStudent);
Student* addStudent();
void deleteStudent(Node* headStudent); 
void findAvg(Node* headStudent);

int main() {
  char input[10];
  bool active = true;
  while(active == true) {
    cout << "Welcome to Student List: Linked List Edition. What can I do for you? Your options are \"ADD,\" \"DELETE,\" \"PRINT,\" \"AVERAGE,\" and \"QUIT.\"" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(10000, '\n');
    if(strcmp(input, "QUIT") == 0){
      active = false;
    }
  }
  
  return 0;
}
