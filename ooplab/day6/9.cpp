#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
  string name;
public:
  Student(string n) {
    name = n;
  }
};

class Arts: public Student {
protected:
  string univ_name;
  string collage_name;
public:
  Arts(string n, string un, string cn):
    Student(n) 
  {
    univ_name = un;
    collage_name = cn;
  }
};

class Medical: public Student {
protected:
  string univ_name;
  string collage_name;
public:
  Medical(string n, string un, string cn):
    Student(n) 
  {
    univ_name = un;
    collage_name = cn;
  }
};

class Engineering: public Student {
protected:
  string univ_name;
  string college_name;
public:
  Engineering(string n, string un, string cn):
    Student(n) 
  {
    univ_name = un;
    college_name = cn;
  }
};

class CS: public Engineering {
  int roll_no;
public:
  CS(string n, string un, string cn, int rn):
    Engineering(n, un, cn)
  {
    roll_no = rn; 
  }
  void display() {
    cout << "In CS Branch\nName: " << name << endl;
  }
};

class IT: public Engineering {
  int roll_no;
public:
  IT(string n, string un, string cn, int rn):
    Engineering(n, un, cn)
  {
    roll_no = rn; 
  }
  void display() {
    cout << "In IT Branch\nCollege Name: " << college_name << endl;
  }
};

class MCA: public Engineering {
  int roll_no;
public:
  MCA(string n, string un, string cn, int rn):
    Engineering(n, un, cn)
  {
    roll_no = rn; 
  }
  void display() {
    cout << "In MCA Branch\nRoll No: " << roll_no << endl;
  }
};

int main() {
  string name, univ, college;
  int roll;

  cout << "Enter student name: ";
  cin >> name;

  cout << "Enter university name: ";
  cin >> univ;

  cout << "Enter college name: ";
  cin >> college;

  cout << "Enter roll no: ";
  cin >> roll;

  CS ob1(name, univ, college, roll);
  IT ob2(name, univ, college, roll);
  MCA ob3(name, univ, college, roll);
  
  ob1.display();
  ob2.display();
  ob3.display();

  return 0;
}