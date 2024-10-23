#include <iostream>
#include <string>
using namespace std;

class Subject {
protected:
  string sub_name;
  int sub_code;
public:
  Subject(string sn, int sc) {
    sub_name = sn;
    sub_code = sc;
  }
};

class Faculty: public virtual Subject {
protected:
  string name;
  string designation;
  int emp_code;
public:
  Faculty(string sn, int sc, string n, string d, int ec):
    Subject(sn, sc) 
  {
    name = n;
    designation = d;
    emp_code = ec;
  }
};

class GuestFaculty: public virtual Subject {
protected:
  string name;
  int emp_code;
public:
  GuestFaculty(string sn, int sc, string n, int ec):
    Subject(sn, sc)
  {
    name = n;
    emp_code = ec;
  }
};

class Student: public virtual Faculty, public virtual GuestFaculty {
  string stud_name;
  int roll_no;
public:
  Student(string sn, int sc, string n, string d, int ec, string stn, int rn):
    Subject(sn, sc), Faculty(sn, sc, n, d, ec), GuestFaculty(sn, sc, n, ec)
  {
    stud_name = stn;
    roll_no = rn;
  }

  void display() {
    cout << "Subject name: " << sub_name << endl;
    cout << "Subject code: " << sub_code << endl;
    cout << "Faculty name: " << Faculty::name << endl;
    cout << "Employee code: " << Faculty::emp_code << endl;
    cout << "Designation: " << designation << endl;
    cout << "Student name: " << stud_name << endl;
    cout << "Roll no: " << roll_no << endl;
  }
};

int main() {
  string sn, n, d, stdn;
  int sc, ec, rn;

  cout << "Enter subject name: ";
  cin >> sn;

  cout << "Enter subject code: ";
  cin >> sc;

  cout << "Enter faculty name: ";
  cin >> n;

  cout << "Enter designation: ";
  cin >> d;

  cout << "Enter employee code: ";
  cin >> ec;

  cout << "Enter student name: ";
  cin >> stdn;

  cout << "Enter roll no: ";
  cin >> rn;

  Student stud(sn, sc, n, d, ec, stdn, rn);
  stud.display();

  return 0;
}