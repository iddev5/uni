#include <iostream>
#include <string>
using namespace std;

class Sales {
protected:
  string salesman_name;
  int qty_sold;
  int salary;
public:
  Sales(string name, int qty, int sal) {
    salesman_name = name;
    qty_sold = qty;
    salary = sal;
  }
};

class Comission: Sales {
  int rate_of_comission;
  int comission_earned;
  int total_salary;

public:
  Comission(string name, int qty_sold, int salary, int rate):
    Sales(name, qty_sold, salary) 
  {
    rate_of_comission = rate;
    comission_earned = rate * qty_sold * 4;
    total_salary = salary + comission_earned;
  }

  void display() {
    cout << "Name: " << salesman_name << endl;
    cout << "Quantity sold: " << qty_sold << endl;
    cout << "Salary: " << salary << endl;
    cout << "Rate of comission: " << rate_of_comission << endl;
    cout << "Comission earned: " << comission_earned << endl;
    cout << "Total salary: " << total_salary << endl;
  }
};

int main() {
  string name;
  int qty, salary, rate;

  cout << "Enter name of salesman: ";
  cin >> name;
  cout << "Enter quantity of product sold: ";
  cin >> qty;
  cout << "Enter base salary: ";
  cin >> salary;
  cout << "Enter rate of comission: ";
  cin >> rate;

  Comission com(name, qty, salary, rate);
  com.display();

  return 0;
}