#include <iostream>
#include <string.h>
using namespace std;

class String {
  char *data;
  int len;

public:
  String(char *val) {
    data = val;
    len = strlen(val);
  }

  void display() {
    cout << data << endl;
  }

  String operator+(String &);
};

String String::operator+(String &s) {
  char *newstr = new char[len + s.len];
  strcpy(newstr, data);
  strcat(newstr, s.data);

  return String(newstr);
}

int main() {
  char s1[100], s2[100];

  cout << "Enter first string: ";
  cin.getline(s1, 100);

  cout << "Enter second string: ";
  cin.getline(s2, 100);

  String str1(s1), str2(s2);

  String str3 = str1 + str2;

  cout << "After concatenating: ";
  str3.display();

  return 0;
}
