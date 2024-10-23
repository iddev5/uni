#include <iostream>
#include <string>
using namespace std;

class Student {
public:
  int roll_no;
  Student(int rn) {
    roll_no = rn;
  }
};

class Test: public Student {
public:
  int oop_marks, dbe_marks;
  Test(int roll, int m1, int m2): Student(roll) {
    oop_marks = m1;
    dbe_marks = m2;
  }
};

class Result: Test {
  int sum_of_marks;
public:
  Result(int roll, int oop, int dbe):
    Test(roll, oop, dbe)
  {
    sum_of_marks = oop_marks + dbe_marks;
  }

  void display_results() {
    cout << "Student roll no: " << roll_no << endl;
    cout << "Marks in OOP: " << oop_marks << endl;
    cout << "Marks in DBE: " << dbe_marks << endl;
    cout << "Sum of marks: " << sum_of_marks << endl;
  }
};

int main() {
  int roll, oop, dbe;
  cout << "Enter roll no: ";
  cin >> roll;

  cout << "Enter OOP marks: ";
  cin >> oop;

  cout << "Enter DBE marks: ";
  cin >> dbe;

  Result res(roll, oop, dbe);
  res.display_results();

  return 0;
}