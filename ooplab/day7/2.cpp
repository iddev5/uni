#include <iostream>
#include <string>
using namespace std;

class Person {
  string name;
  int age;
public:
  Person(string n, int a) {
    name = n;
    age = a;
  }
  void display() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
  }
};

class Employee: Person {
  int salary;
public:
  Employee(string name, int age, int sal):
    Person(name, age)
  {
    salary = sal;
  }
  void display() {
    Person::display();
    cout << "Salary: " << salary << endl;
  }
};

int main() {
  string name;
  int age, salary;

  cout << "Enter name: ";
  cin >> name;

  cout << "Enter age: ";
  cin >> age;

  cout << "Enter salary: ";
  cin >> salary;
  
  Person per(name, age);
  Employee emp(name, age, salary);

  cout << "\nDisplaying details of person:" << endl;
  per.display();

  cout << "\nDisplaying details of employee:" << endl;
  emp.display();

  return 0;
}
