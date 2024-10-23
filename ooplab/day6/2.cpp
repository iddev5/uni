#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
  string name;
  int emp_code;
  int salary;  

  Employee(string n1, int e1, int s1) {
    name = n1;
    emp_code = e1;
    salary = s1;
  }
};

class IncomeTax: private Employee {
  int tax_deducted;
  int net_salary;
public:
  IncomeTax(string n1, int e1, int s1, int t1):
    Employee(n1, e1, s1) 
  {
    tax_deducted = t1;
    net_salary = salary - tax_deducted;  
  }

  void display() {
    cout << "Name: " << name << endl;
    cout << "Employee code: " << emp_code << endl;
    cout << "Salary: " << salary << endl;
    cout << "Tax deducted: " << tax_deducted << endl;
    cout << "Net salary: " << net_salary << endl;
  }
};

int main() {
  string name;
  int ecode, salary, tax;

  cout << "Enter name of employee: ";
  cin >> name;

  cout << "Enter employee code: ";
  cin >> ecode;

  cout << "Enter base salary: ";
  cin >> salary;

  cout << "Enter tax to be deducted: ";
  cin >> tax;

  IncomeTax it(name, ecode, salary, tax);
  it.display();
  
  return 0;
}