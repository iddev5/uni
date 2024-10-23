#include <iostream>
using namespace std;

class Student {
  char name[32];
  int class_;
  unsigned long roll_no;
  int marks;
public:
  void getdata() {
    cout << "Enter student details:" << endl;
    cout << "Name: ";
    cin >> name;

    cout << "Class: ";
    cin >> class_;

    cout << "Roll No: ";
    cin >> roll_no;

    cout << "Marks: ";
    cin >> marks;
  }

  char grade() {
    if (marks >= 90) return 'O';
    else if (marks < 40) return 'F';
    return ('E' - (marks / 10)) + 4; 
  }
  
  void display() {
    cout << "Student details:" << endl;
    cout << "Name: " << name << endl;
    cout << "Class: " << class_ << endl;
    cout << "Roll No: " << roll_no << endl;
    cout << "Grade: " << grade() << endl;
  }
};

int main() {
  Student s;
  s.getdata();
  s.display();
  return 0;
}