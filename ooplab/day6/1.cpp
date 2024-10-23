#include <iostream>
#include <string>
using namespace std;

class Editor {
  string name;
  int emp_code;
  string date_of_joining;
public:
  Editor(string n1, int e1, string d1) {
    name = n1;
    emp_code = e1;
    date_of_joining = d1;
  }

  void display() {
    cout << "Name: " << name << endl;
    cout << "Employee code: " << emp_code << endl;
    cout << "Date of Joining: " << date_of_joining << endl;
  }
};

class Reporter: public Editor {
  string field_of_operation;
  int years_of_exp;
public:
  Reporter(string n1, int e1, string d1, string f1, int y1):
    Editor(n1, e1, d1) 
  {
    field_of_operation = f1;
    years_of_exp = y1;  
  }

  void display() {
    Editor::display();
    cout << "Field of operation: " << field_of_operation << endl;
    cout << "Years of experience: " << years_of_exp << endl;
  }
};

int main() {
  string name, date, field;
  int emp_code, exp;
  
  cout << "Enter name of reporter: ";
  cin >> name;

  cout << "Enter employee code: ";
  cin >> emp_code;

  cout << "Enter date of joining: ";
  cin >> date;

  cout << "Enter field of operation: ";
  cin >> field;

  cout << "Enter years of experience: ";
  cin >> exp;
  
  Reporter r(name, emp_code, date, field, exp);
  r.display();

  return 0;
}