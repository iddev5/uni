#include <iostream>
using namespace std;

class Employee {
  char name[32];
  unsigned long emp_id;
  unsigned long salary;
public:
  void getdata() {
    cout << "Enter employee name: ";
    cin >> name;

    cout << "Enter employee ID: ";
    cin >> emp_id;  
  }

  void setsalary(int hours_worked, float efficiency) {
    salary = hours_worked * 50 * efficiency / 100.0;
  }
  
  void display() {
    cout << "Employee details:" << endl;
    cout << "Name: " << name << endl;
    cout << "ID: " << emp_id << endl;
    cout << "Salary: " << salary << endl;
  }
};

int main() {
  Employee e;
  e.getdata();

  int hours; float eff;
  cout << "To calculate salary based on performance" << endl;
  cout << "Enter hours worked: ";
  cin >> hours;
  cout << "Enter efficiency percentage: ";
  cin >> eff;

  e.setsalary(hours, eff);
  e.display();
  
  return 0;
}