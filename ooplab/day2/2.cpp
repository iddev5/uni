#include <iostream>
using namespace std;

int area(int l, int b) {
  return l * b;
}

double area(double r) {
  return 3.14 * r * r;
}

int area(int s) {
  return s * s;
}

int main() {
  int l, b, s;
  float r;
  
  cout << "Enter length and breadth of reactangle: ";
  cin >> l >> b;
  cout << "Area of rectangle: " << area(l, b) << endl;

  cout << "Enter radius of circle: ";
  cin >> r;
  cout << "Area of circle: " << area(r) << endl;

  cout << "Enter side of square: ";
  cin >> s;
  cout << "Area of square: " << area(s) << endl; 
  return 0;
}
