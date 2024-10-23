#include <iostream>
#include <string.h>
using namespace std;

class String {
  int n;
  char *data;

public:
  String() {
    n = 0;
    data = NULL;
  }

  String(char *str) {
    set(str);
  }

  void set(char *str) {
    n = strlen(str);
    data = str;
  }

  void display() {
    cout << data;
  }

  String concat(String &so) {
    char *newdata = new char[n + so.n + 1];
    strcpy(newdata, data);
    strcat(newdata, so.data);
    String newstr(newdata);
    return newstr;
  }
};

int main() {
  char data1[100], data2[100];
  
  String s1;
  cout << "Enter data to set an uninitialzed object: ";
  cin.getline(data1, 100);
  s1.set(data1);

  cout << "Enter data to create object with string constant: ";
  cin.getline(data2, 100);
  String s2(data2);

  String s3 = s1.concat(s2);
  cout << "After concat: ";
  s3.display();
}
