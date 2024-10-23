#include <iostream>
using namespace std;

class Triangle {
  int a, b, c;
public:
  void getdata() {
    cout << "Enter three side length of the triangle: ";
    cin >> a >> b >> c;
  }
  
  void display() {
    if (a == b && b == c) {
      cout << "Triangle is equilateral" << endl;
    } else if (a != b && b != c && c != a) {
      cout << "Triangle is scalene" << endl;
    } else {
      cout << "Triangle is isosceles" << endl;
    }
  }
};

int main() {
  Triangle t;
  t.getdata();
  t.display();
  return 0;
}